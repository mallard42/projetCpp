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
    // categorie.afficherInfos();

    Produit::Produit produit(categorie, "T-shirt de sport", "Fitness", 25.0, 30.0, false, 0.0);
    // Produit::Produit produit4(categorie, "T-shirt de sport", "Fitness", 25.0, 30.0, false, 0.0);
    // produit->afficherInfos();

    Produit::Produit produit2(categorie, "T-shirt de sport femme", "Fitness", 25.0, 30.0, false, 0.0);
    // Produit::Produit produit3(categorie, "T-shirt de sport femme", "Fitness", 25.0, 30.0, false, 0.0);
    // produit2->afficherInfos();

    // float prixTTC = produit.getPrixTTC();
    // cout << "Prix TTC après promotion : " << prixTTC << endl;
    
    // string description = produit.descriptionProduit();
    // cout << "Description du produit : " << endl;
    // cout << description << endl;

    Stock   *stock1 = new Stock(produit, 10, 500, 25, 20);
    Stock   *stock2 = new Stock(produit2, 10, 1000, 25, 20);

    Fournisseur     *fournisseur = new Fournisseur("gilbert", "usa");

    // fournisseur->addProduit(produit);
    // fournisseur->addProduit(produit2);

    // fournisseur.printNom();
    // fournisseur.printProvenance();
    // fournisseur.printListProduit();

    Magasin         magasin("walmart", "new york");

    magasin.addFournisseur(fournisseur);
    magasin.addStock(stock1);
    magasin.addStock(stock2);

    magasin.printListFournisseur();
    magasin.printListStock();

    return 0;
}