/*
# Name: Gautam Samudrala
# Date: 10/14/22
# Title: Lab3-Step 5
# Description: This program implements the producer-consumer message communication
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   char buffer[60];
   int count;
   int n = atoi(argv[1]);
   int i;
   pipe(fds);
   
   if (fork()==0){
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[0]);
        printf("Enter message \n");
        scanf("%s",buffer);
        write(fds[1],buffer,strlen(buffer));
       exit(0);
   }
   else if(fork()==0){
       close(fds[1]);
       while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);
           }
           printf("\n");
       }
       exit(0);
    }
   else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
