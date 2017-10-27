#ifndef POSITION_H
#define POSITION_H
#include "screen.h"
#include "mappa.h"


class Position
{
    public:
        Position();

        //virtual ~Position();
        void posmove(WINDOW *win1,mappa mapp);
        void passaporta(WINDOW *win1,mappa mapp);
        void crealivello(WINDOW *win1,mappa mapp);

 int posi;
        int posj;
        int posy;
 int posx;
 char main_char = '@';
 int h;
    protected:


        char a[1];


         struct level{
        int num;
        int nstanza;
        level *next;
    };
    typedef level *ptr_level;
    ptr_level p;

    private:
};

#endif // POSITION_H
