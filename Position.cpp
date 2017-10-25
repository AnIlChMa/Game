#include "Position.h"
#include <ncurses/curses.h>
#include "screen.h"


Position::Position()
{
      a[0]='@';
    posy=1;
    posx=1;

    //ctor
}


Position::posmove(WINDOW *win1, mappa mapp,int i,int j){

    int ch= 0;
    mapp.strutturamappa[i][j]->room[posx][posy]=a[0];
    mapp.esistestanza(win1);
    while((ch=getch())!= 'q')
    {
        switch(ch)
        {
            case KEY_UP:{
                if(mapp.strutturamappa[i][j]->room[posx-1][posy]!='-' ){
                        if(mapp.strutturamappa[i][j]->room[posx-1][posy]=='/'){
                                passaporta(win1,mapp,i,j);}
                        else{
                mapp.strutturamappa[i][j]->room[posx][posy]=' ';
                posx--;

                mapp.strutturamappa[i][j]->room[posx][posy]='@';
                mapp.esistestanza(win1);
                        }
                }
                else
                    mapp.strutturamappa[i][j]->room[posx][posy]='@';
            break;
            }

            case KEY_DOWN:{

                if(mapp.strutturamappa[i][j]->room[posx+1][posy]!='-' ){
                        if(mapp.strutturamappa[i][j]->room[posx+1][posy]=='/'){
                                passaporta(win1,mapp,i,j);}
                        else{
                mapp.strutturamappa[i][j]->room[posx][posy]=' ';
                posx++;
                mapp.strutturamappa[i][j]->room[posx][posy]='@';
                mapp.esistestanza(win1);
                }
                }
                else
                    mapp.strutturamappa[i][j]->room[posx][posy]='@';
                break;

            }

            case KEY_RIGHT:{
                if(mapp.strutturamappa[i][j]->room[posx][posy+1]!='|' ){
                        if(mapp.strutturamappa[i][j]->room[posx][posy+1]=='/'){
                                passaporta(win1,mapp,i,j);}
                        else{
                mapp.strutturamappa[i][j]->room[posx][posy]=' ';
                posy++;

                mapp.strutturamappa[i][j]->room[posx][posy]='@';
                mapp.esistestanza(win1);
                }}
                else
                    mapp.strutturamappa[i][j]->room[posx][posy]='@';
                break;

            }

            case KEY_LEFT:{
                if(mapp.strutturamappa[i][j]->room[posx][posy-1]!='|' ){
                        if(mapp.strutturamappa[i][j]->room[posx][posy-1]=='/'){
                                passaporta(win1,mapp,i,j);}
                        else{
                mapp.strutturamappa[i][j]->room[posx][posy]=' ';
                posy--;

                mapp.strutturamappa[i][j]->room[posx][posy]='@';
                mapp.esistestanza(win1);
                }
            }
                else
                    mapp.strutturamappa[i][j]->room[posx][posy]='@';
                break;

            }

            default:
                break;
        }
        wrefresh(win1);

    }

}

Position::passaporta(WINDOW *win1,mappa mapp,int i,int j){


mapp.strutturamappa[i][j]->room[posx][posy]=' ';
mapp.esistestanza(win1);
wrefresh(win1);
//stanza succ sopra
if(posy==4 & posx-1==0){
    i--;
    posx=5;
    posy=4;
mapp.strutturamappa[i][j]->room[posx][posy]='@';
mapp.esistestanza(win1);
posmove(win1,mapp,i,j);
wrefresh(win1);}

//stanza succ sotto
if(posy==4 & posx+1==6){
    i++;
     posx=1;
     posy=4;
mapp.strutturamappa[i][j]->room[posx][posy]='@';
mapp.esistestanza(win1);
posmove(win1,mapp,i,j);
wrefresh(win1);
}

//stanza succ destra
if(posy+1==8 & posx==3){
    j++;
     posx=3;
     posy=1;
mapp.strutturamappa[i][j]->room[posx][posy]='@';
mapp.esistestanza(win1);
posmove(win1,mapp,i,j);
wrefresh(win1);}

//stanza succ sinistra
if(posy-1==0 & posx==3){
    j--;
     posx=3;
     posy=7;
mapp.strutturamappa[i][j]->room[posx][posy]='@';
mapp.esistestanza(win1);
posmove(win1,mapp,i,j);
wrefresh(win1);}

}
