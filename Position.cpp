#include "Position.h"
#include <ncurses/curses.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "screen.h"




Position::Position(){

    posy=1;
    posx=1;
    posi=2;
    posj=8;
    level=1;
    numstanza=0;
    h=50;
    ch=0;
}

//aggiungere un parametro per indicare chi si deve spostare (personaggio/mostro)
void Position::posmove(WINDOW *win1,WINDOW *win2, mappa mapp, screen scr,character chr, Position pos){

    mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
   mapp.esistestanza(win1);

    int c=0;
    if((c=getch())!= 'q')
    {
        switch(c)
        {
            case KEY_UP:{
                ch=1;
                if(mapp.strutturamappa[posi][posj]->room[posx-1][posy] !='-'){
                    if(mapp.strutturamappa[posi][posj]->room[posx-1][posy] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx--;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                        crealivello(win1,win2, mapp,scr,chr);

                    }
                    if( mapp.strutturamappa[posi][posj]->room[posx-1][posy] =='j' || mapp.strutturamappa[posi][posj]->room[posx-1][posy] =='o' || mapp.strutturamappa[posi][posj]->room[posx-1][posy] =='X'){

                        chr.raccoglioggetti(win1,win2,mapp,scr,pos);

                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx--;

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                    }
                    if(mapp.strutturamappa[posi][posj]->room[posx-1][posy] =='/' ){
                        passaporta(win1,win2, mapp ,scr,chr,pos);

                        }
                    if(mapp.strutturamappa[posi][posj]->room[posx-1][posy] ==' '){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx--;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                        mapp.esistestanza(win1);
                }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
                break;
                            }

            case KEY_DOWN:{
                ch=3;
                if(mapp.strutturamappa[posi][posj]->room[posx+1][posy] !='-' ){
                    if(mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='j'){

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=' ';
                        posx++;

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                         crealivello(win1,win2, mapp,scr,chr);

                    }
                    if( mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='j' || mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='o' || mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='X'){
                        chr.raccoglioggetti(win1,win2,mapp,scr,pos );

                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx++;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                    }
                    if(mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='/' ){
                        passaporta(win1,win2, mapp ,scr, chr,pos);


                    }
                    if(mapp.strutturamappa[posi][posj]->room[posx+1][posy] ==' '){
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=' ';
                        posx++;

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                        mapp.esistestanza(win1);
                        }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
                break;

            }

            case KEY_RIGHT:{
                ch=2;
                        if (mapp.strutturamappa[posi][posj]->room[posx][posy+1]!='|'){
                            if(mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='j'){

                                mapp.strutturamappa[posi][posj]->room[ posx][ posy]=' ';
                                posy++;

                                mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                                crealivello(win1,win2, mapp,scr,chr);

                                    }
                            if( mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='j' || mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='o' || mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='X'){
                                chr.raccoglioggetti(win1,win2,mapp,scr,pos );

                                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                                posy++;
                                mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                            }
                    if(mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='/' ){
                        passaporta(win1,win2, mapp ,scr,chr,pos);
                                            }
                    if(mapp.strutturamappa[posi][posj]->room[posx][posy+1] ==' '){
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=' ';
                        posy++;

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                        mapp.esistestanza(win1);
                    }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
                break;

            }

            case KEY_LEFT:{
                ch=4;

                if(mapp.strutturamappa[posi][posj]->room[posx][posy-1]!='|'){
                    if(mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='j'){
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=' ';
                        posy--;

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                        crealivello(win1,win2, mapp,scr,chr);


                    }
                    if( mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='j' || mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='o' || mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='X'){
                        chr.raccoglioggetti(win1,win2,mapp,scr,pos );

                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posy--;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                    }
                    if(mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='/' ){
                        passaporta(win1,win2, mapp ,scr,chr,pos);

                    }
                    if(mapp.strutturamappa[posi][posj]->room[posx][posy-1] ==' '){
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=' ';
                        posy--;

                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=chr.nome;
                        mapp.esistestanza(win1);
                    }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
                break;

            }

            default:
                break;
        }

        wrefresh(win1);
    }


}


 //funzione che permette al personaggio di passare tramite la porta da una stanza ad un altra
void Position::passaporta(WINDOW *win1,WINDOW *win2, mappa mapp, screen scr, character chr, Position pos){

    mapp.strutturamappa[posi][posj]->room[posx][ posy]=' ';
    mapp.esistestanza(win1);
    wrefresh(win1);

    //se la stanza successiva è stata creata sopra
    if((posx-1)==0 && posy==4){
        posi--;
        posx=5;
        posy=4;
        mapp.strutturamappa[posi][posj]->room[posx][ posy]=chr.nome;
         posmove(win1,win2, mapp ,scr, chr,pos);
        mapp.esistestanza(win1);

        wrefresh(win1);
    }
   //se la stanza successiva è stata creata sotto
    if((posx+1)==6 && posy==4){
        posi++;
        posx=1;
        posy=4;
        mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
        posmove(win1,win2, mapp ,scr, chr,pos);
        mapp.esistestanza(win1);

        wrefresh(win1);
    }
    //se la stanza successiva è stata creata destra
    if(posx==3 && (posy+1)==8){
        posj++;
        posx=3;
        posy=1;
        mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
        posmove(win1,win2, mapp ,scr,chr,pos);
        mapp.esistestanza(win1);

        wrefresh(win1);
    }
    //se la stanza successiva è stata creata sinistra
    if(posx==3 && (posy-1)==0){
        posj--;
        posx=3;
        posy=7;
        mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
        posmove(win1,win2, mapp, scr, chr,pos);
        mapp.esistestanza(win1);

        wrefresh(win1);
    }

}

void Position::crealivello(WINDOW *win1,WINDOW *win2, mappa mapp, screen scr,character chr){

    scr.statuslivello(win2,level);
    wrefresh(win2);
    bool flag[20][20];
    int c;//mi fornisce nel while il parametro di controllo per determinare il numero di stanze per livello

    //ciclo che crea la matrice di 0 e 1 per vedere in che punto è già presente una stanza
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(mapp.strutturamappa[i][j]->room[0][0]!=' ')
                flag[i][j]=true;
            else
                flag[i][j]=false;
        }
    }
    //creo la prima stanza con il personaggio all'interno
    if(level==1){
generamonete(win1,mapp);
generamostri(win1,mapp);
        mapp.istanzia(win1, posi, posj);
        mapp.strutturamappa[posi][posj]->room[posx][posy]=chr.nome;
        generachiave(win1, mapp);


        mapp.esistestanza(win1);
        wrefresh(win1);
        level++;
        h=h*2;
    }
    //per i livelli successivi prima controllo il numero di stanze che sono già state create e vado a istanziarne altre quante me ne servono in base al livello
    else if(level!= 1){


        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(flag[i][j]==true){
                    numstanza++; //numero di stanze già istanziate
                }
            }
        }
        c=level;
        while(numstanza<(c+1)){

            mapp.stanzasucc(win1,posi,posj);
            numstanza++;
            generamonete(win1,mapp);
            generamostri(win1,mapp);
        }
        numstanza=0;
       generachiave(win1, mapp);


       mapp.esistestanza(win1);
        wrefresh(win1);
        level++;
        h=h*2;

    }
     numstanza=0;
}

