#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>      /* inet_addr    */

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server;

    /* create socket    */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        printf("could not create socket\n");
    server.sin_addr.s_addr = inet_addr("39.105.216.211");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    /* connect to remote server */
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }
    puts("connected");
    return 0;
}