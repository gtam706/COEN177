// # Name: Gautam Samudrala
// # Date: 10/28/22, Thursday 5:15 PM
// # Title: Lab5 - 
// # Description: This program implements the consumer/producer problem using semaphores for thread synchronization.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>

pthread_t threads[2];
int out, in;
sem_t *mutex;
sem_t *empty;
sem_t *full;
int buff[10];

void *producer() {
    int item;
    do {                                
    	item = rand() % 10;             
    	printf("Produced Item %d\n", item);
        sleep(1);                  
    	sem_wait(empty);           
    	sem_wait(mutex);                // Critical section start
    	buff[in] = item;         
    	in = (in+1)%10;            
	sem_post(mutex);                // Critical section end
    	sem_post(full);

    } while(1); 
}

void *consumer() {
    int item;
    do {                             
    	sem_wait(full);              
    	sem_wait(mutex);                // Critical section start
    	item = buff[out];            
    	out = (out+1)%10;               
    	sem_post(mutex);                // Critical section end
    	sem_post(empty);                      
    	printf("\tConsuming Item %d\n", item);
        sleep(1);                  
    } while(1); 
}

int main() {
    
    out = 0;
    in = 0;
  
    sem_unlink("mutex2");
    sem_unlink("empty2");
    sem_unlink("full2");
    
    mutex = sem_open("mutex2", O_CREAT, 0644, 1);
    empty = sem_open("empty2", O_CREAT, 0644, 10);
    full = sem_open("full2", O_CREAT, 0644, 0);
    
    pthread_create(&threads[0], NULL, producer, NULL);
    
    pthread_create(&threads[1], NULL, consumer, NULL);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
 
    return 0;
}
