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
        system("clear"); 
        menu();
        cout << "votre choix --> " ; 
        cin >> choix; 
        switch (choix)
        {
        case 0: 
            system("clear");
            cout << "Merci d'avoir utilise notre application !" << endl; 
            system("pause"); 
            return 0;
        case 1:  

        default:
            cout << "Entree invalide ! " << endl;
            system("pause"); 
        }
    }
    
    return 0;
}