#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "client_networks/client_socket.h"
#include "client_networks/server_service.h"
#include "client_networks/stringx.h"
#include "client_networks/matrix.h"

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
    if(receive_message(&service->client, output) < 0) {
        close_socket(&service->client);
        return -1;
    }
    return 0;
}

int service_availibility_check(server_service* service, char* service_name, bool service_active) {
    char message[BUFFER_SIZE];
    sprintf(message, "CHECK %s", service_name);
    if(send_message(&service->client, message) < 0) {
        close_socket(&service->client);
        return -1;
    } 
    strcpy(message, "");
    if(receive_message(&service->client, message) < 0) {
        close_socket(&service->client);
        return -1;
    }
    strcpy(message, "");
    if(sscanf("CHECK %s", message) < 0) {
        perror("server_availibity_check sscanf");
        return -1;
    }

    if (strcmp(message, "ACTIVE") == 0) {
        service_active = true;
    } else if(strcmp(message, "INACITVE" == 0)) {
        service_active = false;
    } else {
        perror("server_availibility_check server outputs formats");
        return -1;
    }
    return 0;
}