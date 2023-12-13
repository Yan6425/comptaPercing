#ifndef __fonctions_H_
#define __fonctions_H_


int creerClient(char* nom, char* prenom, char* dateDeNaissance);
int modifClient(char* idClient, int var, char* val);
int suppClient(char* idClient);
int affClient(char* idClient);
int affPercingsClient(char* idClient);
int ajouterPercing(char* idClient, char* date, int zone, int gaugeDePercage, int acte, char* nsGants, char* nsBijou, char* nsAiguille);
int modifPering(char* idPercing, int var, char* val);
int suppPercing(char* idPercing);
int affPercing(char* idPercing);


#endif