#ifndef __GRAWLOG_WRITER__H__
#define __GRAWLOG_WRITER__H__

#include "./Entry.hpp"
#include <string>

namespace Grawlog
{
	/**
	 * Interface for writers
	 */
	class Writer
	{
	public:
		/**
		 * Write a message and entry somewhere
		 * \param  entry    The entry metadata to write
		 * \param  message  The message to write
		 */
		virtual void Write( const Entry& entry, const std::string& message ) const = 0;
	};
}

#endif
