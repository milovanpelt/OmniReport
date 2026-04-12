#include "pch.h"
#include "OmniReport.h"
#include <iostream>

OMNIREPORT_API void PrintTestMessage(char* message)
{
	std::cout << message << "\n";
}
