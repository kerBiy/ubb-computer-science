#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int s, c, l;
    struct sockaddr_in server, client;

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("Eroare la crearea socketului server");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Eroare la bind");
        close(s);
        return 1;
    }

    listen(s, 5);

    printf("Serverul asculta pe portul 1234...\n");

    while (1) {
        l = sizeof(client);
        memset(&client, 0, sizeof(client));
        c = accept(s, (struct sockaddr *)&client, &l);

        if (c < 0) {
            perror("Eroare la accept");
            continue;
        }

        printf("S-a conectat un client.\n");

        if (fork() == 0) {  
            close(s);    
            char string[100], reversed[100];

            recv(c, string, sizeof(string), 0);

            int len = strlen(string);
            for (int i = 0; i < len; i++) {
                reversed[i] = string[len - i - 1];
            }
            reversed[len] = '\0';

            send(c, reversed, strlen(reversed) + 1, 0);
            close(c);  
            exit(0);   
        }
        close(c);  
    }

    close(s);
    return 0;
}