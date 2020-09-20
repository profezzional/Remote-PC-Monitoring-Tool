#include "Unit.hpp"

nlohmann::json Unit::toJson()
{
	nlohmann::json j;
	j["name"] = this->name;
	j["abbreviation"] = this->abbreviation;
	j["units"] = this->unitName;
	return j;
}

Unit* Unit::Get(enum UnitEnum unitEnum)
{
	const int index = static_cast<int>(unitEnum);
	if (index > Unit::g_Units.size())
	{
		return &Unit::g_Units.at(0);
	}
	return &Unit::g_Units.at(index);
}


std::vector<Unit> Unit::g_Units = {
	{ "percent", "%", "Percentage" },
	{ "storageGb", "GB", "Gigabytes" },
	{ "storageMb", "MB", "Megabytes" },
	{"temperature", "&#176", "Degrees"},
	{ "array", "?", "Array"}
};

