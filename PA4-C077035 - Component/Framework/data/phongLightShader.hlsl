
// GLOBALS //

cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};

cbuffer LightBuffer
{
    float4 ambientColor;
    float4 ddiffuseColor;
    float3 lightDirection;
    float specularPower;
    float4 specularColor;
};

cbuffer CameraBuffer
{
    float3 cameraPosition;
    float padding;
};

cbuffer LightPositionBuffer
{
	float4 lightPosition[8];
};

cbuffer LightColorBuffer
{
	float4 diffuseColor[8];
};


Texture2D shaderTexture;
SamplerState SampleType;

// TYPEDEFS //
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
    float4 instancePosition : TEXCOORD1;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
    float3 viewDirection : TEXCOORD1;
	float3 lightPos0 : TEXCOORD2;
	float3 lightPos1 : TEXCOORD3;
	float3 lightPos2 : TEXCOORD4;
	float3 lightPos3 : TEXCOORD5;
    float3 lightPos4 : TEXCOORD6;
    float3 lightPos5 : TEXCOORD7;
    float3 lightPos6 : TEXCOORD8;
    float3 lightPos7 : TEXCOORD9;
};

// Vertex Shader
PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    float4 worldPosition;


    // Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;
    input.instancePosition.w = 1.0f;

    // Calculate the position of the vertex against the world, view, and projection matrices.
    output.position = mul(input.position, worldMatrix);

    output.position.x += input.instancePosition.x;
    output.position.y += input.instancePosition.y;
    output.position.z += input.instancePosition.z;

    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

    // Store the texture coordinates for the pixel shader.
    output.tex = input.tex;

    // Calculate the normal vector against the world matrix only.
    output.normal = mul(input.normal, (float3x3)worldMatrix);

    // Normalize the normal vector.
    output.normal = normalize(output.normal);

    // Calculate the position of the vertex in the world.
    worldPosition = mul(input.position, worldMatrix);



    // Determine the viewing direction based on the position of the camera and the position of the vertex in the world.
    output.viewDirection = cameraPosition.xyz - worldPosition.xyz;

    // Normalize the viewing direction vector.
    output.viewDirection = normalize(output.viewDirection);


    // Determine the light positions based on the position of the lights and the position of the vertex in the world.
    output.lightPos0.xyz = lightPosition[0].xyz - worldPosition.xyz;
    output.lightPos1.xyz = lightPosition[1].xyz - worldPosition.xyz;
    output.lightPos2.xyz = lightPosition[2].xyz - worldPosition.xyz;
    output.lightPos3.xyz = lightPosition[3].xyz - worldPosition.xyz;
    output.lightPos4.xyz = lightPosition[4].xyz - worldPosition.xyz;
    output.lightPos5.xyz = lightPosition[5].xyz - worldPosition.xyz;
    output.lightPos6.xyz = lightPosition[6].xyz - worldPosition.xyz;
    output.lightPos7.xyz = lightPosition[7].xyz - worldPosition.xyz;

    // Normalize the light position vectors.
    output.lightPos0 = normalize(output.lightPos0);
    output.lightPos1 = normalize(output.lightPos1);
    output.lightPos2 = normalize(output.lightPos2);
    output.lightPos3 = normalize(output.lightPos3);
    output.lightPos4 = normalize(output.lightPos4);
    output.lightPos5 = normalize(output.lightPos5);
    output.lightPos6 = normalize(output.lightPos6);
    output.lightPos7 = normalize(output.lightPos7);

    return output;
}

// Pixel Shader
float4 LightPixelShader(PixelInputType input) : SV_TARGET
{
    float4 textureColor;
    float3 lightDir;
    float lightIntensity;
	float4 color;
    float3 reflection;
    float4 specular;
    float pointLightIntensity0, pointLightIntensity1, pointLightIntensity2, pointLightIntensity3,
        pointLightIntensity4, pointLightIntensity5, pointLightIntensity6, pointLightIntensity7;
    float4 pointLightColor0,  pointLightColor1,  pointLightColor2,  pointLightColor3,
        pointLightColor4, pointLightColor5, pointLightColor6, pointLightColor7;

    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor = shaderTexture.Sample(SampleType, input.tex);

    // Set the default output color to the ambient light value for all pixels.
    color = float4(0.0f, 0.0f, 0.0f, 0.0f);
    color = ambientColor;

    // Initialize the specular color.
    specular = float4(0.0f, 0.0f, 0.0f, 0.0f);

    // Invert the light direction for calculations.
    lightDir = -lightDirection;

    // Calculate the amount of light on this pixel.
    lightIntensity = saturate(dot(input.normal, lightDir));

    pointLightIntensity0 = saturate(dot(input.normal, input.lightPos0));
    pointLightColor0 = saturate(diffuseColor[0] * pointLightIntensity0);

    pointLightIntensity1 = saturate(dot(input.normal, input.lightPos1));
    pointLightColor1 = saturate(diffuseColor[1] * pointLightIntensity1);

    pointLightIntensity2 = saturate(dot(input.normal, input.lightPos2));
    pointLightColor2 = saturate(diffuseColor[2] * pointLightIntensity2);

    pointLightIntensity3 = saturate(dot(input.normal, input.lightPos3));
    pointLightColor3 = saturate(diffuseColor[3] * pointLightIntensity3);

    pointLightIntensity4 = saturate(dot(input.normal, input.lightPos4));
    pointLightColor4 = saturate(diffuseColor[4] * pointLightIntensity4);

    pointLightIntensity5 = saturate(dot(input.normal, input.lightPos5));
    pointLightColor5 = saturate(diffuseColor[5] * pointLightIntensity5);

    pointLightIntensity6 = saturate(dot(input.normal, input.lightPos6));
    pointLightColor6 = saturate(diffuseColor[6] * pointLightIntensity6);

    pointLightIntensity7 = saturate(dot(input.normal, input.lightPos7));
    pointLightColor7 = saturate(diffuseColor[7] * pointLightIntensity7);

    if (lightIntensity > 0.0f)
    {
        // Determine the final diffuse color based on the diffuse color and the amount of light intensity.
        color += (ddiffuseColor * lightIntensity);

        // Saturate the ambient and diffuse color.
        color = saturate(color);

        color = saturate(color + pointLightColor0);
        color = saturate(color + pointLightColor1);
        color = saturate(color + pointLightColor2);
        color = saturate(color + pointLightColor3);
        color = saturate(color + pointLightColor4);
        color = saturate(color + pointLightColor5);
        color = saturate(color + pointLightColor6);
        color = saturate(color + pointLightColor7);

        // Calculate the reflection vector based on the light intensity, normal vector, and light direction.
        reflection = normalize(2 * lightIntensity * input.normal - lightDir);

        // Determine the amount of specular light based on the reflection vector, viewing direction, and specular power.
        specular = specularColor * pow(saturate(dot(reflection, input.viewDirection)), specularPower);
        //specular = pow(saturate(dot(reflection, input.viewDirection)), specularPower);
    }

    // Multiply the texture pixel and the input color to get the textured result.
    color = color * textureColor;

    // Add the specular component last to the output color.
    color = saturate(color + specular);

    return color;
}