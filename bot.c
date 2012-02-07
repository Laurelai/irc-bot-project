//
//  Bot.c
//  
//
//  Created by Laurelai Bailey on 2/7/12.
//  Copyright (c) 2012 All rights reserved.
//

#include <stdio.h>
#include <mowgli.h>

mowgli_eventloop_t* base_eventloop;

static void irc_read(mowgli_eventloop_t *eventloop, mowgli_eventloop_pollable_t *pollable, mowgli_eventloop_pollable_dir_t dir, void *userdata)
{
    char buf[16384];
    mowgli_descriptor_t fd;
    int bytes_read;
    
    fd = pollable->fd;
    bzero(buf, sizeof buf);
    
    while ((bytes_read = read(fd, buf, sizeof buf)) > 0)
    {
        printf("-> %s\n", buf);
    }
}

mowgli_eventloop_pollable_t* irc_connect(const char * host, const char * port)
{
    mowgli_eventloop_pollable_t* out;
    mowgli_descriptor_t fd;
    struct addrinfo hints, *res;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    getaddrinfo(host, port, &hints, &res);

    fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    connect(fd, res->ai_addr, res->ai_addrlen);
    
    out = mowgli_pollable_create(base_eventloop, fd, NULL);
    mowgli_pollable_set_nonblocking(out, true);
    mowgli_pollable_setselect(base_eventloop, out, MOWGLI_EVENTLOOP_POLL_READ, irc_read);
    
    return out;
}

int main(int argc, const char **argv)
{
    base_eventloop = mowgli_eventloop_create ();
    
    irc_connect(argv[1], argv[2]);
    
    mowgli_eventloop_run (base_eventloop);
    return EXIT_SUCCESS; 
}
