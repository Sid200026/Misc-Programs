#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

// SERVER SIDE
// 1. Socket Creation : socket
// 2. Bind IP-Address : bind
// 3. Number of clients : listen
// 4. Get client socket number : accept

// read and write

int main() {
    int server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(server_sock<0)
    {
        printf("Error in socket creation");
        return -1;
    }
    struct sockaddr_in socket_server;
    socket_server.sin_family = AF_INET;
    socket_server.sin_port = htons(8080);
    socket_server.sin_addr.s_addr = INADDR_ANY;
    int bindflag = bind(server_sock, (struct sockaddr*)&socket_server, sizeof(socket_server));
    if(bindflag<0) 
    {
        printf("Error in binding");
        return -1;
    }

    // char *message = "Hellloooo"; To client
    // char buffer[1024] = {0}; From client
    // write(clientsocketnum, message, strlen(message));
    // int a = 5;
    // write(clientsocketnum, &a, sizeof(a));
    // read(clientsocketnum, buffer, sizeof(buffer));
    // printf("%s", buffer);
    // close(server_sock);
    
    char *message = "Hellloooo"; // To client
    char buffer[1024] = {0}; // From client
    recvfrom(server_sock, buffer, 1024, MSG_WAITALL, NULL, NULL);
    sendto(server_sock, message, strlen(message), MSG_CONFIRM, NULL, NULL);
    close(server_sock);
}

