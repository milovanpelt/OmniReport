#include "pch.h"
#include "OmniReport.h"
#include <iostream>
#include <cpr/cpr.h>
#include "DiscordClient.h"

OMNIREPORT_API void PrintTestMessage(char* message)
{
	DiscordClient testBot("");
	testBot.SendMessage(message);
}
