#pragma once

#ifdef OMNIREPORT_EXPORTS
	#define OMNIREPORT_API __declspec(dllexport)
#else
	#define OMNIREPORT_API __declspec(dllimport)
#endif // OMNIREPORT_EXPORTS

EXTERN_C OMNIREPORT_API void PrintTestMessage(char* message);