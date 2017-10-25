#ifndef __GRAWLOG_MANAGERIMPL__H__
#define __GRAWLOG_MANAGERIMPL__H__

#include "./Entry.hpp"
#include "./Manager.hpp"
#include "./Writer.hpp"
#include <algorithm>
#include <list>
#include <memory>

namespace Grawlog
{
	class ManagerImpl : public Manager
	{
	private:
		typedef std::list<Writer*> WriterList;

	public:
		static Manager* Instance();
		ManagerImpl();
		~ManagerImpl();
		void Dispose();

	public:
		void Log( const Entry& entry, const std::string& message ) const;

	private:
		bool _loaded;
		WriterList _writers;
	};
}

#endif
