#ifndef SCREEN_H
#define SCREEN_H
#include <ncurses/curses.h>

class screen
{
    public:
        screen();
        virtual ~screen();
        void inizializzafinestra();
        void stampadentromappa(char* test);
        void statusvita(WINDOW *win2, int vita);
        void statuslivello(WINDOW *win2 ,int level);
        void  statusmonete(WINDOW *win2, int monete);
        WINDOW *win1, *win2, *win3;

    protected:

    private:
};

#endif // SCREEN_H


