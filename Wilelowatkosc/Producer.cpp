#include "Producer.h"
#include<chrono>
#include<random>

void Producer::ThreadRoutine()
{
	while (isRunning()) 
	{
		double number = (double)rand() / RAND_MAX;
		collectionMutex.lock();
		collectionSync.push_back(number);
		collectionMutex.unlock();
		//std::this_thread::yield();
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	//int counter = 0;
	//mutex m;
	//thread thr;
	//if (thr.joinable()) {
	//	for (int i = 0; i < 100; i++)
	//	{
	//		double number = rand() % 100 / 100.f;
	//		m.lock();
	//		collection[i] = number;
	//m.unlock();
	//this_thread::sleep_for(chrono::milliseconds(100));
	//	}
	//}
	//
	 
}

std::vector<double> Producer::GetCollection()
{
	collectionMutex.lock();
	vector<double> data = collectionSync;
	collectionMutex.unlock();
	return data;
}
