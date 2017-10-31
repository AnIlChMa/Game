#include <iostream>
#include <cstdlib>
#include "mappa.h"
#include "stanza.h"
#include <ctime>
#include <ncurses/curses.h>
#include "screen.h"
#include "Position.h"
#include "character.h"
#include "mappa.h"
#include<vector>
using namespace std;
//const int size=12;
//class character;

int main()
{
initscr();

   stanza bla;
    screen finestra;
    Position posit;
    finestra.inizializzafinestra();
    mappa pippo;
    character ch;
    mostro mst;
    pippo.creamappa();
    mst.inseriscimostro(finestra.win1, pippo, posit);
    //bla.creastanza();
   // pippo.istanzia(finestra.win1,2,8);
    // pippo.esistestanza(finestra.win1);
    posit.crealivello(finestra.win1,finestra.win2, pippo, finestra,ch);
   //pippo.stanzasucc(finestra.win1);
    finestra.statusmonete(finestra.win2, ch.monete);
   bool v= ch.vivo(finestra.win2, finestra);
    //chr.raccoglioggetti(finestra.win1,finestra.win2, pippo, finestra, posit);
   keypad(stdscr, TRUE);

    while(v){

   posit.posmove(finestra.win1,finestra.win2, pippo, finestra,ch,posit);
   //mst.movimento(finestra.win1,pippo,posit);
   mst.movimento(finestra.win1, posit,pippo);

    }



//finestra.stampadentromappa("ciao");

       // bla.stanzasucc(finestra.win1);




    getch();
    endwin();
    return 0;
}
