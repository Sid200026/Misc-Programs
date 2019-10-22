#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<error.h>
#include<stdbool.h>

int main()
{
    int socket_num;
    socket_num = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_num<0)
    {
        perror("Socket");
        return -1;
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    int status = bind(socket_num, (struct sockaddr*)&server_address, sizeof(server_address));
    if(status<0)
    {
        perror("Bind");
        return -1;
    }
    listen(socket_num,5);
    int client_num = accept(socket_num, NULL, NULL);
    if(client_num<0)
    {
        perror("Accept");
    }
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    bool parity = false;
    if(num%2==0)
    {
        parity=true;
    }
    num = parity?num*10:num*10+1;
    write(client_num, &num, sizeof(num));
    close(socket_num);
}
