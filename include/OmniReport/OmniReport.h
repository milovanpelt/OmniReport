#pragma once

#ifdef OMNIREPORT_EXPORTS
#define OMNIREPORT_API __decspec(dllexport)
#else
#define OMNIREPORT_API __decspec(dllimport)
#endif // OMNIREPORT_EXPORTS

namespace OmniReport 
{
}
