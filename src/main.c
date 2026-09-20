#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "client_networks/server_service.h"
#include "client_networks/client_socket.h"

int main() {
    // client_socket client = {};
    // printf("[+] connecting to server...\n");
    // if(connect_to_server(&client) < 0) {
    //     return 1;
    // }

    server_service *service = service_init();
    if(service == NULL) {
        return 1;
    }

    while(1) {
        printf("input: ");
        char user_input[50];
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0'; // remove '\n'

        // EXIT
        if(strcmp(user_input, "exit") == 0) {
            printf("[+] EXIT\n");
            break;
        }

        

        // printf("[+] sending message to server...\n");
        // if(send_message(&client, user_input) < 0) {
        //     close_socket(&client);
        //     return 1;
        // } 

        // printf("[+] trying to receive message\n");
        char message[BUFFER_SIZE];
        // if(receive_message(&client, message) < 0) {
        //     close_socket(&client);
        //     return 1;
        // }

        if(service_testing(service, user_input, message) < 0) {
            printf("error");
            service_stop(service);
            return 1;
        }
        printf("Message: %s\n", message);
    }
    

    service_stop(service);
    return 0;
}
