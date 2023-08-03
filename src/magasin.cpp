#include "../include/magasin.h"

Magasin::Magasin(const std::string& _nom,const std::string& _ville)
:nom(_nom),ville(_ville)
{

}

Magasin::~Magasin()
{
    for(auto produit = lstStock.begin();produit < lstStock.end(); produit ++)
        delete *produit;
    
    for(auto fournisseur = lstFournisseur.begin();fournisseur < lstFournisseur.end(); fournisseur ++)
        delete *fournisseur;
    lstStock.clear();
    lstFournisseur.clear();
    std::cout <<"liste Magasin détruite"<< std::endl;
}

void Magasin::addStock(Stock * stock)
{
    lstStock.push_back(stock);
}

void Magasin::addFournisseur(Fournisseur * fournisseur)
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
void Magasin::printNom()
{
    std::cout <<"\t Le nom du Magasin: "<< nom << std::endl;
}

void Magasin::printVille()
{
    std::cout <<"\t Le ville du Magasin: "<< ville << std::endl;
}

void Magasin::printListStock()
{
    for(auto stock = lstStock.begin();stock < lstStock.end(); stock++)
        (*stock)->print(); //#doute

}

void Magasin::printListFournisseur()
{
    for(auto fournisseur = lstFournisseur.begin();fournisseur < lstFournisseur.end(); fournisseur++){
        (*fournisseur)->printNom();
        (*fournisseur)->printProvenance();
    }

}

//IS
int     Magasin::isStock(string produit){
    for(auto &elm : lstStock)
        if (elm->getnom() == produit)
            return 1;
    return 0;
}