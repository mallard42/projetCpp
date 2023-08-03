#include "../include/stock.h"

void    alert(vector<Stock *> lstStock){
    for(auto &elm : lstStock)
        if (elm->getNbStock() < elm->getMinStock())
            command(elm, elm->getMaxStock() - elm->getMinStock());
}