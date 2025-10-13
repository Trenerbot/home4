#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    float a[10];

    for(int i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }

    for(int j = 9; j >= 0; j--) {
        printf("%.3f ", a[j]);
    }
    return 0;
}