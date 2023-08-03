void    alert(){
    for(Stock elm : lstStock)
        if (elm.getNbStock() < elm.getMinStock())
            command(elm, elm.getMaxStock() - elm.getMinStock());
}