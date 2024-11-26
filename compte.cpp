#include <iostream>
#include <cstdlib>
#include <cstring>
#include "compte.hh"

using namespace std;

void menu() 
{
    cout << "********************************Bienvenue dans notre app de transfert d'argent**********************************" << endl; 
    cout << "1- Creer un compte " << endl;  
    cout << "2- Liste des comptes " << endl;
    cout << "3- Effectuer un transfert " << endl;
    cout << "4- Afficher le solde d'un compte " << endl;
    cout << "5- Historique des transactions " << endl;
    cout << "0- Fermenr l'application" << endl;
}