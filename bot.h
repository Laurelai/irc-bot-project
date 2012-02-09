//
//  bot.h
//  
//
//  Created by Laurelai Bailey on 2/7/12.
//  Copyright (c) 2012 . All rights reserved.
//

#ifndef _bot_h
#define _bot_h

#include <mowgli.h>

/* parse.c */
#define NICKLEN		60
#define USERLEN		60
#define HOSTLEN		150

typedef struct {
	char nick[NICKLEN];
	char user[USERLEN];
	char host[HOSTLEN];
} irc_origin_t;

typedef struct {
	irc_origin_t origin;
	char target[NICKLEN];
} irc_message_t;

void origin_parse(irc_origin_t *origin, char *origin_str);

/* logger.c */
typedef enum {
	LOG_INFO,
	LOG_ERROR,
	LOG_DEBUG,
	LOG_RAW,
} logtype_t;

void logger(logtype_t type, const char *format, ...);

#endif
