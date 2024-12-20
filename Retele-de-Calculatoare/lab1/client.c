#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int c;
    struct sockaddr_in server;
    char string[100], reversed[100];

    c = socket(AF_INET, SOCK_STREAM, 0);
    if (c < 0) {
        printf("Eroare la crearea socketului client\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(c, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Eroare la conectarea la server\n");
        return 1;
    }

    printf("Enter the string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = 0;

    send(c, string, strlen(string) + 1, 0);

    recv(c, reversed, sizeof(reversed), 0);

    printf("The reversed string is: %s\n", reversed);
    close(c);
}