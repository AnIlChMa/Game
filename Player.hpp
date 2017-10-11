//
//  Player.hpp
//  
//
//  Created by chiara mengoli on 21/09/17.
//
//

#ifndef Player_hpp
#define Player_hpp
#include <stdio.h>

class Player{
public:
    char playerName;
    char playerSymbol[1];
    int Life;
    int valueAttack;
    int valueDefence;
    enum  Direction { STOP= 0, LEFT, RIGHT, UP, DOWN};
    Direction dir;
    
private:
    Player(char Name, int Life){
    }
    
    //int Life(){
       // Life = 1000;
};

    /* 
         u
     l       r
         d
     
     */
    //gestire l'input
    void  Input(){
    }
    //spostarsi
    void Move(){
        }
        
    };
    //raccogliere un oggetto
    //aprire una porta
    //attaccare e difendersi




class Objects{
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
    
    
};







#endif /* Player_hpp */

