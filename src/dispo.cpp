int     getProduit(string produit){
    for(Produit elm : lstProduit)
        if (elm.getnom() == produit)
            return 1;
    return 0;
}

vector<Magasin*>    dispo(vector<Magasin*> lst, Produit produit, string ville){
    vector<Magasin*>    res;

    for(Magasin elm: lst){
        if (elm.getProduit() && elm.getVille() == ville)
            res.push_back(elm);
    }
    return res;
}