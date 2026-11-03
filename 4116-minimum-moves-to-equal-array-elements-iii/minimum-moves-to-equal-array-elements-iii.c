int minMoves(int* nums, int numsSize) {
    long long moves =0;
    int max = INT_MIN;

    for(int i=0; i<numsSize; i++){
        if (nums[i]> max){
            max = nums[i];
        }
    }

    for(int i =0; i<numsSize; i++){
        moves += max - nums[i];
    }

    return moves; 
}