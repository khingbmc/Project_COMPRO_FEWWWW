#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr

int sockDesc;
char *clientMsg , serverReply[4000];

int sendrecv(char *clientMsg)
{
    int sRC, rRC;
    sRC = send(sockDesc , clientMsg , strlen(clientMsg) , 0);
    if(sRC < 0)
    {
        puts("Send failed");
        return 1;
    }
    rRC = 0;
    while (rRC != 0) {
        rRC = recv(sockDesc, serverReply , 4000 , 0);
        if(rRC < 0)
        {
            puts("recv failed");
            return 1;
        }
    }
    return 0;
}

int main(int argc , char *argv[])
{
    struct sockaddr_in server;
    int rc;

    sockDesc = socket(AF_INET , SOCK_STREAM , 0);
    if (sockDesc == -1)
    {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 25 );

    if (connect(sockDesc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
    printf("Lol");
    clientMsg = "EHLO 127.0.0.1\r\n";
    if (sendrecv(clientMsg) != 0) {
        return 1;
    }
    printf("Lol");
    
    clientMsg = "MAIL FROM:<raspberry@localhost>\r\n";
    if (sendrecv(clientMsg) != 0) {
        return 1;
    }
    printf("Lol");
    clientMsg = "RCPT TO:<rawitgun@gmail.com>\r\n";
    if (sendrecv(clientMsg) != 0) {
        printf("done");
        return 1;
    }
    clientMsg = "DATA\r\n";
    if (sendrecv(clientMsg) != 0) {
        return 1;
    }
    clientMsg = "From:raspberry\r\nTo:root\r\nSubject:Test message\r\nTest message from C program\r\n";
    if (sendrecv(clientMsg) != 0) {
        return 1;
    }
    clientMsg = "\r\n.\r\n";
    if (sendrecv(clientMsg) != 0) {
        return 1;
    }
    clientMsg = "QUIT\r\n";
    if (sendrecv(clientMsg) != 0) {
        return 1;
    }
    return 0;
}