#pragma once
#include <string>
#include <vector>
#include "json.hpp"

enum class UnitEnum
{
	Percentage = 0,
	StorageGb = 1,
	StorageMb = 2,
	Temperature = 3
};

class Unit
{
public:
	std::string name;
	std::string abbreviation;
	std::string unitName;

	static Unit* Get(enum class UnitEnum);
	
	nlohmann::json toJson();
	static std::vector<Unit> g_Units;
};

