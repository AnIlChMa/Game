#include "mappa.h"
#include "stanza.h"
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
        void mappa::creamappa(){
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
       void mappa::esistestanza(WINDOW *win1){
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

                            strutturamappa[i][j]->wprintroom(win1, i*7,j*9);
                  }
        }
                //cout<<endl;
                wrefresh(win1);
            }

        }

   //crea una stanza adiacente ad una che è già stata creata, la posizione di questa stanza viene decisa tramite un numero random da 1 a 4.

void mappa::stanzasucc(WINDOW *win1, int x,int y){
    bool flag[20][20];
     wclear(win1);
    //ciclo che crea la matrice di 0 e 1 per vedere in che punto è già presente una stanza
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(strutturamappa[i][j]->room[0][0]!=' ')
                flag[i][j]=true;
            else
                flag[i][j]=false;
        }
    }
    //leggiama la matrice flag

   // for(int i=0; i<20;i++){
       // for(int j=0;j<20;j++){
            //se troviamo un 1 (quindi è presente una stanza) tramite k (numero random) scegliamo la posizione della stanza adiacente e la istanziamo e poi la stampiamo
            while(flag[x][y]==true){
                srand((unsigned)time(0));
                int k=(rand()%4+1);

                switch(k){
                        //stanza in alto
                    case 1:{

                                if(flag[x-1][y]== false){

                            //prima mette la porta nella stanza corrente
                        strutturamappa[x][y]->room[0][4]='/';
                        istanzia(win1,x-1, y);

                            //poi nella stanza adiacente che andremo a creare
                        strutturamappa[x-1][y]->room[6][4]='/';


                        controllo(win1, x, y);
                        wrefresh(win1);
                                    x--;
                                }

                    }
                        break;
                        //stanza a destra
                    case 2:{

                                if(flag[x][y+1]== false){

                        strutturamappa[x][y]->room[3][8]='/';
                         istanzia(win1, x, y+1);

                        strutturamappa[x][y+1]->room[3][0]='/';


                        controllo(win1, x, y);
                        wrefresh(win1);
                                    y++;
                                }

                    }
                        break;
                        //stanza in basso
                    case 3:{

                                if(flag[x+1][y]== false){

                        strutturamappa[x][y]->room[6][4]='/';
                        istanzia(win1,x+1, y);

                        strutturamappa[x+1][y]->room[0][4]='/';


                        controllo(win1, x, y);
                        wrefresh(win1);
                                    x++;
                            }

                }
                         break;
                        //stanza a sinistra
                    case 4:{

                                if(flag[x][y-1]== false){

                       strutturamappa[x][y]->room[3][0]='/';
                        istanzia(win1, x, y-1);

                        strutturamappa[x][y-1]->room[3][8]='/';


                        controllo(win1, x, y);
                        wrefresh(win1);
                                    y--;
                            }

                }
                    default:
                        break;
                }

            }
     //   }
   // }
}



//istanzia una stanza all'interno della mappa nella posizione x,y presa in input

  void  mappa::istanzia(WINDOW *win1,int x,int y){
      if((x*7)>0 && (y*9)>0){
          if((x*7+7)<35 && (y*9+9)<110){
              strutturamappa[x][y]->creastanza();
          }
      }
      else
      stanzasucc(win1, x, y); //se una stanza non viene istanziata chiedo di generarne un'altra
}

//funzione che toglie la porta nel caso in cui la stanza succesiva non viene istanziata perchè tocca il bordo
void mappa::controllo(WINDOW *win1, int x, int y){

    bool flag[20][20];

    //ciclo che crea la matrice di 0 e 1 per vedere in che punto è già presente una stanza
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(strutturamappa[i][j]->room[0][0]!=' ')
                flag[i][j]=true;
            else
                flag[i][j]=false;
        }
    }

            if(flag[x][y]==true){
                //leggo la matrice stanza
                for(int r=0;r<7;r++){
                    for(int c=0;c<9;c++){
                        if(strutturamappa[x][y]->room[r][c]=='/'){
                            //se la stanza sopra non è stata creata
                            if(flag[x-1][y]==false){
                              strutturamappa[x][y]->room[0][4]='-';
                                esistestanza(win1);
                                wrefresh(win1);
                            }
                            //se la stanza sotto non è stata creata
                            if(flag[x+1][y]==false){
                                strutturamappa[x][y]->room[6][4]='-';

                                esistestanza(win1);
                                wrefresh(win1);
                            }
                            //se la stanza a sinistra non è stata creata
                            if(flag[x][y-1]==false){
                                strutturamappa[x][y]->room[3][0]='|';

                                esistestanza(win1);
                                wrefresh(win1);
                            }
                            //se la stanza a destra non è stata creata
                            if(flag[x][y+1]==false){
                                strutturamappa[x][y]->room[3][8]='|';

                                esistestanza(win1);
                                wrefresh(win1);
                            }

                        }
                 }

        }
    }

}
