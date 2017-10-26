#include "./ManagerImpl.hpp"
#include "./Writers/Stream.hpp"
#include <iostream>

namespace Grawlog
{
	Manager* ManagerImpl::Instance()
	{
		static ManagerImpl instance;

		if (!instance._loaded)
		{
			// TODO: add config loading here
			auto writer = new Writers::Stream(&std::cout);
			instance._writers.push_back(writer);
			instance._loaded = true;
		}

		return &instance;
	}

	ManagerImpl::ManagerImpl()
		: _loaded(false)
		, _writers(WriterList())
	{
	}
	
	ManagerImpl::~ManagerImpl()
	{
		Dispose();
	}
		
	void ManagerImpl::Dispose()
	{
	}

	void ManagerImpl::Log( const Entry& entry, const std::string& message ) const
	{
		std::for_each(_writers.begin(), _writers.end(), [entry, message]( const auto& writer )
		{
			writer->Write(entry, message);
		});
	}
}
