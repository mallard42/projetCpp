void    alert(){
    for(Stock elm : lstProduit)
        if (elm.getNb() < elm.getMin())
            command(elm, elm.getMax() - elm.getMin());
}