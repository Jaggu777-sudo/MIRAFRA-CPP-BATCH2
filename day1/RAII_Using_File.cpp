#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

class File
{
    int fd;

public:
    File(const char *path, const char *data)
    {
        fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0664);
        if (fd < 0)
        {
            perror("open");
            return;
        }

        cout << "File opened: " << path << endl;
        cout << "fd = " << fd << endl;

        write(fd, data, strlen(data));
    }
    void writeData(const char *data)
    {
        if (fd < 0)
            return;

        write(fd, data, strlen(data));
        cout << "Written successfully\n";
    }

 
    ~File()
    {
        if (fd >= 0)
        {
            close(fd);
            cout << "File is closed\n";
        }
    }
};

int main()
{
    File f1("mno.txt", "Welcome To Mirafra\n");
    File f2("abc.txt", "Training Started\n");

    f1.writeData("Jagadeesh\n");

    return 0;
}

