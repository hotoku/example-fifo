#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <cstring>
#include <sstream>

int main()
{
    const char *fifoPath = "/tmp/my_fifo";
    mkfifo(fifoPath, 0666);
    std::cout << "Opening FIFO for writing..." << std::endl;
    int fd = open(fifoPath, O_WRONLY);

    std::stringstream ss;
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Writing message " << i << "..." << std::endl;
        ss << i << ": abcdefghi" << std::endl;
    }

    std::cout << "Writing to FIFO..." << std::endl;
    write(fd, ss.str().c_str(), ss.str().size());

    std::cout << "Closing FIFO..." << std::endl;
    close(fd);

    return 0;
}
