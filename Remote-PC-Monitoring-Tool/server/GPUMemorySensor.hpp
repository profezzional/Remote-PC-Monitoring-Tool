#pragma once
#include "Sensor.hpp"
#include "GraphicsCard.hpp"

class GPUMemorySensor : public Sensor
{
public:
	std::string_view getName() override
	{
		return "gpuMem";
	}

	std::string_view getPrettyName() override
	{
		return "GPU Memory Usage";
	}

	UnitEnum getUnit() override
	{
		// todo: Fix units to support arrays
		return UnitEnum::Array;
	}

	nlohmann::json getValue() override
	{
		nlohmann::json j;
		nlohmann::json value;

		static GraphicsCard* pGpu = GraphicsCard::GetGraphicsCard();
		// todo: Add multi-gpu support
		MemoryInfo memInfo = pGpu->GetMemoryInfo(0);
		
		value["total"] = memInfo.total;
		value["free"] = memInfo.free;
		value["used"] = memInfo.used;
		value["perc"] = memInfo.GetPercentUsed();
		
		j["value"] = value;
		j["success"] = true;
		return j;
	}

	std::string_view getDesc() override
	{
		return "Gets GPU memory usage information";
	}
};