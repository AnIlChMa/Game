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
    pippo.creamappa();
    pippo.esistestanza();
//    pippo.scriviinfinestra();

    //screen finestra(0,0,30,120);
    screen finestra;
    //screen fin(finestra,0,0,25,120);
finestra.inizializzafinestra();
    refresh();
     //mvwvline(finestra.win1,1,1,pippo.strutturamappa,100);
    //cbreak(finestra.win1)




    //pippo.stampamappa();

   /* stanza bla;
    bla.creastanza();


    bla.creaporta();
    bla.stamparoom();
*/

         //printw("Hello word");
       
    finestra.anapuzza("hahah");//per stampare i caratteri dentro la mappa
    
    refresh();
    getch();
    endwin();
    return 0;
}
