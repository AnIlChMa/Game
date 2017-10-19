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
        /*for(int r=1;r<7;r++){
                Matrice[r]->a[1]='|';
                Matrice[r]->a[8]='|';
        }
        for(int c=1;c<9;c++){
                Matrice[1]->a[c]='_';
                Matrice[6]->a[c]='-';
        }
                for(int r=2;r<6;r++){
                    for(int c=2;c<8;c++){
                        Matrice[r]->a[c]=' ';
                    }
                }
        Matrice[7]->a[9]='\0';
            Matrice[3]->a[4]='@';*/
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

