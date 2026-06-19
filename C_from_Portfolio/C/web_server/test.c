//
// Created by mykhaylo on 19.06.26.
//
#include "Server.h"
#include <stdio.h>
#include <string.h>

#include <unistd.h>

void launch(struct Server *server) {
    printf("=== WAITING FOR CONNECTION === \n");

    char buffer[1024];
    int server_length = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&server_length);
    read(new_socket, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    char *hello =
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: 48\n"
        "Connection: close\n"
        "\n"
        "<html><body><h1>Hello, World!</h1></body></html>";

    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

int main () {
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY,2000, 10, launch);
    server.launch(&server);
}