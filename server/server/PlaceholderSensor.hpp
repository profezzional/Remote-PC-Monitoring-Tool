#pragma once
#include "Sensor.hpp"

// copy/paste this class for new sensors
// then, in SensorApi.cpp, include your new file, and add an instance of your sensor to g_sensors

class PlaceholderSensor : public Sensor
{
public:
	std::string getName() override
	{
		return "Placeholder Sensor";
	}

	std::string getValue() override
	{
		// placeholder
		DEBUG_LOG("sensor executed");
		return "It's just a placeholder, go away";
	}

	std::string getDesc() override
	{
		return "Doesn't actually do anything...";
	}
};