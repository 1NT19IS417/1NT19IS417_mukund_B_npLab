 /*Title: UDP
 Question : C program in Define the Server of the UDP
Author:Mukund.G -USN:1NT19IS417
 Date: 21/05/21*/ 
 

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    int udpSocket, nBytes, i;

    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;

    /*Creating the  UDP socket*/
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configuring the  settings for the address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    /*Bind socket with address struct*/
    bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    addr_size = sizeof serverStorage;

    while (1) 
    {
        /* Try to receive any incoming UDP datagram.*/
        nBytes = recvfrom(udpSocket, buffer, 1024, 0, (struct sockaddr *)&serverStorage, &addr_size);
        /* print message */
        printf("Message from client:\n\n");
        for(i = 0; i < nBytes - 1; i++)
            printf("%c", buffer[i]);
        printf("\n");
        for(i = 0; i < nBytes - 1; i++)
        buffer[i] = toupper(buffer[i]);
        sendto(udpSocket, buffer, nBytes, 0, (struct sockaddr *)&serverStorage, addr_size);
    }

    return 0;
}
