#pragma once
#include "target.hpp"
#include <functional>
#include <thread>
#include <string_view>


class UDPServer
{
public:
	static void listen(int port, std::function<std::string_view(std::string_view message)> callback);
};
