#pragma once
#include "ApiHandler.hpp"

class Sensor
{
public:
	virtual std::string getName() = NULL;
	virtual std::string getValue() = NULL;
	virtual std::string getDesc() = NULL;
};