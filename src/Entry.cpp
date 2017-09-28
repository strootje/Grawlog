#include "./Entry.hpp"

namespace Grawlog
{
	Entry::Entry( const std::time_t& time, const Severity& severity, const std::string& file, const std::string& function, const int line )
		: _time(time)
		, _severity(severity)
		, _file(file)
		, _function(function)
		, _line(line)
	{
	}

	Entry::~Entry()
	{
	}
}
