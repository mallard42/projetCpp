#include "../include/stock.h"

void    command(std::shared_ptr<Stock> stock, int volume){
    int     total;

    total = stock->getNbStock() + volume;

    if (total > stock->getMaxStock())
        cout << "La commande est trop importante" << endl;
    else
        stock->setNbStock(total);
}