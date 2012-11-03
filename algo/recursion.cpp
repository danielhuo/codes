#include <cstdio>

int factorial(int n)
{
    if(n == 0) return 1;
    return (n * factorial(n-1));
}

int fib(int n)
{
    if(n == 0 or n == 1) return n;
    return (fib(n - 1) + fib(n - 2));
}

int factorial2(int n)
{
    int ret = 1;
    for(int i = n; i > 0; --i) {
        ret *= i;
    }
    return ret;
}

int fib2(int n)
{
    if(n == 0 or n == 1) return n;

    int j = 0, k = 1, ret = 0;
    for(int i = 2; i < n+1; ++i) {
        ret = j + k;
        j = k;
        k = ret;
    }
    return ret;
}

void hanoi(int n, char from, char aux, char to)
{
    if(n == 1) {
        printf("move disk %d from %c to %c\n", n, from, to);
        return ;
    }

    /* move n-1 disk FROM from TO aux HELPED BY to */
    hanoi(n-1, from, to, aux);

    /* move disk n FROM from TO to directly */
    printf("move disk %d from %c to %c\n", n, from, to);

    /* move n-1 disk FROM aux TO to HELPED BY from */
    hanoi(n-1, aux, from, to);
}

int main()
{
    printf("%d, %d, %d, %d\n", factorial(10), factorial(11), factorial(12), factorial(13));
    printf("%d, %d, %d, %d\n", factorial2(10), factorial2(11), factorial2(12), factorial2(13));
    printf("%d, %d, %d, %d\n", fib(10), fib(20), fib(30), fib(40));
    printf("%d, %d, %d, %d\n", fib2(10), fib2(20), fib2(30), fib2(40));

    hanoi(4, 'A', 'B', 'C');

    return 0;
}
