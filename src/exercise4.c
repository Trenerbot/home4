#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    float a[10];
    float b[10];
    float c[10];
    float x = atoi(argv[1]);
    int k = atoi(argv[2]);

    if(k >= 10 || k < 0) {
        return 1;
    }

    for(int i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }

    for(int i = 0; i < 10; i++) {
        c[i] = a[i];
    }

    for(int i = 0; i < k; i++) {
        b[i] = a[i];
    }

    for(int i = 9; i > k; i--) {
        b[i] = c[i - 1];
    }

    b[k] = x;

    for(int i = 0; i < 10; i++) {
        printf("%.0f ", b[i]);
    }

    return 0;
}