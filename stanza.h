#ifndef STANZA_H
#define STANZA_H
#include<vector>
#include<iostream>
//#include "mappa.h"

using namespace std;

class stanza
{
    public:
        stanza();
        char room[7][9];

        virtual ~stanza();
        creastanza();
        stamparoom();
        creaporta();


    protected:


    private:
};

#endif // STANZA_H
