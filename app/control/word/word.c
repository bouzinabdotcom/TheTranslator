#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "word.h"


char* getLevelPath(int level) {
    char* path;
    path = (char*)malloc(50*sizeof(char)); 
    strcpy(path, "test/app/levels/level");
    char c = level + '0';
    char s[2];
    s[0] = c;
    s[1] = '\0';

    strcat(path, s);

    return path;
}

Word* loadLevel(int level){
    char *path = getLevelPath(level);
    Word* words;
    FILE *f = fopen(path, "rt");
    int i;
    

    if(!f){
        return NULL;
    }

    words = (Word*)malloc(10*sizeof(Word));

    for(i=0; i<MAX_WORDS; i++){
        fscanf(f, "%s", words[i].fr);
        fscanf(f, "%s", words[i].en);
    }

    fclose(f);

    return words;
}

char** loadWords(int level) {
    
    Word* w = loadLevel(level);
    
    char** words = (char**)malloc(MAX_WORDS*sizeof(char*));
    
    int i;
    for(i=0; i<MAX_WORDS; i++){
        words[i] = (char*)malloc(21*sizeof(char));
        words[i]= w[i].fr;
    }
    
    return words;
}



int verifyAnswer(int level, char* word, char* answer) {
    Word* w = loadLevel(level);
    int i;
    for(i=0; i<MAX_WORDS; i++){
        if(!strcmp(w[i].fr, word) && !strcmp(w[i].en, answer))
            return 1;
    }
    return 0;
}