#pragma once
#include "Sensor.hpp"

class CPUUsageSensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "cpuUsage";
	}

	std::string_view getPrettyName() override
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
	
	std::string_view getDesc() override
	{
		return "Current utilization of the CPU, as a percentage";
	}
};