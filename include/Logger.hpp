#ifndef __GRAWLOG_LOGGER__H__
#define __GRAWLOG_LOGGER__H__

#include "./Entry.hpp"
#include "./ManagerImpl.hpp"
#include "./Severity.hpp"
#include <ctime>
#include <memory>
#include <sstream>
#include <string>

#ifndef __DEBUG__
	#define __DEBUG__ false
#else
	#undef __DEBUG__
	#define __DEBUG__ true
#endif

#define GRAWLOG(SEVERITY) Grawlog::Logger(SEVERITY, __FILE__, __FUNCTION__, __LINE__)
// #define DGRAWLOG(SEVERITY) if(!__DEBUG__); else GRAWLOG(SEVERITY)
#define DGRAWLOG(SEVERITY) GRAWLOG(SEVERITY)

#ifndef __EXPLICIT__
	#define LOG(SEVERITY) GRAWLOG(SEVERITY)
	#define DLOG(SEVERITY) DGRAWLOG(SEVERITY)
#endif

namespace Grawlog
{
	class Logger : public std::stringstream
	{
	public:
		Logger( const Severity& severity, const std::string& file, const std::string& function, const int line );
		~Logger();
		void Dispose();

	private:
		Manager* _manager;
		std::unique_ptr<Entry> _entry;

	private:
		void WriteLog() const;
	};
}

#endif
