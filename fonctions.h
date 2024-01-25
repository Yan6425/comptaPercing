#ifndef __fonctions_H_
#define __fonctions_H_

// arguments : char* nom, char* prenom, char* dateDeNaissance
int ajouterClient(char* argv[]);
// arguments : char* idClient, int var, char* val
int modifClient(char* argv[]);
// arguments : char* idClient
int suppClient(char* argv[]);
// arguments : char* idClient
int affClient(char* argv[]);
// arguments : char* idClient
int affPiercingsClient(char* argv[]);
// arguments : char* idClient, char* date, int zone, int gaugeDePercage, int acte, char* nsGants, char* nsBijou, char* nsAiguille
int ajouterPiercing(char* argv[]);
// arguments : char* idClient, int var, char* val
int modifPering(char* argv[]);
// arguments : char* idClient
int suppPiercing(char* argv[]);
// arguments : char* idClient
int affPiercing(char* argv[]);


#endif