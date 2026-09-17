#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "client_networks/client_socket.h"

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    struct sockaddr_in serv_addr;
    int sock_fd;
} client_socket;

int connect_to_server(client_socket *client) {

    // buat socket  
    if ((client->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return -1;
    }

    // DEFINISIKAN ADDRESS SERVER
    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &client->serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    // BANGUN KONEKSI KE SERVER
    if(connect(client->sock_fd, (struct sockaddr *)&client->serv_addr, sizeof(client->serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    return 0;
}

int send_message(client_socket *client, char* message) {
    if(send(client->sock_fd, message, strlen(message), 0) < 0) {
        perror("failed to send data");
        return -1;
    }
    return 0;
}

int receive_message(client_socket *client, char* message) {
    if(recv(client->sock_fd, message, BUFFER_SIZE, 0) < 0) {
        perror("failed to receive data");
        return -1;
    }
    return 0;
}

void close_socket(client_socket *client) {
    close(client->sock_fd);
}