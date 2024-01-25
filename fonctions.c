#include "fonctions.h"
#include <stdio.h>
#include <sqlite3.h>

// Déclaration de la base de données SQLite globale
sqlite3 *db;

// Fonction pour ouvrir la base de données
int ouvrirBaseDeDonnees() {
    int rc = sqlite3_open("ma_base_de_donnees.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Impossible d'ouvrir la base de données : %s\n", sqlite3_errmsg(db));
    }
    return rc;
}

// Fonction pour fermer la base de données
void fermerBaseDeDonnees() {
    sqlite3_close(db);
}

// Fonction pour créer un client
int ajouterClient(char* argv[]) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO clients (nom, prenom, dateDeNaissance) VALUES ('%s', '%s', '%s');", argv[2], argv[3], argv[4]);
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Fonction pour modifier un client
int modifClient(char* argv[]) {
    char sql[256];
    const char *columns[] = {"nom", "prenom", "dateDeNaissance"};
    snprintf(sql, sizeof(sql), "UPDATE clients SET %s = '%s' WHERE idClient = '%s';", columns[(int)argv[3]], argv[4], argv[2]);
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Fonction pour supprimer un client
int suppClient(char* argv[]) {
    char sql[128];
    snprintf(sql, sizeof(sql), "DELETE FROM clients WHERE idClient = '%s';", argv[2]);
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Fonction pour afficher un client
int affClient(char* argv[]) {
    char sql[128];
    snprintf(sql, sizeof(sql), "SELECT * FROM clients WHERE idClient = '%s';", argv[2]);
    return sqlite3_exec(db, sql, callback, 0, 0);
}

// Fonction pour afficher les piercings d'un client
int affPiercingsClient(char* argv[]) {
    char sql[128];
    snprintf(sql, sizeof(sql), "SELECT * FROM piercings WHERE idClient = '%s';", argv[2]);
    return sqlite3_exec(db, sql, callback, 0, 0);
}

// Fonction pour ajouter un piercing
int ajouterPiercing(char* argv[]) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO piercings (idClient, date, zone, gaugeDePercage, acte, nsGants, nsBijou, nsAiguille) VALUES ('%s', '%s', %d, %d, %d, '%s', '%s', '%s');", argv[2], argv[3], (int)argv[4], (int)argv[5], (int)argv[6], argv[7], argv[8], argv[9]);
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Fonction pour modifier un piercing
int modifPiercing(char* argv[]) {
    char sql[256];
    const char *columns[] = {"date", "zone", "gaugeDePercage", "acte", "nsGants", "nsBijou", "nsAiguille"};
    snprintf(sql, sizeof(sql), "UPDATE piercings SET %s = '%s' WHERE idPiercing = '%s';", columns[(int)argv[3]], argv[4], argv[2]);
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Fonction pour supprimer un piercing
int suppPiercing(char* argv[]) {
    char sql[128];
    snprintf(sql, sizeof(sql), "DELETE FROM piercings WHERE idPiercing = '%s';", argv[2]);
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Fonction pour afficher un piercing
int affPiercing(char* argv[]) {
    char sql[128];
    snprintf(sql, sizeof(sql), "SELECT * FROM piercings WHERE idPiercing = '%s';", argv[2]);
    return sqlite3_exec(db, sql, callback, 0, 0);
}
