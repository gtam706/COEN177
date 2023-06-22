// # Name: Gautam Samudrala
// # Date: 10/28/22, Thursday 5:15 PM
// # Title: Lab5 - Producer/Consumer using Semaphores
// # Description: This program implements the consumer/producer problem using condition variables for thread synchronization.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>

pthread_t threads[2];
int out, in;
pthread_mutex_t lock;
pthread_mutex_t empty;
pthread_mutex_t full;
int buff[10];

void *producer() {
    int item;
    do {                                
    	item = rand() % 10;             
    	printf("Produced Item %d\n", item);
        sleep(1);
	pthread_mutex_lock(&empty);                  
    	pthread_mutex_lock(&lock);                // Critical section start
    	buff[in] = item;         
    	in = (in+1)%10;            
	pthread_mutex_unlock(&lock);                // Critical section end
    	pthread_mutex_unlock(&full);

    } while(1); 
}

void *consumer() {
    int item;
    do {                             
    	pthread_mutex_lock(&full);              
    	pthread_mutex_lock(&lock);                // Critical section start
    	item = buff[out];            
    	out = (out+1)%10;               
    	pthread_mutex_unlock(&lock);                // Critical section end
    	pthread_mutex_unlock(&empty);                      
    	printf("\tConsuming Item %d\n", item);
        sleep(1);                  
    } while(1); 
}

int main() {
    
    out = 0;
    in = 0;
    
    if (pthread_mutex_init(&lock, NULL) != 0 || pthread_mutex_init(&empty, NULL) != 0 || pthread_mutex_init(&full, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
    pthread_mutex_lock(&full);

    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
 
    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&empty);
    pthread_mutex_destroy(&full);

    return 0;
}
