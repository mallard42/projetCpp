#include <iostream>
#include <string>
#include <vector>
//#include <gtk/gtk.h>

using namespace std;

// namespace Categorie {
// class Categorie  {

//     private:

//     public:
//         string type;
//         string unite;
//         int min;
//         int max;

//         //Categorie(){}
//         Categorie(const string& _type, const string& _unite, int _min, int _max): type(_type), unite(_unite), min(_min), max(_max){}

//         // Categorie(const Categorie& _c){
//         //         this->type = _c.type;
//         //         this->unite = _c.unite;
//         //         this->min = _c.min;
//         //         this->max = _c.max;
//         //     }

//         void set_type(const string& _type){type = type;}
//         void set_unite(const string& _unite){unite = _unite;}
//         void set_min(int _min){min = _min;}
//         void set_max(int _max){min = _max;}

//         string get_type(){return type;}
//         string get_unite(){return unite;}
        
//         int get_min(){return min;}
//         int get_max(){return max;}

//         void afficherInfos() {
//             cout << "---CATEGORIE----" << endl;
//             cout << " Type: " << type << endl;
//             cout << " Unite en: " << unite  << endl;
//             cout << " Taille Min: " << min << endl;
//             cout << " Taille Max: " << max << endl;

//         }

//         //~Categorie(){}
//     };
// }

// namespace Produit{

//     class Produit: public Categorie::Categorie {
//         private:

//         public:
//             string nom;
//             string rayon;
//             float pht;
//             float pttc;
//             bool promo;
//             float prix_promo;

//             Produit(const Categorie c, const string& _nom, const string& _rayon, float _pht, float _pttc, bool _promo, float _prix_promo)
//               :Categorie(c), nom(_nom), rayon(_rayon), pht(_pht), pttc(_pttc), promo(_promo), prix_promo(_prix_promo){}

            
//             void setnom(const string& _nom){nom = _nom;}
//             void setrayon(const string& _rayon){rayon = _rayon;}
//             void setpromo(float _prix_promo){prix_promo= _prix_promo;}

//             void setpht(float prixHT, int tva){
//                 pht = prixHT;
//                 pttc = pht*tva;
//             }

//             void setpttc(float prixTTC, int tva ){
//                 pttc = prixTTC;
//                 pht = pttc/tva;
//             }
 
//             string getnom(){return nom;}
//             string getrayon(){return rayon;}
            
//             float getpht(){return pht;}
//             float getPrixTTC() const {
//                 if (promo) {
//                     return prix_promo;
//                 } else {
//                     return pttc;
//                 }
//             }

//            void afficherInfos() {
//                 Categorie::afficherInfos();
//                 cout << "--- PRODUIT ---" << endl;
//                 cout << "Nom: " << nom << endl;
//                 cout << "Rayon: " << rayon << endl;
//                 cout << "Prix HT: " << pht << endl;
//                 cout << "Prix TTC: " << pttc << endl;
//                 cout << "Promo: " << (promo ? "Oui" : "Non") << endl;
//                 if (promo) {
//                     std::cout << "Prix Promo: " << prix_promo << endl;
//                 }
//             }

//             void Promotion(float pourcentage) {
//                 if (pourcentage > 0.0 && pourcentage <= 100.0) {
//                     promo = true;
//                     prix_promo = pttc * (1.0 - pourcentage / 100.0);
//                 } else {
//                     std::cout << "Pourcentage de promo invalide !" << std::endl;
//                 }
//             }

//             string descriptionProduit() const {
//                 std::string description = nom + " (" + rayon + ")\n";
//                 description += "Prix HT: " + std::to_string(pht) + "\n";
//                 description += "Prix TTC: " + std::to_string(pttc) + "\n";
//                 // description += "En promotion: " + (oui ou non)"\n";
//                 if (promo) {
//                     description += "Prix Promo: " + std::to_string(prix_promo) + "\n";
//                 }
//                 return description;
//             }
// };
// }

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

    void afficherInfos() const {
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

    // Categorie::Categorie categorie("vetement", "cm", 35, 43);
    // categorie.afficherInfos();

    // Produit::Produit produit(categorie, "T-shirt de sport", "Fitness", 25.0, 30.0, false, 0.0);
    // produit.afficherInfos();

    // float prixTTC = produit.getPrixTTC();
    // cout << "Prix TTC après promotion : " << prixTTC << endl;
    
    // string description = produit.descriptionProduit();
    // cout << "Description du produit : " << endl;
    // cout << description << endl;

    Personnel personnel("Jean Dupont", "Vendeur", "Temps plein", 2500.0);
    personnel.afficherInfos();
    personnel.calculerSalaireNet(250.34);
    

    return 0;

};