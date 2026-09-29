#include <limits>

using namespace std;

class Joueur{
    private:
        int points;
        string nom;


    public:
        Joueur(string nom){
            this->points = 40;
            this->setNom(nom);
        };

        void setNom(string nom){
            this->nom = nom;
        }

        void decrementerPoints(int points){
            this->points = this->points - (10 - points);
        }

        int getPoints(){
            return this->points;
        }

        string getNom(){
            return this->nom;
        }

        string toString(){
            return getNom() + " = " + to_string(getPoints());
        }

        void endGame(){
            cout << endl << "La partie est terminee !" << endl;
            string txt = "";
            if (getPoints() <= 0){
                txt = " a perdu(e)";
            }
            else{
                txt = " a gagne(e)";
            }
            cout << getNom() << txt << endl << endl;
            cout << "Appuyez sur n'importe quelle touche pour fermer le programme...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            exit(0);
        }
};
