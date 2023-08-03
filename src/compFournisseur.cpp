#include "../include/fournisseur.h"

template <typename T>
T   minimum(T a, T b){
    return (a < b) ? a : b;
}

Fournisseur     *compFornisseur(vector<Fournisseur*> lst, string produit){
    int                 min;
    Fournisseur         *res;
    Produit::Produit    *tmp;

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