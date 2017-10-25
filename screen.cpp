#include "screen.h"
#include<stdlib.h>
#include<stdio.h>
#include "mappa.h"
#include "stanza.h"

screen::screen()
{
    //ctor
   // altezza=30;
    //larghezza=120;
}

screen::~screen()
{
    //dtor
}

 void screen::inizializzafinestra(){
    win1=newwin(40,150,0,0);
    win2=newwin(5,150,40,0);
    //getch();

    box(win1, ACS_VLINE, ACS_HLINE);
    box(win2, ACS_VLINE, ACS_HLINE);
    refresh();

    wprintw(win2, "Status: ");
    //wprintw(win1,mappa.strutturamappa);
    wrefresh(win1);
    wrefresh(win2);
    //mvwaddchnstr(win1,1,1,mappa.strutturamappa,100);
    wrefresh(win1);
    //getch();
}

 void screen::stampadentromappa(char* test){

    wmove(win2,3,7);
    wprintw(win2,"%s",test);
    wrefresh(win2);
    getch();
}




