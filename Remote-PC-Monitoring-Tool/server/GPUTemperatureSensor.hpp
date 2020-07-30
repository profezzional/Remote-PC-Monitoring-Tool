#pragma once
#include "Sensor.hpp"

class GPUTemperatureSensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "gpuTemp";
	}

	std::string_view getPrettyName() override
	{
		return "GPU Temperature";
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

	std::string_view getDesc() override
	{
		return "Returns the current GPU temperature in C";
	}
};