/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Left Pass: Calculate prefix products
    result[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Right Pass: Calculate suffix products and multiply on the fly
    int rightProduct = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * rightProduct;
        rightProduct = rightProduct * nums[i];
    }
    
    return result;
}