#include "character.h"
#include "Position.h"
#include "mappa.h"
#include "screen.h"



character::character()
{
    this->attacco;
    this->difesa;
    //ctor
}


bool character::vivo(){
    if(vita<=0)
        return false;
    else
        return true;
}



void character::raccoglioggetti(WINDOW *win1,mappa mapp,Position pos){
    int ch=0;
    if((ch=getch())!= 'q')
    {
    switch(ch)
        {
            case KEY_UP:{
                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=='o' ){
                    monete++;
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=='X'){
                        p->nomeogg;
                        p->next;
                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=='j'){
                                p->nomeogg;
                                p->next;}}
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=' ';
                        pos.posx--;
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;
                        }
                else
                    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;
            break;
            }

            case KEY_DOWN:{

                 if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='o' ){
                    monete++;
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='X'){
                        p->nomeogg;
                        p->next;
                       if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='j'){
                                p->nomeogg;
                                p->next;}}
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=' ';
                        pos.posx++;
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;}
                else
                    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;
            break;
            }

            case KEY_RIGHT:{
                 if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=='o' ){
                    monete++;
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=='X'){
                        p->nomeogg;
                        p->next;
                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=='j'){
                                p->nomeogg;
                                p->next;}}
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=' ';
                        pos.posy++;
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;}
                else
                    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;
            break;
            }

            case KEY_LEFT:{
                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=='o' ){
                    monete++;
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=='X'){
                        p->nomeogg;
                        p->next;
                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=='j'){
                                p->nomeogg;
                                p->next;}}
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=' ';
                        pos.posy--;
                        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;}
                else
                    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=pos.main_char;
            break;
            }

            default:
                break;
        }
        wrefresh(win1);
    }
}

void character::usaoggetti(WINDOW *win1,mappa mapp,Position pos){
    if(monete==pos.h){
    for(pos.posx=1;pos.posx<7;pos.posx++){
        for(pos.posy=1;pos.posy<7;pos.posy++){

        if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]==' ')
        mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]='j';
        }}
    }
    }
