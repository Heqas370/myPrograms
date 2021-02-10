#pragma once
#include <vector>
#include <mutex>
#include "Integrator.h"
class IntegratorPool
{
	std::vector<Integrator*> pool;
public:
	IntegratorPool(const size_t);
	virtual ~IntegratorPool();
	Integrator* GetInstance();
	size_t GetLoad();
};

