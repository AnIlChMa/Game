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

      mappa::stanzasucc(WINDOW *win1){
        srand(time(0));
        int k=(rand()%4+1);
        //senso orario
        for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
        switch(k){
        case 1:{
            strutturamappa[i][j]->wprintroom(win1,1,50);}
        break;
            case 2:{
            strutturamappa[i][j]->wprintroom(win1,9,59);}
            break;
                case 3:{
                strutturamappa[i][j]->wprintroom(win1,17,50);}
                break;
                    case 4:{
                    strutturamappa[i][j]->wprintroom(win1,9,41);}
                    break;
                    default:
                        break;

        }
               }
        }
        }


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

      /*mappa::scriviinfinestra(WINDOW *win1){
           char tmp[7][9];
           for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                        for(int k=0;k<7;k++){
                            for(int z=0;z<9;z++){

                        tmp[i][j]=strutturamappa[i][j]->room[k][z];


                           }}wmove(win1,7,5);
                           wprintw(win1,"%s",tmp);
                           wrefresh(win1);

       }
           }

           //wprintw(win1, "\n");
            }*/

       /*    mappa::scriviinfinestra(){
                vector<stanza*> st;
                vector<std::vector<stanza*> > ::iterator iti;
                vector<stanza*>::iterator itj;
                vector<std::vector<stanza*> > *ptr;
                ptr=&strutturamappa;
                for(iti=strutturamappa.begin();iti!=strutturamappa.end();iti++){
                        for(itj=(*iti).begin();itj!=(*iti).end();itj++){
                                for(int k=0;k<7;k++){
                                    for(int z=0;z<9;z++){
                                        cout<<strutturamappa[k][z]->room[k][z];
                                        //cout<<ptr->at(stanza.room[k][z])<<endl;
                }
                               }
                           }
                }
            }*/


            //crea una stanza all'interno della mappa nella posizione x,y presa in input
//x,y indicano la posizione della prima stanza
    mappa::istanzia(int x,int y){
    //i cout erano di controllo
    cout<<"il carattere e' ."<<strutturamappa[x][y]->room[0][0]<<"."<<endl;
    strutturamappa[x][y]->creastanza();
    cout<<"il carattere e' ."<<strutturamappa[x][y]->room[0][0]<<".";
    cout<<endl;
}
