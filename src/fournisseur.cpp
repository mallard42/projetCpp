#include "fournisseur.h"

Fournisseur::Fournisseur(const std::string& _nom,const std::string& _provenance)
:nom(_nom),provenance(_provenance)
{

}

Fournisseur::~Fournisseur()
{
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        delete *produit
    lstProduit.clear();
    std::cout <<"liste fournisseur détruite"<< std::endl;
}

void Fournisseur::addProduit(const Produit * produit)
{
    lstProduit.push_back(produit);
}

//SETTERS
void Fournisseur::setNom(const std::string & _nom)
{
    nom = _nom;
}

void Fournisseur::setProvenance(const std::string & _provenance)
{
    provenance = _provenance;
}


//PRINT
void printNom()
{
    std::cout <<"\t Le nom du fournisseur: "<< nom << std::endl;
}

void printProvenance()
{
    std::cout <<"\t Le provenance du fournisseur: "<< provenance << std::endl;
}

void printListProduit()
{
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        (*produit)->printProduit() //#doute

}
