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

bool service_error_check(char* message, char* error_message) {
    char *temp;
    if(sscanf(message, "ERROR %s", error_message) < 0) {
        return 0;
    }
    return 1;
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
    char *temp;
    if(sscanf(message, "CHECK %s", temp) < 0) {
        if(service_error_check(message, temp)) {
            char *temp2;
            sprintf(temp2, "server_availibity_check server error: %s", temp);
            printf(temp2);
        } else {
            perror("server_availibity_check sscanf");
        }
        
        return -1;
    }

    if (strcmp(message, "ACTIVE") == 0) {
        service_active = true;
    } else if(strcmp(message, "INACITVE" == 0)) {
        service_active = false;
    } else {
        printf("server_availibility_check server outputs format error");
        return -1;
    }
    return 0;
}


int service_acknowledgement(server_service *service, bool is_valid) {
    char *result;
    if(is_valid) {
        result = "TRUE";
    } else {
        result = "FALSE";
    }
    char message[BUFFER_SIZE];
    sprintf(message, "ACK %s", result);
    if(send_message(&service->client, message) < 0) {
        close_socket(&service->client);
        return -1;
    } 
    strcpy(message, "");
    if(receive_message(&service->client, message) < 0) {
        close_socket(&service->client);
        return -1;
    }

    char *temp;
    if(service_error_check(message, temp)) {
        char *temp2;
        sprintf(temp2, "server_acknowledgement server error -> %s", temp);
        perror(temp2);
        return -1;
    } 
    
    return 0;
}