/* Name: Gautam Samudrala
# Date: 11/18/22
# Title: Lab8-Step4
# Description: This program implements the LRU page replacement algorithm
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {//to 
    int pageno;
    int age;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int totalRequests = 0;
    int temp;
    int oldest;
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
         cache[i].age = -1;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
        bool foundInCache = false;
        for(i = 0; i < CACHE_SIZE; i++){
            temp = 0;
            oldest = cache[i].age;
            if(cache[i].pageno == page_num){
                for(int j = 0; j < CACHE_SIZE; j++){
                    if(cache[j].age < cache[i].age){
                        cache[j].age++;
                    }
                }
                foundInCache = true;
                cache[i].age = 0;
                break;
            }
            for(int j = 0; j < CACHE_SIZE; j++){
                cache[j].age++;
            }
        }
        if(foundInCache == false){
            for(int j = 0; j <CACHE_SIZE; j++){
                if(oldest < cache[j].age){
                    temp = j;
                    oldest = cache[j].age;
                }
            }
            cache[temp].pageno = page_num;
            cache[temp].age = 0 ;
            totalFaults++;

        }
        totalRequests++;
    }


    printf("%d Total Page Faults\n", totalFaults);
    printf("numMisses: %d\n", totalFaults);
    printf("numRequests: %d\n", totalRequests);
    double numMisses = totalFaults;
    double numRequests = totalRequests;
    double missRate = (numMisses/ numRequests);
    double hitRate = 1 - missRate;
    printf("Hit Rate = %f\n\n", hitRate);
    return 0;
}
