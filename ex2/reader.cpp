#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>

int main()
{
    const char *fifoPath = "/tmp/my_fifo";

    // Open the FIFO for reading
    int fd = open(fifoPath, O_RDONLY);

    // Buffer to store the read message
    char buffer[256];
    std::string message;

    // Read the message from the FIFO in a loop
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytesRead] = '\0'; // Null-terminate the read message
        message += buffer;        // Append to the message string
    }

    // Check if the read was successful
    if (bytesRead == -1)
    {
        std::cerr << "Error reading from FIFO" << std::endl;
    }
    else
    {
        std::cout << "Received: " << message << std::endl;
    }

    // Close the FIFO
    close(fd);

    return 0;
}
