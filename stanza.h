#ifndef STANZA_H
#define STANZA_H
#include<vector>
#include<iostream>
#include "screen.h"
#include "Array.h"
//#include "mappa.h"

using namespace std;

class stanza
{
    public:
        stanza();
        char room[7][10];

        virtual ~stanza();
        creastanza();
        stamparoom();
        creaporta();
        wprintroom(WINDOW *win1,int x,int y);
        stanzasucc(WINDOW *win1);


    protected:


    private:
};

#endif // STANZA_H
