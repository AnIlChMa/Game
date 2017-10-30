
#include "character.h"
#include "Position.h"

character::character()
{
    monete=0;
    nome='@';
    vita=200;
    p= new loggetti;
}


bool character::vivo(WINDOW *win2, screen scr){
    scr.statusvita(win2, vita);
    if(vita<=0)
        return false;
    else
        return true;
}



void character::raccoglioggetti(WINDOW *win1,WINDOW *win2,mappa mapp,screen scr, Position pos){
    scr.statusmonete(win2, monete);

        switch(pos.ch)
        {
                cout<<pos.ch;
            case 1:{

                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=='o' ){
                    monete++;
                    scr.statusmonete(win2, monete);
                    wrefresh(win2);
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=='X'){
                        p=p->next;
                        p->nomeogg='X';
                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx+1][pos.posy]=='j'){
                            p=p->next;
                            p->nomeogg='j';
                        }
                    }
                break;
            }

            case 3:{

                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='o' ){
                    monete++;
                    scr.statusmonete(win2, monete);
                    wrefresh(win2);
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='X'){
                        p=p->next;
                        p->nomeogg='X';
                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='j'){
                            p=p->next;
                            p->nomeogg='j';
                        }
                    }
                }
                break;
            }

            case 2:{
                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=='o' ){
                    monete++;
                    scr.statusmonete(win2, monete);
                    wrefresh(win2);
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=='X'){
                        p=p->next;
                        p->nomeogg='X';

                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy+1]=='j'){
                            p=p->next;
                            p->nomeogg='j';

                        }
                    }
                }
                                    break;
            }

            case 4:{
                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=='o' ){
                    monete++;
                    scr.statusmonete(win2, monete);
                    wrefresh(win2);
                    if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=='X'){
                        p=p->next;
                        p->nomeogg='X';

                        if (mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy-1]=='j'){
                            p=p->next;
                            p->nomeogg='j';
                            }
                    }
                   }
                break;
            }

            default:
                break;
            }
        }
    }

    //wrefresh(win2);
    /*if(map.strutturamappa[pos.posi][pos.posj]->room[pos.posx-1][pos.posy]=='o'){


                    monete++;
                    scr.statusmonete(win2, monete);
        wrefresh(win2);
    }
    if (map.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=='X'){
            p->nomeogg='X';
            //p->next;
    }
                        if (map.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]=='j'){
                            p=p->next;
                            p->nomeogg='j';
                           //p->next;


                }

}*/

//questa funzione dovrebbe permettere di usare gli oggeti ->svuotare la lista degli oggetti
//adesso sta generando la chiave, dovrebbe essere integrata alla funzione generahiave
void character::usaoggetti(WINDOW *win1,mappa mapp, Position pos){
    if(monete==pos.h){
        for(pos.posx=1;pos.posx<6;pos.posx++){
            for(pos.posy=1;pos.posy<8;pos.posy++){

                if(mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]==' ')
                    mapp.strutturamappa[pos.posi][pos.posj]->room[pos.posx][pos.posy]='j';
            }
        }
    }
}
