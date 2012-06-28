/*
 * berlinix, 2009/12/21
 * study ptrace()
 * 1. reading system call parameters
 * 2. reading register values
 */

#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/syscall.h>    /* for SYS_write, etc  */
#include <asm/ptrace.h>
#include <linux/user.h>     /* for struct user_regs_struct{}; */

int main()
{
    pid_t cpid;
    long orig_eax, eax;
    long params[3];
    int status;
    struct user_regs_struct regs;
    int insyscall = 0;

    cpid = fork();
    if(cpid == 0){
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl("/bin/ls", "ls", NULL);
    }
    else{
        while(1){
            wait(&status);
            if(WIFEXITED(status)){
                break;
            }

            orig_eax = ptrace(PTRACE_PEEKUSER, cpid, 4 * ORIG_EAX, NULL);
            if(orig_eax == SYS_write){
                if(insyscall == 0){     /* syscall entry */
                    insyscall = 1;

                    /* read write() parameters */
                    params[0] = ptrace(PTRACE_PEEKUSER, cpid, 4 * EBX, NULL);
                    params[1] = ptrace(PTRACE_PEEKUSER, cpid, 4 * ECX, NULL);
                    params[2] = ptrace(PTRACE_PEEKUSER, cpid, 4 * EDX, NULL);
                    printf("\n+++ write called with %ld, %x, %ld +++\n",    /* todo: %x ? */
                            params[0], (unsigned long)params[1], params[2]);

                    /* read registers: %ebx, %ecx, %edx */
                    ptrace(PTRACE_GETREGS, cpid, NULL, &regs);
                    printf("\n--- write called with registers: %ld, %x, %ld ---\n", /* todo: %x ? */
                            regs.ebx, regs.ecx, regs.edx);

                }
                else{   /* syscall exit */
                    eax = ptrace(PTRACE_PEEKUSER, cpid, 4 * EAX, NULL);
                    printf("\n+++ write return with %ld +++\n", eax);
                    insyscall = 0;
                }
            }
            ptrace(PTRACE_SYSCALL, cpid, NULL, NULL);
        }
    }

    return 0;
}
