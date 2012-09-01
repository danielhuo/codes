#include <iostream>
#include <cstring>

int isbn_cs(const char* isbn)
{
    const char* varr = "131313131313";
    const int len = 12;

    int sum = 0;
    for(int i = 0; i < len; ++i) {
        sum += (int(isbn[i] - '0') * int(varr[i] - '0'));
    }

    int checksum = 10 - sum % 10;

}

int main(int argc, const char** argv)
{
    if(argc != 2) {
        printf("usage: ./a.out isbn");
        return 0;
    }

    const char* isbn = argv[1]; 
    int checksum = isbn_cs(isbn);
    printf("%s-%d\n", isbn, checksum);

    return 0;
}
