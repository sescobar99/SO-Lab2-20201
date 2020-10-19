#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <assert.h>

int main(int argc, char *argv[]) {

    struct timeval start,end;
    pid_t rc = fork();
    gettimeofday(&start,NULL);
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        
        // exec()
        char *myargs[2];
        for (int i = 1; i < argc; i++){
            myargs[i-1] = argv[i];

        }
            myargs[argc-1] = NULL; // mark end of array
        execvp(myargs[0], myargs); // runs word count
   
        
    } else { // parent goes down this path (main)
        assert(wait(NULL) >= 0);
        
        //tomar tiempo
        gettimeofday(&end, NULL);
        long int  elapsed_time = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        printf("Time : %ld micro seconds\n", elapsed_time);
    }
    return 0;
}
