#ifndef __GRAWLOG_WRITERS_CONSOLE__H__
#define __GRAWLOG_WRITERS_CONSOLE__H__

#include "./Entry.hpp"
#include "./Writer.hpp"
#include <ostream>

namespace Grawlog::Writers
{
	class Stream : public Grawlog::Writer
	{
	public:
		Stream(std::ostream* output);
		~Stream();
		void Dispose();
		void Write( const Entry& entry, const std::string& message ) const;

	private:
		std::ostream* _output;
	};
}

#endif
