#pragma once
#include "ApiHandler.hpp"
#include "Sensor.hpp"

extern std::vector<Sensor*> g_sensors;

class SensorApiHandler : public ApiHandler
{
public:
	
	std::string_view getUrl() override
	{
		return "/sensorValues";
	}

	void handler(const httplib::Request& request, httplib::Response& response) override
	{
		DEBUG_LOG(this->getUrl() << " Accessed from " << request.remote_addr);
		nlohmann::json sensorArray;
		for(Sensor* sensor : g_sensors)
		{
			sensorArray[sensor->getName().data()] = sensor->getValue();
		}
	

#ifdef _DEBUG
		response.set_content(sensorArray.dump(4), "application/json");
#else
		response.set_content(sensorArray.dump(), "application/json");
#endif
	}
};


