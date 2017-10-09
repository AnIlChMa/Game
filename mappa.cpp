#include "mappa.h"
#include "stanza.h"
//#include "stanza.cpp"
#include <iostream>
using namespace std;
mappa::mappa()
{
    //ctor
}

mappa::~mappa()
{
    //dtor
}
     //funzione che crea la lista delle liste(ossia la lista delle matrici/stanze)
        mappa::creamappa(){
         strutturamappa.resize(20);
         //stanza test();
         stanza* x= new stanza();
         //x.creastanza();
         for(int i=0;i<20;i++){
                for(int j=0;j<20;j++)
                    strutturamappa[i].push_back(x);
                    cout<<"ciao";


        }

}
     mappa::stampamappa(){
         for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                cout<<strutturamappa[i][j];
       cout<<endl;     }
            }

        }

