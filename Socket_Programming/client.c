#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

// Socket Creation : socket
// Socket binding : connect

int main()
{
    int socket_num = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_num<0)
    {
        printf("Error in socket creation");
        return -1;
    }
    struct sockaddr_in clientsocket;
    clientsocket.sin_addr.s_addr = INADDR_ANY;
    clientsocket.sin_family = AF_INET;
    clientsocket.sin_port = htons(8080);
    int status = connect(socket_num , (struct sockaddr*)&clientsocket, sizeof(clientsocket));
    if(status<0)
    {
        printf("Error in connect");
        return -1;
    }
    // // char *message = "Hellooo";
    // // char buffer[1024] = {0};
    // read(socket_num, buffer, sizeof(buffer));
    // int a;
    // read(socket_num, &a, sizeof(a));
    // write(socket_num, message, strlen(message));
    // close(socket_num;)

    // Addition of 2 numbers

    int a,b;
    bool flag = true;
    scanf("%d %d",&a,&b);
    write(socket_num, &a, sizeof(a));
    write(socket_num, &b, sizeof(b));
    int result;
    read(socket_num, &result, sizeof(result));
    printf("%d", result);
    close(socket_num);
}