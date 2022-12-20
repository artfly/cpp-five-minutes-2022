#include <string>
#include <sstream>
#include <iostream>

template<typename T> std::string stringify(const T& x) {
    std::ostringstream out;
    out << x;
    return out.str();
}

template<> std::string stringify<bool>(const bool& x) {
    std::ostringstream out;
    // allows to print x as true / false and not 0 / 1
    out << std::boolalpha << x;
    return out.str();
}

template<> std::string stringify<int>(const int& x) {
    std::ostringstream out;
    out << x << ".0";
    return out.str();
}

int main() {
    std::cout << stringify<uint>(42) << std::endl;
    std::cout << stringify(42) << std::endl;
    std::cout << stringify(42 == 42) << std::endl;
    return 0;
}
