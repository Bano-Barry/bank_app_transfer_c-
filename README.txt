# Application de Gestion de Comptes Bancaires

## Description du Projet
Cette application permet de gérer des comptes bancaires avec des fonctionnalités de base telles que la création de comptes, les transferts, la consultation de solde, et la gestion du statut des comptes.

## Fonctionnalités
1. Créer un nouveau compte
2. Lister tous les comptes
3. Effectuer un transfert entre comptes
4. Consulter le solde d'un compte
5. Afficher l'historique des transactions
6. Recharger un compte
7. Activer ou bloquer un compte
8. Trier la liste des comptes par ID croissant

## Prérequis
- Compilateur C++ (g++)
- Système d'exploitation Linux ou Windows

## Compilation
```bash
g++ -std=c++11 main.cpp compte.cpp -o bank_app
```

## Exécution
```bash
./bank_app
```

## Structure du Projet
- `main.cpp`: Fichier principal contenant la logique du menu et du programme
- `compte.cpp`: Implémentation des fonctions de gestion de comptes
- `compte.hh`: Déclarations des structures et prototypes de fonctions

## Limitations
- Nombre maximum de comptes : 1000
- Nombre maximum de transactions : 10000
- Solde initial par défaut : 5000
- Plafond de solde : 10 000 000

## Auteur
Mamadou Bano Barry
Date de création : 26/10/2024
