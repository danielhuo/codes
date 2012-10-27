#include <cstdio>
#include <memory>

int main()
{
    std::auto_ptr<int> p1(new int(1));
    std::auto_ptr<int> p2(p1);  // p1 is null

    std::auto_ptr<int> p3;
    p3 = p2;                    // p2 is null

    printf("%d\n", *p3);

    return 0;
}
