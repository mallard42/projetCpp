#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "produit.h"
#include "fournisseur.h"
#include "stock.h"
#include "../src/Personnel.cpp"

class Magasin {
    private:
        std::string nom;
        std::string ville;
        std::vector<std::shared_ptr<Stock>> lstStock;
        std::vector<std::shared_ptr<Fournisseur>> lstFournisseur;
        std::vector<std::shared_ptr<Personnel>> lstPersonnel;

    public:
        Magasin(const std::string&,const std::string&);
        ~Magasin();
        void addStock(std::shared_ptr<Stock>);
        void addFournisseur(std::shared_ptr<Fournisseur>);
        void addPersonnel(std::shared_ptr<Personnel>);
        //Getters
        inline std::string getNom() const{ return nom; }
        inline std::string getville() const{ return ville; }
        //SETTERS
        void setNom(const std::string &);
        void setVille(const std::string &);
        
        int  isStock(std::string);

        //PRINT
        void printNom();
        void printVille();
        void printProvenace();
        void printListStock();
        void printListFournisseur();

};

vector<std::shared_ptr<Magasin>>    dispo(vector<std::shared_ptr<Magasin>> lst, Produit::Produit produit, string ville);
