#include "../include/magasin.h"
#include "../include/produit.h"

vector<Magasin*>    dispo(vector<Magasin*> lst, Produit::Produit produit, string ville){
    vector<Magasin*>    res;

    for(auto &elm: lst){
        if (elm->isStock(produit.getnom()) && elm->getville() == ville)
            res.push_back(elm);
    }
    return res;
}