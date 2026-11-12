int longestMonotonicSubarray(int* nums, int numsSize) {
    int inc =0;
    int dec =0;
    int before_inc = 0;
    int before_dec =0;

    for(int i=0; i<numsSize -1; i++){
        if(nums[i] < nums[i+1]){
            inc +=1;
            dec =0;
        }
        else if(nums[i]>nums[i+1]){
            dec +=1;
            inc =0;
        }
        else{
            inc =0;
            dec =0;
        }

        if(inc>before_inc) before_inc = inc;
        if(dec>before_dec) before_dec = dec;
    }

    return (before_inc > before_dec ? before_inc : before_dec) + 1;
}