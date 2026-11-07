/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(nums1[0]),compare);
    qsort(nums2, nums2Size, sizeof(nums2[0]),compare);

    int size;
    if(nums1Size < nums2Size){
        size = nums1Size;
    }
    else{
        size = nums2Size;
    }

    int *result = malloc(size * sizeof(int));
    int k=0, i=0, j=0;

    while(i < nums1Size && j < nums2Size){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else {
            if(k==0 || result[k-1] != nums1[i]){
                result[k++] = nums1[i];
            }
            i++;
            j++;
        }
    }

    *returnSize = k;
    return result;
    
}