#pragma once
#include"IThread.h"
class Integrator :public IThread
{
public:
	enum Status 
	{
		IDLE,
		WORKING,
	};
private:
	vector<double> data;
	Status status;
	double step;
	double result;
	mutex dataMutex;
	mutex statusMutex;
	mutex resultMutex;
	void setStatus(Status);
	virtual void ThreadRoutine() override;
public:
	Integrator();
	void Count(const vector<double>&, const double);
	Status GetStatus(); 
	double GetResult();
};

