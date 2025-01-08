#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sscal1.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s count\n", argv[0]);
        exit(1);
    }

    float factor = 2.0;
    int vec_size;
    sscanf("%d", argv[1], &vec_size);
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
}