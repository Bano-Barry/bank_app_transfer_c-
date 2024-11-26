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
        case 3: 
            // system("clear");
            effectuer_transfert(comptes, taille_comptes, transactions, nb_transactions);
            break;
        case 4 : 
            // system("cls");
             int idCompteAConsulter ;
            cout << "Entrez l'identifiant du compte a consulter : " ; 
            cin >> idCompteAConsulter ;
            afficher_solde(comptes, taille_comptes, idCompteAConsulter);
            // system("pause");
            break;
        case 5 : 
            // system("cls");
            afficher_historiques(transactions, nb_transactions); 
            break;
        case 6 : 
            // system("cls");
            float montantRecharge;
            int idCompteARecharger ; 
            cout << "Entrez l'identifiant du compte a recharger : " ; 
            cin >> idCompteARecharger ; 
            recharger_compte(comptes, taille_comptes, idCompteARecharger, montantRecharge); 
            // system("pause");
            break;
        case 7 :
            // system("cls");
            int idCompteA_activer_bloquer ;
            activer_bloquer_compte(comptes, taille_comptes, idCompteA_activer_bloquer);
            // system("pause");
            break;
        case 8 : 
            // system("cls");
            trier_comptes_par_id(comptes, taille_comptes);
            break;
        default:
            cout << "Entree invalide ! " << endl;
            // system("pause"); 
        }
    }
    
    return 0;
}