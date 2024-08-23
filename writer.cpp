#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>

int main()
{
    const char *fifoPath = "/tmp/my_fifo";
    int fd = open(fifoPath, O_WRONLY);

    for (int i = 0; i < 10; i++)
    {
        std::cout << "> ";
        std::string buf;
        std::cin >> buf;
        write(fd, (buf + "\n").c_str(), buf.size() + 1);
    }

    close(fd);

    return 0;
}
