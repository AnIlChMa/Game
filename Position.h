#ifndef POSITION_H
#define POSITION_H
#include "screen.h"
#include "mappa.h"
#include "mostro.h"
#include "character.h"


class Position
{
    public:
        Position();

        //virtual ~Position();
void posmove(WINDOW *win1,WINDOW *win2, mappa mapp, screen scr,character chr, Position pos);
void passaporta(WINDOW *win1,WINDOW *win2, mappa mapp, screen scr, character chr, Position pos);
         void crealivello(WINDOW *win1,WINDOW *win2,mappa mapp, screen scr, character chr);
    void generachiave(WINDOW *win1,mappa mapp);
    void generamostri(WINDOW *win1,mappa mapp);
    void generamonete(WINDOW *win1,mappa mapp);
        int posi;
        int posj;
        int posy;
        int posx;
        char main_char = '@';
        int h;
        int level;
        int ch;
    protected:
        int numstanza;


    private:
};

#endif // POSITION_H
