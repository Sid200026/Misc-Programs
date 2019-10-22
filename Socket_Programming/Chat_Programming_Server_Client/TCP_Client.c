#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int socket_num;
    struct sockaddr_in socket_address;

    socket_num = socket(AF_INET, SOCK_STREAM, 0);

    socket_address.sin_family=AF_INET;
    socket_address.sin_port = htons(8080);
    socket_address.sin_addr.s_addr = INADDR_ANY;

    int connectflag = connect(socket_num, (struct sockaddr *)&socket_address, sizeof(socket_address));

    if(connectflag < 0)
    {
        perror("Connect");
        return -1;
    }
    while(1)
    {
        char *message;
        char buffer[1024] = {0};
        read(socket_num, buffer, sizeof(buffer));
        printf("Server: \t %s \n\n",buffer);
        fgets(message,1024,stdin);
        printf("\n");
        write(socket_num, message, strlen(message));
    }

    close(socket_num);

    return 0;
}