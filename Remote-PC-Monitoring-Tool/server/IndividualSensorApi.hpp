#pragma once
#include "ApiHandler.hpp"
#include "Sensor.hpp"
#include "SensorApi.hpp"

class IndividualSensorApiHandler : public ApiHandler
{
public:

	std::string_view getUrl() override
	{
		return "/getSensor";
	}

	void handler(const httplib::Request& request, httplib::Response& response) override
	{
		DEBUG_LOG(this->getUrl() << " Accessed from " << request.remote_addr);
		std::string sensorName = request.get_param_value("name");
		std::cout << "Name: " << sensorName << std::endl;
		for (Sensor* sensor : g_sensors)
		{
			if (sensor->getName() == sensorName) {
				nlohmann::json sensorData = sensor->getValue();
				sensorData["desc"] = sensor->getDesc();
				sensorData["name"] = sensor->getPrettyName();
				sensorData["unit"] = sensor->getUnit();
				response.set_content(sensorData.dump(4), "application/json");
				return;
			}
		}
	}
};

