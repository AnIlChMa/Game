#include "Position.h"
#include <ncurses/curses.h>
#include "screen.h"


Position::Position()
{
      a[0]='@';
    posy=1;
    posx=1;
    p=new level;
    p->nstanza=1;
    p->num=1;
    p->next=NULL;
    posi=2;
    posj=8;

    //ctor
}


void Position::posmove(WINDOW *win1, mappa mapp){
    int ch= 0;
    mapp.strutturamappa[posi][posj]->room[posx][posy]=a[0];
    mapp.esistestanza(win1);
    if((ch=getch())!= 'q')
    {
        switch(ch)
        {
            case KEY_UP:{
                if(mapp.strutturamappa[posi][posj]->room[posx-1][posy]!='-' ){
                        if(mapp.strutturamappa[posi][posj]->room[posx-1][posy] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx--;
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx-1][posy]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posx--;

                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                        }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
            break;
            }

            case KEY_DOWN:{

                if(mapp.strutturamappa[posi][posj]->room[posx+1][posy]!='-' ){
                          if(mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx++;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx+1][posy]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posx++;
                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                break;

            }

            case KEY_RIGHT:{
                if(mapp.strutturamappa[posi][posj]->room[posx][posy+1]!='|' ){
                          if(mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posy++;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx][posy+1]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posy++;

                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                }}
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                break;

            }

            case KEY_LEFT:{
                if(mapp.strutturamappa[posi][posj]->room[posx][posy-1]!='|' ){
                          if(mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posy--;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx][posy-1]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posy--;

                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                }
            }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                break;

            }

            default:
                break;
        }
        wrefresh(win1);

    }

}

void Position::passaporta(WINDOW *win1,mappa mapp){


mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
mapp.esistestanza(win1);
wrefresh(win1);
//stanza succ sopra
if(posy==4 & posx-1==0){
    posi--;
    posx=5;
    posy=4;
mapp.strutturamappa[posi][posj]->room[posx][posy]='@';
posmove(win1,mapp);
mapp.esistestanza(win1);

wrefresh(win1);}

//stanza succ sotto
if(posy==4 & posx+1==6){
    posi++;
     posx=1;
     posy=4;
mapp.strutturamappa[posi][posj]->room[posx][posy]='@';
posmove(win1,mapp);
mapp.esistestanza(win1);

wrefresh(win1);
}

//stanza succ destra
if(posy+1==8 & posx==3){
    posj++;
     posx=3;
     posy=1;
mapp.strutturamappa[posi][posj]->room[posx][posy]='@';
posmove(win1,mapp);
mapp.esistestanza(win1);

wrefresh(win1);}

//stanza succ sinistra
if(posy-1==0 & posx==3){
    posj--;
     posx=3;
     posy=7;
mapp.strutturamappa[posi][posj]->room[posx][posy]='@';
posmove(win1,mapp);
mapp.esistestanza(win1);

wrefresh(win1);}

}


void Position::crealivello(WINDOW *win1,mappa mapp){
    mapp.stanzasucc(win1);
    wrefresh(win1);
    p->next=new level;
    p=p->next;
    p->nstanza=p->nstanza*2;
    p->num++;
    p->next=NULL;

}



