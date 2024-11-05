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
    char sir[101];
    uint16_t nr_spatii;

    // Crearea socketului client
    c = socket(AF_INET, SOCK_DGRAM, 0);
    if (c < 0) {
        printf("Eroare la crearea socketului client\n");
        return 1;
    }

    // Configurarea adresei serverului
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Citirea șirului de la utilizator
    printf("Introduceti un sir de maximum 100 de caractere: ");
    fgets(sir, 101, stdin);

    // Trimiterea șirului către server
    sendto(c, sir, strlen(sir), 0, (struct sockaddr *)&server, sizeof(server));

    // Primirea numărului de caractere spațiu de la server
    socklen_t len = sizeof(server);
    recvfrom(c, &nr_spatii, sizeof(nr_spatii), MSG_WAITALL,
             (struct sockaddr *)&server, &len);
    nr_spatii = ntohs(nr_spatii);

    // Afișarea rezultatului
    printf("Numarul de caractere spatiu este: %hu\n", nr_spatii);

    // Închiderea socketului
    close(c);

    return 0;
}