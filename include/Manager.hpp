#ifndef __GRAWLOG_MANAGER__H__
#define __GRAWLOG_MANAGER__H__

#include "./Entry.hpp"
#include "./Writer.hpp"
#include <functional>
#include <string>

namespace Grawlog
{
	class Manager
	{
	protected:
		typedef std::function<const Writer*()> Factory;

	public:
		virtual void Register( const std::string& name, Factory factory ) = 0;
		virtual void Log( const Entry& entry, const std::string& message ) const = 0;
	};
}

#endif
