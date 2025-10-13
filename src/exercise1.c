#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    float a[10];
    float sum = 0;
    float sr = 0;

    for(int i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
        sum = sum + a[i];
    }

    sr = sum / 10;
    printf("%.3f\n", sr);

    return 0;
}