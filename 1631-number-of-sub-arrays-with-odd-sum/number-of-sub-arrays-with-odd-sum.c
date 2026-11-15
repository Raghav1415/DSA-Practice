int numOfSubarrays(int* arr, int arrSize) {
    long long mod = 1000000007LL;

    long long prefix =0;
    long long odd =0;

    for(int i=0; i<arrSize; i++){
        prefix += arr[i];

        if(prefix % 2 != 0){
            odd++;
        }
    }

    return ((odd * (arrSize - odd + 1))%mod);
}