#ifndef __GRAWLOG_SEVERITY__H__
#define __GRAWLOG_SEVERITY__H__

#define GRAWLOG_DIAG Grawlog::Severity::Diagnostic
#define GRAWLOG_INFO Grawlog::Severity::Information
#define GRAWLOG_WARN Grawlog::Severity::Warning
#define GRAWLOG_ERR Grawlog::Severity::Error
#define GRAWLOG_FATAL Grawlog::Severity::Fatal

#ifndef __EXPLICIT__
	#define DIAG GRAWLOG_DIAG
	#define INFO GRAWLOG_INFO
	#define WARN GRAWLOG_WARN
	#define ERR GRAWLOG_ERR
	#define FATAL GRAWLOG_FATAL
#endif

namespace Grawlog
{
	/**
	 * Severity indicator enum
	 */
	enum class Severity
	{
		/**
		 * Only used for debugging
		 */
		Diagnostic,

		/**
		 * Write to the information sink
		 */
		Information,

		/**
		 * Write to the warning sink
		 */
		Warning,

		/**
		 * Write to the error sink
		 */
		Error,

		/**
		 * Write to the fatal sink
		 */
		Fatal
	};
}

#endif
