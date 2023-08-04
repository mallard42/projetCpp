#include "../include/stock.h"

void    alert(vector<std::shared_ptr<Stock>> lstStock){
    /**
    * @param Regarde si les stock ne sont pas sous le seuil critique si ils le sont on passe commande
    * @var lstStock liste de stock 
    */
    
    for(auto &elm : lstStock)
        if (elm->getNbStock() < elm->getMinStock())
            command(elm, elm->getMaxStock() - elm->getMinStock());
}