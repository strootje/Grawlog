#ifndef __GRAWLOG_WRITER__H__
#define __GRAWLOG_WRITER__H__

#include "./Entry.hpp"
#include <string>

namespace Grawlog
{
	class Writer
	{
	public:
		virtual void Write( const Entry& entry, const std::string& message ) const = 0;
	};
}

#endif
