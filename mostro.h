#ifndef MOSTRO_H
#define MOSTRO_H

#include "Position.h"
#include "mappa.h"
#include "screen.h"
#include "character.h"



 class mostro :public character{
    public:
        #include "Position.h"
        mostro();
        //virtual ~mostro();
        battaglia(WINDOW *win1);
        movimento(WINDOW *win1,mappa mapp,Position pos,int i, int j);

    protected:

    private:
};

#endif // MOSTRO_H
