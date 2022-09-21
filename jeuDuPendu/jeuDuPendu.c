#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "main.h"



int main() {

	char lettre = 0; //stock la lettre proposé par le joueur
	char motSecret[] = "ROUGE";
	int coupRestant = 10;
	int nombreLettreMot = nombreLettreMotSecret(motSecret);

	int* lettreTrouve = NULL;
	lettreTrouve = malloc(nombreLettreMot * sizeof(int));

	initTab(lettreTrouve, nombreLettreMot);

	printf("Mon premier pendu en C !\n");

	while (coupRestant > 0 && !gagne(lettreTrouve, nombreLettreMot)) {
		printf("il vous reste %d coup(s) rate avant de perdre \n", coupRestant);
		printf("Le mot est ");

		for (int i = 0; i < nombreLettreMot; i++) {
			if (lettreTrouve[i]) {
				printf("%c", motSecret[i]);
			}
			else {
				printf("*");
			}
		}

		printf("\nQuelle est votre lettre ? >");
		lettre = lireLettre();
		if (!rechercheCaractere(lettre, motSecret, nombreLettreMot, lettreTrouve)) {
			coupRestant--;
		}
	};

	if (gagne(lettreTrouve, nombreLettreMot)) {
		printf("\n\n Super !! tu as gagne ! le mot etait %s\n", motSecret);
	}
	else {
		printf("\n\n OUPS... Tu as perdu le mot etait %s\n", motSecret);
	}

	return 0;
}

//compte le nombre de lettre du mot secret
int nombreLettreMotSecret(char motSecret[]) {
	int nbLettre = 0 , i = 0;

	for (i = 0; motSecret[i] != '\0'; i++) {
		nbLettre++;
	}
	return nbLettre;
}

//initialiser la tableau avec les valeurs 0
void initTab(int* lettreTrouve, int taille) {
	for (int i = 0; i < taille; i++) {
		lettreTrouve[i] = 0;
	}
}

//le joueur gagne ?
int gagne(int * lettreTrouve, int taille) {
	int i = 0, aGagner = 1;

	for (i = 0; i < taille; i++) {
		if (!lettreTrouve[i]) {
			aGagner = 0;
		}
	}
	return aGagner;
}
//prend la lettre entré par lu'utilisateur
char lireLettre() {
	char caractere = 0;

	caractere = getchar();
	caractere = toupper(caractere);

	while (getchar() != '\n');

	return caractere;
}

int rechercheCaractere(char lettre, char motSecret[], int taille, int* lettreTrouve) {
	int i = 0, bonneLettre = 0;

	for (i = 0; i < taille; i++) {
		if (lettre == motSecret[i]) {
			bonneLettre = 1;
			lettreTrouve[i] = 1;
		}
	}
	return bonneLettre;
}