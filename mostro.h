#ifndef mostro_h
#define mostro_h

#include <stdio.h>
#include "mappa.h"
#include "screen.h"
#include "character.h"
#include "Position.h"


class mostro: public character{
    public:
    mostro();
    void charactervsmostro(WINDOW *win1,WINDOW *win2, screen scr,mappa mapp,Position pos);
   // void movimento(WINDOW *win1, mappa mapp, Position pos);
    void inseriscimostro(WINDOW *win1, mappa mapp, Position pos);
    void mostrovscharacter(WINDOW *win1,WINDOW *win2, screen scr,Position pos,mappa mapp);
    //void movimento(WINDOW *win1, Position pos, mappa mapp);
    void movimento(WINDOW *win1,WINDOW *win2, mappa mapp, Position pos, screen scr);
    int mostrox;
    int mostroy;
};



#endif /* mostro_hpp */

