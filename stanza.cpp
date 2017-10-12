#include "stanza.h"
#include <iostream>
#include "mappa.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;
stanza::stanza()
{
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

