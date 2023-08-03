void    command(Stock stock, int volume){
    int     total;

    total = stock.getNbStock() + volume;

    if (total > stock.getMaxStock())
        cout << "La commande est trop importante" << endl;
    else
        stock.setNbStock(total);
}