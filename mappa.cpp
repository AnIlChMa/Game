#include "mappa.h"
#include "stanza.h"
//#include "stanza.cpp"
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include "screen.h"

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
            srand(time(0));
            int y=(rand()%10+1);
            int z=(rand()%10+1);
         strutturamappa.resize(20);
         //stanza test();
         stanza* x= new stanza();
         for(int i=0;i<20;i++){
                for(int j=0;j<20;j++)
                    strutturamappa[i].push_back(x);
        }
            cout<<y<<endl;
                    cout<<z<<endl;
                    strutturamappa[y][z]->creastanza();

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

      /*  mappa::stanzasucc(){
            stanza st=new stanza;
            int k[1][1];
            for(int i=0;i<7;i++){
                for(int j=0;j<9;j++){
            if(st[i][j]=='/')
                stampamappa(); //richiama la funzione stampamappa per aggiornare la mappa con la nuova stanza creata in base a dove viene generata la porta
        }
        }}*/
//funzione che controlla l'esistenza delle stanze visto che non si possono visualizzare senza ncurses tramite una matrice che stampa 0 se non c'e e 1 altrimenti
        mappa::esistestanza(){
            bool flag[20][20];
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    if(strutturamappa[i][j]->room[0][0]!=' ')
                        flag[i][j]=true;
                    else
                        flag[i][j]=false;
                }
            }

                                    //flag[3][4]=true;
                //cout<<flag[3][4];
            for(int i=0;i<20;i++){
                    for(int j=0;j<20;j++){
                            cout<<flag[i][j];
        }
        cout<<endl;
            }
        }
       /*mappa::scriviinfinestra(){
            wprintw(screen.win1,"g");
       }*/
