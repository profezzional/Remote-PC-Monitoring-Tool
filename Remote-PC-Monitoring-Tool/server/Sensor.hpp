#pragma once
#include "ApiHandler.hpp"
#include "Unit.hpp"

class Sensor
{
public:
	virtual std::string getName() = 0;
	virtual std::string getPrettyName() = 0;
	virtual std::string getDesc() = 0;
	virtual UnitEnum getUnit() = 0;
	virtual nlohmann::json getValue() = 0;
};