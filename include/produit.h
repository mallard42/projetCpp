#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "categorie.h"

using namespace std;

namespace Produit{
    class Produit: public Categorie::Categorie {
        protected:
            string nom;
            string rayon;
            float pht;
            float pttc;
            bool promo;
            float prix_promo;

        public:
            Produit(const Categorie c, const string& _nom, const string& _rayon, float _pht, float _pttc, bool _promo, float _prix_promo)
              :Categorie(c), nom(_nom), rayon(_rayon), pht(_pht), pttc(_pttc), promo(_promo), prix_promo(_prix_promo){}

            Produit(const Produit &_p): Categorie(_p.type, _p.unite, _p.min, _p.max){
                this->nom = _p.nom;
                this->rayon = _p.rayon;
                this->pht = _p.pht;
                this->pttc = _p.pttc;
                this->promo = _p.promo;
                this->prix_promo = _p.prix_promo;
            }
            
            void setnom(const string& _nom){nom = _nom;}
            void setrayon(const string& _rayon){rayon = _rayon;}
            void setpromo(float _prix_promo){prix_promo= _prix_promo;}

            void setpht(float prixHT, int tva){
                pht = prixHT;
                pttc = pht*tva;
            }

            void setpttc(float prixTTC, int tva ){
                pttc = prixTTC;
                pht = pttc/tva;
            }
 
            string getnom(){return nom;}
            string getrayon(){return rayon;}
            
            float getpht(){return pht;}
            float getPrixTTC() const {
                if (promo) {
                    return prix_promo;
                } else {
                    return pttc;
                }
            }

           void afficherInfos() {
                Categorie::afficherInfos();
                cout << "--- PRODUIT ---" << endl;
                cout << "Nom: " << nom << endl;
                cout << "Rayon: " << rayon << endl;
                cout << "Prix HT: " << pht << endl;
                cout << "Prix TTC: " << pttc << endl;
                cout << "Promo: " << (promo ? "Oui" : "Non") << endl;
                if (promo) {
                    std::cout << "Prix Promo: " << prix_promo << endl;
                }
            }

            void Promotion(float pourcentage) {
                if (pourcentage > 0.0 && pourcentage <= 100.0) {
                    promo = true;
                    prix_promo = pttc * (1.0 - pourcentage / 100.0);
                } else {
                    std::cout << "Pourcentage de promo invalide !" << std::endl;
                }
            }

            string descriptionProduit() const {
                std::string description = nom + " (" + rayon + ")\n";
                description += "Prix HT: " + std::to_string(pht) + "\n";
                description += "Prix TTC: " + std::to_string(pttc) + "\n";
                // description += "En promotion: " + (oui ou non)"\n";
                if (promo) {
                    description += "Prix Promo: " + std::to_string(prix_promo) + "\n";
                }
                return description;
            }
};
}