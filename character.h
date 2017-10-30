#ifndef character_h
#define character_h
#include <string.h>
#include "screen.h"
#include "mappa.h"
#include <stdio.h>


class Position;

class character{
    public:
        character();
       //virtual ~character();

        //battaglia(WINDOW *win1);
        bool vivo(WINDOW *win2, screen scr);

void raccoglioggetti(WINDOW *win1,WINDOW *win2,mappa mapp,screen scr, Position pos);
void usaoggetti(WINDOW *win1,mappa mapp, Position pos);
char nome;
int monete;
      protected:
        char descr;
        int vita;

        int difesa;
        int attacco;

        struct loggetti{
            char nomeogg;
            loggetti *next;
        };
        typedef loggetti *ptr_oggetti;
    ptr_oggetti p;


    private:

};

#endif // CHARACTER_H
