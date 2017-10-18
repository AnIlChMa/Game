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
                room[0][c]='_';
                room[6][c]='-';
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
    cout<<"entra";
        //for(int i=1;i<23;i++){
            //for(int j=1;j<118;j++){
           // for(int r=1;r<2;r++){
           /*wprintw(win1,"crea stanza");
                ptr=&room[1][1];
                wprintw(win1,"\n");
                    wprintw(win1,"%s",ptr);*/
            //wrefresh(win1);
            //wprintw(win1,"\0");
           //for(int c=1;c<7;c++){
                for(int r=0;r<7;r++){
                        //char car;
                        //car=room[c][r];

                        //c[2]='\0';
                        //mvwprintw(win1,1,1,"%s",room);

                        mvwprintw(win1,r+1,1,"%s",room[r]);

                }
            //wprintw(win1, "\n");
            //wprintw(win1,"\n");

            //}
            wrefresh(win1);
        //wrefresh(win1);
        printf(ptr);
       // }
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

