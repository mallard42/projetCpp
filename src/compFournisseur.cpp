template <typename T>
T   minimum(T a, T b){
    return (a < b) ? a : b;
}

int     isProduit(string produit){
    for(Produit elm : lstStock)
        if (elm.getnom() == produit)
            return 1;
    return 0;
}

Fournisseur     compFornisseur(vector<Fournisseur*> lst, string produit){
    int             min;
    Fournisseur     res;

    for (Fournisseur elm : lst){
        if (elm.isProduit(produit)){
            min = minimum<int>(min, elm.getpttc());
            if (min == elm.getpttc())
                res = elm;
        }
    }
    return res;
}