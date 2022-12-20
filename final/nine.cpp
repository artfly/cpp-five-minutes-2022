#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-exception-baseclass"
#pragma ide diagnostic ignored "misc-throw-by-value-catch-by-reference"
#include <stdexcept>
#include <iostream>

class my_exception: public std::runtime_error {
public:
    my_exception(): std::runtime_error("default") {}

    const char * what() const noexcept override {
        return "my_exception";
    }
};

void test() {
    try {
        try {
            throw 1;
        } catch (int i) {
            std::cout << i << std::endl;
            throw my_exception();
        }
        std::cout << "here" << std::endl;
    } catch (int i) {
        std::cout << "int!" << std::endl;
        throw my_exception();
    }
}

int main() {
    try {
        test();
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }
}


#pragma clang diagnostic pop