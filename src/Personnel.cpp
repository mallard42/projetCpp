#include <iostream>
#include <string>
#include <vector>
//#include <gtk/gtk.h>

using namespace std;

class Personne {
protected:
    string nom;

public:
    
    Personne(const string& _nom) : nom(_nom) {}

    virtual void afficherInfos() const = 0;
    string getNom() const { return nom; }
};

class Personnel : public Personne {
private:
    string poste;
    string horaire;
    float salaire;

public:
    Personnel(const string& _nom, const string& _poste, const string& _horaire, float _salaire)
        : Personne(_nom), poste(_poste), horaire(_horaire), salaire(_salaire) {}

    void afficherInfos() const override {
        cout << "--- PERSONNEL ---" << endl;
        cout << "Nom: " << nom << endl;
        cout << "Poste: " << poste << endl;
        cout << "Horaire: " << horaire << endl;
        cout << "Salaire avant impot: " << salaire << " EUR" << endl;
    }

    string getPoste() const { return poste; }
    string getHoraire() const { return horaire; }
    float getSalaire() const { return salaire; }

    void setPoste(const string& _poste) { poste = _poste; }
    void setHoraire(const string& _horaire) { horaire = _horaire; }
    void setSalaire(float _salaire) { salaire = _salaire; }

    float calculerSalaireNet(float deductions) const {
        float salaire_net = salaire - deductions;
        cout << "Deductions: " << deductions << " EUR" << endl;
        cout<<"Le salaire après impot: "<< salaire_net << "EUR" << endl;
        return salaire_net;
    }

}; 

int main(){

    Personnel personnel("Jean Dupont", "Vendeur", "Temps plein", 2500.0);
    personnel.afficherInfos();
    personnel.calculerSalaireNet(250.34);
    

    return 0;

};