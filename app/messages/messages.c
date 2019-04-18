#include<stdio.h>
#include <string.h>

#include "messages.h"

void menu(void){
    puts("=============Le Traducteur=============");
    puts("Le jeu qui teste votre niveau d'anglais");
    puts("==================MENU=================");
    puts("1-Se Connecter.");
    puts("2-S\'inscrire.");
    puts("3-Niveau 1.");
    puts("4-Niveau 2.");
    puts("5-Niveau 3.");
    puts("6-Score.");
    puts("7-Se Deconnecter.");
    puts("8-Quitter.");
    printf("Votre choix: ");
}




void scoreV(int s){

    char r[30];

    if(s>=90)
        strcpy(r, "Excellent");
    else if(s<90 && s>=60)
        strcpy(r, "Bon");
    else if(s<60 && s>=40)
        strcpy(r, "Moyen");
    else
        strcpy(r, "Faible");


    printf("Votre score est: %d%% (%s).\n", s, r);
}

void nomV(void){
    printf("Nom: ");
}

void mdpV(void){
    printf("Mot de pass: ");
}

void loginV(void) {
    puts("=======Se Connecter=======");
}

void signupV(void) {
    puts("=======S'inscrire=======");
}

void playerNotFound(void) {
    puts("Nom introuvable!\nVeuillez vous inscrire svp.");
}

void dbError(void) {
    puts("Erreur d'acces a la base de donnees");
}

void nameUsed(void) {
    puts("Nom deja utilise!");
}

void level(int level){
    printf("===========================Niveau %d===========================\n", level);
    puts("Veuillez consulter votre score avant de passer aux autres niveaux.\nLes mots doivent etre en miniscule.");

}

void noLevelPlayed(void) {
    puts("Veuillez jouer d'abord avant de consulter le score.");

}

void commandNotFound(void) {
    puts("Ce numero ne correspond a aucune commande.");
}

void clickAny(void) {
    puts("Veuillez cliquer sur la touche entree pour continuer.");
}

void noPlayerConnected(void){
    puts("Veuillez vous connecter avant de commencer le jeux, si vous n'avez pas de compte veuillez vous inscrire svp.");
}

void disconnectedSuccessfully(void) {
    puts("Vous etes deconnecte avec succes.");
}

void playerAlreadyConnected(char* name){
    printf("%s est deja connecte.\n", name);
}