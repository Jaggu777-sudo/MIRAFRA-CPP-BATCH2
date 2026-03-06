#include <iostream>
#include <memory>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;
class File
{
	int fd;
	public:
	File(const char* filename)
	{
		fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0664);
		if (fd < 0)
		{
			perror("open");
		}
		else
		{
			cout << "File opened, fd = " << fd << endl;
		}
	}
	~File()
	{
		if (fd >= 0)
		{
			close(fd);
			cout << "File closed, fd = " << fd << endl;
		}
	}
	void writeData(const char* data)
	{
		write(fd, data, strlen(data));
		cout << "Written: " << data << endl;
	}
	void readData()
	{
		lseek(fd, 0, SEEK_SET);
		char buffer[100];
		int n = read(fd, buffer, sizeof(buffer));
		buffer[n] = '\0';
		cout << "Read: " << buffer << endl;
	}
	int getFd() const
	{
		return fd;
	}
};
void takeByValue(unique_ptr<File> file)
{
	cout << "ownership taken\n";
	file->writeData("Written by takeByValue\n");
}

void takeByRef(unique_ptr<File>& file)
{
	cout << "borrowed file\n";
	file->writeData("Written by takeByRef\n");
}

void takeByConstRef(const unique_ptr<File>& file)
{
	cout << "read-only borrow\n";
	//  file.reset();//we trying to modify const unique_ptr
//	file.release();
	cout << "FD = " << file->getFd() << endl;
}

void takeByRvalue(unique_ptr<File>&& file)
{
	cout << "ownership transferred\n";
	file->writeData("Written by takeByRvalue\n");
}

int main()
{
	unique_ptr<File> f1 = make_unique<File>("abc.txt");
	takeByRef(f1);
	takeByConstRef(f1);
	takeByValue(std::move(f1));
	if (!f1)
		cout << "f1 is nullptr after takeByValue (ownership moved)\n";
	unique_ptr<File> f2 = make_unique<File>("mno.txt");
	takeByRvalue(std::move(f2));
	if (!f2)
		cout << "f2 is nullptr after takeByRvalue (ownership transferred)\n";

	return 0;
}

