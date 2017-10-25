#ifndef __GRAWLOG_MANAGER__H__
#define __GRAWLOG_MANAGER__H__

#include "./Entry.hpp"
#include <string>

namespace Grawlog
{
	class Manager
	{
	public:
		virtual void Log( const Entry& entry, const std::string& message ) const = 0;
	};
}

#endif
