#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "produit.h"
#include "fournisseur.h"

class Magasin {
    private:
        std::string nom;
        std::string ville;
        std::vector<* Produit> lstProduit;
        std::vector<* Fournisseur> lstFournisseur;
    public:
        Magasin(const std::string&,const std::string&);
        ~Magasin();
        void addProduit(const Produit *);
        void addFournisseur(const Fournisseur *);
        //Getters
        inline std::string getNom() const{ return nom; }
        inline std::string getville() const{ return ville; }
        //SETTERS
        void setNom(const std::string &);
        void setville(const std::string &);
        
        //PRINT
        void printNom();
        void printProvenace();
        void printListeProduit();

};