#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int main() {
    int a2b = open("fifoA", O_RDONLY);
    int b2a = open("fifoB", O_WRONLY);

    while (1) {
        int len;
        read(a2b, &len, sizeof(int));

        if (len < 0) break;

        char buf[len + 1]; read(a2b, &buf, sizeof(char) * len);
        buf[len] = 0;

        for (int i = 0; i < len; ++i) {
            if (buf[i] >= 'a' && buf[i] <= 'z') {
                buf[i] += 'A' - 'a';
            }
        }

        // Write to A
        write(b2a, &len, sizeof(int));
        write(b2a, buf, sizeof(char) * len);
    }
    
    close(a2b);
    close(b2a);

    return 0;
}
