#include "Consumer.h"

Consumer::Consumer(Producer *producer): producer(producer)
{
	
}

void Consumer::ThreadRoutine()
{
	
	data=producer->GetCollection();
	while (isRunning())
	{
		double sum = 0;
		if (data.size() != 0) {
			
			for (vector<double>::const_iterator i = data.begin(); i != data.end(); i++) {
				sum += *i;
			}
			collectionMutex.lock();
			 average= double(sum / data.size());
			collectionMutex.unlock();
		}
		
		this_thread::sleep_for(chrono::milliseconds(100));
	}


}

double Consumer::GetAverage()
{
	collectionMutex.lock();
	double value = average;
	collectionMutex.unlock();
	return value;
}
