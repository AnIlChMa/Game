#include "stanza.h"
#include <iostream>

using namespace std;
stanza::stanza()
{
    //ctor
 //this->room[7][9]=room[7][9];
}

stanza::~stanza()
{
    //dtor

}
     stanza::creastanza(){

        for(int r=0;r<7;r++){
            for(int c=0;c<9;c++){
                room[r][c]='#';

            }
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
