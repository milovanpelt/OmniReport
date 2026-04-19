#pragma once

#ifdef OMNIREPORT_EXPORTS
	#define OMNIREPORT_API __declspec(dllexport)
#else
	#define OMNIREPORT_API __declspec(dllimport)
#endif // OMNIREPORT_EXPORTS

namespace OmniReport
{
	extern "C"
	{
		OMNIREPORT_API bool LinkCategoryToWebhook(const char* category, const char* webhook);
		OMNIREPORT_API bool SendMessageToCategory(const char* category, const char* message);
	}
}

