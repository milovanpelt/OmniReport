#include "pch.h"
#include "OmniReport.h"
#include <iostream>
#include <cpr/cpr.h>

OMNIREPORT_API void PrintTestMessage(char* url, char* message)
{
	std::cout << message << "\n";
	
	std::string json_payload = "{\"content\": \"" + std::string(message) + "\"}";

	cpr::Response r = cpr::Post(cpr::Url{ url },
		cpr::Body{ json_payload },
		cpr::Header{ {"Content-Type", "application/json"} });
	std::cout << r.text << std::endl;

	std::cout << json_payload << "\n";
}
