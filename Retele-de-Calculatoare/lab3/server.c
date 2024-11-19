#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int s;
    struct sockaddr_in server, client;
    char sir[101];
    uint16_t nr_spatii;
    socklen_t l;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        printf("Eroare la crearea socketului server\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Eroare la bind\n");
        return 1;
    }

    l = sizeof(client);
    memset(&client, 0, sizeof(client));

    recvfrom(s, sir, sizeof(sir), MSG_WAITALL, (struct sockaddr *)&client, &l);

    nr_spatii = 0;
    for (int i = 0; i < strlen(sir); i++) {
        if (sir[i] == ' ') {
            nr_spatii++;
        }
    }

    nr_spatii = htons(nr_spatii);
    sendto(s, &nr_spatii, sizeof(nr_spatii), 0, (struct sockaddr *)&client, l);

    close(s);
    return 0;
}