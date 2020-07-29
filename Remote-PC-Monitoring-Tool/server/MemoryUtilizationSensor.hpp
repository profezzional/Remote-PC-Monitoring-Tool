#pragma once
#include "Sensor.hpp"


class MemoryUtilizationSensor : public Sensor
{
public:
	std::string getName() override
	{
		return "Memory Utilization";
	}

	std::string getValue() override
	{
		// placeholder
		return std::to_string(.25f);
	}

	std::string getDesc() override
	{
		return "Shows the current memory utilization";
	}
};