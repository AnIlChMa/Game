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
    //ptr=&room[7][9];
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
                room[r][0]='|';
                room[r][8]='|';
        }
        for(int c=0;c<9;c++){
                room[0][c]='_';
                room[6][c]='-';
        }
                for(int r=1;r<6;r++){
                    for(int c=1;c<8;c++){
                        room[r][c]=' ';
                    }
                }

            room[3][4]='@';
    }



     stanza::stamparoom(){
         for(int i=0;i<7;i++){
            for(int j=0;j<9;j++){
                cout<<room[i][j];
            }
            cout<<endl;
         }
     }

    /* stanza::wprintroom(WINDOW *win1){
         char r[7][9];
         r[7][9]=room[7][9];
         for(int i=0;i<7;i++){
            for(int j=0;j<9;j++){
                    wprintw(win1,"%s",r[i][j]);
                    wrefresh(win1);
                    getch();
            }
            }
    }*/

    stanza::wprintroom(WINDOW *win1,char* ptr){
        int x=0;
        int y=0;
        //for(int i=1;i<23;i++){
            //for(int j=1;j<118;j++){
                wmove(win1,5,5);
                for(int r=0;r<9;r++){
                        ptr=&room[x][r];
                        //wprintw(win1,"\n");
                        wprintw(win1,ptr);
                        wrefresh(win1);
                    for(int c=0;c<7;c++){
                        ptr=&room[c][y];
                        wprintw(win1,"\n");
                        wprintw(win1,ptr);

                        wrefresh(win1);
                    }x++;

                }y++;

           // }
        //}
    }


     stanza::creaporta(){
         int k;
         srand(time(0));
           k=(rand()%4+1);
         if (k==1){
         room[0][4]='/';
         }
         if (k==2){
            room[3][8]='/';
            }
         if  (k==3){
            room[6][4]='/';
            }
         if (k==4){
            room[3][0]='/';
                     }
     }

