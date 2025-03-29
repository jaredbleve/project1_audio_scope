#include <unistd.h>

int main() {
    const char *msg = "Audio Scope: future sample visualizer\n";
    write(STDOUT_FILENO, msg, 39); // 39 is the length of the string
    return 0;
}

