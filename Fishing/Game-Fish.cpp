#include "TXLib.h"

struct Fish
    {
    int x, y;
    int rasm;

    } ;

void DrawFish ();


int main ()
    {
    txCreateWindow (800, 624);

    DrawFish ();


    //txSetFillColor (RGB (128, 255, 255));
    //txRectangle (1, 1, 540, 600);

    return 0;
    }
 //--рыбки----------------------------
void DrawFish ()
    {
    HDC fon = txLoadImage ("image\\Fon.bmp");
    HDC fish1 = txLoadImage ("blueFish1.bmp");
    HDC fish2 = txLoadImage ("Pink-1.bmp");

    int sizeX  = txGetExtentX (fish1) / 3,
        sizeY  = txGetExtentY (fish1) / 4;
    int sizeXp = txGetExtentX (fish2) / 7,
        sizeYp = txGetExtentY (fish2) / 2;

    int nAnim = 0;

    int t = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txBitBlt (txDC(), 0, 0, 0, 0, fon, 0, 0);

        int x  = t % (800 - sizeX),
            xp = t % (800 - sizeXp);

        //txAlphaBlend (txDC(), 0,  50, 0, 0, grass0, 0, 0);

        txAlphaBlend (txDC(), x,  300, sizeX,  sizeY,  fish1, (t % 3) * sizeX,  nAnim * sizeY);
        txAlphaBlend (txDC(), xp, 400, sizeXp, sizeYp, fish2, (t % 7) * sizeXp, nAnim%2 * sizeYp);


        if (txGetAsyncKeyState (VK_F1)) nAnim = 0;
        if (txGetAsyncKeyState (VK_F2)) nAnim = 1;
        if (txGetAsyncKeyState (VK_F3)) nAnim = 2;
        if (txGetAsyncKeyState (VK_F4)) nAnim = 3;
        if (txGetAsyncKeyState (VK_F5)) nAnim = 4;

        t ++;
        txSleep (40);
        }

    txDeleteDC (fish1);
    txDeleteDC (fish2);
    txDeleteDC (fon);
    }

