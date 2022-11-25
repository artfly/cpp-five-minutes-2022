struct A {
  A() {
    std::cout << "A!" << std::endl;    
  }

  ~A() {
    std::cout << "~A!" << std::endl;    
  }

  A(const A & other) {
    std::cout << "Acopy!" << std::endl;
  }

  operator=(const A & other) {
    std::cout << "A=!" << std::endl;
  }

  void foo() {
    std::cout << "foo!" << std::endl;
  }
};

template<typename T>
class shared_ptr {
  public:

    // creates new shared_ptr with the same underlying raw pointer, sets counter to 1
    shared_ptr(T * t = nullptr);

    // creates shared_ptr with the same underlying raw pointer as 'other' has, increments counter
    shared_ptr(const shared_ptr & other);

    // decrements the counter for the old raw pointer, assigns the new one from 'other'
    shared_ptr & operator=(const shared_ptr & other);

    // destructs underlying raw pointer if there're no other shared_ptr that owns it
    // otherwise decrements the counter
    ~shared_ptr();

    // releases stored pointer, replaces it with nullptr. 
    // counter is decremented, but raw pointer is not deleted (even if it was the last shared_ptr).
    T * release();

    // replaces current raw pointer with a new one
    // counter is decremented, raw pointer is deleted if it was the last shared_ptr
    void reset(T * other);

    // get the underlying raw pointer. counter is not changed
    T * get();

    // dereference underlying pointer
    T operator*();

    // returns underlying pointer in order to access one of its members
    T * operator->();

  private:
     // TODO: add fields
};

void test1() {
  shared_ptr<A> s1;
  shared_ptr<A> s2;
}

void test2() {
  // A!
  A * a = new A();
  shared_ptr<A> s1(a);
  shared_ptr<A> s2(s1);
  // ~A!
}

void test3() {
  // A!
  A * a = new A();
  shared_ptr<A> s1(a);
  shared_ptr<A> s2(a);
  // Error: double free!
}

void test4() {
  // A!
  A * a = new A();
  // A!
  A * a1 = new A();
  shared_ptr<A> s1(a);
  shared_ptr<A> s2(a1);
  // ~A!
  a1 = a;
  // ~A!
}

void test5() {
  // A!
  A * a = new A();
  shared_ptr<A> s1(a);
  s1.release();
  // memory leak: a is not destructed
}

void test6() {  
  // A!
  A * a = new A();
  shared_ptr<A> s1(a);
  // ~A!
  s1.reset(nullptr);
  // A!
  A * a1 = new A();
  shared_ptr<A> s2(a1);
  shared_ptr<A> s3(s2);
  s2.reset(nullptr);
  // Hello!
  std::cout << "Hello!" << std::endl;
  // ~A
}

void test7() {
  // A!
  A * a = new A();
  shared_ptr<A> s1(a);
  A * a1 = s1.get();
  // true
  std::cout << std::boolalpha << (a == a1) << std::endl;
  // ~A!
}

void test8() {
  // A!
  A * a = new A();
  shared_ptr<A> s1(a);
  // Acopy!
  A copy(*s1);
  // ~A!
}

void test9() {
  A * a = new A();
  shared_ptr<A> s1(a);
  s1->foo();
}

int main() {

  

  return 0;
}
