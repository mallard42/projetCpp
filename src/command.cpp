void    command(Stock stock, int volume){
    int     total;

    total = stock.getNbr() + volume;

    if (total > stock.getMax())
        cout << "La commande est trop importante" << endl;
    else
        stock.setNbr(total);
}