#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>

int main()
{
    const char *fifoPath = "/tmp/my_fifo";

    int fd = open(fifoPath, O_RDONLY);
    char buffer[256];
    std::string message;

    while (true)
    {
        ssize_t bytesRead;
        message = "";
        while (bytesRead = read(fd, buffer, sizeof(buffer) - 1) > 0)
        {
            std::cout << "Read " << bytesRead << " bytes" << std::endl;
            buffer[bytesRead] = '\0';
            message += buffer;
            bytesRead = read(fd, buffer, sizeof(buffer) - 1);
        }

        if (bytesRead == -1)
        {
            std::cerr << "Error reading from FIFO" << std::endl;
        }
        else
        {
            std::cout << "Received: " << message << std::endl;
        }
    }

    // Close the FIFO
    close(fd);

    return 0;
}
