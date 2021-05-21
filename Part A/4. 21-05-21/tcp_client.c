 /*Title: TCP 
 Question : C program in Define the Client of the TCP 
Author:Mukund.G -USN:1NT19IS417
 Date: 21/05/21*/ 

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int main() 
{
    int sock, bytes_recv;
    struct sockaddr_in server_addr;
    char recv_data[1024], send_data[1024];

    struct hostent *host;
    host = gethostbyname("127.0.0.1");

    if ((sock=socket(AF_INET,SOCK_STREAM,0)) == -1) 
    {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sock,(struct sockaddr *)&server_addr,sizeof(struct sockaddr)) == -1) 
    {
        perror("connect");
        exit(1);
    }

    printf("The File to be Sent\n");
    gets(send_data);

    if (strcmp(send_data,"q") != 0)
        send(sock,send_data,strlen(send_data),0);

    while((bytes_recv = recv(sock,recv_data,1024,0)) > 0) 
    {
        recv_data[bytes_recv] = '\0';
        printf("%s\n", recv_data);
    }

    close(sock);
    return 0;
}
