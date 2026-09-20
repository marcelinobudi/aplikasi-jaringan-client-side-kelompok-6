#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "client_networks/client_socket.h"
#include "client_networks/server_service.h"
#include "client_networks/stringx.h"
#include "client_networks/matrix.h"

typedef struct server_service server_service;


/* HELPER FUNCTION*/
static bool service_error_check(char* message, char* error_message) {
    char *temp;
    if(sscanf(message, "ERROR %s", error_message) < 0) {
        return 0;
    }
    return 1;
}

static int send_and_receive(server_service *service, const char *input, char *output) {
    if (send_message(&service->client, input) < 0 || receive_message(&service->client, output) < 0) {
        close_socket(&service->client);
        return -1;
    }
    return 0;
}

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
    return send_and_receive(service, user_input, output);
}

int service_availibility_check(server_service* service, char* service_name, bool *service_active) {
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "CHECK %s", service_name);
    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }
    char temp[BUFFER_SIZE]; 
    if(service_error_check(message, temp)) {
        char temp2[BUFFER_SIZE];
        snprintf(temp2, BUFFER_SIZE, "server_availibity_check server error: %s", temp);
        printf("%s\n", temp2);
    }
    if(sscanf(message, "CHECK %s", temp) < 0) {
        perror("server_availibity_check sscanf");
        return -1;
    }

    if (strcmp(message, "ACTIVE") == 0) {
        *service_active = true;
    } else if(strcmp(message, "INACITVE") == 0) {
        *service_active = false;
    } else {
        printf("server_availibility_check server outputs format error");
        return -1;
    }
    return 0;
}

int service_character_count(server_service *service, char *text, size_t *num) {
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "REQUEST CHARACTER_COUNT %s", text);
    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }
    char temp[BUFFER_SIZE]; 
    if(service_error_check(message, temp)) {
        char temp2[BUFFER_SIZE];
        snprintf(temp2, BUFFER_SIZE, "server_character_count server error: %s", temp);
        printf("%s\n", temp2);
    }
    if(sscanf(message, "RESPONSE %zu", num) != 1) {
        perror("server_character_count sscanf");
        return -1;
    }
    return 0;
}
int service_word_count(server_service *service, char *text, size_t *num) {
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "REQUEST WORD_COUNT %s", text);
    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }
    char temp[BUFFER_SIZE]; 
    if(service_error_check(message, temp)) {
        char temp2[BUFFER_SIZE];
        snprintf(temp2, BUFFER_SIZE, "server_word_count server error: %s", temp);
        printf("%s\n", temp2);
    }
    if(sscanf(message, "RESPONSE %zu", num) != 1) {
        perror("server_word_count sscanf");
        return -1;
    }
    return 0;
}

int service_reverse_string(server_service *service, char *text, char *reversed) {
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "REQUEST REVERSE_STRING %s", text);
    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }
    char temp[BUFFER_SIZE]; 
    if(service_error_check(message, temp)) {
        char temp2[BUFFER_SIZE];
        snprintf(temp2, BUFFER_SIZE, "server_reverse_string server error: %s", temp);
        printf("%s\n", temp2);
    }
    if(sscanf(message, "RESPONSE %s", reversed) != 1) {
        perror("server_reverse_string sscanf");
        return -1;
    }
    return 0;
}

int service_string_without_vowels(server_service *service, char *text, char *text_without_vowels) {
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "REQUEST STRING_WITHOUT_VOWELS %s", text);
    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }
    char temp[BUFFER_SIZE]; 
    if(service_error_check(message, temp)) {
        char temp2[BUFFER_SIZE];
        snprintf(temp2, BUFFER_SIZE, "server_string_without_vowels server error: %s", temp);
        printf("%s\n", temp2);
    }
    if(sscanf(message, "RESPONSE %s", text_without_vowels) != 1) {
        perror("server_string_without_vowels sscanf");
        return -1;
    }
    return 0;
}

int service_determinan_and_inverse_matrix(server_service *service, double matrix[3][3], double *determinan, double inverse_matrix[3][3]) {
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "REQUEST DETERMINAN_AND_INVERSE_MATRIX %lf %lf %lf %lf %lf %lf %lf %lf %lf", matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }
    char temp[BUFFER_SIZE]; 
    if(service_error_check(message, temp)) {
        char temp2[BUFFER_SIZE];
        snprintf(temp2, BUFFER_SIZE, "server_determinan_and_inverse_matrix server error: %s", temp);
        printf("%s\n", temp2);
        return -1;
    }
    if(sscanf(message, "RESPONSE %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", determinan,  &inverse_matrix[0][0], &inverse_matrix[0][1], &inverse_matrix[0][2], &inverse_matrix[1][0], &inverse_matrix[1][1], &inverse_matrix[1][2], &inverse_matrix[2][0], &inverse_matrix[2][1], &inverse_matrix[2][2]) != 10) {
        perror("server_determinan_and_inverse_matrix sscanf");
        return -1;
    }
    return 0;
}

int service_acknowledgement(server_service *service, bool is_valid) {
    char result[10];
    strcpy(result, (is_valid) ? "TRUE" : "FALSE");
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "ACK %s", result);

    if(send_and_receive(service, message, message) < 0) {
        return -1;
    }

    char *temp;
    if(service_error_check(message, temp)) {
        char *temp2;
        snprintf(temp2, BUFFER_SIZE, "server_acknowledgement server error -> %s", temp);
        printf("%s\n", temp2);
        return -1;
    } 
    
    return 0;
}