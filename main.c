#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#define DEBUG_MODE 1
#define debug(x) if(DEBUG_MODE) x

#define LENGTH 101

int main() {
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    uint8_t arr[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    register uint8_t i = 2;
    for (i; i < LENGTH; ++i)
        if (arr[i]) 
            for (uint16_t j = i * i; j < LENGTH; j += i) 
                arr[j] = 0;

    uint8_t buffer[1024];
    setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
    for (i = 2; i < LENGTH; ++i) 
        if (arr[i] && fprintf(stdout, "%d\n", i));

    gettimeofday(&stop, NULL);
    debug({
        printf("Finished in %fs\n", 
            (double)(stop.tv_usec - start.tv_usec) / 1000000 
            + (double)(stop.tv_sec - start.tv_sec));
    });

    return 0;
}
