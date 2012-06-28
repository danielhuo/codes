/*
 * berlinix, 2009/12/21
 * study ptrace()
 * reverse string passed to the write()
 * some bugs? calloc/malloc
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/syscall.h>    /* for SYS_write, etc  */
#include <asm/ptrace.h>
#include <linux/user.h>     /* for struct user_regs_struct{}; */

#define LONG_SZ sizeof(long)

union _data{
    long val;
    char data[LONG_SZ];
};

void reverse(char* str);
void get_data(pid_t pid, long addr, char* str, int len);
void put_data(pid_t pid, long addr, char* str, int len);

int main()
{
    pid_t cpid;

    cpid = fork();
    if(cpid == 0){
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl("/bin/ls", "ls", NULL);
    }
    else{
        long orig_eax;
        long params[3];
        int status;
        char* str, *laddr;
        int toggle = 0;

        while(1){
            wait(&status);
            if(WIFEXITED(status)){
                break;
            }

            orig_eax = ptrace(PTRACE_PEEKUSER, cpid, 4 * ORIG_EAX, NULL);
            if(orig_eax == SYS_write){
                if(0 == toggle){
                    toggle = 1;

                    params[0] = ptrace(PTRACE_PEEKUSER, cpid, 4 * EBX, NULL);
                    params[1] = ptrace(PTRACE_PEEKUSER, cpid, 4 * ECX, NULL);
                    params[2] = ptrace(PTRACE_PEEKUSER, cpid, 4 * EDX, NULL);

                    //printf("\n--- strlen: %d ---\n", params[2]);
                    //str = (char*)calloc((params[2]+1) * sizeof(char), 0);     /* why? */
                    str = (char*)malloc((params[2]+1) * sizeof(char));
                    memset(str, 0, params[2]+1);

                    get_data(cpid, params[1], str, params[2]);  /* p[1] -> str */
                    reverse(str);
                    put_data(cpid, params[1], str, params[2]);  /* str -> p[1] */

                    if(str != NULL) free(str);
                }
                else{
                    toggle = 0;
                }
            }
            ptrace(PTRACE_SYSCALL, cpid, NULL, NULL);
        }
    }

    return 0;
}

void reverse(char* str)
{
    int i, j;
    char tmp;

    for(i = 0, j = strlen(str) - 1; i < j; ++i, --j){
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void get_data(pid_t pid, long addr, char* str, int len)
{
    char* laddr = str;
    int i = 0;
    int j = len/LONG_SZ;
    union _data d;

    while(i < j){
        d.val = ptrace(PTRACE_PEEKDATA, pid, addr + i * 4, NULL);
        memcpy(laddr, d.data, LONG_SZ);
        ++i;
        laddr += LONG_SZ;
    }

    j = len % LONG_SZ;
    if(0 != j){
        d.val = ptrace(PTRACE_PEEKDATA, pid, addr + i * 4, NULL);
        memcpy(laddr, d.data, LONG_SZ);
    }
    str[len] = '\0';
}

void put_data(pid_t pid, long addr, char* str, int len)
{
    union _data d;
    int i = 0;
    int j = len/LONG_SZ;
    char* laddr = str;

    while(i < j){
        memcpy(d.data, laddr, LONG_SZ);
        ptrace(PTRACE_POKEDATA, pid, addr + i * 4, d.val);
        ++i;
        laddr += LONG_SZ;
    }

    j = len % LONG_SZ;
    if(0 != j){
        memcpy(d.data, laddr, j);
        ptrace(PTRACE_POKEDATA, pid, addr + i * 4, d.val);
    }
}

