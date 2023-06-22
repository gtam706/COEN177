/* Name: Gautam Samudrala
# Date: 10/7/22
# Title: Lab2-Step 5
# Description: This program runs 7 processes at time.
*/
#include <stdio.h>     /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[])
{
    pid_t pid, pid_1, pid_2, pid_3, pid_4;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    if (pid)
    {
        printf("Parent process 1 \n");
        pid_1 = fork();
        if (pid_1 == -1)
        {
            fprintf(stderr, "can't fork, error %d\n", errno);
        }
        if (pid_1)
        {
            printf("\t Child process 1 \n");
            usleep(n);
        }
        else
        {
            pid_3 = fork();
            if (pid_3 == -1)
            {
                fprintf(stderr, "can't fork, error %d\n", errno);
            }
            if (pid_3)
            {
                printf("\t \t Child process 3  \n");
                usleep(n);
            }
            else
            {
                printf("\t \t Child process 4  \n");
            }
        }
    }
    else
    {
        pid_2 = fork();
        if (pid_2 == -1)
        {
            fprintf(stderr, "can't fork, error %d\n", errno);
        }
        if (pid_2)
        {
            printf("\t Child process 2 \n");
            usleep(n);
        }
        else
        {
            pid_4 = fork();
            if (pid_4 == -1)
            {
                fprintf(stderr, "can't fork, error %d\n", errno);
                
            }
            if (pid_4)
            {
                printf("\t \t Child process 5 \n");
                usleep(n);
            }
            else
            {
                printf("\t \t Child process 6 \n");
            }
        }
    }
    return 0;
}