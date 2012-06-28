/*
 * bailing, 2009/07/13
 *
 * test non-atomic access
 * codes from http://www.delorie.com/gnu/docs/glibc/libc_495.html
 */

#include <signal.h>
#include <stdio.h>

struct two_words { int a; int b; } memory;

void handler(int signo)
{
    printf("in handler: %d, %d\n", memory.a, memory.b); // N.B.: use printf in signal handler is dangerous
    alarm(1);
}

int main()
{
    static struct two_words zeros = {0, 0};
    static struct two_words ones = {1, 1};

    memory = zeros;

    signal(SIGALRM, handler);
    alarm(1);

    while(1){
        memory = zeros;
        memory = ones;
    }

    return 0;
}
