#ifndef MAPPA_H
#define MAPPA_H
#include "stanza.h"
#include "screen.h"


class mappa
{
    public:

        mappa();
        virtual ~mappa();
        creamappa();
        scriviinfinestra(WINDOW *win1);
                 stampamappa();
        esistestanza(WINDOW *win1);
        stanzasucc(WINDOW *win1);

        std::vector<std::vector<stanza*> > strutturamappa;
        istanzia(WINDOW *win1,int x,int y);

    protected:

    private:
};

#endif // MAPPA_H
