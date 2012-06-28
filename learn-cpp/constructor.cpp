/* 
 * berlinix
 * don't change main(), 
 * print "initialize" before hello and "cleanup" after hello 
 */

#include <iostream>

struct constr {
    constr()    { std::cout << "initialize\n"; }
    ~constr()   { std::cout << "cleanup\n"; }
} c;

int main()
{
    std::cout << "hello berlinix!\n";
    return 0;
}
