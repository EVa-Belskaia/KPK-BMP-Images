#include "TXLib.h"

void Fisherman ( );

int main ()
    {
    txCreateWindow (800, 624);

    Fisherman ();


    return 0;
    }

//---

void Fisherman ()
    {
    HDC fon = txLoadImage ("image\\Fon.bmp");
    HDC Fman = txLoadImage ("image\\Fisherman.bmp");

    int sizeX  = txGetExtentX (Fman) / 6,
        sizeY  = txGetExtentY (Fman) ;
    int t = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txBitBlt (txDC(), 0, 0, 0, 0, fon, 0, 0);

        txAlphaBlend (txDC(), 700 - t % 300,  130, sizeX,  sizeY,  Fman, (t % 6) * sizeX, 0);

        t ++;
        txSleep (50);
        }

    txDeleteDC (Fman);
    txDeleteDC (fon);
    }
