#include<iostream>
#include<cassert>
using namespace std;

template<typename type>
class Mydeque
{
    type* data;
    size_t size;
    size_t capacity;

    void grow(size_t newcap = 0)
    {
        if(newcap == 0)
            newcap = (capacity == 0) ? 1 : capacity * 2;

        type* newdata = new type[newcap];

        for(size_t i = 0; i < size; i++)
            newdata[i] = data[i];

        delete[] data;
        data = newdata;
        capacity = newcap;
    }

public:

    // Constructor
    Mydeque() : data(nullptr), size(0), capacity(0) {}

    // Copy Constructor
    Mydeque(const Mydeque& other)
    {
        size = other.size;
        capacity = other.capacity;

        data = new type[capacity];

        for(size_t i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    // Copy Assignment Operator
    Mydeque& operator=(const Mydeque& other)
    {
        if(this == &other)
            return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;

        data = new type[capacity];

        for(size_t i = 0; i < size; i++)
            data[i] = other.data[i];

        return *this;
    }

    // Destructor
    ~Mydeque()
    {
        delete[] data;
    }

    // push_back
    void push_back(const type& value)
    {
        if(size == capacity)
            grow();

        data[size++] = value;
    }

    // push_front
    void push_front(const type& value)
    {
        if(size == capacity)
            grow();

        for(size_t i = size; i > 0; i--)
            data[i] = data[i - 1];

        data[0] = value;
        size++;
    }

    // pop_back
    void pop_back()
    {
        assert(size > 0);
        size--;
    }

    // pop_front
    void pop_front()
    {
        assert(size > 0);

        for(size_t i = 0; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
    }

    // Resize
    void resize(size_t newsize, type value = type())
    {
        if(newsize > capacity)
            grow(newsize);

        if(newsize > size)
        {
            for(size_t i = size; i < newsize; i++)
                data[i] = value;
        }

        size = newsize;
    }

    // Clear
    void clear()
    {
        size = 0;
    }

    // Front
    type& front()
    {
        assert(size > 0);
        return data[0];
    }

    // Back
    type& back()
    {
        assert(size > 0);
        return data[size - 1];
    }

    // Index operator
    type& operator[](size_t index)
    {
        assert(index < size);
        return data[index];
    }
	Mydeque(std::initializer_list<T> l){
			size=l.size();
			cap=l.size();
			data=(cap==0)?nullptr:new T[cap];
			int i=0;
			for(const auto&x:l)
				data[i++]=x;
		}
    const type& operator[](size_t index) const
    {
        assert(index < size);
        return data[index];
    }

    // Iterators
    type* begin() const
    {
        return data;
    }

    type* end() const
    {
        return data + size;
    }

    // Size
    size_t size_of() const
    {
        return size;
    }

    bool empty() const
    {
        return size == 0;
    }
};

int main()
{
    Mydeque<int> de;

    de.push_back(10);
    de.push_front(20);
    de.push_back(30);

    // Copy constructor
    Mydeque<int> copyDeque(de);

    // Copy assignment
    Mydeque<int> assignDeque;
    assignDeque = de;

    // Resize
    de.resize(5, 99);

    // Print
    for(size_t i = 0; i < de.size_of(); i++)
        cout << de[i] << " ";

    cout << endl;

    // Front & Back
    cout << "Front: " << de.front() << endl;
    cout << "Back : " << de.back() << endl;
}
