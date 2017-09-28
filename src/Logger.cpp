#include "./Logger.hpp"

namespace Grawlog
{
	Logger::Logger( const Severity& severity, const std::string& file, const std::string& function, const int line )
		: std::stringstream()
		, _manager(ManagerImpl::Instance())
		, _entry(std::make_unique<Entry>(std::time(nullptr), severity, file, function, line))
	{
	}
	
	Logger::~Logger()
	{
		WriteLog();
		Dispose();
	}

	void Logger::Dispose()
	{
	}

	void Logger::WriteLog() const
	{
		_manager->Log(*_entry, str());
	}
}
