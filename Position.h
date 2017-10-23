#ifndef POSITION_H
#define POSITION_H
#include "screen.h"
#include "mappa.h"


class Position
{
    public:
        Position();
        int posx;
        char a[1];
        int posy;
        //virtual ~Position();
        posmove(WINDOW *win1,mappa mapp);
        passaporta(WINDOW *win1,mappa mapp,int i,int j);



    protected:
        char main_char = '@';


    private:
};

#endif // POSITION_H
