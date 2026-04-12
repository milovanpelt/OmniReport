#pragma once

#ifdef OMNIREPORT_EXPORTS
	#define OMNIREPORT_API __declspec(dllexport)
#else
	#define OMNIREPORT_API __declspec(dllimport)
#endif // OMNIREPORT_EXPORTS

extern "C" OMNIREPORT_API void PrintTestMessage(char* url, char* message);