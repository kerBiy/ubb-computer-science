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
    server.sin_port = htons(8889);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("172.30.240.4");

    if (connect(c, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Eroare la conectarea la server\n");
        return 1;
    }

    short id = 3475;
    id = htons(id);
    send(c, &id, sizeof(id), 0);

    uint16_t len;
    recv(c, &len, sizeof(len), MSG_WAITALL);
    len = ntohs(len);
    printf("%d", len);

    char problem[len];
    recv(c, problem, (len) * sizeof(char), MSG_WAITALL);
    printf("%s", problem);

    len = htons(len);
    send(c, &len, sizeof(len), 0);

    float menu_size;
    recv(c, &menu_size, sizeof(menu_size), MSG_WAITALL);
    printf("%f", menu_size);

    char menu[(int)menu_size];
    recv(c, menu, ((int)menu_size) * sizeof(char), MSG_WAITALL);
    printf("\n%s", menu);

    // char option = 'b';

    char option;
    printf("\nEnter the option: ");
    scanf("%c", &option);

    send(c, &option, sizeof(option), 0);

    float size;
    recv(c, &size, sizeof(size), MSG_WAITALL);

    char buffer[(int)size];
    recv(c, buffer, ((int)size) * sizeof(char), MSG_WAITALL);
    printf("\n%s", buffer);

    if (option == 'a') {
    } else if (option == 'b') {
        char username[255];
        printf("Enter username: ");
        fgets(username, sizeof(username), stdin);

        char password[255];
        printf("Enter password: ");
        fgets(password, sizeof(password), stdin);

        float username_len = strlen(username);
        send(c, &username_len, sizeof(username_len), 0);
        send(c, username, username_len + 1, 0);

        float password_len = strlen(password);
        send(c, &password_len, sizeof(password_len), 0);
        send(c, password, password_len + 1, 0);

        float size_message;
        recv(c, &size_message, sizeof(size_message), MSG_WAITALL);

        char message[(int)size_message];
        recv(c, message, ((int)size_message) * sizeof(char), MSG_WAITALL);
        printf("\n%s", message);

    } else if (option == 'c') {
    } else {
        printf("Else\n");
    }
    // send(c, &username_len, sizeof(username_len), 0);
    // send(c, username, username_len + 1, 0);
    // send(c, &password_len, sizeof(username_len), 0);
    // send(c, password, password_len + 1, 0);

    close(c);
}