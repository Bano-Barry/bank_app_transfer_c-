#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED
#include <cstring>
#include <string>

using namespace std; 
struct date_creation
{
    int jour; 
    int mois; 
    int annee;
};
struct  Transaction
{
    int source_id; 
    int destination_id; 
    float montant; 
};
struct Compte
{
    int id ;
    string nom_titulaire; 
    float solde = 1000; 
    int status = 1; // 1 : compte actif par defaut &  0 : compte inactif 
    struct date_creation date; 
    
};
const int MAX_COMPTES = 1000; 
const int MAX_TRANSACTIONS = 10000; 

void menu() ;
void creer_compte(Compte C[], int &taille); 
void liste_comptes(Compte C[], int taille); 
int rechercherParID(Compte C[], int taille, int idRecherche);
void effectuer_transfert(Compte C[], int taille, Transaction T[], int &nb_transactions); 
void afficher_solde(Compte C[], int taille); 
void afficher_historiques(Transaction T[], int nb_transactions);

#endif