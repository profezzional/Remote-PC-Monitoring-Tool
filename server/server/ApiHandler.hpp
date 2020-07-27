#pragma once
#include "target.hpp"
#include "httplib.h"
#include "json.hpp"

#include <string>
#include <vector>

class ApiHandler
{
public:
	virtual std::string getUrl() = NULL;
	virtual void handler(const httplib::Request& request, httplib::Response& response) = NULL;
};

extern std::vector<ApiHandler*> g_apiHandlers;