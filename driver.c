#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sscal1.h"

#define COUNT 100
#define TIME 5000000000

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s COUNT\n", argv[0]);
        exit(1);
    }

    float factor = 2.0;
    int vec_size;
    sscanf(argv[1], "%d", &vec_size);
    printf("%s: vec_size: %d\n", argv[0], vec_size);
    float *vec = (float *)malloc(sizeof(float) * vec_size);
    for(int i = 0; i < vec_size; i++) {
        vec[i] = (float)i;
    }
    sscal1(factor, vec, vec_size);
    for(int i = 0; i < vec_size; i++) {
        if(fabs(vec[i] - factor * i) > 0.0000001) {
            printf("%d differ (%f).\n", i, vec[i]);
        }
    }

    uint64_t time = 0;
    uint64_t count = 0;
    float *v[COUNT];
    for(int i = 0; i < COUNT; i++) {
        v[i] = (float *)malloc(sizeof(float) * vec_size);
    }
    do {
        for(int i = 0; i < COUNT; i++) {
            for(int j = 0; j < vec_size; j++) {
                v[i][j] = (float)j;
            }
        }
        uint64_t before = clock_gettime_nsec_np(_CLOCK_REALTIME);
        for(int i = 0; i < COUNT; i++) {
            sscal1(factor, v[i], vec_size);
        }
        uint64_t after = clock_gettime_nsec_np(_CLOCK_REALTIME);
        time += after - before;
        count++;
    } while (time < TIME);

    printf("time: %llu (nano sec)\n", time);
    printf("count: %llu\n", count);
    printf("IPS: %lf (giga)\n", (double)count / time * COUNT);
    printf("average: %lf (nano sec)\n", (double)time / count / COUNT);
}