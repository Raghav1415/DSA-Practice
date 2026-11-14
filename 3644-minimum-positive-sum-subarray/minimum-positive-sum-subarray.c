int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int min_sum = INT_MAX;

    for(int i =l; i<=r; i++){
        int sum =0;

        for(int j =0; j<i; j++){
            sum += nums[j];
        }

        if(sum >0 && sum < min_sum){
            min_sum = sum;
        }

        for(int k =i; k<numsSize; k++){
            sum += nums[k] - nums[k-i];

            if(sum >0 && sum < min_sum){
                min_sum = sum;
            }
        }
    }

    return min_sum == INT_MAX ? -1 : min_sum;
}