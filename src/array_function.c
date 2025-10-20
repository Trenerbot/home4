#include "../include/array_function.h"

void join_int_arrays(int *src1, size_t size_src1, int *src2, size_t size_src2, int *dest) {
    int size_dest = size_src1 + size_src2;
    for (int i = 0; i < size_dest; i++) {
        dest[i] = src1[i];
        if(size_src1 < i + 1) {
            dest[i] = src2[i - size_src1];
        }
    }
}

void join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest) {
    int size_dest = size_src1 + size_src2;
    join_int_arrays(src1, size_src1, src2, size_src2, dest);
    for (int i = 0; i < size_dest - 1; i++) {
        for (int j = 0; j < size_dest - i - 1; j++) {
            if (dest[j] > dest[j + 1]) {
                int temp_dest = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp_dest;
            }
        }
    }
}

void get_min_and_max_from_int_array(int* src, size_t size, int* min, int* max) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if(src[j] > src[j + 1]) {
                int temp_dest = src[j];
                src[j] = src[j + 1];
                src[j + 1] = temp_dest;
            }
        }
    }
    *min = src[0];
    *max = src[size - 1];
}

