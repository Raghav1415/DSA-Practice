int minMoves(int* nums, int numsSize) {
    long long k = 0;
    int mini = INT_MAX;

    for(int i=0; i<numsSize; i++){
        if(nums[i]<mini){
            mini = nums[i];
        }
    }

    for(int i=0; i<numsSize; i++){
        k = k + (nums[i] - mini);
    }

    return k;

}