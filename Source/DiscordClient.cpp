#include "DiscordClient.h"
#include <cpr/cpr.h>

DiscordClient::DiscordClient(std::string webhook_url)
{
	webhook_ = webhook_url;
}

bool DiscordClient::SendMessage(char* message)
{
	if (!webhook_.empty())
	{
		std::string json_payload = "{\"content\": \"" + std::string(message) + "\"}";

		cpr::Response r = cpr::Post(cpr::Url{ webhook_ },
			cpr::Body{ json_payload },
			cpr::Header{ {"Content-Type", "application/json"} });

		return true;
	}

	return false;
}
