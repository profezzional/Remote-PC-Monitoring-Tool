#pragma once
#include "Sensor.hpp"

class CPUUsageSensor : public Sensor
{
public:
	std::string getName() override
	{
		return "CPU Usage";
	}
	
	std::string getValue() override
	{
		// placeholder
		return std::to_string(.50f);
	}
	
	std::string getDesc() override
	{
		return "Current utilization of the CPU";
	}
};