/*
 * berlinix, 2009/12/21
 * study ptrace()
 * simple example
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
//#include <linux/user.h>   /* ORIG_EAX, etc */
#include <asm/ptrace.h>     /* ORIG_EAX, or <sys/reg.h>, not <linux/user.h> */

int main()
{
    pid_t cpid;
    long orig_eax;

    cpid = fork();
    if(cpid == 0){
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl("/bin/ls", "ls", NULL);
    }
    else{
        wait(NULL); /* for ptrace */

        orig_eax = ptrace(PTRACE_PEEKUSER, cpid, 4 * ORIG_EAX, NULL);
        printf("\n+++ the child made a system call: %ld +++\n", orig_eax);
        ptrace(PTRACE_CONT, cpid, NULL, NULL);

        wait(NULL); /* for child process */
        printf("\n+++ parent exit +++\n");
    }

    return 0;
}
