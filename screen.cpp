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
    win1=newwin(35,110,0,0);
    win2=newwin(5,110,35,0);
    win3=newwin(40,10,0,110);
    //getch();

    box(win1, ACS_VLINE, ACS_HLINE);
    box(win2, ACS_VLINE, ACS_HLINE);
    box(win3, ACS_VLINE, ACS_HLINE);
    refresh();

    wprintw(win2, "Status: ");
        wprintw(win3, "Oggetti: ");
    //wprintw(win1,mappa.strutturamappa);
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    //mvwaddchnstr(win1,1,1,mappa.strutturamappa,100);

    //getch();
}

 void screen::stampadentromappa(char* test){

    wmove(win2,3,7);
    wprintw(win2,"%s",test);
    wrefresh(win2);
    getch();
}
void screen::statuslivello(WINDOW *win2,int level){
    mvwprintw(win2,2,2, "%s", "LIVELLO:");
    mvwprintw(win2,2,11, "%d", level);
    wrefresh(win2);
}

void screen::statusvita(WINDOW *win2, int vita){
    mvwprintw(win2,3,2, "%s", "VITA:");
    mvwprintw(win2,3,8, "%d",vita);
    wrefresh(win2);
}

void screen::statusmonete(WINDOW *win2, int monete){
    mvwprintw(win2,2,20, "%s", "Monete raccolte:");
    mvwprintw(win2,2,36, "%d", monete);
    wrefresh(win2);

}



