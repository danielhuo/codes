#include <cstdio>

template<typename T>
T Add(const T& a, const T& b)
{
    return (a+b);
}

// genernal
template<typename T>
class Vector
{
    public:
        Vector() { printf("template<typename T> class Vector\n"); };
};

// partcial specialization
template<typename T>
class Vector<T*>
{
    public:
        Vector() { printf("template<typename T> class Vector<T*>\n"); }
};

// complete specialization
template<>
class Vector<int*>
{
     public:
        Vector() { printf("template<> class Vector<int*>\n"); }
};

int main()
{
    Vector<int> vi;
    Vector<char*> vcp;
    Vector<int*> vip;
    Vector<int**> vipp;

    printf("%d\n", Add(1, 2));

    return 0;
}
