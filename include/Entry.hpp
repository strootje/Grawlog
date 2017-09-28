#ifndef __GRAWLOG_ENTRY__H__
#define __GRAWLOG_ENTRY__H__

#include "./Severity.hpp"
#include <ctime>
#include <string>

namespace Grawlog
{
	class Entry
	{
	public:
		Entry( const std::time_t& time, const Severity& severity, const std::string& file, const std::string& function, const int line );
		virtual ~Entry();

	public:
		const std::time_t _time;
		const Severity _severity;
		const std::string _file;
		const std::string _function;
		const int _line;
	};
}

#endif
