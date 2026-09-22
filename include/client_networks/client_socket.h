#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
#include <arpa/inet.h>
#define BUFFER_SIZE 1024

typedef struct client_socket {
    struct sockaddr_in serv_addr;
    int sock_fd;
} client_socket;

int connect_to_server(client_socket *client);
int send_message(client_socket *client, char* message);
int receive_message(client_socket *client, char* message);
void close_socket(client_socket *client);
#endif