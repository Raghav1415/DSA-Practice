#include <limits.h>

int maxSubArray(int* nums, int numsSize) {

    int current = 0;
    int global = INT_MIN;

    for (int i =0; i <numsSize; i++){
        current = current + nums[i];

        if(current > global){
            global = current;
        }

        if(current <0){
            current =0;
        }
    }

    return global;
}