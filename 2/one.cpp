// что выведет эта программа?
#include <iostream>

int main(int argc, char const *argv[]) {
    int a = 42;
    int b = 1;
    b = a; // 42 42
    a = 11; // 11 42
    std::cout << b << " " << a << std::endl; // 42 11
    int & r = b; // r=42
    r = 22; // b=22, r=22 a=11
    std::cout << r << " " << b << " " << a << std::endl;
    int & rr = r; // rr = 22 r = 22 b = 22 a = 11
    r = 33; // rr = 33 r = 33 b = 33 a = 11
    std::cout << rr << " " << r << " " << b << " " << a << std::endl;
    return 0;
}

