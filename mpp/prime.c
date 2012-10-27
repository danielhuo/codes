#include <stdio.h>
#include <math.h>

int root(int n)
{
    return ((int)sqrt((float)n));
}

int prime(int n)
{
    if(n % 2 == 0) return (n == 2);
    if(n % 3 == 0) return (n == 3);
    if(n % 5 == 0) return (n == 5);

    int bound = root(n);
    for(int i = 7; i <= bound; i += 2) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 1000;
    for(int i = 2; i <= n; ++i) {
        if(prime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
