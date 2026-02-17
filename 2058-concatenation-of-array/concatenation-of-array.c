/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    *returnSize = 2 * n;

    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    if (ans == NULL) return NULL;

    for (int i=0; i<n;i++){
        ans[i] = nums[i];
        ans[i+n]= nums[i];
    }
    return ans;
    
}