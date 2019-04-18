#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "player.h"

extern int PlayerNum;



Player* getPlayers(void) {
    Player* db;
    FILE *f;
    int i=0, size=2;

    f = fopen(PLAYER_DB, "rt");
    if(!f){
        return NULL;
    }

    db = (Player*)malloc(sizeof(Player));
    while(!feof(f)) {
        fscanf(f, "%d", &(db+i)->id);
        fscanf(f, "%s", (db+i)->name); 
        fscanf(f, "%s", (db+i)->password);

        db = (Player*)realloc(db, (size++)*sizeof(Player));
        i++;
    }
    PlayerNum = i-1;

    fclose(f);
    return db;
}





int findPlayer(char* name, Player* db, Player* p) {
 
    int i;
    for(i=0; i<PlayerNum; i++) {
        if(!strcmp(db[i].name, name)){
            p->id = db[i].id;
            strcpy(p->name, db[i].name);
            strcpy(p->password, db[i].password);
            return 1;
        }
    }

    return 0;
}





int createPlayer(char* name, char* password) {

    getPlayers();

    FILE *f = fopen(PLAYER_DB, "at");
    if(!f){
        return 0;
    }

    if(!ftell(f))
        PlayerNum = 1;
    else
        PlayerNum++;

    fprintf(f, "%d %s %s\n", PlayerNum, name, password);
    fclose(f);
    return 1;
}




