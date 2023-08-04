#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
//#include <gtk/gtk.h>

using namespace std;

class Personne {
    /**
    * @param Classe Personne
    * @var string nom
    */
protected:
    string nom;

public:
    
    Personne(const string& _nom) : nom(_nom) {}
    virtual ~Personne() = default;
    virtual void afficherInfos() const = 0;
    string getNom() const { return nom; }
};

class Personnel : public Personne {
    /**
    * @param Classe personne
    * @var string poste 
    * @var string horaire 
    * @var float salaire 
    */
private:
    string poste;
    string horaire;
    float salaire;

public:
    Personnel(const string& _nom, const string& _poste, const string& _horaire, float _salaire)
        :Personne(_nom), poste(_poste), horaire(_horaire), salaire(_salaire) {}
    ~Personnel() = default;
    void afficherInfos() const override {
    /**
    * @param Afficher information
    */
        cout << "--- PERSONNEL ---" << endl;
        cout << "Nom: " << nom << endl;
        cout << "Poste: " << poste << endl;
        cout << "Horaire: " << horaire << endl;
        cout << "Salaire avant impot: " << salaire << " EUR" << endl;
    }

    string getPoste() const { 
        /**
        * @param Retourne le poste
        */
        return poste; 
    }
    string getHoraire() const { 
        /**
        * @param Retourne les horaires
        */
        return horaire;
    }
    float getSalaire() const { 
        /**
        * @param Retourne le salaire
        */
        return salaire; 
    }

    void setPoste(const string& _poste) { 
        /**
        * @param Modifie le poste
        */
        poste = _poste; 
    }

    void setHoraire(const string& _horaire) {
        /**
        * @param Modifie les horaires
        */
        horaire = _horaire;
    }
    
    void setSalaire(float _salaire) {
        /**
        * @param Modifie le salaire
        */
        salaire = _salaire;
    }

    float calculerSalaireNet(float deductions) const {
        /**
        * @param calcule le salaire net 
        * @var float deductions 
        */
        float salaire_net = salaire - deductions;
        cout << "Deductions: " << deductions << " EUR" << endl;
        cout<<"Le salaire après impot: "<< salaire_net << "EUR" << endl;
        return salaire_net;
    }

};

class Client : public Personne{
    /**
        * @param classe client
        * @var float deductions 
    */
    private:
        int pt_fidelity;
    public:
        Client(const std::string &_nom,const int _pt_fidelity)
            :Personne(_nom),pt_fidelity(_pt_fidelity){}
        ~Client() = default;
        //Getters
        inline int getPtFidelity() const { 
            /**
            * @param Retourne les points de fidélité
            */
            return pt_fidelity; 
        }
        //Setters
        void setPtFidelity(const int & _pt_fidelity) {
            /**
            * @param Modifie les points de fidélité
            */
            pt_fidelity = _pt_fidelity;
        }
        //Methode
        void afficherInfos() const override {
            /**
            * @param Affiche les informations
            */
            cout <<"\tnom du client :"<<nom<< endl
            <<"\tle nombre de point de fidelité :"<<pt_fidelity<< endl;
        }
};

class People {
    /**
        * @param class People 
        * @var vector<shared_ptr<Personne>> lstPeople
    */
    private:
        vector<shared_ptr<Personne>> lstPeople;
    public:
        ~People() = default;
        void addPeople(shared_ptr<Personne> personne){
            /**
            * @param Ajoute une personne  
            */
            lstPeople.push_back(personne);
        }

        void whois()
        {
            /**
            * @param Affiche selon le profil de la personne si la personne fait parti du personnel ou de la clientèle
            */
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
