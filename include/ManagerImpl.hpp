#ifndef __GRAWLOG_MANAGERIMPL__H__
#define __GRAWLOG_MANAGERIMPL__H__

#include "./Entry.hpp"
#include "./Manager.hpp"
#include "./Writer.hpp"
#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <memory>

namespace Grawlog
{
	class ManagerImpl : public Manager
	{
	private:
		typedef std::map<std::string, Factory> FactoryMap;
		typedef std::list<std::shared_ptr<const Writer>> WriterList;

	public:
		static Manager* Instance();
		ManagerImpl();
		~ManagerImpl();
		void Dispose();

	public:
		void Register( const std::string& name, Factory factory );
		void Log( const Entry& entry, const std::string& message ) const;

	private:
		FactoryMap _factories;
		WriterList _writers;
	};
}

#endif
