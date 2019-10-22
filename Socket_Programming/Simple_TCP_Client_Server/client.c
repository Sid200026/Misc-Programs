#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<error.h>

int main()
{
    int socket_num = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_num<0)
    {
        perror("Socket");
        return -1;
    }

    struct sockaddr_in socket_address;
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(8080);
    socket_address.sin_addr.s_addr = INADDR_ANY;

    int status = connect(socket_num, (struct sockaddr*)&socket_address, sizeof(socket_address));

    if(status<0)
    {
        perror("Connect");
        return -1;
    }

    char *message = "Hello Server";
    char buffer[1024] = {0};

    read(socket_num, buffer, sizeof(buffer));

    printf("Client : %s",buffer);

    write(socket_num, message, strlen(message));

    close(socket_num);

    return 0;
}