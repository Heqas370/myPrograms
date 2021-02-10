#pragma once
#include"IThread.h"
#include<vector>
#include<iostream>
#include<mutex>
class Producer:public IThread
{
	std::mutex collectionMutex;
	std::vector<double> collectionSync;
public:
	virtual void ThreadRoutine() override;
	vector<double> GetCollection();
};
 
