#include <iostream>
#include <cstdlib>
#include <cstring>
#include "compte.hh"
#include <ctime>
#include <iomanip>

using namespace std;

/**
 * Affiche le menu principal de l'application bancaire
 * Présente les différentes options disponibles à l'utilisateur
 */
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
    cout << "8- Trier la liste des comptes " << endl;
    cout << "0- Fermer l'application" << endl;
}

/**
 * Recherche un compte dans le tableau de comptes par son identifiant
 * @param C Tableau de comptes
 * @param taille Nombre de comptes existants
 * @param idRecherche Identifiant du compte à rechercher
 * @return Index du compte si trouvé, -1 sinon
 */
int rechercherParID(Compte C[], int taille, int idRecherche) 
{
    // Parcourt tous les comptes pour trouver l'ID correspondant
    for(int i=0; i<taille; i++)
    {
        if(C[i].id == idRecherche)
        {
            return i; // Retourne l'index du compte
        }
    }
    return -1; // Compte non trouvé
}

/**
 * Crée un nouveau compte bancaire avec validation des données
 * @param C Tableau de comptes
 * @param taille Référence au nombre de comptes existants
 */
void creer_compte(Compte C[], int &taille) 
{
    // Vérification du nombre maximum de comptes
    if (taille >= MAX_COMPTES) 
    {
        cout << "Nombre maximum de comptes atteint !" << endl;
        return;
    }

    // Saisie et validation de l'identifiant unique
    cout << "Entrez l'identifiant du compte : " ; 
    cin >> C[taille].id; 
    while (rechercherParID(C, taille, C[taille].id) != -1)  
    {
        cout << "ID de compte existant, essayer avec un autre" << endl;
        cout << "Entrez l'identifiant du compte : " ; 
        cin >> C[taille].id;
    }

    // Saisie du nom du titulaire
    cout << "Entrez le nom du proprietaire du compte : " ;
    cin.ignore();
    getline(cin, C[taille].nom_titulaire);

    // Saisie et validation de la date de création
    cout << "Entrez la date de creation du compte : " << endl ;
    
    // Validation du jour
    cout << "Jour > " ; 
    cin >> C[taille].date.jour; 
    while (C[taille].date.jour < 1 || C[taille].date.jour > 31)
    {
        cout << "Jour invalide !" << endl ;
        cout << "Jour > " ; 
        cin >> C[taille].date.jour; 
    }

    // Validation du mois
    cout << "Mois > " ; 
    cin >> C[taille].date.mois; 
    while ((C[taille].date.mois < 1 || C[taille].date.mois > 12) || 
           (C[taille].date.mois == 2 && C[taille].date.jour > 29)) 
    {
        cout << "Mois Invalide !" << endl;
        cout << "Mois > " ; 
        cin >> C[taille].date.mois; 
    }

    // Validation de l'année
    cout << "Annee > " ; 
    cin >> C[taille].date.annee; 
    while (C[taille].date.annee < 2000 || C[taille].date.annee > 2024)
    {
        cout << "Annee Invalide !" << endl; 
        cout << "Annee > " ; 
        cin >> C[taille].date.annee; 
    }

    // Incrémentation du nombre de comptes
    taille++;
}

/**
 * Affiche la liste de tous les comptes existants
 * @param C Tableau de comptes
 * @param taille Nombre de comptes existants
 */
void liste_comptes(Compte C[], int taille) 
{
    // Vérification si la liste est vide
    if (taille == 0) 
    {
        cout << "La liste des comptes est vide " << endl;
        return;
    }

    // Affichage de l'en-tête du tableau
    cout << string(50, '-') << endl;
    cout << "N0" << "\t\t\t" << "idCompte" << "\t\t" << "Nom Titulaire" << "\t\t"  << "Solde" << "\t\t\t" << "Statut" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    // Parcourt et affichage de chaque compte
    for(int i = 0; i < taille; i++)
    {
        cout << i+1 << "\t\t\t" <<  C[i].id << "\t\t\t" << C[i].nom_titulaire <<
            "\t\t\t" <<  C[i].solde << "\t\t\t" << 
            (C[i].statut ? "Actif" : "Bloque") << endl;
    }
}

/**
 * Affiche le solde d'un compte spécifique
 * @param C Tableau de comptes
 * @param taille Nombre de comptes existants
 * @param id Identifiant du compte à consulter
 */
void afficher_solde(Compte C[], int taille, int id)
{
    // Recherche du compte par son ID
    int index = rechercherParID(C, taille, id);
    
    // Vérification du statut du compte
    if (index != -1 && C[index].statut == true)
    {
        // Affichage du solde si le compte est actif
        cout << "Solde du compte : " << setprecision(3) << C[index].solde << endl;
    }
    else if (index != -1 && C[index].statut == false)
    {
        // Message si le compte est bloqué
        cout << "Votre compte est bloque, vous ne pouvez pas consulter votre solde !" << endl;
    }
    else {
        // Message si le compte n'est pas trouvé
        cout << "Compte introuvable !" << endl;
    }
}

/**
 * Recharge le solde d'un compte
 * @param C Tableau de comptes
 * @param taille Nombre de comptes existants
 * @param id Identifiant du compte à recharger
 * @param montantRecharge Montant à recharger (passé par référence)
 */
