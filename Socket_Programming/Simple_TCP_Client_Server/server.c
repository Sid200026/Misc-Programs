#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<error.h>
#include<string.h>

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

    int flag = bind(socket_num, (struct sockaddr*)&socket_address, sizeof(socket_address));

    if(flag<0)
    {
        perror("Bind");
    }

    listen(socket_num, 5);

    int client_num = accept(socket_num, NULL, NULL);

    char *message = "Hello Client";
    char buff[1024] = {0};

    write(client_num, message, strlen(message));

    read(client_num, buff, sizeof(buff));

    printf("Server : %s",buff);

    close(socket_num);

}
