//
//  bot.h
//  
//
//  Created by Laurelai Bailey on 2/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _bot_h
#define _bot_h

#include <mowgli.h>

#define NICKLEN		60
#define USERLEN		60
#define HOSTLEN		150

typedef struct {
	char nick[NICKLEN];
	char user[USERLEN];
	char host[HOSTLEN];
} irc_origin_t;

void origin_parse(irc_origin_t *origin, char *origin_str);

#endif
