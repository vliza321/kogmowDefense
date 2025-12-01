#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <vector>
#include <queue>
#include <concurrent_queue.h>

#include <mutex>
#include <thread>

#include <functional>


using namespace std;

class ThreadPool
{
private:
	vector<thread> m_workers;
	queue<function<void()>> m_jobs;

	mutex m_queueMutex;
	condition_variable m_condition;

	atomic<bool> _running;

public:
	ThreadPool(unsigned int threadCount)
	{
		_running.store(true);

		for (size_t i = 0; i < threadCount; ++i)
		{
			m_workers.emplace_back([this]() { WorkerLoop(); });
		}
	}

	virtual ~ThreadPool()
	{
		{
			std::unique_lock<std::mutex> lock(m_queueMutex);
			_running = false;
		}
		m_condition.notify_all();
		for (auto& worker : m_workers)
			worker.join();
	}

	template<typename F>
	void Enqueue(F&& f)
	{
		std::function<void()> job = std::forward<F>(f);
		{
			unique_lock<mutex> lock(m_queueMutex);
			m_jobs.push(std::move(job));
		}
		m_condition.notify_one();
	}
private:
	void WorkerLoop()
	{
		while (true)
		{
			function<void()> job;

			{ // 락 시작
				unique_lock<mutex> lock(m_queueMutex);
				m_condition.wait(lock, [this]() {
					return !_running || !m_jobs.empty(); 
					});

				if (!_running && m_jobs.empty()) 
					return;

				job = move(m_jobs.front());
				m_jobs.pop();// 큐에서 꺼냄
			} // 락 해제 

			job(); // 실제 작업 실행
		}
	}
};

#endif