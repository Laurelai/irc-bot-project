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

/*
 * irc_parse()
 *
 * Inputs - line to parse
 * Outputs - none
 * Side Effect - none
 */
void irc_parse(const char *line)
{

}
