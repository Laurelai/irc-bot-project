//
//  logger.c
//  
//
//  Created by Laurelai Bailey on 2/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "bot.h"

logtype_t log_level = LOG_RAW;

void logger(logtype_t type, const char *format, ...)
{
	va_list va;

	if (type < log_level)
		return;

	va_start(va, format);
	vprintf(format, va);
	va_end(va);
}
