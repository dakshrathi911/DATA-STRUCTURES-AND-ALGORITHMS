#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomArray[1000];
    
    // Initialize random number generator
    srand(time(0));

    // Generate random numbers between 1 and 1000
    for(int i = 0; i < 1000; i++) {
        randomArray[i] = rand() % 1000 + 1;
    }

    // Print the random array
    for(int i = 0; i < 1000; i++) {
        printf("%d ,", randomArray[i]);
    }

    return 0;
}