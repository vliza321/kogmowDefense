
// GLOBALS //

cbuffer MatrixBuffer : register(b0)
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};

cbuffer LightBuffer : register(b1)
{
    float4 ambientColor;
    float4 ddiffuseColor;
    float3 lightDirection;
    float specularPower;
    float4 specularColor;
};

cbuffer CameraBuffer : register(b2)
{
    float3 cameraPosition;
    float padding;
};

cbuffer LightPositionBuffer : register(b3)
{
	float4 lightPosition[8];
};

cbuffer LightColorBuffer : register(b4)
{
	float4 diffuseColor[8];
};

//0. Texture0
//1. Texture1
//2. Alpha0
//3. Alpha1
//4. Light
//5. Bump
//6. Specular
Texture2D shaderTexture[7] : register(t0);
SamplerState SampleType : register(s0);

// TYPEDEFS //
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float3 binormal : BINORMAL;
    float4 instancePosition : TEXCOORD1;
};

//deviceContext를 통한 맵핑(lightshaderclass참고)
struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float3 binormal : BINORMAL;
    float3 viewDirection : TEXCOORD1;
	float3 lightDir0 : TEXCOORD2;
    float3 lightDir1 : TEXCOORD3;
    float3 lightDir2 : TEXCOORD4;
    float3 lightDir3 : TEXCOORD5;
    float3 lightDir4 : TEXCOORD6;
    float3 lightDir5 : TEXCOORD7;
    float3 lightDir6 : TEXCOORD8;
    float3 lightDir7 : TEXCOORD9;
};

// Vertex Shader
PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    float4 worldPosition;


    // Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;
    input.instancePosition.w = 1.0f;

    // Calculate the position of the vertex in the world.
    worldPosition = mul(input.position, worldMatrix);
    
    // Calculate the position of the vertex against the world, view, and projection matrices.
    output.position = mul(input.position, worldMatrix);
    
    output.position.x += input.instancePosition.x;
    output.position.y += input.instancePosition.y;
    output.position.z += input.instancePosition.z;

    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

    // Store the texture coordinates for the pixel shader.
    output.tex = input.tex;

    // Calculate the normal vector against the world matrix only and Normalize the normal vector.
    output.normal = mul(input.normal, (float3x3)worldMatrix);
    output.normal = normalize(output.normal);

    // 월드 행렬에 대해서만 접선 벡터를 계산 한 다음 최종 값을 정규화합니다.
    output.tangent = mul(input.tangent, (float3x3) worldMatrix);
    output.tangent = normalize(output.tangent);

    // 세계 행렬에 대해서만 비 유효 벡터를 계산 한 다음 최종 값을 정규화합니다.
    output.binormal = mul(input.binormal, (float3x3) worldMatrix);
    output.binormal = normalize(output.binormal);
    
    

    // Determine the viewing direction based on the position of the camera and the position of the vertex in the world.
    output.viewDirection = cameraPosition.xyz - worldPosition.xyz;

    // Normalize the viewing direction vector.
    output.viewDirection = normalize(output.viewDirection);


    // Determine the light positions based on the position of the lights and the position of the vertex in the world.
    output.lightDir0.xyz = lightPosition[0].xyz - worldPosition.xyz;
    output.lightDir1.xyz = lightPosition[1].xyz - worldPosition.xyz;
    output.lightDir2.xyz = lightPosition[2].xyz - worldPosition.xyz;
    output.lightDir3.xyz = lightPosition[3].xyz - worldPosition.xyz;
    output.lightDir4.xyz = lightPosition[4].xyz - worldPosition.xyz;
    output.lightDir5.xyz = lightPosition[5].xyz - worldPosition.xyz;
    output.lightDir6.xyz = lightPosition[6].xyz - worldPosition.xyz;
    output.lightDir7.xyz = lightPosition[7].xyz - worldPosition.xyz;
    
    return output;
}

