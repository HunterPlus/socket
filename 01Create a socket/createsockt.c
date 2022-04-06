#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) 
        printf("cound not create socket");
    else
        printf("socket create success\n");
    return 0;
}