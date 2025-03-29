#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <time.h>

#define HEIGHT 24
#define SCALE  300

int main() {
    int fd = open("output.raw", O_RDONLY);
    if (fd < 0) {
        write(2, "Failed to open output.raw\n", 26);
        return 1;
    }

    int16_t sample;
    char line[HEIGHT + 2];

    struct timespec delay = {0, 10000}; // 1 ms = 1,000,000 ns

    while (read(fd, &sample, sizeof(sample)) == sizeof(sample)) {
        for (int i = 0; i < HEIGHT; i++) line[i] = ' ';
        line[HEIGHT] = '\n';
        line[HEIGHT + 1] = '\0';

        int center = HEIGHT / 2;
        int scaled = sample / SCALE;
        int pos = center - scaled;

        if (pos >= 0 && pos < HEIGHT)
            line[pos] = '|';

        write(1, line, HEIGHT + 1);
        nanosleep(&delay, NULL);  // Sleep 1 ms
    }

    close(fd);
    return 0;
}

