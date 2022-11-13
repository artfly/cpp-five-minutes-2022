// что выведет эта программа?
#include <iostream>

class Command {
 public:
    virtual void apply() {
        std::cout << "Base command apply!" << std::endl;
    }
};

class Sub: public Command {
 public:
    void apply() override {
        std::cout << "Sub apply!" << std::endl;
    }
};

int main(int argc, char const *argv[]) {
    Sub sub = Sub();
    Command * cmd1 = &sub;
    cmd1->apply();
    Command cmd2(sub);
    cmd2.apply();
    Command & cmd3 = sub;
    cmd3.apply();
    return 0;
}
