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
        char room[7][9];
        char* ptr;

        virtual ~stanza();
        creastanza();
        stamparoom();
        creaporta();
        wprintroom(WINDOW *win1,char* ptr);


    protected:


    private:
};

#endif // STANZA_H
