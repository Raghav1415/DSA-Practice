int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize) {
    long long moves =0;
    qsort(nums, numsSize, sizeof(nums[0]), compare);

    int left = 0; int right = numsSize-1;

    int mid = left + ((right - left)/2);
    int median = nums[mid];

    for(int i=0; i<numsSize; i++){
        if((median - nums[i]) < 0){
            moves += (-1) * (median - nums[i]);
        }
        else{
            moves += median - nums[i];
        }
    }
    return moves;
}