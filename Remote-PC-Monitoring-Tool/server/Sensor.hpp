#pragma once
#include "ApiHandler.hpp"

class Sensor
{
public:
	virtual std::string getName() = 0;
	virtual std::string getValue() = 0;
	virtual std::string getDesc() = 0;
};