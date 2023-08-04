#include "../include/fournisseur.h"

Fournisseur::Fournisseur(const std::string& _nom,const std::string& _provenance)
:nom(_nom),provenance(_provenance)
{

}

Fournisseur::~Fournisseur()
{
    // for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
    //     delete *produit;
    lstProduit.clear();
    std::cout <<"liste fournisseur détruite"<< std::endl;
}

void Fournisseur::addProduit(std::shared_ptr<Produit::Produit> produit)
{
    /**
    * @param Ajouter Produit
    */
    lstProduit.push_back(produit);
}

//SETTERS
void Fournisseur::setNom(const std::string & _nom)
{
    /**
    * @param Modifier nom
    */
    nom = _nom;
}

void Fournisseur::setProvenance(const std::string & _provenance)
{
    /**
    * @param Modifier provenance
    */
    provenance = _provenance;
}


//PRINT
void Fournisseur::printNom()
{
    /**
    * @param Afficher nom
    */
    std::cout <<"\t Le nom du fournisseur: "<< nom << std::endl;
}

void Fournisseur::printProvenance()
{
    /**
    * @param Afficher provenance
    */
    std::cout <<"\t Le provenance du fournisseur: "<< provenance << std::endl;
}

void Fournisseur::printListProduit()
{
    /**
    * @param Afficher Produit
    */
    for(auto produit = lstProduit.begin();produit < lstProduit.end(); produit ++)
        (*produit)->afficherInfos(); //#doute

}

//GETTER
std::shared_ptr<Produit::Produit> Fournisseur::getProduit(string produit){
    /**
    * @param Recherche si il y a un produit dans ce fournisseur
    * @var produit produit recherché
    */
    
    for(auto &elm : lstProduit)
        if (elm->getnom() == produit)
            return elm;
    return nullptr;
}