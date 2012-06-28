/*
 * bailing, 2010/01/20
 * study prctl(): set thread name
 *
 * to check the thread name
 * cat /proc/TID/task/TID/status | grep Name
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/types.h>

/* cannot use gettid(), defined it by syscall(SYS_gettid); */
unsigned long gettid() { return (unsigned long)syscall(SYS_gettid); }

void* func(void* arg)
{
    char* oname = "Thread Name by Berlin";
    char nname[64];
    prctl(PR_SET_NAME, (unsigned long)oname);
    prctl(PR_GET_NAME, (unsigned long)nname);
    printf("cat /proc/%lu/task/%lu/status | grep Name\n", gettid(), gettid());
    printf("prctl set name: %s(onamelen: %d, nnamelen: %d)\n", nname, strlen(oname), strlen(nname));

    while(1){
        sleep(1);
    }


    return (NULL);
}

int main()
{
    printf("pid: %d\n", getpid());

    pthread_t tid;
    pthread_create(&tid, NULL, func, NULL);
    pthread_join(tid, NULL);

    return 0;
}
