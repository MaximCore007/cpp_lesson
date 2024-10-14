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

class ClassicInit {
    /* Class witn initilization classic */
    unsigned int sz;
    SimpleClass *p;
    public:
    ClassicInit(unsigned int size);
    ~ClassicInit();
    void print_size() {
        printf("Size is %d\n", (int)sz);
    }
};

ClassicInit::ClassicInit(unsigned int num) {
    std::cout << "Call constructor. Traditional intilization" << std::endl;
    sz = num + 1;
    p = new SimpleClass(sz);
}

ClassicInit::~ClassicInit() {
    std::cout << "Call destructor. Traditional intilization" << std::endl;
    delete(p);
}

class DefInit {
    unsigned int sz;
    SimpleClass *pa;
    SimpleClass *pb;
    public:
    DefInit(unsigned int size);
    ~DefInit();
};

DefInit::DefInit(unsigned int size)
: pb((int)size), pa(size), sz(size)
{
    std::cout << "Call constructor. members intilization" << std::endl;
}

void f_init() {
    std::cout << "\nExample initialization:" << std::endl;
    InitClass A1(5);
    A1.print_size();
}

int main() {

    return 0;
}