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
        esistestanza();

        std::vector<std::vector<stanza*> > strutturamappa;
        istanzia(int x,int y);

    protected:

    private:
};

#endif // MAPPA_H
