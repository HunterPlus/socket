#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int sockfd;
    struct sockaddr_in server;
    char *message;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        fprintf(stderr, "could not create socket.\n");
    
    server.sin_addr.s_addr = inet_addr("39.105.216.211");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }
    puts("connected\n");
    
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        puts("send message failed.");
        return 1;
    }
    puts("send message success\n");

    return 0;
}
