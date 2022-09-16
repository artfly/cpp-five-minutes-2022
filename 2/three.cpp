// какие переменные доступны в функциях f?

class Foo {
 public:
    Foo(int i) {
      this->i_ = i;
    }
    void f() {
      
    }
 private:
    int i_;
};

void f(Foo foo) {

}


