#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int socket_num;
    int opt = 1;
    struct sockaddr_in server_address;

    socket_num = socket(AF_INET, SOCK_STREAM, 0);


    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int status = bind(socket_num, (struct sockaddr *)&server_address, sizeof(server_address));
    if(status<0)
    {
        perror("Bind ");
    }
    listen(socket_num, 5);

    int client_sock_num = accept(socket_num, NULL, NULL);
    
    while(1)
    {
        char *message;
        char buffer[1024] = {0};
        fgets(message,1024,stdin);
        printf("\n");
        write(client_sock_num, message, strlen(message));
        read(client_sock_num, buffer, sizeof(buffer));
        printf("Client: \t %s \n\n",buffer);
    }

    close(socket_num);
    return 0;
}