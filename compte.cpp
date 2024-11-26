#include <iostream>
#include <cstdlib>
#include <cstring>
#include "compte.hh"
#include <ctime>
#include <iomanip> // defini des fonctions de manipulations utilisees pour manipuler le format d'entree et de sortie de notre programme

using namespace std;

void menu() 
{
    cout << "********************************Bienvenue dans notre app de transfert d'argent**********************************" << endl; 
    cout << "1- Creer un compte " << endl;  
    cout << "2- Liste des comptes " << endl;
    cout << "3- Effectuer un transfert " << endl;
    cout << "4- Afficher le solde d'un compte " << endl;
    cout << "5- Historique des transactions " << endl;
    cout << "6- Recharger un compte " << endl;
    cout << "7- Activer ou Bloquer un compte " << endl;
    cout << "0- Fermenr l'application" << endl;
}
// rechercher un element par son identifiant
int rechercherParID(Compte C[], int taille, int idRecherche) 
{
    for(int i=0; i<taille; i++)
    {
        if(C[i].id == idRecherche)
        {
            return i;
        }
    }
    return -1;
}

void creer_compte(Compte C[], int &taille) 
{
    if (taille > MAX_COMPTES) 
    {
        cout << "Nombres maximum de comptes atteint !" << endl;
        return;
    }
    cout << "Entrez l'identifiant du compte : " ; 
    cin >> C[taille].id; 
    while (rechercherParID(C, taille, C[taille].id) != -1)  
    {
        cout << "ID de compte existant, essayer avec un autre" << endl;
        cout << "Entrez l'identifiant du compte : " ; 
        cin >> C[taille].id;
    }
    cout << "Entrez le nom du proprietaire du compte : " ;
    cin.ignore();
    getline(cin, C[taille].nom_titulaire);
    cout << "Entrez la date de creation du compte : " << endl ;
    cout << "Jour > " ; 
    cin >> C[taille].date.jour; 
    while (C[taille].date.jour < 1 || C[taille].date.jour > 31)
    {
        cout << "Jour invalide !" << endl ;
        cout << "Jour > " ; 
        cin >> C[taille].date.jour; 
    }
    cout << "Mois > " ; 
    cin >> C[taille].date.mois; 
    while ((C[taille].date.mois < 1 || C[taille].date.mois > 12) || (C[taille].date.mois == 2 && C[taille].date.jour > 29)) 
    {
        cout << "Mois Invalide !" << endl;
        cout << "Mois > " ; 
        cin >> C[taille].date.mois; 
    }
    cout << "Annee > " ; 
    cin >> C[taille].date.annee; 
    while (C[taille].date.annee < 2000 || C[taille].date.annee > 2024)
    {
        cout << "Annee Invalide !" << endl; 
        cout << "Annee > " ; 
        cin >> C[taille].date.annee; 
    }
    taille++;
}
void liste_comptes(Compte C[], int taille) 
{
    if (taille == 0) 
    {
        cout << "La liste des comptes est vide " << endl;
        return; // termine l'execution d'une fonction et restitue le controle a la fonction appelante
    }
    cout << left << setw(10) << "ID" // setw(10) --> met 10 espaces blancs a droite de ID
        << setw(20) << "Nom du Titulaire" 
        << setw(15) << "Solde"
        << "Statut" << endl; 
    cout << string(50, '-') << endl;
    for(int i = 0; i < taille; i++)
    {
        cout << left << setw(10) << C[i].id
            << setw(20) << C[i].nom_titulaire
            << setw(15) << fixed << setprecision(2) << C[i].solde
            << (C[i].statut ? "Actif" : "Bloque") << endl;
    }
}
void afficher_solde(Compte C[], int taille)
{
    int id ;
    cout << "Entrez l'identifiant du compte a consulter : " ; 
    cin >> id ;
    int index = rechercherParID(C, taille, id);
    if (index != -1)
    {
        cout << "Solde du compte : " << setprecision(3) << C[index].solde << endl;
    }
    else {
        cout << "Compte introuvable !" << endl;
    }
}
void recharger_compte(Compte C[], int taille, float montantRecharge)
{
    int id ; 
    cout << "Entrez l'identifiant du compte a recharger : " ; 
    cin >> id ; 
    int index = rechercherParID(C, taille, id); 
    if (index != -1)
    {
        cout << "Entrez le montant a recharger : " ;
        cin >> montantRecharge; 
        if (montantRecharge > C[index].plafond_solde)
        {
            cout << "Impossible de recharger le compte au dela de " <<  C[taille].plafond_solde << endl;
        }
        else 
        {
            C[index].solde += montantRecharge;
            cout << "Compte recharge avec success !!!" << endl;
        }
    }
}