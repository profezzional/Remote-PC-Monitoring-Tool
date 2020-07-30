#pragma once
#include "Sensor.hpp"

class GPUUsageSensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "gpuUsage";
	}

	std::string_view getPrettyName() override
	{
		return "GPU Usage";
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
		return "Current utilization of the main GPU, as a percentage";
	}
};