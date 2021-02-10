#pragma once
#include"IThread.h"
#include"Producer.h"
class Consumer:public IThread
{
private:
	mutex collectionMutex;
	double average;
	Producer* producer;
	vector<double> data;
public:
	Consumer(Producer *producer);
	virtual void ThreadRoutine()override;
	double GetAverage();
}; 

