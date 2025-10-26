#include "../include/advanced_array_function.h"
#include <stdio.h>
#include <stdlib.h>

int max_subarray_sum(int* nums, int size) {
    int res;
    if(size == 0) { 
        res = 0;
        return res;
    }
    res = nums[0];
    int temp_res = 0;
    for(int a = 0; a < size; a++){
        temp_res += nums[a];
        if(res < temp_res){
            res = temp_res;
        }
        if(temp_res < res){
            int mega_temp_res = 0;
            for(int k = a; k < size; k++){
                mega_temp_res += nums[k];
                if(res < mega_temp_res){
                    res = mega_temp_res;
                }
            }
        }
    }
    return res;
}


int length_of_lis(int* nums, int numsSize) {
    int flug = 1;
    int temp_flug = 1;
    if(numsSize == 0){
        flug = 0;
        return flug;
    }
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] < nums[i + 1]){
            temp_flug++;
            if(flug < temp_flug){
                flug  = temp_flug;
            }
        }
        else {
            temp_flug = 1;
        }
    }
    return flug;
}


int* merge(int* intervals, int intervalsSize, int* returnSize) {
    intervalsSize *=2;
    if (intervalsSize == 0 || intervals == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int temp_array_a[2][intervalsSize / 2];
    int temp_array_res[2][20] = {0};
    for(int i = 0; i < intervalsSize; i += 2){
        temp_array_a[0][i / 2] = intervals[i];
        temp_array_a[1][i / 2] = intervals[i + 1];
    }
    for(int i = 0; i < intervalsSize/2; i++){
        for(int a = 0; a < (intervalsSize/2) - i - 1; a++){
            if( temp_array_a[0][a] > temp_array_a[0][a + 1]){
            int temp_sort_up = temp_array_a[0][a];
            int temp_sort_dwn = temp_array_a[1][a];
            temp_array_a[0][a] = temp_array_a[0][a + 1];
            temp_array_a[1][a] = temp_array_a[1][a + 1];
            temp_array_a[1][a + 1] = temp_sort_dwn;
            temp_array_a[0][a + 1] = temp_sort_up;
            }
        }
    }
    temp_array_res[0][0] = temp_array_a[0][0];
    temp_array_res[1][0] = temp_array_a[1][0];
    int flag = 0;
    for(int i = 1; i < intervalsSize/2 ; i++){
        printf("i = %d\n", i);
        if(temp_array_res[1][flag] >= temp_array_a[0][i]){ 
            if(temp_array_a[1][i] > temp_array_res[1][flag]){
                temp_array_res[1][flag] = temp_array_a[1][i];
            }
        }
        else {
            flag++;
            temp_array_res[0][flag] = temp_array_a[0][i];
            temp_array_res[1][flag] = temp_array_a[1][i];
        }
    }
    flag++;
    int* res = (int*)malloc(flag * 2 *sizeof(int));
    for(int i = 0; i < flag; i++){
        res[2 * i] = temp_array_res[0][i];
        res[2 * i + 1] = temp_array_res[1][i];
    }
    *returnSize = flag;
    return res;
}