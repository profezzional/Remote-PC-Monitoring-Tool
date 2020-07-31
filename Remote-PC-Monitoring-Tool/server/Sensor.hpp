#pragma once
#include "ApiHandler.hpp"
#include "Unit.hpp"

class Sensor
{
public:
	virtual std::string_view getName() = 0;
	virtual std::string_view getPrettyName() = 0;
	virtual std::string_view getDesc() = 0;
	virtual UnitEnum getUnit() = 0;
	virtual nlohmann::json getValue() = 0;
};