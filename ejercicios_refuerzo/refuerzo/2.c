#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    /* fork a child process */
    fork();
    /* fork another child process */
    fork();
    /* and fork another */
    fork();
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    //printf('pid %d \n', (int) getpid());
    return 0;
}
//debrian crearse 8 procesos