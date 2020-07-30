#pragma once
#include "Sensor.hpp"


class MemoryUtilizationSensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "memUtili";
	}

	std::string_view getPrettyName() override
	{
		return "Memory Utilization";
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
		return "Shows the current memory utilization";
	}
};