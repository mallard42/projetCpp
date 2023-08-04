#include "../include/fournisseur.h"

template <typename T>
T   minimum(T a, T b){
    return (a < b) ? a : b;
}

std::shared_ptr<Fournisseur> compFornisseur(vector<std::shared_ptr<Fournisseur>> lst, string produit){
    int                                 min;
    std::shared_ptr<Fournisseur>        res;
    std::shared_ptr<Produit::Produit>   tmp;

    for (auto &elm : lst){
        tmp = elm->getProduit(produit);
        if (tmp != nullptr){
            min = minimum<int>(min, tmp->getPrixTTC());
            if (min == tmp->getPrixTTC())
                res = elm;
        }
    }
    return res;
}