#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<error.h>
#include<stdbool.h>

int main()
{
    int socket_num;
    char serverMessage[1024] = {0};
    socket_num = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_num<0)
    {
        perror("Socket");
        return -1;
    }
    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(8080);
    client_address.sin_addr.s_addr = INADDR_ANY;
    int status = connect(socket_num, (struct sockaddr*)&client_address, sizeof(client_address));
    if(status<0)
    {
        perror("Connect");
        return -1;
    }
    read(socket_num, &serverMessage, sizeof(serverMessage));
    printf("%s\n\n",serverMessage);
    while(true)
    {
        char *num;
        char ans[1024] = {0};
        printf("Enter your token number\n");
        scanf("%s",num);
        printf("\n");
        write(socket_num, num, strlen(num));
        if(strcmp(num,"Finish")==0)
        {
            close(socket_num);
            return 0;
        }
        read(socket_num, ans, sizeof(ans));
        printf("%s\n\n",ans);
    }
    close(socket_num);
    return 0;
}