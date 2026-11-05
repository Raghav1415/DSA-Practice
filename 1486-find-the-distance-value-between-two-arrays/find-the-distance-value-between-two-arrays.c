int compare(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x>y) return 1;
    if(x<y) return -1;
    return 0;
}
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {

    qsort(arr2,arr2Size,sizeof(arr2[0]),compare);
    int distance =0;

    for(int i =0; i<arr1Size; i++){
        int left =-1; int right = arr2Size;
        int num = arr1[i];
        bool found = false;

        while(right - left >1){
            int mid = left + (right - left)/2;
            if(abs(num - arr2[mid])<=d){
                found = true;
                break;
            }
            if(arr2[mid]<num) left = mid ;
            else right = mid ;
        }
        if(!found) ++distance;
    }
    return distance;
}
