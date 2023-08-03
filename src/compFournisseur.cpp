template <typename T>
T   minimum(T a, T b){
    return (a < b) ? a : b;
}

int     getProduit(string produit){
    for(Produit elm : lstProduit)
        if (elm.getnom() == produit)
            return 1;
    return 0;
}

Fournisseur     compFornisseur(vector<Fournisseur*> lst, string produit){
    int             min;
    Fournisseur     res;

    for (Fournisseur elm : lst){
        if (elm.getProduit(produit)){
            min = minimum<int>(min, elm.getPTTC);
            if (min == elm.getPTTC)
                res = elm;
        }
    }
    return res;
}