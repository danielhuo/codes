/* 
 * berlinix
 * don't change main(), 
 * print "initialize" before hello and "cleanup" after hello 
 */

#include <iostream>
#include <string>

class A {
    public:
        A() { printf("construct A\n"); }
};

class B {
    A _a;
};

class C : public B {};

int main()
{
    C c;

    return 0;
}
