/* Example with constant and static modifiers */
#include <iostream>

class SimpleClass {
    int value;
    public:
    SimpleClass(int num = 0) {
        std::cout << "Constructor SimpleClass" << std::endl;
        value = num;
    }
    ~SimpleClass() {
        std::cout << "Destructor SimpleClass" << std::endl;
    }
    void print_value() {
        std::cout << "SimpleClass: value is " << value << std::endl;
    }
};

class ConstClass {
    /* Class with constant modifier */
    int value;
public:
    ConstClass(int num = 1) {
        std::cout << "Constructor ConstClass" << std::endl;
        value = num;
    }
    ~ConstClass() {
        std::cout << "Destructor ConstClass" << std::endl;
    }
    void read() const {
        printf("Read from read is %d\n", value);
    }

    void read_cheat() const {
        int a = ((ConstClass*)this)->value + 1;
        printf("Read from read_cheat is %d\n", a);
    }

    void write_value(int num) {
        value = num;
    }
};

void f_const() {
    std::cout << "\nExample with a constant variable:" << std::endl;
    ConstClass C1(5);
    C1.read();
    C1.read_cheat();
}

class StaticClass {
    /* Class with static modifier */
    static SimpleClass A;
    static int count;
    public:
    StaticClass() {
        std::cout << "Constructor StaticClass_" << ++count << std::endl;
    }
    ~StaticClass() {
        std::cout << "Destructor StaticClass_" << count-- << std::endl;
    }
    static void func_static() {
        std::cout << "Call func. in StaticClass; No. of classes " << count << std::endl;
    }
};

void f_static_func() {
    std::cout << "\nExample with static function:" << std::endl;
    StaticClass::func_static();
}

void f_static() {
    std::cout << "\nExample with static variables:" << std::endl;
    StaticClass S1, S2, S3;
    S1.func_static();
    S2.func_static();
    S3.func_static();
}

SimpleClass StaticClass::A;
int StaticClass::count = 0;


int main(void)
{
    f_const();

    f_static();
    f_static_func();

    return 0;
}