#ifndef CHARACTER_H
#define CHARACTER_H
#include <string.h>
#include "screen.h"
#include "Position.h"
#include "mappa.h"


class character
{
    public:
        character();
        virtual ~character();

        //battaglia(WINDOW *win1);
        bool vivo();
        void raccoglioggetti(WINDOW *win1,mappa mapp,Position pos);
        void usaoggetti(WINDOW *win1,mappa mapp,Position pos);


      protected:
        char descr;
        int vita;
        char nome;
        int difesa;
        int attacco;
        int monete;
        struct loggetti{
            char nomeogg;
            loggetti *next;
        };
        typedef loggetti *ptr_oggetti;
    ptr_oggetti p;


    private:

};

#endif // CHARACTER_H
