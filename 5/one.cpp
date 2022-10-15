// какие из методов test() скомпилируются?
class A {
    friend class B;
    void test(A& a) {
        a.i_++;
    }
 private:
   int i_;
};

class B {
    friend class C;
    void test(A& a) {
        a.i_++;
    }
};

class C {
    friend class B;
    friend class A;
    void test(A & a) {
        a.i_++;  // error
    }
};

