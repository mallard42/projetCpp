#include "../include/fournisseur.h"

Fournisseur::Fournisseur(const std::string& _nom,const std::string& _provenance)
:nom(_nom),provenance(_provenance)
{

}

Fournisseur::~Fournisseur()
{
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        delete *produit;
    lstProduit.clear();
    std::cout <<"liste fournisseur détruite"<< std::endl;
}

void Fournisseur::addProduit(Produit::Produit * produit)
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
void Fournisseur::printNom()
{
    std::cout <<"\t Le nom du fournisseur: "<< nom << std::endl;
}

void Fournisseur::printProvenance()
{
    std::cout <<"\t Le provenance du fournisseur: "<< provenance << std::endl;
}

void Fournisseur::printListProduit()
{
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        (*produit)->afficherInfos(); //#doute

}

//GETTER
Produit::Produit *Fournisseur::getProduit(string produit){
    for(auto &elm : lstProduit)
        if (elm->getnom() == produit)
            return elm;
    return nullptr;
}