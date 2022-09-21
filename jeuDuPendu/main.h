#include <stdio.h>
#ifndef main1_hpp
#define main1_hpp

int nombreLettreMotSecret(char motSecret[]);
void initTab(int* lettreTrouve, int taille);
int gagne(int* lettreTrouve, int taille);
char lireLettre();
int rechercheCaractere(char lettre, char motSecret[], int taille, int* lettreTrouve);

#endif 
