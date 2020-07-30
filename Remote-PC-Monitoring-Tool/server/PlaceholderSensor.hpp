#pragma once
#include "Sensor.hpp"

// copy/paste this class for new sensors
// then, in SensorApi.cpp, include your new file, and add an instance of your sensor to g_sensors

class PlaceholderSensor : public Sensor
{
public:
	std::string getName() override
	{
		return "placeholder";
	}

	std::string getPrettyName() override
	{
		return "Placeholder Sensor";
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
		return "Doesn't actually do anything...";
	}
};