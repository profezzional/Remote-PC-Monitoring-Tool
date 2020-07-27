#include "ApiHandler.hpp"

#include "SensorApi.hpp"

std::vector<ApiHandler*> g_apiHandlers = {
	new SensorApiHandler(),
};