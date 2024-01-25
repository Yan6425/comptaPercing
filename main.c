#include "fonctions.h"
#include <stdio.h>
#include <string.h>

// Définition du type de fonction
typedef void (*FunctionPointer)(char* argv[]);

// Structure associant un nom de fonction à son pointeur
struct FunctionMap {
    const char *nom;
    FunctionPointer fonction;
    int nbArgs;
};

int main(int argc, char* argv[]) {
    /// Initialisation de la map
    struct FunctionMap map[] = {
        {"ajouterClient", creerClient, 3},
        {"modifClient", modifClient, 3},
        {"suppClient", suppClient, 1},
        {"affClient", affClient, 1},
        {"affPiercingsClient", affPiercingsClient, 1},
        {"ajouterPiercing", ajouterPiercing, 8},
        {"modifPiercing", modifPiercing, 3},
        {"suppPiercing", suppPiercing, 1},
        {"affPiercing", affPiercing, 1},
    };

    // Vérifie que le nom de la fonction est renseigné
    if (argc < 2){
        fprintf(stderr, "Indiquez le nom de la fonction à exécuter\n");
    }

    // Recherche de la fonction dans la map
    int iFonction = -1;
    for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
        if (strcmp(nomFonction, map[i].nom) == 0) {
            iFonction = i;
        }
    }

    // Si le nom de la fonction n'est pas trouvé
    if (iFonction == -1){
        fprintf(stderr, "Fonction non trouvée : %s\n", nomFonction);
    }

    // Vérifie que le nombre d'arguments est suffisant
    if (argc < map[iFonction].nbArgs){
        fprintf(stderr, "Nombre d'arguments insuffisant\n");
    }

    map[iFonction].fonction(map[iFonction].nbArgs, argv);

    return 0;
}
