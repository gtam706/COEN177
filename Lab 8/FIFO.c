/* Name: Gautam Samudrala
# Date: 11/18/22
# Title: Lab8-Step4
# Description: This program implements the FIFO page replacement algorithm
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int placeInArray = 0;
    int totalRequests = 0;

    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
        bool foundInCache = false;
        for (i=0; i<CACHE_SIZE; i++){
            if (cache[i].pageno == page_num){
                foundInCache = true;
                placeInArray = i;
                break; //break out loop because found page_num in cache  
            }
        }   
        if (foundInCache == false){
            //You may print the page that caused the page fault
            cache[placeInArray].pageno = page_num;
            totalFaults++;
            placeInArray = (placeInArray+ 1) % CACHE_SIZE; //Need to keep the value within the cacheSize
        }
        totalRequests += 1;

    }

    printf("%d Total Page Faults\n", totalFaults);
    printf("numMisses: %d\n", totalFaults);
    printf("numRequests: %d\n", totalRequests);
    double numMisses = totalFaults;
    double numRequests = totalRequests;
    double missRate = (numMisses / numRequests);
    double hitRate = 1 - missRate;
    printf("Hit Rate = %f\n\n", hitRate);
    return 0;



}
