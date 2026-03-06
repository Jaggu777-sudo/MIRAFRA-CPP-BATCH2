#include <iostream>
#include <cstring>

using namespace std;

class spi {
    char* spi_data;
    int spi_num;
    int spi_speed;

public:
    spi(int num = 0, int speed = 1000, const char* data = nullptr);
    ~spi();

    spi(const spi& other);
    spi& operator=(const spi& other);
    spi(spi&& other) noexcept;
    spi& operator=(spi&& other) noexcept;

    void set_data(const char* p);

    char* get_data();
    void print_info();
};
spi::spi(int num, int speed, const char* data)
    : spi_num(num), spi_speed(speed) {
    if (data) {
        spi_data = new char[strlen(data) + 1];
        strcpy(spi_data, data);
    } else {
        spi_data = nullptr;
    }
    cout << "Constructor called\n";
}
spi::~spi() {
    cout << "Destructor called\n";
    delete[] spi_data;
}
spi::spi(const spi& other) {
    cout << "Copy constructor called\n";
    spi_num = other.spi_num;
    spi_speed = other.spi_speed;

    if (other.spi_data) {
        spi_data = new char[strlen(other.spi_data) + 1];
        strcpy(spi_data, other.spi_data);
    } else {
        spi_data = nullptr;
    }
}

spi& spi::operator=(const spi& other) {
    cout << "Copy assignment called\n";
    if (this != &other) {
        delete[] spi_data;

        spi_num = other.spi_num;
        spi_speed = other.spi_speed;

        if (other.spi_data) {
            spi_data = new char[strlen(other.spi_data) + 1];
            strcpy(spi_data, other.spi_data);
        } else {
            spi_data = nullptr;
        }
    }
    return *this;
}
spi::spi(spi&& other) noexcept {
    cout << "Move constructor called\n";
    spi_num = other.spi_num;
    spi_speed = other.spi_speed;
    spi_data = other.spi_data;

    other.spi_num = -1;
    other.spi_speed = 0;
    other.spi_data = nullptr;
}
spi& spi::operator=(spi&& other) noexcept {
    cout << "Move assignment called\n";
    if (this != &other) {
        delete[] spi_data;

        spi_num = other.spi_num;
        spi_speed = other.spi_speed;
        spi_data = other.spi_data;

        other.spi_num = -1;
        other.spi_speed = 0;
        other.spi_data = nullptr;
    }
    return *this;
}

void spi::set_data(const char* p) {
    delete[] spi_data;

    if (p) {
        spi_data = new char[strlen(p) + 1];
        strcpy(spi_data, p);
    } else {
        spi_data = nullptr;
    }
}
char* spi::get_data() {
    return spi_data;
}
 void spi::print_info() {
    cout << "spi_num   : " << spi_num << endl;
    cout << "spi_speed : " << spi_speed << endl;

    if (spi_data == nullptr)
        cout << "spi_data  : data is null\n";
    else
        cout << "spi_data  : " << spi_data << endl;
}

int main() {
    spi s1(1, 500000, "SPI Data");
    s1.print_info();
    spi s2 = s1;
    s2.print_info();

    spi s3 = std::move(s1);
    cout << "s1 after move\n";
    s1.print_info();

    cout << "s3 after stealing resource from s1 by move constructor\n";
    s3.print_info();

    spi s4;
    s4 = s2;
    s4.print_info();

    spi s5;
    s5 = std::move(s2);

    cout << "s2 after move assignment\n";
    s2.print_info();

    cout << "s5 after getting resource from s2 by move assignment\n";
    s5.print_info();
    s5.set_data("New SPI Data");
    s5.print_info();

    return 0;
}

