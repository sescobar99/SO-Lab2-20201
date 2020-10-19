#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    // printf("hello world (pid:%d)\n", (int) getpid());
    printf("hello world");
    
    for (i = 0; i < 4; i++){
        fork();//fork();
        printf("i: %d ,pid: %d\n",i, (int) getpid());
        
    }
    return 0;
}
