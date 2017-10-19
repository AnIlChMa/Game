#ifndef SCREEN_H
#define SCREEN_H
#include <ncurses/curses.h>

class screen
{
    public:
        screen();
        virtual ~screen();
        inizializzafinestra();
        stampadentromappa(char* test);
        WINDOW *win1, *win2;
        WINDOW * test;

    protected:
        int x, y;
        int altezza, larghezza;
        //sottofinestre per il gioco

        //ci dice se è o meno una sottofinestra
        bool flag;
        //puntatore finestra padre(terminale)
        WINDOW *padre;

    private:
};

#endif // SCREEN_H


