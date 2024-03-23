// https://leetcode.com/problems/find-the-difference/description/

int charToInt(char c){
    return c>='A' && c<='Z' ? c-'A' : c-'A'-('a'-'Z')+1;
}

char intToChar(int i){
    return i>=0 && i<=25 ? i+'A' : i+'A'+('a'-'Z')-1;
}

char findTheDifference(char* s, char* t) {
    int i, *qs=calloc(52, sizeof(int)), *qt=calloc(52, sizeof(int));
    for(i=0;i<strlen(s);i++){
        qt[charToInt(t[i])]++;
        qs[charToInt(s[i])]++;   
    }
    qt[charToInt(t[i])]++;
    for(i=0;i<=52;i++)
        if(qt[i]!=qs[i])
            return intToChar(i);
    return '\0';
}


//versione con print per debug
/*
char findTheDifference(char* s, char* t) {
    int i;
    int *qs=calloc(52, sizeof(int));
    int *qt=calloc(52, sizeof(int));
    char c;

    for(i=0;i<strlen(s)+1;i++){
        c=charToInt(t[i]);
        qt[charToInt(t[i])]++;
        printf("t[%d]: '%c' -> qt[%d]: %d\n", i, t[i], c, qt[c]);

        if(i<strlen(s)){
            c=charToInt(s[i]);
            qs[charToInt(s[i])]++;
            printf("s[%d]: '%c' -> qs[%d]: %d\n", i, s[i], c, qs[c]);
        }
            
    }

    printf("\n");

    for(i=0;i<=52;i++){
        if(qt[i] || qs[i])
            printf("qt[%d]: %d, qs[%d]: %d ('%c' %d volte in t e %d volte in s)\n", i, qt[i], i, qs[i], intToChar(i), qt[i], qs[i]);
    
        if(qt[i]!=qs[i]){
            printf("=> la lettera differente è '%c'\n", intToChar(i));
            return intToChar(i);
        }
    }
    return '\0';
}
*/

//funzioni di conversione senza operatori ternari
/*
int charToInt(char c){
    if(c>='A' && c<='Z')
        return c-'A';
    return c-'A'-('a'-'Z')+1;  
}

char intToChar(int i){
    if(i>=0 && i<=25)
        return i+'A';
    return i+'A'+('a'-'Z')-1;
}
*/