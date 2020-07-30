#pragma once
#include "ApiHandler.hpp"
#include "Sensor.hpp"

extern std::vector<Sensor*> g_sensors;

class SensorApiHandler : public ApiHandler
{
public:
	
	std::string_view getUrl() override
	{
		return "/sensors";
	}

	void handler(const httplib::Request& request, httplib::Response& response) override
	{
		nlohmann::json sensorArray;
		for(Sensor* sensor : g_sensors)
		{
			nlohmann::json sensorData = sensor->getValue();
			sensorData["desc"] = sensor->getDesc();
			sensorData["name"] = sensor->getPrettyName();
			sensorData["unit"] = sensor->getUnit();
			sensorArray[sensor->getName().data()] = sensorData;
		}
		nlohmann::json unitArray;
		for(Unit& unit : Unit::g_Units)
		{
			unitArray.push_back(unit.toJson());
		}
		nlohmann::json outputArray;
		outputArray["sensors"] = sensorArray;
		outputArray["units"] = unitArray;

#ifdef _DEBUG
		response.set_content(outputArray.dump(4), "application/json");
#else
		response.set_content(outputArray.dump(), "application/json");
#endif
	}
};


