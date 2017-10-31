#include "mostro.h"
#include <math.h>
#include<stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>



mostro::mostro()
{


    //ctor
   nome='M';

}

//il mostro attacca il personaggio
void mostro::mostrovscharacter(WINDOW *win1,WINDOW *win2, screen scr,Position pos,mappa mapp){
    if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]==nome){
            if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]==nome){
                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]==nome){
                    if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]==nome){
//controllo che ci sia vita
    if (character::vita>0){
        //se l'attacco del personaggi è minore della difesa del mostro tolgo vita al personaggio altrimnti al mostro
        int k=(attacco)-(character::difesa);
        character::vita=character::vita-(k*0.1);
        scr.statusvita(win2, character::vita);
        character::vivo(win2,scr);
    }
    }
                }
            }
    }
}

//il personaggio attacca il mostro
void mostro::charactervsmostro(WINDOW *win1,WINDOW *win2, screen scr,mappa mapp,Position pos){
    if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]==nome){
            if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]==nome){
                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]==nome){
                    if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]==nome){
    if (vita>0){
        //se l'attacco del personaggi è minore della difesa del mostro tolgo vita al personaggio altrimnti al mostro
        int k=(character::attacco)-(difesa);
        vita=vita-(k*0.1);
        scr.statusvita(win2, vita);
    }
                    }
                }
            }
    }

}
//funzione  che muove il mostro
/*
void mostro::movimento(WINDOW *win1,mappa mapp,Position pos){
        int poss = -1;
        int	 score = (pos.posx)*(pos.posx )+ (pos.posy*pos.posy);
        	int dist = -1;
        //si muove verso sinistra
        if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1] ==' '){
                dist=sqrt(pow(pos.posi-pos.posx,2)+pow((pos.posj+1)-pos.posy,2));

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
        dist=sqrt(pow(pos.posi-pos.posx,2)+pow((pos.posj-1)-pos.posy,2));
        	 		if(score > dist) {
 			score = dist;
 			poss = 1;
 		}
 		wrefresh(win1);
 	 }

 	// si muove verso sopra
 	if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy] ==' '){
        dist=sqrt(pow((pos.posi-1)-pos.posx,2)+pow(pos.posj-pos.posy,2));
        	 		if(score > dist) {
 			score = dist;
 			poss = 2;
 		}
 		wrefresh(win1);
 	}

 	// si muove verso sotto
 	if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy] ==' '){
        dist=sqrt(pow((pos.posi+1)-pos.posx,2)+pow(pos.posj-pos.posy,2));
        	 		if(score > dist) {
 			score = dist;
 			poss = 3;
 		}
 		wrefresh(win1);
 	}

 	switch(poss) {
 		case 0:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=nome;
 		    mapp.esistestanza(win1);
 			break;
 		case 1:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=nome;
 		    mapp.esistestanza(win1);
 			break;
 		case 2:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=nome;
 		    mapp.esistestanza(win1);
			break;
 		case 3:
 		    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=nome;
 		    mapp.esistestanza(win1);
 			break;
 	}
    }*/
/*
void mostro::movimento(WINDOW *win1, Position pos, mappa mapp){
    int direction=1;//rigth
    //2 left
    //3 up
    //4 down

    if((mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy] !='-') &&(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy] !='|')){
        double a = sqrt( pow((double) (mostrox-1)-pos.posx,2) + pow((double) mostroy-pos.posy,2)); //UP

    double b = sqrt (pow((double) (mostrox+1)-pos.posx,2) + pow((double) mostroy-pos.posy,2)); //DOWN

    double c = sqrt(pow((double) mostrox-pos.posx,2) + pow((double) (mostroy-1)-pos.posy,2)); //RIGHT

    double d = sqrt(pow((double) mostrox-pos.posx,2) + pow((double) (mostroy+1)-pos.posy,2)); //LEFT

    if(a < b && a <= c && a <= d && direction!=4) {
            direction=3;
    mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox-1][mostroy]=nome;
    mapp.esistestanza(win1);
 		    wrefresh(win1);}
    else if(b <= c && b <= d && direction!=3 ){
        direction=4;
    mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox+1][mostroy]=nome;
    mapp.esistestanza(win1);
 		    wrefresh(win1);}

    else if(c < d && direction!=2) {
        mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy+1]=nome;
        mapp.esistestanza(win1);
 		    wrefresh(win1);
 		    direction=1;
    }

    else if(direction!=1){
        mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy-1]=nome;
        mapp.esistestanza(win1);
 		    wrefresh(win1);
 		    direction=2;
    }

    }
}*/
void mostro::movimento(WINDOW *win1,WINDOW *win2, mappa mapp, Position pos, screen scr){
    srand(time(0));
   int k=(rand()%4+1);

        switch(k)
        {
            case 1:{

                if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox-1][mostroy] !='-'){
                        if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox+1][mostroy] =='@'){
                        mostrovscharacter(win1, win2, scr,pos,mapp);
                        //mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=nome;
                    }
                      else  if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox-1][mostroy] ==' '){
                  //mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=' ';
                        pos.posx--;

                        mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][ mostroy]=nome;
              }}
               break;
}


            case 2:{

                if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox+1][mostroy] !='-' ){
                    if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox+1][mostroy] =='@'){
                        mostrovscharacter(win1, win2, scr,pos,mapp);
                        //mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][ mostroy]=nome;
                    }

                    else if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox+1][mostroy] ==' '){
                        //mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=' ';
                        pos.posx++;

                        mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][ mostroy]=nome;
                        //mapp.esistestanza(win1);
                        }
             }

                break;
}


            case 3:{

                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy+1]!='|'){
                            if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy+1] =='@'){
                                mostrovscharacter(win1, win2, scr,pos,mapp);

                                //mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=nome;
                            }

                    else if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy+1] ==' '){
                        //mapp.strutturamappa[posi][posj]->room[mostrox][mostroy]=' ';
                        pos.posy++;

                        mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=nome;
                        //mapp.esistestanza(win1);
                    }

                }
                break;}



            case 4:{


                if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy-1]!='|'){
                    if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy-1] =='@'){
                        mostrovscharacter(win1, win2, scr,pos,mapp);

                       // mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=nome;
                    }

                    else if(mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy-1] ==' '){
                        //mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][ mostroy]=' ';
                        pos.posy--;

                        mapp.strutturamappa[pos.posi][pos.posj]->room[mostrox][mostroy]=nome;
                        //mapp.esistestanza(win1);
                    }


               }
                break;}



            default:
                break;
        }

        wrefresh(win1);

}

  /*  void mostro::inseriscimostro(WINDOW *win1, mappa mapp, Position pos){
          mapp.strutturamappa[pos.posi][pos.posj]->room[4][4]=nome;
    mapp.esistestanza(win1);
    wrefresh(win1);

}*/


