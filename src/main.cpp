#include <iostream>
#include <limits>
#include <random>
#include <array>
#include "../include/Joueur.h"

using namespace std;

/* Initialisation des méthodes */
int generateNumber(){
    return rand() % 10 + 1;
}


string demanderNom(){
    cout << "Quel est votre nom ? ";
    string nom;
    cin >> nom;
    return nom;
}

void afficherScore(Joueur* j1, Joueur* j2){
    system("cls");
    cout << "Points des joueurs : " << endl;
    cout << "   ->" << j1->toString() << endl;
    cout << "   ->" << j2->toString() << endl << endl;
}


int main()
{
    cout << "Joueur 1 :" << endl;
    Joueur* j1 = new Joueur(demanderNom());

    cout << endl << "Joueur 2 : " << endl;
    Joueur* j2 = new Joueur(demanderNom());

    array<Joueur*, 2> listJoueurs = {j1,j2};

    int nombreAleatoire = generateNumber();

    cout << endl << "Le but du jeu est de trouver le nombre aleatoire entre 1 et 10." << endl;
    cout << "Si un joueur trouve le bon nombre, la partie est termine." << endl;
    cout << "Mais si un des joueurs ne trouve pas la partie, il perdra des points. " << endl;
    cout << "C'est-a-dire que le joueur perd le nombre de points qu'il y a entre la difference du nombre genere et son nombre." << endl;
    cout << "Exemple : " << endl;
    cout << "* 10 -> le nombre aleatoire" << endl;
    cout << "*  4 -> le nombre tire par le joueur" << endl;
    cout << "Le joueur perdra 6 points (10-4)." << endl << endl;


    cout << "Appuyez sur n'importe quelle touche pour commencer...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    afficherScore(j1, j2);

    while(true){
        for(const auto& element : listJoueurs){
            cout << element->getNom() << ", a votre tour : " ;
            int nombre;
            cin >> nombre;
             while (nombre < 0 | nombre > 10){
                cout << endl << "Retapez un nombre compris entre 1 et 10." << endl << "Nombre : ";
                cin >> nombre;
             }

            if(nombre != nombreAleatoire){
                if(nombreAleatoire > nombre){
                    element->decrementerPoints(nombreAleatoire - nombre);
                }
                else{
                    element->decrementerPoints(nombre - nombreAleatoire);
                }


                if(element->getPoints()<= 0){
                    element->endGame();
                }
                else{
                    afficherScore(j1, j2);
                }
            }
            else{
                element->endGame();
            }
        }
    }
    return 0;
}





