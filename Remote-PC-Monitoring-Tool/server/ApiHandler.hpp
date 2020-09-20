#pragma once
#include "target.hpp"
#include "httplib.h"
#include "json.hpp"

#include <string>
#include <string_view>
#include <vector>

class ApiHandler
{
public:
	virtual ~ApiHandler() = default;
	virtual std::string_view getUrl() = 0;
	virtual void handler(const httplib::Request& request, httplib::Response& response) = 0;
};

extern std::vector<ApiHandler*> g_apiHandlers;