void recharger_compte(Compte C[], int taille, int id, float montantRecharge)
{
    // Recherche du compte par son ID
    int index = rechercherParID(C, taille, id); 
    
    if (index != -1)
    {
        // Saisie du montant à recharger
        cout << "Entrez le montant a recharger : " ;
        cin >> montantRecharge; 

        // Vérification du montant de rechargement
        if (montantRecharge > C[index].plafond_solde)
        {
            cout << "Impossible de recharger le compte au dela de " <<  C[index].plafond_solde << endl;
        }
        else if(montantRecharge <= 0)
        {
            cout << "Montant invalide" << endl;
        }
        else 
        {
            // Mise à jour du solde
            C[index].solde += montantRecharge;
            cout << "Compte recharge avec success !!!" << endl;
        }
    }
    else 
    {
        cout << "L'ID du compte que vous essayez de recharger est introuvable !" << endl;
    }
}

/**
 * Active ou bloque un compte existant
 * @param C Tableau de comptes
 * @param taille Nombre de comptes existants
 * @param id Identifiant du compte à modifier
 */
void activer_bloquer_compte(Compte C[], int taille, int id) 
{
    // Affichage du sous-menu
    cout << "Activer ou Bloquer un compte " << endl ;
    cout << "1- Activer un compte " << endl ;
    cout << "2- Bloquer un compte " << endl << " votre choix > " ;
    
    int choix, index; 
    cin >> choix ;

    switch (choix)
    {
        case 1: // Activation de compte
            cout << "Entrez l'id du compte a activer : " ; 
            cin >> id ; 
            index = rechercherParID(C, taille, id); 
            
            if(index != -1)
            {
                if (C[index].statut == true)
                {
                    cout << "Le compte est deja actif !" << endl ;
                    return;
                }
                else 
                {
                    C[index].statut = true; 
                    cout << "Compte active avec succes" << endl ;
                }
            }
            else
            {
                cout << "L'ID du compte est introuvable !" << endl ;
            }
        break;
        
        case 2: // Blocage de compte
            cout << "Entrez l'id du compte a bloquer : " ; 
            cin >> id ; 
            index = rechercherParID(C, taille, id); 
            
            if(index != -1)
            {
                if (C[index].statut == false)
                {
                    cout << "Le compte est deja bloque !" << endl ;
                    return;
                }
                else 
                {
                    C[index].statut = false; 
                    cout << "Compte bloque avec succes !" << endl ;
                }
            }
            else
            {
                cout << "L'ID du compte est introuvable !" << endl ;
            }
        break;
        
        default:
            cout << "Mauvaise entree" << endl ;
            break;
    }
}

/**
 * Effectue un transfert d'argent entre deux comptes
 * @param C Tableau de comptes
 * @param taille Nombre de comptes existants
 * @param T Tableau des transactions
 * @param nb_transactions Nombre de transactions existantes
 */
void effectuer_transfert(Compte C[], int taille, Transaction T[], int &nb_transactions)
{
    // Vérification du nombre maximum de transactions
    if (nb_transactions >= MAX_TRANSACTIONS)
    {
        cout << "Nombre de transactions atteint " << endl ;
        return ;
    }

    int id_source, id_destination;
    float montantTransfert; 

    // Saisie et vérification du compte source
    cout << "Entrez l'ID du compte source : " ; 
    cin >> id_source;
    int index_source = rechercherParID(C, taille, id_source);
    if (index_source == -1)
    {
        cout << "Compte source non trouve" << endl ; 
        return;
    }

    // Saisie et vérification du compte destination
    cout << "Entrez l'ID du compte destination : " ; 
    cin >> id_destination;
    int index_destination = rechercherParID(C, taille, id_destination);
    if (index_destination == -1)
    {
        cout << "Compte destination non trouve" << endl ; 
        return;
    }

    // Saisie et vérification du montant
    cout << "Entrez le montant a transferer : " ; 
    cin >>  montantTransfert; 
    
    // Validation du montant
    if (montantTransfert < 0)
    {
        cout << "Montant invalide" << endl ; 
        return;
    }

    // Vérification du solde suffisant
    if(C[index_source].solde < montantTransfert)
    {
        cout << "Solde insuffisant !" << endl ; 
        return; 
    }

    // Effectuer le transfert
    C[index_source].solde -= montantTransfert; 
    C[index_destination].solde += montantTransfert;

    // Enregistrement de la transaction
    T[nb_transactions].source_id = id_source; 
    T[nb_transactions].destination_id = id_destination; 
    T[nb_transactions].montant = montantTransfert;
    nb_transactions++;

    cout << "Transfert effectue avec succes !" << endl;
}

/**
 * Affiche l'historique des transactions
 * @param T Tableau des transactions
 * @param nb_transactions Nombre de transactions existantes
 */
void afficher_historiques(Transaction T[], int nb_transactions)
{
    // Vérification si aucune transaction n'a été effectuée
    if (nb_transactions == 0)
    {
        cout << "Aucune Transaction" << endl;
        return;
    }

    // Affichage de l'en-tête du tableau des transactions
    cout << "N0 " << "\t\t\t" << "id_compte_source" << "\t\t\t" << "id_compte_destination" << "\t\t\t" << "montant_transfert" << endl ;
    
    // Parcourt et affichage de chaque transaction
    for(int i = 0; i < nb_transactions; i++) 
    {
        cout << i+1 << "\t\t\t" << T[i].source_id << "\t\t\t\t\t" 
             << T[i].destination_id << "\t\t\t\t\t" << T[i].montant << endl; 
    }
}
void trier_comptes_par_id(Compte comptes[], int taille_comptes) {
    for (int i = 0; i < taille_comptes - 1; i++) {
        for (int j = 0; j < taille_comptes - i - 1; j++) {
            // Comparer et échanger si nécessaire
            if (comptes[j].id > comptes[j + 1].id) {
                // Échange des comptes
                Compte temp = comptes[j];
                comptes[j] = comptes[j + 1];
                comptes[j + 1] = temp;
            }
        }
    }
    
    cout << "Comptes triés par ID avec succès !" << endl;
}