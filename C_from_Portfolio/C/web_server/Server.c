#include <stdio.h>
#include "Server.h"
#include <stdlib.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, in_addr_t interface, int port, int backlog, void(*launch)(struct Server *server)) {
    struct Server server;

    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    // Converts from host (server.port) to network byte order
    server.address.sin_port = htons(server.port);
    server.address.sin_addr.s_addr = htonl(interface);

    // Socket allows OS to operate with network
    server.socket = socket(domain, service, protocol);
    if (server.socket == 0) {
        perror("Failed to connect socket...\n");
        exit(1);
    }
    // Binding a socket to the network
    if ((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0) {
        perror("Failed to bind socket...\n");
        exit(1);
    }

    if ((listen(server.socket, server.backlog)) < 0) {
        perror("Failed to start listening");
        exit(1);
    }

    server.launch = launch;

    return server;
}
