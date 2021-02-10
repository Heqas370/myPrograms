#include "Integrator.h"

void Integrator::setStatus(Integrator::Status stat)
{
	statusMutex.lock();
	status = stat;
	statusMutex.unlock();
}

void Integrator::ThreadRoutine()//mozna blokowac mutex przy kopiach ale trzeba uzyc petli lub mozna dla calej operacji bez uzywania petli
{
	while (isRunning()) {

		if (GetStatus()==Integrator::Status::WORKING) {
			double integral=0;
			
			dataMutex.lock();
			vector<double> dataCopy; 
			double stepCopy = step;
			for (size_t i = 0; i < dataCopy.size(); i++)
				dataCopy.push_back(data[i]);
			dataMutex.unlock();
			for (vector<double>::const_iterator i = dataCopy.begin(); i != dataCopy.end(); i++) {
				integral += *i * stepCopy;
			}
			resultMutex.lock();
			result = integral;
			resultMutex.unlock();
			setStatus(Integrator::Status::IDLE);
		}
		std::this_thread::yield();
	}
}

Integrator::Integrator() :status(Integrator::Status::IDLE),step(0)
{
}

void Integrator::Count(const vector<double>& data, const double step)
{
		while (GetStatus() == Integrator::Status::WORKING);
		dataMutex.lock();
		this->data=data;
		this->step=step;
		dataMutex.unlock();
		setStatus(Integrator::Status::WORKING);
}

Integrator::Status Integrator::GetStatus()
{
	statusMutex.lock();
	Integrator::Status stat = status;
	statusMutex.unlock();
	return stat;
}

double Integrator::GetResult()
{
	resultMutex.lock();
	double res = result;
	resultMutex.unlock();
	return res;
}
