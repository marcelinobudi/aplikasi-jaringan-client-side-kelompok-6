#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
typedef struct client_socket client_socket;
int connect_to_server(client_socket *client);
int send_message(client_socket *client, char* message);
int receive_message(client_socket *client, char* message);
void close_socket(client_socket *client);
#endif