#include "target.hpp"
#include "httplib.h"
#include "json.hpp"
#include "ApiHandler.hpp"
#include "UDPServer.hpp"

#include <thread>
#include <iostream>


int main(int argc, char** argv)
{
    httplib::Server svr;

    for (ApiHandler* pApi : g_apiHandlers)
    {
        DEBUG_LOG("API: " << pApi->getUrl());
        svr.Get(pApi->getUrl().data(), [pApi](const httplib::Request& request, httplib::Response& response)
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



    UDPServer::listen(42069, [](std::string_view message)-> std::string_view
    {
        DEBUG_LOG("Message recieved: " << message);
    	if (message == "discover")
    	{
            return "found";
    	}
        return "incorrect request";
    });

	
    svr.listen("0.0.0.0", 1234);
	std::cout << "done" << std::endl;
	std::cin.get();
	return 0;
}
