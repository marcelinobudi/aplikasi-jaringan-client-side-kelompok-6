#include <stdlib.h>
#include <string.h>
#include "client_networks/client_socket.h"
#include "client_networks/server_service.h"

typedef struct server_service server_service;
server_service* service_init(){
    server_service  *service = malloc(sizeof(server_service));
    if(service == NULL) {
        return NULL;
    }
    if(connect_to_server(&service->client) < 0) {
        return NULL;
    }
    return service;
}

void service_stop(server_service *service) {
    close_socket(&service->client);
}

int service_testing(server_service* service, char* user_input, char* output) {
    if(send_message(&service->client, user_input) < 0) {
        close_socket(&service->client);
        return -1;
    } 
    char message[BUFFER_SIZE];
    if(receive_message(&service->client, output) < 0) {
        close_socket(&service->client);
        return -1;
    }
    return 0;
}