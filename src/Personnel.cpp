#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
//#include <gtk/gtk.h>

using namespace std;

class Personne {
protected:
    string nom;

public:
    
    Personne(const string& _nom) : nom(_nom) {}
    virtual ~Personne() = default;
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
        :Personne(_nom), poste(_poste), horaire(_horaire), salaire(_salaire) {}
    ~Personnel() = default;
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

class Client : public Personne{
    private:
        int pt_fidelity;
    public:
        Client(const std::string &_nom,const int _pt_fidelity)
            :Personne(_nom),pt_fidelity(_pt_fidelity){}
        ~Client() = default;
        //Getters
        inline int getPtFidelity() const { return pt_fidelity; }
        //Setters
        void setPtFidelity(const int & _pt_fidelity) { pt_fidelity = _pt_fidelity; }
        //Methode
        void afficherInfos() const override {
            cout <<"\tnom du client :"<<nom<< endl
            <<"\tle nombre de point de fidelité :"<<pt_fidelity<< endl;
        }
};

class People {
    private:
        vector<shared_ptr<Personne>> lstPeople;
    public:
        ~People() = default;
        void addPeople(shared_ptr<Personne> personne){
            lstPeople.push_back(personne);
        }

        void whois()
        {
            for(auto people = lstPeople.begin();people < lstPeople.end(); people ++){
                shared_ptr<Personnel> personne = dynamic_pointer_cast<Personnel> (*people);
                shared_ptr<Client> client = dynamic_pointer_cast<Client>(*people);

                if(personne) {
                    std::cout << "\til fait partie du personnel " << personne->getNom() << std::endl;
                }else if(client){
                    std::cout << "\til fait partie de la clientèle " << client->getNom() << std::endl;
                }else{
                    std::cout << "unknow" << std::endl;
                }
            }
        }
    

};
