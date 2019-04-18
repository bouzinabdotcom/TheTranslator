#include<stdio.h>
#include<stdlib.h>
#include "bootstrap.h"
#include "control/control.h"
#include "messages/messages.h"

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}



void start(void){
    int answer, exists, score;
    char nom[20], mdp[20];
    system("clear");
    do{
        if(getConnectedPlayer(nom)){
            printf("Bienvenue %s\n", nom);
        }
        menu();
        scanf("%d", &answer);
        system("clear");
        switch(answer){
            case 1: loginV();
                    nomV();
                    scanf("%s", nom);
                    filter_input(nom);
                    mdpV();
                    scanf("%s", mdp);
                    filter_input(mdp);
                    if(!login(nom, mdp, &exists)){
                        if(!exists)
                            playerNotFound();
                        else
                            dbError();
                    }
                    break;
            case 2: if(getConnectedPlayer(nom))
                        playerAlreadyConnected(nom);
                    else{
                        signupV();
                        nomV();
                        scanf("%s", nom);
                        filter_input(nom);
                        mdpV();
                        scanf("%s", mdp);
                        filter_input(mdp);
                        if(!signup(nom, mdp, &exists)){
                            if(exists)
                                nameUsed();
                            else
                                dbError();
                        }
                    }
                    break;
            case 3: level(1);
                    if(!playLevel(1)){
                        system("clear");
                        noPlayerConnected();
                    }
                    break;
            case 4: level(2);
                    if(!playLevel(2)){
                        system("clear");
                        noPlayerConnected();
                    }
                    break;
            case 5: level(3);
                    if(!playLevel(3)){
                        system("clear");
                        noPlayerConnected();
                    }
                    break;
            case 6: score = getScore(&exists);
                    if(!exists)
                        noLevelPlayed();
                    else
                        scoreV(score);
                    break;
            case 7: disconnect();
                    disconnectedSuccessfully();
                    break;
            case 8: break;
            default: commandNotFound();

                    

        }
        clickAny();
        clean_stdin();
        getchar();
        system("clear");
    }while(answer != 8);

    

}