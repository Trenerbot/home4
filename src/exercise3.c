#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    float a[10];
    float b[10];
    float c[10];
    int k = atoi(argv[1]);
    k = k % 10;

    if(k < 0) {
        k = k + 10;
    }

    for(int i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }

    for(int i = 0; i < 10; i++) {
        b[(i + k) % 10] = a[i];
    }

    for(int i = 0; i < 10; i++) {
        c[i] = b[i];
    }
    
    for(int i = 0; i < 10; i++) {
        printf("%.3f ", c[i]);
    }
    return 0;
}