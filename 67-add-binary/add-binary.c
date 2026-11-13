char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) -1;
    int carry = 0;
    int ind =0;

    char *result = (char*)malloc(fmax(i,j) + 10);

    while(i>=0 || j>=0 || carry==1){
        int digit1 =0, digit2 =0;
        if(i>=0){
            digit1 = a[i] - '0';
            i--;
        }
        if(j>=0){
            digit2= b[j] -'0';
            j--;
        }

        int sum = digit1 + digit2+ carry;
        result[ind++] = (sum%2) + '0';
        carry = sum/2;
    }

    result[ind] = '\0';

    int start =0, end = strlen(result) -1;
    while(start < end){
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;

        start+=1;
        end-=1;
    }

    return result;
    
}