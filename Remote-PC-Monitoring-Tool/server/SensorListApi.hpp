#pragma once
#include "ApiHandler.hpp"
#include "Sensor.hpp"

class SensorListApiHandler : public ApiHandler
{
public:

	std::string_view getUrl() override
	{
		return "/sensorInfo";
	}

	void handler(const httplib::Request& request, httplib::Response& response) override
	{
		DEBUG_LOG(this->getUrl() << " Accessed from " << request.remote_addr);
		nlohmann::json sensorArray;
		for (Sensor* sensor : g_sensors)
		{
			nlohmann::json sensorData;
			sensorData["desc"] = sensor->getDesc();
			sensorData["name"] = sensor->getPrettyName();
			sensorData["unit"] = sensor->getUnit();
			sensorArray[sensor->getName().data()] = sensorData;
		}
		nlohmann::json unitArray;
		for (Unit& unit : Unit::g_Units)
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