// Pixel Shader
float4 LightPixelShader(PixelInputType input) : SV_TARGET
{
    float4 textureColor1;
    float4 textureColor2;
    float4 lightAlphaColor;
    float4 bumpColor;
    float3 bumpNormal;
    
    float3 lightDir;
    float lightIntensity;
	float4 color;
    float3 reflection;
    float4 specular;
    
    float3 inputPLDir[8];
    float PLD[8];
    float4 PLC[8];
    float PLI[8];
    float3 PLR[8];
    float4 PLS[8];
    
    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor1 = shaderTexture[0].Sample(SampleType, input.tex);
    textureColor2 = shaderTexture[1].Sample(SampleType, input.tex);
    lightAlphaColor = shaderTexture[4].Sample(SampleType, input.tex);
    bumpColor = shaderTexture[5].Sample(SampleType, input.tex);
    
    // Set the default output color to the ambient light value for all pixels.
    color = float4(0.0f, 0.0f, 0.0f, 0.0f);

    // Initialize the specular color.
    specular = float4(0.0f, 0.0f, 0.0f, 0.0f);

    bumpColor = ((bumpColor * 2.0f) - 1.0f) * 0.5f;
    
    bumpNormal = (bumpColor.x * input.tangent) + (bumpColor.y * input.binormal) + (bumpColor.z * input.normal);
    
    bumpNormal = normalize(bumpNormal);
    
    // Invert the light direction for calculations.
    lightDir = -lightDirection;

    // Calculate the amount of light on this pixel.
    //lightIntensity = dot(lightDir, input.normal);
    lightIntensity = saturate(dot(lightDir, bumpNormal));
    
    inputPLDir[0] = input.lightDir0;
    inputPLDir[1] = input.lightDir1;
    inputPLDir[2] = input.lightDir2;
    inputPLDir[3] = input.lightDir3;
    inputPLDir[4] = input.lightDir4;
    inputPLDir[5] = input.lightDir5;
    inputPLDir[6] = input.lightDir6;
    inputPLDir[7] = input.lightDir7;
    
    float4 pointLightColor = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 pointLightSpecular = float4(0.0f, 0.0f, 0.0f, 0.0f);
    
    for (int i = 0; i < 8; ++i)
    {
        PLD[i] = dot(inputPLDir[i], inputPLDir[i]);
        PLC[i] = diffuseColor[i] / (PLD[i] * 2 + 0.5f);
        PLI[i] = max(dot(normalize(inputPLDir[i]), input.normal), 0.0f);
        //PLI[i] = max(dot(normalize(inputPLDir[i]), bumpNormal), 0.0f);
        PLC[i] = saturate(PLC[i] * PLI[i]);
        
        pointLightColor += PLC[i];
        
        //PLR[i] = normalize(2 * PLI[i] * bumpNormal - inputPLDir[i]);
        PLR[i] = normalize(2 * PLI[i] * input.normal - inputPLDir[i]);
        PLS[i] = PLC[i] * pow(saturate(dot(PLR[i], input.viewDirection)), specularPower / 2);
        pointLightSpecular += PLS[i];

    }
    
    float4 minColor = float4(0.1f, 0.1f, 0.1f, 0.1f) * 5;
    color = ambientColor + minColor;
    
    if (lightIntensity > 0.0f)
    {
        // Determine the final diffuse color based on the diffuse color and the amount of light intensity.
        color += (ddiffuseColor * lightIntensity);

        // Saturate the ambient and diffuse color.
        color = saturate(color);

        // Calculate the reflection vector based on the light intensity, normal vector, and light direction.
        //reflection = normalize(2 * lightIntensity * bumpNormal - lightDir);
        reflection = normalize(2 * lightIntensity * input.normal - lightDir);

        // Determine the amount of specular light based on the reflection vector, viewing direction, and specular power.
        specular = specularColor * pow(saturate(dot(reflection, input.viewDirection)), specularPower);
    }

    // Multiply the texture pixel and the input color to get the textured result.
    float4 finalTextureColor = textureColor1 * textureColor2 * 2.0f;
    finalTextureColor = saturate(finalTextureColor);
    finalTextureColor = finalTextureColor * lightAlphaColor;
    
    color = color * finalTextureColor;
    
    // Add the pointLight DiffuseColor componenet
    color += pointLightColor;

    // Add the specular component last to the output color.
    color = saturate(color + specular + pointLightSpecular);
    
    return color;
}