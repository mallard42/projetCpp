#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "produit.h"
#include "fournisseur.h"
#include "stock.h"

class Magasin {
    private:
        std::string nom;
        std::string ville;
        std::vector<Stock *> lstStock;
        std::vector<Fournisseur *> lstFournisseur;
    public:
        Magasin(const std::string&,const std::string&);
        ~Magasin();
        void addStock(Stock *);
        void addFournisseur(Fournisseur *);
        //Getters
        inline std::string getNom() const{ return nom; }
        inline std::string getville() const{ return ville; }
        //SETTERS
        void setNom(const std::string &);
        void setVille(const std::string &);
        
        //PRINT
        void printNom();
        void printVille();
        void printProvenace();
        void printListStock();
        void printListFournisseur();

};