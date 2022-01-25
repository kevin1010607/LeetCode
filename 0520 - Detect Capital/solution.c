bool detectCapitalUse(char * word){
    for(int i = 1; word[i]; i++){
        if(isupper(word[1])!=isupper(word[i]) || (!isupper(word[0])&&isupper(word[i]))) return false;
    }
    return true;
}