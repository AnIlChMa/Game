#ifndef STANZA_H
#define STANZA_H
#include<vector>
#include<iostream>
#include "screen.h"

//#include "mappa.h"

using namespace std;

class stanza
{
    public:
        stanza();
        char room[7][10];


        virtual ~stanza();
        void creastanza();
        void stamparoom();
        void creaporta();
        void wprintroom(WINDOW *win1,int x,int y);
       void  stanzasucc(WINDOW *win1);


    protected:

    private:
};

#endif // STANZA_H
