#include <iostream>
using namespace std;
class Sensor {
    int **block;
    int *sizes;
    int no_of_blocks;

public:
    Sensor(int n) : no_of_blocks(n) {
        block = new int*[no_of_blocks];
        sizes = new int[no_of_blocks];

        for (int i = 0; i < no_of_blocks; i++) {
            block[i] = nullptr;
            sizes[i] = 0;
        }
    }

    void read_values(int index, int size, const string& name) {
        cout << "Reading " << name << " values"<<endl;
        sizes[index] = size;
        block[index] = new int[size];

        for (int i = 0; i < size; i++) {
            cin >> block[index][i];
        }
    }

    void print_values(int index, const string& name) {
        cout << name << " values: ";
        for (int i = 0; i < sizes[index]; i++) {
            cout << block[index][i] << " ";
        }
        cout << endl;
    }

    ~Sensor() {
        for (int i = 0; i < no_of_blocks; i++) {
            delete[] block[i];
        }
        delete[] block;
        delete[] sizes;
    }
};

int main() {
    Sensor s(3);

    s.read_values(0, 5, "Temperature"); 
    s.read_values(1, 3, "Humidity");    
    s.read_values(2, 7, "Fuel");        

    s.print_values(0, "Temperature");
    s.print_values(1, "Humidity");
    s.print_values(2, "Fuel");

    return 0;
}

