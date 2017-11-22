#include "./Writers/Stream.hpp"

namespace Grawlog { namespace Writers
{
	Stream::Stream( std::ostream* output )
		: _output(output)
	{
	}

	Stream::~Stream()
	{
		Dispose();
	}

	void Stream::Dispose()
	{
		delete _output;
	}

	void Stream::Write( const Entry& entry, const std::string& message ) const
	{
		(*_output)
			<< "[" << entry._time << "]"
			<< "[" << (int)entry._severity << "]";

		switch(entry._severity)
		{
			case Severity::Diagnostic:
				(*_output) << " " << entry._function;
				break;

			default:
				(*_output) << " " << message;
				break;
		}

		(*_output) << std::endl;
	}
}}
