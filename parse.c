//
//  parse.c
//  
//
//  Created by Laurelai Bailey on 2/7/12.
//  Copyright (c) 2012. All rights reserved.
//

#include "bot.h"

/*
 * origin_parse()
 *
 * Inputs - origin string (e.g. nick[!user[@host]])
 * Outputs - none
 * Side Effect - "origin" is populated with nick, user and host information
 */
void origin_parse(irc_origin_t *origin, char *origin_str)
{
	char *p, *i;

	i = origin_str;
	if ((p = strchr(i, '!')) != NULL)
	{
		*p = '\0';
		mowgli_strlcpy(origin->nick, i, sizeof origin->nick);
	}
	else
	{
		mowgli_strlcpy(origin->nick, i, sizeof origin->nick);
		return;
	}

	i = p + 1;
	if ((p = strchr(i, '@')) != NULL)
	{
		*p = '\0';
		mowgli_strlcpy(origin->user, i, sizeof origin->user);
	}
	else
	{
		mowgli_strlcpy(origin->user, i, sizeof origin->user);
		return;
	}

	i = p + 1;
	mowgli_strlcpy(origin->host, i, sizeof origin->host);
}

#if 0
/*
 * irc_parse()
 *
 * Inputs - line to parse
 * Outputs - none
 * Side Effect - none
 */
void irc_parse(const char *line)
{
    char *string = strdup(line);
    char *token;
   
    if (string == NULL)
        return NULL;
    
    strip(string, "\r\n");
    logger(LOG_RAW, ">> %s", string);
    
    token = strtok(string, " ");
    if (token == NULL)
        return NULL;
    
    if((strncmp(token, ":", 1)) == 0)
    {
        event->origin = mowgli_alloc(sizeof(irc_user_t));
        event->origin = parse_user(token + 1);
    }
    else
    {
        event->command = token;
    }
    
    if(token != NULL)
    {
        if(event->command != NULL)
        {
            token = strtok(NULL, "\0");
            event->data = token;
        }
        else
        {
            token = strtok(NULL, " ");
            event->command = token;
        }
    }
    
    if(token != NULL)
    {
        token = strtok(NULL, " ");
        
        if (token != NULL)
        {
            
            if ((strncmp(token, ":", 1)) == 0)
                event->target = token + 1;
            else
                event->target = token;
            
            if ((strcmp(event->target, me.client->nick)) == 0)
                event->target = event->origin->nick;
        }
    }
    
    if ((token != NULL) && (!event->data))
    {
        token = strtok(NULL, "\0");
        if (token != NULL)
        {
            if ((strncmp(token, ":", 1)) == 0)
                event->data = token + 1;
            else
                event->data = token;
        }
    }
    
    if (event != NULL)
    {
        mowgli_hook_call(event->command, event);
    }
    
    free(string);
    
    return event;
}
#endif
