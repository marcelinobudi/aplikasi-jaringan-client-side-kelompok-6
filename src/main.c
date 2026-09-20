#include <stdio.h>
#include "client_networks/client_socket.h"

int main() {
    client_socket client = {};
    printf("[+] connecting to server...\n");
    if(connect_to_server(&client) < 0) {
        return 1;
    }

    printf("[+] sending message to server...\n");
    if(send_message(&client, "10 22") < 0) {
        close_socket(&client);
        return 1;
    } 

    printf("[+] trying to receive message\n");
    char message[BUFFER_SIZE];
    if(receive_message(&client, message) < 0) {
        close_socket(&client);
        return 1;
    }
    printf("Message: %s\n", message);

    close_socket(&client);
    return 0;
}
