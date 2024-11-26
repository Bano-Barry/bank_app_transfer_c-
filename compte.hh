#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED
#include <cstring>
#include <string>

using namespace std; 

// Structure pour stocker la date de création d'un compte
struct date_creation
{
    int jour;   // Jour de création du compte (1-31)
    int mois;   // Mois de création du compte (1-12)
    int annee;  // Année de création du compte
};

// Structure pour enregistrer les détails d'une transaction
struct Transaction
{
    int source_id;         // ID du compte source du transfert
    int destination_id;    // ID du compte destination du transfert
    float montant;         // Montant du transfert
};

// Structure représentant un compte bancaire
struct Compte
{
    int id;                    // Identifiant unique du compte
    string nom_titulaire;      // Nom du propriétaire du compte
    float solde = 5000;        // Solde initial par défaut
    bool statut = true;        // Statut du compte (true: actif, false: inactif)
    struct date_creation date; // Date de création du compte
    double plafond_solde = 10000000; // Plafond maximum du solde
};

// Constantes définissant les limites du système
const int MAX_COMPTES = 1000;         // Nombre maximum de comptes
const int MAX_TRANSACTIONS = 10000;   // Nombre maximum de transactions

// Prototypes des fonctions de gestion de comptes
void menu();                                                          // Affiche le menu principal
void creer_compte(Compte C[], int &taille);                           // Créer un nouveau compte
void liste_comptes(Compte C[], int taille);                           // Lister tous les comptes
int rechercherParID(Compte C[], int taille, int idRecherche);         // Rechercher un compte par ID
void recharger_compte(Compte C[], int taille, int id, float montantRecharge);  // Recharger un compte
void activer_bloquer_compte(Compte C[], int taille, int id);          // Activer ou bloquer un compte
void effectuer_transfert(Compte C[], int taille, Transaction T[], int &nb_transactions);  // Effectuer un transfert
void afficher_solde(Compte C[], int taille, int id);                  // Afficher le solde d'un compte
void afficher_historiques(Transaction T[], int nb_transactions);       // Afficher l'historique des transactions
void trier_comptes_par_id(Compte comptes[], int taille_comptes);
#endif