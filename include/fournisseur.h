#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "produit.h"
#include <memory>

/**
 * @file fournisseur.h
 */

class Fournisseur {
    private:
        std::string nom;
        std::string provenance;
        std::vector<std::shared_ptr<Produit::Produit>> lstProduit;
    public:
        Fournisseur(const std::string&,const std::string&);
        ~Fournisseur();
        void addProduit(std::shared_ptr<Produit::Produit>);
        //Getters
        inline std::string getNom() const{ return nom; }
        inline std::string getProvenance() const{ return provenance; }
        std::shared_ptr<Produit::Produit> getProduit(std::string);
        //SETTERS
        void setNom(const std::string &);
        void setProvenance(const std::string &);
        
        //PRINT
        void printNom();
        void printProvenance();
        void printListProduit();

};