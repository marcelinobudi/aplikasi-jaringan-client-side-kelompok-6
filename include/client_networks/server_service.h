#ifndef SERVER_SERVICE_H
#define SERVER_SERVICE_H
#include "client_socket.h"
typedef struct server_service{
    struct client_socket client;
} server_service;

server_service* service_init();
void service_stop(server_service *service);
int service_testing(server_service* service, char* user_input, char* output);
#endif