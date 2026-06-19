//
// Created by mykhaylo on 19.06.26.
//

#ifndef Server_h
#define Server_h

#include <netinet/in.h>


struct Server {
    int domain;
    int protocol;
    int service;
    in_addr_t interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    int socket;
    // Function pointer
    void(*launch)(struct Server *server);
};

// Function prototype
struct Server server_constructor(int domain, int service, int protocol, in_addr_t interface, int port, int backlog, void(*launch)(struct Server *server));

#endif
