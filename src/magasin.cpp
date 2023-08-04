#include "../include/magasin.h"

Magasin::Magasin(const std::string& _nom,const std::string& _ville)
:nom(_nom),ville(_ville)
{

}

Magasin::~Magasin()
{
    // for(auto produit = lstStock.begin();produit < lstStock.end(); produit ++)
    //     delete *produit;
    
    // for(auto fournisseur = lstFournisseur.begin();fournisseur < lstFournisseur.end(); fournisseur ++)
    //     delete *fournisseur;
    lstStock.clear();
    lstFournisseur.clear();
    std::cout <<"liste Magasin détruite"<< std::endl;
}


void Magasin::addStock(std::shared_ptr<Stock> stock)
{
    /**
    * @param Ajouter Stock
    */
    lstStock.push_back(stock);
}

void Magasin::addFournisseur(std::shared_ptr<Fournisseur> fournisseur)
{
    /**
    * @param Ajouter Fournisseur
    */
    lstFournisseur.push_back(fournisseur);
}

void Magasin::addPersonnel(std::shared_ptr<Personnel> personnel){
    /**
    * @param Ajouter Personnel
    */
    lstPersonnel.push_back(personnel);
}

//SETTERS
void Magasin::setNom(const std::string & _nom)
{
    /**
    * @param Modifier nom
    */
    nom = _nom;
}

void Magasin::setVille(const std::string & _ville)
{
    /**
    * @param Modifier ville
    */
    ville = _ville;
}


//PRINT
void Magasin::printNom()
{
    /**
    * @param Afficher nom
    */
    std::cout <<"\t Le nom du Magasin: "<< nom << std::endl;
}

void Magasin::printVille()
{
    /**
    * @param Afficher ville
    */
    std::cout <<"\t Le ville du Magasin: "<< ville << std::endl;
}

void Magasin::printListStock()
{
    /**
    * @param Afficher Stock
    */
    for(auto stock = lstStock.begin();stock < lstStock.end(); stock++)
        (*stock)->print(); //#doute

}

void Magasin::printListFournisseur()
{
    /**
    * @param Afficher Fournisseur
    */
    for(auto fournisseur = lstFournisseur.begin();fournisseur < lstFournisseur.end(); fournisseur++){
        (*fournisseur)->printNom();
        (*fournisseur)->printProvenance();
    }

}

//IS
int     Magasin::isStock(string produit){
    /**
    * @param Regarde si le produit existe dans le stock 
    * @return bool
    * @retval 1 si vrai
    * @retval 0 si faux
    */
    for(auto &elm : lstStock)
        if (elm->getnom() == produit)
            return 1;
    return 0;
}