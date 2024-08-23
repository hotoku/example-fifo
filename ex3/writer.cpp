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

    std::string buf;
    std::string msg;

    write(fd, "1\n", 2);
    write(fd, "12\n", 3);
    write(fd, "123\n", 4);
    write(fd, "123456789012345678901234567890\n", 31);
    write(fd, "1\n", 2);
    write(fd, "12\n", 3);
    write(fd, "123\n", 4);

    std::cout << "Closing FIFO..." << std::endl;
    close(fd);

    return 0;
}
