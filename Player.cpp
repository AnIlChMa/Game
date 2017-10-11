//
//  Player.cpp
//  
//
//  Created by chiara mengoli on 21/09/17.
//
//

#include "Player.hpp"
#include <conio.h>
#include <iostream>
bool gameOver;

class Player(){
pubblic:
    char playerName[50];
    char playerSymbol[1];
    int Life;
    int valueAttack;
    int valueDefence;
    enum  Direction { STOP= 0, LEFT, RIGHT, UP, DOWN};
    Direction dir;
    
private:
    Player(char Name, int Life){
        this->playerSymbol = playerSymbol;
        this->playerName = playerName;
        this->Life = Life ;
    }
    
    int Life(){
       Life = 1000;
    }
    
    /* 
         u
     l       r
         d
     
     */
    //gestire l'input
    void  Input(){
        if (_kbhit()){
            switch(_getch()){
                    case'l':
                       dir=LEFT;
                       break;
                    case 'r':
                       dir= RIGHT;
                       break;
                    case'u':
                       dir=UP;
                       break;
                    case 'd':
                       dir= DOWN;
                       break;
                    case 'g':
                       gameOver=true;
                       break;
                    
            }
        }
    }
    //spostarsi
    void Move(){
        switch (dir) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y++;
                break;
            case DOWN:
                y--;
                break;
            default:
                break;
        }
        
    }
    //raccogliere un oggetto
    //aprire una porta
    //attaccare e difendersi
   
}



class Objects(){
public:
    char objectName[20];
    //posizione
    char description[100];
    char objectsSymbol[1];
    int objAttack;
    int objDefence;
    
private:
    //l'oggetto deve scomparire dalla mappa quando viene raccolto
    //visualizzare l'oggetto sulla mappa in un tempo casuale
    
    
}
