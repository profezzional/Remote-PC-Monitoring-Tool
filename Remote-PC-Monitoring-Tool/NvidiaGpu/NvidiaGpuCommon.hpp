#pragma once

struct MemoryInfo
{
	unsigned long long total;
	unsigned long long free;
	unsigned long long used;

	float GetPercentUsed()
	{
		return static_cast<float>(
			static_cast<double>(this->used) / 
			static_cast<double>(this->total)
			);
	}
};