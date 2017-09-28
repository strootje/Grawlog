#include "./ManagerImpl.hpp"
#include <iostream>

namespace Grawlog
{
	Manager* ManagerImpl::Instance()
	{
		static ManagerImpl instance;
		return &instance;
	}

	ManagerImpl::ManagerImpl()
		: _factories(FactoryMap())
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
	
	void ManagerImpl::Register( const std::string& name, Factory factory )
	{
		_factories.insert({ name, factory });
	}

	void ManagerImpl::Log( const Entry& entry, const std::string& message ) const
	{
		std::cout
			<< "[" << entry._time << "]"
			<< "[" << (int)entry._severity << "]";

		switch(entry._severity)
		{
			case Severity::Diagnostic:
			std::cout << " " << entry._function;
				break;

			default:
			std::cout << " " << message;
				break;
		}

		std::cout << std::endl;

		std::for_each(_writers.begin(), _writers.end(), [entry, message]( const auto& writer )
		{
			writer->Write(entry, message);
		});
	}
}
