/* Name: Gautam Samudrala
# Date: 10/7/22
# Title: Lab2-Step 6
# Description: Program uses threads instead of processes
*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
#include <pthread.h>
/* main function with command-line arguments to pass */
void *parent(int x){
    for (int i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n",i);
            usleep(x);
        }
        pthread_exit(NULL);
}

void *child(int x){
    for (int i=0;i<100;i++) {
            printf("Child process %d\n",i);
            usleep(x);
        }
        pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    pthread_t parentThread, childThread;
    i = pthread_create(&parentThread, NULL, parent, n);
    i = pthread_create(&childThread, NULL, child, n);


    pthread_exit(NULL);
    return 0;
}