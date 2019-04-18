#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

#include "player/player.h"
#include "word/word.h"

#include "control.h"


void filter_input(char* input){
    char* p = input;
    
    while(*p){
        if(isalpha(*p)){
            if(isupper(*p)){
                *p = tolower(*p);
            }
        }
        p++;

    }
    

}

int login(char* name, char* password, int* exists) {
    Player p;
    if(findPlayer(name, getPlayers(), &p)){
        *exists = 1;
        if(!strcmp(password, p.password)){
            FILE *f = fopen(SESSION_FILE, "w");
            fprintf(f, "%s", name);
            fclose(f);
            return 1;
        }else{
            return 0;
        }
    }else{
        *exists = 0;
        return 0;
    }

}

void disconnect(void){
    remove(SESSION_FILE);
}

int getConnectedPlayer(char* player){
    FILE *f=fopen(SESSION_FILE, "rt");
    if(!f){
        return 0;
    }

    fscanf(f, "%s", player);

    fclose(f);
    return 1;

}


int signup(char* name, char* password, int* exists) {
    Player p;
    
    if(findPlayer(name, getPlayers(), &p)){
        *exists = 1;
        return 0;    
    } else {
        *exists = 0;
        return createPlayer(name, password);
    }

}


int playLevel(int level){
    char** words;
    
    words = loadWords(level);
    
    int scores[10];
    int i;

    char path[50], player[20], answer[20];
    strcpy(path, SCORE_FILE);
    if(getConnectedPlayer(player)){
        strcat(path, player);
        FILE *f=fopen(path, "wt");
        if(f){
            for(i=0; i<MAX_WORDS; i++){
                printf("%s: ", words[i]);
                scanf("%s", answer);
                filter_input(answer);
                fprintf(f, "%s ", words[i]);
                fprintf(f, "%d\n", verifyAnswer(level, words[i], answer));
            }
            fclose(f);
        }
        return 1;
    }
    return 0;




}



int getScore(int* playerConnected) {
    char player[20], path[50], word[20];
    int score = 0, i;
    strcpy(path, SCORE_FILE);
    if(*playerConnected = getConnectedPlayer(player)){

        strcat(path, player);
        FILE *f=fopen(path, "rt");
        if(f){
            while(!feof(f)){
                fscanf(f, "%s", word);
                fscanf(f, "%d", &i);
                if(!feof(f))
                    score += i;
            }
            fclose(f);
        }
        return score*10;
    }

    return 0;
}





