#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void print() { i_print(); }
        virtual void i_print() { printf("base\n"); }
};

class Sub : public Base
{
    public:
        void print() { 
            Base::print();
            i_print();
        }
        void i_print() {
            printf("sub\n");
        }
};

int main()
{
    Base* p;
    p = new Sub();
    p->print();

    return 0;
}

