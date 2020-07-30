#pragma once
#include "Sensor.hpp"

class CPUTemperatureSensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "cpuTemp";
	}

	std::string_view getPrettyName() override
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

	std::string_view getDesc() override
	{
		return "Returns the current CPU temperature in C";
	}
};