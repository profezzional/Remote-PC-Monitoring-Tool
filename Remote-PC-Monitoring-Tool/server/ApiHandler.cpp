#include "ApiHandler.hpp"

#include "SensorApi.hpp"
#include "IndividualSensorApi.hpp"
#include "SensorListApi.hpp"

std::vector<ApiHandler*> g_apiHandlers = {
	new SensorApiHandler(),
	new IndividualSensorApiHandler(),
	new SensorListApiHandler(),
};