#include "OmniReport.h"
#include "pch.h"
#include "OmniReport.h"
#include <iostream>
#include <cpr/cpr.h>
#include "DiscordClient.h"

static std::map<std::string, std::string> Webhooks;

OMNIREPORT_API bool OmniReport::LinkCategoryToWebhook(const char* category, const char* webhook)
{
	auto [foundCategory, succes] = Webhooks.insert({ category, webhook });

	if (!succes)
	{
		throw std::invalid_argument(
			std::string("[OmniReport]: Category'") + category + "' is already linked to a webhook"
		);
	}

	return true;
}

OMNIREPORT_API bool OmniReport::SendMessageToCategory(const char* category, const char* message)
{
	auto it = Webhooks.find(category);

	if (it != Webhooks.end())
	{
		std::string json_payload = "{\"content\": \"" + std::string(message) + "\"}";

		cpr::Response r = cpr::Post(cpr::Url{ it->second },
			cpr::Body{ json_payload },
			cpr::Header{ {"Content-Type", "application/json"} });

		return true;
	}

	throw std::invalid_argument(
		std::string("[OmniReport]: Category'") + category + "' does not exist"
	);
}
