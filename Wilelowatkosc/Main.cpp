#pragma once
using namespace std;
#include "IThread.h"
#include"IntegratorPool.h"
#include"Integrator.h"
#include<thread>
#include "Producer.h"
#include"Consumer.h"
#include<iostream>
#include<conio.h>
int main() {
	//create dataset
	double dt = 0.1;
	std::vector<double> dataSet;
	for (size_t i = 0; i < 1000; i++)
	{
		dataSet.push_back(sin(i * dt) + 1);
		//dataSet.push_back(i);
	}

	//creating threads when needed (conventional way)
	{
		Integrator* integrators[100];
		auto tstart = std::chrono::high_resolution_clock::now();
		//create and start 100 threads
		for (size_t i = 0; i < 100; i++)
		{
			integrators[i] = new Integrator();
			integrators[i]->Start();
			integrators[i]->Count(dataSet, dt);
		}
		//wait until threads are done
		for (size_t i = 0; i < 100; i++)
		{
			while (integrators[i]->GetStatus() == Integrator::Status::WORKING);
			integrators[i]->Stop();
			delete integrators[i];
		}
		auto tstop = std::chrono::high_resolution_clock::now();
		std::cout << "Brak puli: " << std::chrono::duration_cast<std::chrono::microseconds>(tstop - tstart).count() << "us\n";

	}

	//pool
	{
		//create integrator pool with 10 workers
		auto threadPool = new IntegratorPool(8);
		auto tstart = std::chrono::high_resolution_clock::now();
		//perform count 100 times
		for (size_t i = 0; i < 100; i++)
		{
			Integrator* integrator;
			//blocking wait until any integrator is free
			while ((integrator = threadPool->GetInstance()) == nullptr);
			integrator->Count(dataSet, dt);
		}
		//wait until all threads are done
		while (threadPool->GetLoad() > 0);
		auto tstop = std::chrono::high_resolution_clock::now();
		std::cout << "Pula obiektow: " << std::chrono::duration_cast<std::chrono::microseconds>(tstop - tstart).count() << "us\n";
		delete threadPool;
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;
	char key;
	std::vector<double> v;

	auto p1 = new Producer();
	p1->Start();
	auto c1 = new Consumer(p1);
	c1->Start();
	auto c2 = new Consumer(p1);
	c2->Start();
	auto c3 = new Consumer(p1);
	c3->Start();
	auto c4 = new Consumer(p1);
	c4->Start();
	while (true)
	{
		if(_kbhit())
		{
			cout << "Podaj klawisz" << endl;
			key = _getch();
			if (key == 13)
			{
				std::cout << "Srednia consumer 1: " << c1->GetAverage() << std::endl;
				std::cout << "Srednia consumer 2: " << c2->GetAverage() << std::endl;
				std::cout << "Srednia consumer 3: " << c3->GetAverage() << std::endl;
				std::cout << "Srednia consumer 4: " << c4->GetAverage() << std::endl;
			}
			if (key == 27)
			{
				p1->Stop();
				c1->Stop();
				c2->Stop();
				c3->Stop();
				c4->Stop();
				std::cout << "Stop" << std::endl;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
//Wyniki:
// W puli  1000000 10,57839 [s], Pula obiektów 1,28594 [s] -dla 10 obiektów w puli;
//W puli 1000 obiektów czas 269851 mikro sek,w puli 8 obiektów czas 1747 mikro sek;
