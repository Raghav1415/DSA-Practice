/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *final = (int*)calloc((digitsSize +1),sizeof(int));

    for(int i =0; i<digitsSize; i++){
        final[i] = digits[i];
    }

    for(int i = digitsSize -1; i>=0;i--){
        if(final[i]!=9){
            final[i] +=1;
            *returnSize = digitsSize;
            return final;
        }
        else{
            final[i]=0;
        }
    }
    final[0] =1;
    *returnSize = digitsSize +1;
    return final;
}