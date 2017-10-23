#include "mappa.h"
#include "stanza.h"
//#include "stanza.cpp"
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include "screen.h"
#include <ncurses/curses.h>

using namespace std;
mappa::mappa()
{
    //ctor
}

mappa::~mappa()
{
    //dtor
}
     //funzione che crea la lista delle liste(ossia la lista delle matrici/stanze)
        mappa::creamappa(){
            //srand(time(0));
           // int y=(rand()%10+1);
           // int z=(rand()%10+1);
         //stanza test();
         strutturamappa.resize(20);
         for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                   stanza* x=new stanza();
                   strutturamappa[i].push_back(x);
        }}
           /* cout<<y<<endl;
                    cout<<z<<endl;
                    strutturamappa[y][z]->creastanza();*/

        }
 //non serve
    /*  mappa::stampamappa(){
       for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                cout<<strutturamappa[i][j];
       cout<<endl;     }
            }*/
            /*for(std::vector<std::vector<stanza<*char> > >::const_iterator it=strutturamappa.begin();it!=strutturamappa.end();it++){
                std::string tmp=*it;
                wprintw(win1,tmp.c_str());
            }

        }*/




//funzione che controlla l'esistenza delle stanze visto che non si possono visualizzare senza ncurses tramite una matrice che stampa 0 se non c'e e 1 altrimenti
        mappa::esistestanza(WINDOW *win1){
            bool flag[20][20];
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    if(strutturamappa[i][j]->room[0][0]!=' ')
                        flag[i][j]=true;
                    else
                        flag[i][j]=false;
                }
            }



            for(int i=0;i<20;i++){
                    for(int j=0;j<20;j++){
                        //cout<<flag[i][j];
                        if(flag[i][j]==true){
                            strutturamappa[i][j]->wprintroom(win1, i*7, j*9);
                  }
        }
                //cout<<endl;
                wrefresh(win1);
            }

        }

        mappa::stanzasucc(WINDOW *win1){
    bool flag[20][20];
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(strutturamappa[i][j]->room[0][0]!=' ')
                flag[i][j]=true;
            else
                flag[i][j]=false;
        }
    }

    for(int i=0; i<20;i++){
        for(int j=0;j<20;j++){
            if(flag[i][j]==true){
                srand(time(0));
                int k=(rand()%4+1);

                switch(k){
                    case 1:{
                        if(flag[i-1][j]==false){
                         strutturamappa[i][j]->room[0][4]='/';
                        istanzia(win1,i-1, j);
                        strutturamappa[i-1][j]->room[6][4]='/';
                        esistestanza(win1);
                        wrefresh(win1);
                        }
                    }
                        break;
                    case 2:{
                        if(flag[i][j+1]==false){
                        strutturamappa[i][j]->room[3][8]='/';
                         istanzia(win1, i, j+1);
                        strutturamappa[i][j+1]->room[3][0]='/';

                        esistestanza(win1);
                        wrefresh(win1);
                        }
                    }
                        break;
                    case 3:{
                        if(flag[i+1][j]==false){
                        strutturamappa[i][j]->room[6][4]='/';
                        istanzia(win1,i+1, j);
                        strutturamappa[i+1][j]->room[0][4]='/';

                        esistestanza(win1);
                        wrefresh(win1);}

                    }
                        break;
                    case 4:{
                        if(flag[i][j]==false){
                        strutturamappa[i][j-1]->room[3][0]='/';
                        istanzia(win1, i, j-1);
                        strutturamappa[i][j-1]->room[3][8]='/';

                        esistestanza(win1);
                        wrefresh(win1);
                        }
                    }
                        break;
                    default:
                        break;
                }
                wrefresh(win1);
            }
        }
    }

}


            //crea una stanza all'interno della mappa nella posizione x,y presa in input
//x,y indicano la posizione della prima stanza
    mappa::istanzia(WINDOW *win1,int x,int y){
    strutturamappa[x][y]->creastanza();

}
