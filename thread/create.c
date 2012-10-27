#include <stdio.h>
#include <pthread.h>

void* thread1(void* arg)
{
    printf("start thread1\n");
    return ((void*)1);
}

void* thread2(void* arg)
{
    printf("start thread2\n");
    pthread_exit((void*)2);
}

int main()
{
    pthread_t tid1, tid2;
    void *tret;

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, &tret);
    printf("join thread1, return: %d\n", (int)tret);
    pthread_join(tid2, &tret);
    printf("join thread2, return: %d\n", (int)tret);

    return 0;
}
