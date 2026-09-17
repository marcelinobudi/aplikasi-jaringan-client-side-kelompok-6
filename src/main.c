#include <stdio.h>
#include "client_networks/client_socket.h";

int main() {
    client_socket *client;
    if(connect_to_server(client) < 0) {
        return 1;
    }

    if(send_message(client, "test") < 0) {
        return 1;
    } 

    char *message;
    if(receive_message(client, message) < 0) {
        return 1;
    }
    printf("Message: %s", message);

    close_socket(client);
    return 0;
}
