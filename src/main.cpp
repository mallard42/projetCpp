#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "../include/categorie.h"
#include "../include/produit.h"
#include "../include/magasin.h"
#include "../include/fournisseur.h"

int     main(){
    Categorie::Categorie categorie("vetement", "cm", 38, 43);

    Produit::Produit produit(categorie, "T-shirt de sport", "Fitness", 25.0, 30.0, false, 0.0);
    Produit::Produit produit2(categorie, "T-shirt de sport femme", "Fitness", 25.0, 30.0, false, 0.0);

    std::shared_ptr<Stock> stock1(new Stock(produit, 10, 500, 25, 20));
    std::shared_ptr<Stock> stock2(new Stock(produit2, 10, 1000, 25, 20));

    std::shared_ptr<Produit::Produit>    produit4(new Produit::Produit(categorie, "T-shirt femme", "Fitness", 25.0, 30.0, false, 0.0));
    std::shared_ptr<Produit::Produit>    produit5(new Produit::Produit(categorie, "T-shirt homme", "Fitness", 25.0, 30.0, false, 0.0));

    std::shared_ptr<Fournisseur> fournisseur(new Fournisseur("gilbert", "usa"));

    fournisseur->addProduit(produit4);
    fournisseur->addProduit(produit5);

    fournisseur->printNom();
    fournisseur->printProvenance();
    fournisseur->printListProduit();

    Magasin         magasin("walmart", "new york");

    magasin.addFournisseur(fournisseur);
    magasin.addStock(stock1);
    magasin.addStock(stock2);

    magasin.printListFournisseur();
    magasin.printListStock();

    Personnel person("nom","poste","horraie",1);
    Client client("client",10);
    person.afficherInfos();
    client.afficherInfos();
    // vector<unique_ptr<Personne>> lstPeople;
    // lstPeople.push_back(make_unique<Personne> ("nom"));
    return 0;
}