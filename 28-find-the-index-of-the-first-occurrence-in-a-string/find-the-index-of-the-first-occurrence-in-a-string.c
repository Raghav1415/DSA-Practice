int strStr(char* haystack, char* needle) {
    int l1 = strlen(haystack);
    int l2 = strlen(needle) ;
    for(int i=0; i <=l1 - l2; i++){
        if(haystack[i] == needle[0]){
            if((strncmp(&haystack[i], needle, l2))==0){
                return i;
            }
        }
    }
    return -1;
}