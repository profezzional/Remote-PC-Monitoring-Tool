#pragma once
#include "Sensor.hpp"

class CPUTemperatureSensor : public Sensor
{
public:
	std::string getName() override
	{
		return "cpuTemp";
	}

	std::string getPrettyName() override
	{
		return "CPU Temperature";
	}

	UnitEnum getUnit() override
	{
		return UnitEnum::Temperature;
	}

	nlohmann::json getValue() override
	{
		nlohmann::json j;
		j["value"] = 69.69;
		j["success"] = true;
		return j;
	}

	std::string getDesc() override
	{
		return "Returns the current CPU temperature in C";
	}
};