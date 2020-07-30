#pragma once
#include "Sensor.hpp"

class CPUUsageSensor : public Sensor
{
public:
	std::string getName() override
	{
		return "cpuUsage";
	}

	std::string getPrettyName() override
	{
		return "CPU Usage";
	}
	
	UnitEnum getUnit() override
	{
		return UnitEnum::Percentage;
	}

	nlohmann::json getValue() override
	{
		nlohmann::json j;
		j["value"] = 0.125;
		j["success"] = true;
		return j;
	}
	
	std::string getDesc() override
	{
		return "Current utilization of the CPU, as a percentage";
	}
};