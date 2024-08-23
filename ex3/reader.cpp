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
    char buffer[3];
    std::string message;
    const char *delimiter = "\n";

    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytesRead] = '\0';
        message += buffer;
        size_t pos;
        while ((pos = message.find(delimiter)) != std::string::npos)
        {
            const auto val = message.substr(0, pos);
            message = message.substr(pos + 1, message.size());
            std::cout << "val: " << val << std::endl;
        }
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
