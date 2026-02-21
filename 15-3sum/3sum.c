/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    // 1. Sort the array to handle duplicates and use two pointers
    qsort(nums, numsSize, sizeof(int), compare);

    // Initial allocation for result array
    int capacity = 1000; 
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // Found a triplet
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Resize result array if needed
                if (*returnSize == capacity) {
                    capacity *= 2;
                    res = (int**)realloc(res, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Skip duplicates for the second and third elements
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++; // We need a larger value
            } else {
                right--; // We need a smaller value
            }
        }
    }
    return res;
}