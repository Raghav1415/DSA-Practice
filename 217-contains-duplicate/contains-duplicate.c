int compare(const void *a, const void *b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x<y) return -1;
    if (x>y) return 1;
    return 0;
    
}


bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(nums[0]),compare);
    bool value = false;

    for(int i=1; i<numsSize; i++){
        if(nums[i] == nums[i-1]){
            value = true;
        }
    }
    
    return value;
}