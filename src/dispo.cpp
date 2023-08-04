#include "../include/magasin.h"
#include "../include/produit.h"

vector<std::shared_ptr<Magasin>>    dispo(vector<std::shared_ptr<Magasin>> lst, Produit::Produit produit, string ville){
    vector<std::shared_ptr<Magasin>>    res;

    for(auto &elm: lst){
        if (elm->isStock(produit.getnom()) && elm->getville() == ville)
            res.push_back(elm);
    }
    return res;
}