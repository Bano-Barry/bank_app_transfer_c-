#include <iostream>
#include <cstring>
#include "compte.hh"
#include <cstdlib>

using namespace std;

int main()
{
    Compte comptes[MAX_COMPTES]; 
    Transaction transactions[MAX_TRANSACTIONS]; 
    int taille_comptes = 0;
    int nb_transactions = 0;
    int choix ; 
    bool exit = false;

    while (!exit)
    {
        // system("clear"); 
        menu();
        cout << "votre choix --> " ; 
        cin >> choix; 
        switch (choix)
        {
        case 0: 
            system("clear");
            cout << "Merci d'avoir utilise notre application !" << endl; 
            // system("pause"); 
            return 0;
        case 1:  
            // system("clear");
            creer_compte(comptes, taille_comptes);
            cout << "Compte cree avec succes !" << endl; 
            // system("pause"); 
            break;
        case 2: 
            // system("clear");
            liste_comptes(comptes, taille_comptes);
            // system("pause"); 
            break;
        case 4 : 
            // system("cls");
            afficher_solde(comptes, taille_comptes);
            // system("pause");
            break;
        case 6 : 
            // system("cls");
            float montantRecharge;
            recharger_compte(comptes, taille_comptes, montantRecharge); 
            // system("pause");
            break;
        default:
            cout << "Entree invalide ! " << endl;
            // system("pause"); 
        }
    }
    
    return 0;
}