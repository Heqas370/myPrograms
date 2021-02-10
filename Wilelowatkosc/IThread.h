#pragma once
#include <thread>
#include<mutex>
#include<vector>
using namespace std;
class IThread
{
private:
	std::thread* thr;
protected:
	enum Status
	{
		STOPPED,
		RUNNING
	};
	Status status;
public:
	IThread();
	virtual ~IThread();
	void Start();
	void Stop();
	void Join();
	bool isRunning();
	virtual void ThreadRoutine() = 0;
};

