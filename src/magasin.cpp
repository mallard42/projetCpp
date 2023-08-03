#include "Magasin.h"

Magasin::Magasin(const std::string& _nom,const std::string& _ville)
:nom(_nom),ville(_ville)
{

}

Magasin::~Magasin()
{
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        delete *produit
    
    for(auto fournisseur = lstFournisseur.begin();fournisseur < lstFournisseur.end(); fournisseur ++)
        delete *fournisseur
    lstProduit.clear();
    lstFournisseur.clear();
    std::cout <<"liste Magasin détruite"<< std::endl;
}

void Magasin::addProduit(const Produit * produit)
{
    lstProduit.push_back(produit);
}

void Magasin::addFournisseur(const Fournisseur * fournisseur)
{
    lstFournisseur.push_back(fournisseur);
}

//SETTERS
void Magasin::setNom(const std::string & _nom)
{
    nom = _nom;
}

void Magasin::setVille(const std::string & _ville)
{
    ville = _ville;
}


//PRINT
void printNom()
{
    std::cout <<"\t Le nom du Magasin: "<< nom << std::endl;
}

void printVille()
{
    std::cout <<"\t Le ville du Magasin: "<< ville << std::endl;
}

void printListProduit()
{
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        (*produit)->printProduit() //#doute

}

void printListFournisseur()
{
    for(auto fournisseur = lstFournisseur.begin();fournisseur < lstFournisseur.end(); fournisseur ++){
        (*fournisseur)->printNom();
        (*fournisseur)->printVille();
    }

}