#include "stanza.h"
#include <iostream>
#include "mappa.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;
stanza::stanza()
{
    //ptr=&room[7][7];
    //ctor
    for(int r=0;r<7;r++){
        for(int c=0;c<9;c++){
            room[r][c]=' ';
        }
    }

}

stanza::~stanza()
{
    //dtor

}
     stanza::creastanza(){
        for(int r=0;r<7;r++){
            for(int c=0;c<9;c++){
                 room[r][c]=' ';
            }
        }
        for(int r=0;r<7;r++){
                room[r][0]='|';
                room[r][8]='|';
                room[r][9]='\0';
        }
        for(int c=0;c<9;c++){
                room[0][c]='O';
                room[6][c]='O';
        }

            room[3][4]='@';

    }



     stanza::stamparoom(){
         for(int i=1;i<7;i++){
            for(int j=1;j<9;j++){
                cout<<room[i][j];
            }
            cout<<endl;
         }
     }


    stanza::wprintroom(WINDOW *win1,int x,int y){
    //cout<<"entra";
//ciclo per stampare la stanza, stampiamo come se fossero "array" di riga
                for(int r=0;r<7;r++){
                        mvwprintw(win1,r+x,y,"%s",room[r]);

                }
            wrefresh(win1);
              // printf(ptr);
    }

    stanza::stanzasucc(WINDOW *win1){
        srand(time(0));
        int k=(rand()%4+1);
        //senso orario

        switch(k){
        case 1:{
            room[6][4]='/';
            wprintroom(win1,3,50);}
        break;
            case 2:{
                room[3][0]='/';
            wprintroom(win1,9,58);}
            break;
                case 3:{
                    room[0][4]='/';
                wprintroom(win1,15,50);}
                break;
                    case 4:{
                        room[3][8]='/';
                    wprintroom(win1,9,42);}
                    break;
                    default:
                        break;
        }
        wrefresh(win1);
        }




