// https://leetcode.com/problems/length-of-last-word/description/

void rimuoviSpaziFinali(char *s){
    if(s[strlen(s)-1]!=' ')
        return;

    s[strlen(s)-1]='\0';
    
    rimuoviSpaziFinali(s);
}

int lengthOfLastWord(char* s) {
    int i, len=0;
    rimuoviSpaziFinali(s);

    for(i=strlen(s)-1;i>=0;i--){
        if(s[i]==' ')
            return len;
        len++;
    }
    return len;
}