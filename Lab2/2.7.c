/* Name: Gautam Samudrala
# Date: 10/7/22
# Title: Lab2-Step 7
# Description: Programs runs ls before parent continues running
*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    else if (pid == 0){
        execlp("/bin/ls", "ls", NULL);
    }
    else {
        wait(NULL);
        printf("Child Complete\n\n");
        exit(0);
    }
    return 0;
}