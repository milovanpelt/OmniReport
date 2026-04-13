#pragma once

#include <string>
#include <Windows.h>
#undef SendMessage

class DiscordClient
{
public:
	DiscordClient(std::string webhook_url);

	bool SendMessage(char* message);
private:
	std::string webhook_;
};