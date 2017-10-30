#include "mostro.h"
#include <math.h>


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
void mostro::movimento(WINDOW *win1,mappa mapp,Position pos,int i,int j){
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
 			poss = 2;
 		}
 		wrefresh(win1);
 	}

 	// si muove verso sotto
 	if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy] ==' '){
        dist=pow(i-pos.posx,2)+pow(j-pos.posy,2);
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
    }


    void mostro::inseriscimostro(WINDOW *win1, mappa mapp, Position pos){
          mapp.strutturamappa[pos.posi][pos.posj]->room[4][4]=nome;
    mapp.esistestanza(win1);
    wrefresh(win1);


}


