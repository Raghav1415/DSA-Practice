bool checkString(char* s) {
    int len = strlen(s) -1;
    for(int i=0; i<=len; i++){
        if(s[i] == 'b' && s[i+1] == 'a'){
            return false;
            break;
        }
    }
    return true;
}