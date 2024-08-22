#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifoPath = "/tmp/my_fifo";

    // Create the FIFO (named pipe)
    mkfifo(fifoPath, 0666);

    // Message to be sent
    const char *message = "Hello, FIFO!";

    // Open the FIFO for writing
    int fd = open(fifoPath, O_WRONLY);

    // Write the message to the FIFO
    write(fd, message, strlen(message));

    // Close the FIFO
    close(fd);

    return 0;
}
