bool isPalindrome(char* s) {
    int i=0,j=0;

    while(s[i]!='\0'){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            s[j] = s[i];
            j++;
        }
        i++;
    }

    s[j] = '\0';

    for(int i=0; s[i]!='\0';i++){
        s[i] = tolower(s[i]);
    }
    int left = 0;
    int right = j-1;

    while(left<=right){
        if(s[left]!=s[right]){
            return false;
            break;
        }
        else{
            left+=1;
            right-=1;
        }
    }

    return true;
    
}