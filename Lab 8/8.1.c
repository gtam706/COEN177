/* Name: Gautam Samudrala
# Date: 11/18/22
# Title: Lab8-Step 1
# Description: This programs generates a textfile
*/
#include <stdio.h>
#include <stdlib.h>

#define someNumber 10000
#define capNumber 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer [sizeof(int)];
    int i;
    fp = fopen("testInput.txt", "w");
    for (i=0; i<someNumber; i++){
        sprintf(buffer, "%d\n", rand()%capNumber);
        fputs(buffer, fp);
    }
    fclose(fp);
    return 0;
}