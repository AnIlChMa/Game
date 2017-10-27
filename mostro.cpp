#include "mostro.h"

mostro::mostro()
{
    //ctor
    this->attacco;
    this->difesa;
    this->descr;

}

mostro::battaglia(WINDOW *win1){
    //controllo che ci sia vita
    if (character::vita>0){
            //se l'attacco del personaggi è minore della difesa del mostro tolgo vita al personaggio altrimnti al mostro
       int k=(character::attacco)-(difesa);
                character::vita=character::vita-(k*0.1);
                vivo();}

    }

