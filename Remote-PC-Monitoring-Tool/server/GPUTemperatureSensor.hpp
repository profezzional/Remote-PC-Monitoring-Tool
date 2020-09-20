#pragma once
#include "GraphicsCard.hpp"
#include "Sensor.hpp"

class GPUTemperatureSensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "gpuTemp";
	}

	std::string_view getPrettyName() override
	{
		return "GPU Temperature";
	}

	UnitEnum getUnit() override
	{
		return UnitEnum::Temperature;
	}

	nlohmann::json getValue() override
	{
		nlohmann::json j;


		static GraphicsCard* pGpu = GraphicsCard::GetGraphicsCard();
		int deviceCount = pGpu->GetDeviceCount();
		// todo: Add multi-GPU support
		
		j["value"] = deviceCount > 0 ? pGpu->GetDeviceTemp(0) : -1;
		j["success"] = true;
		return j;
	}

	std::string_view getDesc() override
	{
		return "Returns the current GPU temperature in C";
	}
};