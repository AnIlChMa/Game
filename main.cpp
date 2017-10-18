#include <iostream>
#include <cstdlib>
#include "mappa.h"
#include "stanza.h"
#include <ctime>
#include <ncurses/curses.h>
#include "screen.h"
#include<vector>
using namespace std;
//const int size=12;


int main()
{

   initscr();
    mappa pippo;
    stanza bla;
    screen finestra;
    finestra.inizializzafinestra();
    //finestra.stampadentromappa(bla.ptr);


    pippo.creamappa();
    bla.creastanza();
    pippo.istanzia(3,4);
    //pippo.esistestanza();

    //pippo.scriviinfinestra(finestra.win1);


    //bla.creaporta();
    //bla.stamparoom();
    char* ptr;
     ptr=&bla.room[7][9];
     cout<<"comincia";
        bla.wprintroom(finestra.win1,ptr);



    refresh();
    getch();
    endwin();
    return 0;
}
