#ifndef SERVER_SERVICE_H
#define SERVER_SERVICE_H
#include "client_socket.h"
typedef struct server_service{
    struct client_socket client;
} server_service;

server_service* service_init();
void service_stop(server_service *service);
int service_testing(server_service* service, char* user_input, char* output);
int service_availibility_check(server_service* service, char* service_name, bool *service_active);
int service_character_count(server_service *service, char *text, size_t *num);
int service_word_count(server_service *service, char *text, size_t *num);
int service_reverse_string(server_service *service, char *text, char *reversed);
int service_string_without_vowels(server_service *service, char *text, char *text_without_vowels);
int service_determinan_and_inverse_matrix(server_service *service, double matrix[3][3], double *determinan, double inverse_matrix[3][3]);
int service_acknowledgement(server_service *service, bool is_valid);
#endif