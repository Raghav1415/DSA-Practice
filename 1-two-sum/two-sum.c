#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int value;
    int index;
}Items;

int compare(const void* a, const void* b){
    return (((Items*)a)-> value - ((Items*)b) -> value);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Items *indices = (Items*)malloc(numsSize * sizeof(Items));

    for(int i =0; i<numsSize; i++){
        indices[i].value = nums[i];
        indices[i].index = i;
    }

    qsort(indices, numsSize, sizeof(Items), compare);

    int left = 0;
    int right = numsSize - 1;

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    while(left<right){
        int sum = indices[left].value + indices[right].value;

        if (sum == target){
            result[0] = indices[left].index;
            result[1] = indices[right].index;
            free(indices);
            return result;
        }
        else if(sum < target){
            left++;
        }
        else if(sum > target){
            right--;
        }
    }
    free(indices);
    *returnSize = 0;
    return NULL;
}
