// что выведет эта программа?
#include <iostream>

int main(int argc, char ** argv) {
  int i = 5;
  const int & r = 5; // int tmp = 5; r = tmp;
  const int * p = &r; // &tmp
  (*p)++;
  std::cout << *p << std::endl;
  return 0;
}

