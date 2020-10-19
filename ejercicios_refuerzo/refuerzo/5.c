#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid1;
    /* fork a child process */
    pid = fork();
    //padre x, hijo y
    //x = 2600 y = 2603
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) { /* child process */
        pid1 = getpid(); //pid1 y
        printf("child: pid = %d\n",pid); /* A */ //0
        printf("child: pid1 = %d\n",pid1); /* B */ // y
    }
    else { /* parent process */
        pid1 = getpid(); //pid1 = x
        printf("parent: pid = %d\n",pid); /* C */ // y
        printf("parent: pid1 = %d\n",pid1); /* D */ //x
        wait(NULL);
    }
    return 0;
}