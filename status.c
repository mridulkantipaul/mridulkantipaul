#include "kernel/types.h"
#include "user/user.h"
#include "kernel/pstat.h"
int main(int argc, char *argv[])
{
    struct pstat ps;
    // names of system calls for printing purposes
    char *syscall_names[N_SYSCALLS] = {
        "",
        "fork",
        "exit",
        "wait",
        "pipe",
        "read",
        "kill",
        "exec",
        "fstat",
        "chdir",
        "dup",
        "getpid",
        "sbrk",
        "pause",
        "uptime",
        "open",
        "write",
        "mknod",
        "unlink",
        "link",
        "mkdir",
        "close",
        "proc_status"
    };



    if(proc_status((uint64)&ps) < 0){
        printf("Error: proc_status failed\n");
        exit(1);
    }

    printf("PID: %d\n", ps.pid);
    printf("Turnaround Time: %d\n", ps.turnaround);
    printf("System Call Counts:\n");
    for(int i = 1; i < N_SYSCALLS; i++) {
        if(ps.syscall_count[i] > 0) {
        printf("Syscall name %s: %d\n", syscall_names[i], ps.syscall_count[i]);
        }
    }
}