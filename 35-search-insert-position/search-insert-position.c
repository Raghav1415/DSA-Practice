int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize<0) return -1;
    int left = 0;
    int right = numsSize-1;
    int mid;
    while (left<=right){
        mid = left + ((right - left)/2);

        if(nums[mid] == target){
            return mid;
        }
        else if(target < nums[mid]){
            right--;
        }
        else if(target > nums[mid]){
            left++;
        }
    }
    return left;
}