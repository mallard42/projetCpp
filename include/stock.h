#include "produit.h"

class Stock: public Produit::Produit{
    private:
        int     minStock;
        int     maxStock;
        int     nbStock;
        int     alertStock; // ??

    public:
        // Stock(){}
        Stock(const Produit &_p, int _min, int _max, int _nb, int _alert):
            Produit(_p), minStock(_min), maxStock(_max), nbStock(_nb), alertStock(_alert) {}

        void    setMinStock(int _min){minStock = _min;}
        void    setMaxStock(int _max){maxStock = _max;}
        void    setNbStock(int _nb){nbStock = _nb;}
        void    setAlertStock(int _alert){alertStock = _alert;}

        int     getMinStock(){return minStock;}
        int     getMaxStock(){return maxStock;}
        int     getNbStock(){return nbStock;}
        int     getAlertStock(){return alertStock;}

        void    alert(){
            if (nbStock < minStock)
                cout << "Seuil critique !!" << endl;
        }

        void    print(){
            cout << "--------" << endl;
            // this->Produit::Produit::print();
            cout << "\nMin: " << minStock << endl;
            cout << "Max: " << maxStock << endl;
            cout << "Nombre en stock: " << nbStock << endl;
            cout << "Seuil d'alerte: " << alertStock << endl;

        }

        ~Stock() = default;
};

void    command(std::shared_ptr<Stock> stock, int volume);
void    alert(vector<std::shared_ptr<Stock>> lstStock);