//genera la chiave in una sola delle stanze generate per livello, questa funzione verrà chiamata solo quando l'utente raccoglie un tot di monete (diverso per livello)
void Position::generachiave(WINDOW *win1,mappa mapp){
    numstanza=0;

    bool flag[20][20];
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(mapp.strutturamappa[i][j]->room[0][0]!=' '){
                flag[i][j]=true;
                numstanza++;
            }
            else
                flag[i][j]=false;
        }
    }
    srand(time(0));
    int r=(rand()%5+1); //numero random che indica la riga per le coordinate della chiave
    int c=(rand()%7+1);//numero random che indica la colonna per le coordinate della chiave
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(flag[i][j]==true){

                if(numstanza==1){   //se numstanza==1 indica che sono nell'ultima stanza generata
                    mapp.strutturamappa[i][j]->room[r][c]='j';
                }

                numstanza--;
            }
        }
    }


}
//questa funzione controlla dove è stata creata la stampa e se c'è uno spazio vuoto aggiunge i mostri(tanti quanti il num di livello)
void Position::generamostri(WINDOW *win1,mappa mapp){
    srand(time(0));
    bool flag[20][20];
    //numstanza=0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(mapp.strutturamappa[i][j]->room[0][0]!=' '){
                    flag[i][j]=true;
            }
            else
                flag[i][j]=false;
        }}
          int r=(rand()%4+1);
        int c=(rand()%6+1);
            for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(flag[i][j]==true){
                        if(mapp.strutturamappa[i][j]->room[r][c]==' '){
                        mapp.strutturamappa[i][j]->room[r][c]='M';


                }
                else
                    mapp.strutturamappa[i][j]->room[r+1][c+1]='M';

                }
            }}
}
//genera monete
void Position::generamonete(WINDOW *win1,mappa mapp){
    srand(time(0));
    bool flag[20][20];
    //numstanza=0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(mapp.strutturamappa[i][j]->room[0][0]!=' '){
                    flag[i][j]=true;
            }
            else
                flag[i][j]=false;
        }}
        int r=(rand()%5+1);
        int c=(rand()%7+1);
            for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(flag[i][j]==true){
                        if(mapp.strutturamappa[i][j]->room[r][c]==' '){
                        mapp.strutturamappa[i][j]->room[r][c]='o';

            }
            }
            }}

}
















