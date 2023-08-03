int     isProduit(string produit){
    for(Produit elm : lstStock)
        if (elm.getNom() == produit)
            return 1;
    return 0;
}

vector<Magasin*>    dispo(vector<Magasin*> lst, Produit produit, string ville){
    vector<Magasin*>    res;

    for(Magasin elm: lst){
        if (elm.isProduit() && elm.getville() == ville)
            res.push_back(elm);
    }
    return res;
}