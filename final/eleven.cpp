#include <memory>
#include <vector>
#include <iostream>

class A {
public:
    A() { std::cout << "ctor" << std::endl; }
    ~A() { std::cout << "dtor" << std::endl; }
    A(A & a) { std::cout << "acopy" << std::endl; }
    A & operator=(const A & a) { std::cout << "=" << std::endl; return *this; }
};

template<typename T>
class array {
public:
    explicit array(int capacity=4): data(new T[capacity]()), size(0), capacity(capacity) {}
    ~array() {delete[] data; }
    void push_back(const T & t) {
        if (size >= capacity) throw std::out_of_range("array is full");
        data[size] = t;
        size++;
    }
private:
    T * data;
    int size;
    int capacity;
};

int main() {
    array<std::unique_ptr<A>> v;
    for (int i = 0; i < 3; i++) {
         std::unique_ptr<A> ptr(new A());
         v.push_back(ptr);
        std::cout << "-----" << std::endl;
    }
    return 0;
}
