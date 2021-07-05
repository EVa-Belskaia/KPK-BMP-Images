#include "TXLib.h"
//#include "..\Progi\BelskaiaEvgeniia.h"

int main ()
    {
    txCreateWindow (540, 600);

    txSetFillColor (RGB (128, 255, 255));
    txRectangle (1, 1, 540, 600);

    HDC pac = txLoadImage ("blueFish1.bmp");
    HDC fish2 = txLoadImage ("Pink-1.bmp");
    //HDC komar = txLoadImage ("image\\__Crazy.bmp");

    int sizeX  = txGetExtentX (pac) / 3,
        sizeY  = txGetExtentY (pac) / 4;
    int sizeXp = txGetExtentX (fish2) / 7,
        sizeYp = txGetExtentY (fish2) / 2;

    int nAnim = 0;
    //int boloto = 0;

    int t = 1;
    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 540, 600);

        //txAlphaBlend (txDC(), 0,  50, 0, 0, grass0, 0, 0);

        txAlphaBlend (txDC(), t % 100 ,   0, sizeX, sizeY, pac, (t % 3) * sizeX, nAnim * sizeY);
        txAlphaBlend (txDC(), t % 100 ,   100, sizeXp, sizeYp, fish2, (t % 7) * sizeXp, nAnim%2 * sizeYp);
        /*if (boloto == 1)
            {
            txTransparentBlt (txDC(), 0,   0, sizeX, 0, komar, (t % 4) * sizeX, 0, RGB (0, 255, 0));
            } */

        if (txGetAsyncKeyState (VK_F1)) nAnim = 0;
        if (txGetAsyncKeyState (VK_F2)) nAnim = 1;
        if (txGetAsyncKeyState (VK_F3)) nAnim = 2;
        if (txGetAsyncKeyState (VK_F4)) nAnim = 3;
        if (txGetAsyncKeyState (VK_F5)) nAnim = 4;
        //if (txGetAsyncKeyState (VK_F6)) boloto = 1; else boloto = 0;

        t ++;
        txSleep (40);
        }

    txDeleteDC (pac);
    txDeleteDC (fish2);

    return 0;
    }
