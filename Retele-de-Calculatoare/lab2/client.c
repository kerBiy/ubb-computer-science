#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilizare: %s <adresa_IP_server> <port_server>\n", argv[0]);
        return 1;
    }

    int c;
    struct sockaddr_in server;
    char string[100], reversed[100];

    c = socket(AF_INET, SOCK_STREAM, 0);
    if (c < 0) {
        perror("Eroare la crearea socketului client");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));  
    server.sin_addr.s_addr = inet_addr(argv[1]);  

    if (connect(c, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Eroare la conectarea la server");
        close(c);
        return 1;
    }

    printf("Enter the string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = 0;

    send(c, string, strlen(string) + 1, 0);

    recv(c, reversed, sizeof(reversed), 0);
    printf("The reversed is: %s\n", reversed);

    close(c);
    return 0;
}