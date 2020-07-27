#pragma once
#include "ApiHandler.hpp"
#include "Sensor.hpp"

extern std::vector<Sensor*> g_sensors;

class SensorApiHandler : public ApiHandler
{
public:
	
	std::string getUrl() override
	{
		return "/sensors";
	}

	void handler(const httplib::Request& request, httplib::Response& response) override
	{
		nlohmann::json j;
		for(Sensor* sensor : g_sensors)
		{
			j[sensor->getName()] = sensor->getValue();
		}
		response.set_content(j.dump(4), "application/json");
	}
};


