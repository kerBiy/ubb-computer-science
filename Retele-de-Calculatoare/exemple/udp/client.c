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
    uint16_t a, b, suma, i, k;

    c = socket(AF_INET, SOCK_DGRAM, 0);
    if (c < 0) {
        printf("Eroare la crearea socketului client\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("172.30.0.3");

    for (i = 0; i < 10000; i++) {
        k = i + 1;
        k = htons(k);
        sendto(c, &k, sizeof(k), 0, (struct sockaddr *)&server, sizeof(server));
    }

    close(c);
}