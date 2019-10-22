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
    int status = connect(socket_num, (struct sockaddr*)&server_address, sizeof(server_address));
    if(status<0)
    {
        perror("Connect");
        return -1;
    }
    int num;
    read(socket_num, &num, sizeof(num));
    int parity = num%10;
    num = num/10;
    int parityclient = num%2==0?0:1;
    if(parityclient == parity)
    {
        printf("The number is %d \nThe parity is %d",num,parity);
    }
    else
    {
        printf("Error in transmission");
    }
    
    close(socket_num);
}
