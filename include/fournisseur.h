#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "produit.h"

class Fournisseur {
    private:
        std::string nom;
        std::string provenance;
        std::vector<* Produit> lstProduit;
    public:
        Fournisseur(const std::string&,const std::string&);
        ~Fournisseur();
        void addProduit(const Produit *);
        //Getters
        inline std::string getNom() const{ return nom; }
        inline std::string getProvenance() const{ return provenance; }
        //SETTERS
        void setNom(const std::string &);
        void setProvenance(const std::string &);
        
        //PRINT
        void printNom();
        void printProvenace();
        void printListProduit();

};