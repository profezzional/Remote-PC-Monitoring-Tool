#include "target.hpp"
#include "httplib.h"
#include "json.hpp"
#include "ApiHandler.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    httplib::Server svr;

    for (ApiHandler* pApi : g_apiHandlers)
    {
        svr.Get(pApi->getUrl().data(), [&pApi](const httplib::Request& request, httplib::Response& response)
        {
            pApi->handler(request, response);
        });
    }
	
    svr.Get("/", [](const httplib::Request& req, httplib::Response& res)
    {
        nlohmann::json j;
        for(ApiHandler* pApi : g_apiHandlers)
        {
            j["apis"].push_back(pApi->getUrl());
        }
        res.set_content(j.dump(4), "application/json");
    });
	
    svr.listen("0.0.0.0", 1234);

	std::cout << "done" << std::endl;
	std::cin.get();
	return 0;
}
