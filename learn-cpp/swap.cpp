#include <cstdio>
#include <cstring>
#include <algorithm>

template<class T>
class Vector
{
    public:
        void swap(Vector<T>& v) {}
};

class Buffer
{
    public:
        Buffer(const char* s) {
            int slen = strlen(s);
            _buf = new char[slen + 1];
            strncpy(_buf, s, slen);
        }
        ~Buffer() { delete[] _buf; }

        const char* str() { return (const char*)_buf; }

        void swap(Buffer& b) {
            std::swap(_buf, b._buf);
        }
    private:
        char* _buf;
};

namespace std {
    template<>
    void swap<Buffer>(Buffer& f, Buffer& t) {
        f.swap(t);
    }

    template<>
    void swap(Vector<>& lhs, Vector<>& rhs) {
        lhs.swap(rhs);
    }
}

int main()
{
    Buffer s1("hello, world");
    Buffer s2("Welecome to Berlinix");
    std::swap(s1, s2);
    printf("%s\n", s1.str());
    printf("%s\n", s2.str());

   return 0; 
}

