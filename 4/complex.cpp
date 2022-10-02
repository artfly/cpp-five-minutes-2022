#include <iostream>

class Complex {
  public:
    explicit Complex(const double a = 0, const double b = 0): a_(a), b_(b) {}

    Complex operator+(const Complex & other) const {
      return Complex(a_ + other.a_, b_ + other.b_);
    }

    Complex operator-(const Complex & other) const {
      return Complex(a_ - other.a_, b_ - other.b_);
    }

    bool operator==(const Complex & other) const {
      return this->a_ == other.a_ && this->b_ == other.b_;
    }
  private:
    double a_;
    double b_;
};

int main() {
  Complex a(1, 2);
  Complex b(a);
  std::cout << (a == b) << std::endl;

  // Complex
  // реализовать заданные операции:
  // Complex a(1, 2);
  // Complex b(a);
  // a = b;

  // Complex c = a + b;
  // Complex c = a + b;

  // a - b;
  // a == b;
}