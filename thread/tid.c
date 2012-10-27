#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>

void* thread(void* arg)
{
    printf("new thread, pthread_self() return: %u\n", (unsigned int)pthread_self());
    printf("new thread, getpid() return: %u\n", (unsigned int)getpid());
    printf("new thread, syscall() return: %u\n", (unsigned int)syscall(SYS_gettid));
    sleep(60);
    pthread_exit((void*)0);
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, thread, NULL);
    printf("main get pthread id: %u\n", (unsigned int)tid);
    printf("main getpid: %u\n", (unsigned int)getpid());
    pthread_join(tid, NULL);

    return 0;
}
