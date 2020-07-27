#include "SensorApi.hpp"

// include your sensors here
#include "PlaceholderSensor.hpp"
#include "CPUUsageSensor.hpp"
#include "MemoryUtilizationSensor.hpp"


// then add them to the vector
std::vector<Sensor*> g_sensors = {
	new PlaceholderSensor(),
	new CPUUsageSensor(),
	new MemoryUtilizationSensor(),
};