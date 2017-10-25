#include <iostream>
#include <cstdlib>
#include "mappa.h"
#include "stanza.h"
#include <ctime>
#include <ncurses/curses.h>
#include "screen.h"
#include "Position.h"
#include<vector>
using namespace std;
//const int size=12;


int main()
{
initscr();

    mappa pippo;
    Position pos;
    stanza bla;
    screen finestra;
    finestra.inizializzafinestra();



    pippo.creamappa();
    //bla.creastanza();
    //pippo.esistestanza();

    //pippo.scriviinfinestra(finestra.win1);

pippo.istanzia(finestra.win1,2,8);
     pippo.esistestanza(finestra.win1);


    //bla.creaporta();
     //cout<<"comincia";
        //bla.wprintroom(finestra.win1,9,50);
        //pippo.stanzasucc(finestra.win1);
        keypad(stdscr, TRUE);
            while(true){
           pos.posmove(finestra.win1,pippo);
//finestra.stampadentromappa("ciao");
            }
       // bla.stanzasucc(finestra.win1);



    refresh();
    getch();
    endwin();
    return 0;
}
