#include "mostro.h"
#include <math.h>
#include <iostream>
#include<stdlib.h>

mostro::mostro()
{
    //ctor
    this->attacco;
    this->difesa;
    this->descr;

}

mostro::battaglia(WINDOW *win1){
    //controllo che ci sia vita
    if (character::vita>0){
            //se l'attacco del personaggi è minore della difesa del mostro tolgo vita al personaggio altrimnti al mostro
       int k=(character::attacco)-(difesa);
                character::vita=character::vita-(k*0.1);
                vivo();}

    }

    mostro::movimento(WINDOW *win1,mappa mapp,Position pos,int i,int j){
        int poss = -1;
        int	 score = (pos.posx)*(pos.posx )+ (pos.posy*pos.posy);
        	int dist = -1;
        //si muove verso sinistra
        if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1] ==' '){
                dist=pow(i-pos.posx,2)+pow(j-pos.posy,2);

        //if( game_map.target_position(monster.row(), monster.col() - 1)) {
            //dist = std::pow(main_char.row() - monster.row(),2) + std::pow(main_char.col() - (monster.col() - 1),2);
            if(score > dist) {
 			score = dist;
 			poss = 0;
            }
            wrefresh(win1);
        }
 	// si muove verso destra
 	 if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1] ==' '){
        dist=pow(i-pos.posx,2)+pow(j-pos.posy,2);
        	 		if(score > dist) {
 			score = dist;
 			poss = 1;
 		}
 		wrefresh(win1);
 	 }

 	// si muove verso sopra
 	if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy] ==' '){
        dist=pow(i-pos.posx,2)+pow(j-pos.posy,2);
        	 		if(score > dist) {
 			score = dist;
 			poss = 1;
 		}
 		wrefresh(win1);
 	}

 	// si muove verso sotto
 	if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy] ==' '){
        dist=pow(i-pos.posx,2)+pow(j-pos.posy,2);
        	 		if(score > dist) {
 			score = dist;
 			poss = 1;
 		}
 		wrefresh(win1);
 	}

 	switch(poss) {
 		case 0:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]='M';
 			break;
 		case 1:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]='M';
 			break;
 		case 2:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]='M';
			break;
 		case 3:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]='M';
 			break;
 	}
    }


/*
void mostro::movimento(WINDOW *win1,mappa mapp){
    int ch= 0;
    //mapp.strutturamappa[posi][posj]->room[posx][posy]=a[0];
    mapp.esistestanza(win1);
    if((ch=getch())!= 'q')
    {
        switch(ch)
        {
            case 0:{
                if(mapp.strutturamappa[posi][posj]->room[posx-1][posy]!='-' ){
                        if(mapp.strutturamappa[posi][posj]->room[posx-1][posy] ==' '){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx--;
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx-1][posy]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posx--;

                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                        }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
            break;
            }

            case 1:{

                if(mapp.strutturamappa[posi][posj]->room[posx+1][posy]!='-' ){
                          if(mapp.strutturamappa[posi][posj]->room[posx+1][posy] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posx++;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx+1][posy]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posx++;
                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                }
                }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                break;

            }

            case 2:{
                if(mapp.strutturamappa[posi][posj]->room[posx][posy+1]!='|' ){
                          if(mapp.strutturamappa[posi][posj]->room[posx][posy+1] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posy++;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx][posy+1]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posy++;

                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                }}
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                break;

            }

            case 3:{
                if(mapp.strutturamappa[posi][posj]->room[posx][posy-1]!='|' ){
                          if(mapp.strutturamappa[posi][posj]->room[posx][posy-1] =='j'){
                        mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                        posy--;
                        mapp.strutturamappa[posi][posj]->room[ posx][ posy]=main_char;
                        crealivello(win1, mapp);
                    }
                        if(mapp.strutturamappa[posi][posj]->room[posx][posy-1]=='/'){
                                passaporta(win1,mapp);}
                        else{
                mapp.strutturamappa[posi][posj]->room[posx][posy]=' ';
                posy--;

                mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                mapp.esistestanza(win1);
                }
            }
                else
                    mapp.strutturamappa[posi][posj]->room[posx][posy]=main_char;
                break;

            }

            default:
                break;
        }
        wrefresh(win1);

    }

}*/
