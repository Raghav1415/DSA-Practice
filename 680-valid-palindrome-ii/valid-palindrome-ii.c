bool validPalindrome(char* s) {
    int left =0;
    int right = strlen(s) -1;
    int count_start = 0;

    while(left<right){
        if(s[left] == s[right]){
            left+=1;
            right-=1;
        }
        else{
            count_start +=1;
            left+=1;
        }

        if(count_start>1) break;
    }

    left =0;
    right = strlen(s) -1;
    int count_end =0;

    while(left<right){
        if(s[left] == s[right]){
            left+=1;
            right -=1;
        }
        else{
            count_end += 1;
            right-=1;
        }

        if(count_end>1) break;
    }

    if(count_start ==1 || count_end ==1){
        return true;
    }
    else if(count_start ==0 || count_end ==1){
        return true;
    }

    return false;
}