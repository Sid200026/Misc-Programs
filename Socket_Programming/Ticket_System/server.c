#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<error.h>
#include<time.h>
#include<stdbool.h>

int getRandomNo()
{
    srand(time(0));
    return (rand()%(99999-10000+1))+10000;
}

int checkisValid(int arr[], int ele, int size)
{
    for(int i=0;i<size;i++)
    {
        if(ele==arr[i])
            return 0;
    }
    return 1;
}

int main()
{
    char *message = "Welcome to Online Ticket System";
    char *errmsg = "Request Denied";
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
    int listenStatus = listen(socket_num, 5);
    if(listenStatus<0)
    {
        perror("Listen");
        return -1;
    }
    int client_num = accept(socket_num, NULL, NULL);
    if(client_num<0)
    {
        perror("Accept");
        return -1;
    }
    int choicearr[50];
    int choicecount = 0;
    write(client_num, message, strlen(message));
    while(1)
    {
        char choice[1035];
        read(client_num, choice, sizeof(choice));
        if(strcmp(choice,"Finish")==0)
        {
            close(socket_num);
            return 0;
        }
        char newarr[1024];
        int count = 0;
        for(int i=3;choice[i]!='\0';i++)
        {
            newarr[count++] = choice[i];
        }
        newarr[count] = '\0';
        int opt;
        sscanf(newarr, "%d", &opt);
        choicearr[choicecount++] = opt;
        int stat = checkisValid(choicearr, opt, choicecount-1);
        if(stat==1)
        {
            int randomnum = getRandomNo();
            char answer[1024];
            sprintf(answer, "%d", randomnum);
            write(client_num, answer, sizeof(answer));
        }
        else
        {
            write(client_num, errmsg, strlen(errmsg));
        }
        
    }
    close(socket_num);
    return 0;
}