#ifndef MAPPA_H
#define MAPPA_H
#include "stanza.h"
#include "screen.h"


class mappa
{
    public:

        mappa();
        virtual ~mappa();
        void creamappa();
        //scriviinfinestra(WINDOW *win1);
                 void stampamappa();
        void esistestanza(WINDOW *win1);
        void stanzasucc(WINDOW *win1);

        std::vector<std::vector<stanza*> > strutturamappa;
       void istanzia(WINDOW *win1,int x,int y);

    protected:


    private:
};

#endif // MAPPA_H
