#include "TXLib.h"
//#include "..\Progi\BelskaiaEvgeniia.h"
void grassWind ();
void Grass_Animate ();

int main ()
    {
    txCreateWindow (540, 600);

    grassWind ();
    //Grass_Animate ();

    return 0;
    }

 void grassWind ()
    {
    HDC grass1 = txLoadImage ("image\\grass-1.bmp");
    HDC grass2 = txLoadImage ("image\\grass-2.bmp");
    HDC grass3 = txLoadImage ("image\\grass-3-1.bmp");
    HDC grass4 = txLoadImage ("image\\grass-4.bmp");
    HDC zemla  = txLoadImage ("image\\Zemla.bmp");

    //txBitBlt (txDC(), 0, 0, 0, 0, grass1, 0, 0);

    int t = 0;
    while (t < 20)
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 540, 600);

        //DrawPlanet (600, 400, 160,  ROUND (160*cos(100-(i*0.05))+600), ROUND (400+160*sin(100-(i*0.05))), 15, RGB ( 90, 170, 255));
        txTransparentBlt (txDC(), ROUND (270*cos(100+(t*0.2))) , ROUND (250 + 270*sin(100+(t*0.2))), 0, 0, zemla, 0, 0);
        //txTransparentBlt (txDC(), 50 + t*5, 50, 0, 0, zemla, 0, 0);

        txTransparentBlt (txDC(), 0, 450, 0, 0, grass1, 0, 0);
        txSleep (100);
        txTransparentBlt (txDC(), 0, 450, 0, 0, grass2, 0, 0);
        txSleep (100);
        txTransparentBlt (txDC(), 0, 450, 0, 0, grass3, 0, 0);
        txSleep (100);
        txTransparentBlt (txDC(), 0, 450, 0, 0, grass4, 0, 0);
        txSleep (100);

        t ++;
        }

    txDeleteDC (grass1);
    txDeleteDC (grass2);
    txDeleteDC (grass3);
    txDeleteDC (grass4);
    txDeleteDC (zemla);
    }

 void Grass_Animate ()
    {
    HDC grass0 = txLoadImage ("image\\grass-2A.bmp");
    HDC grassA = txLoadImage ("image\\grassAnim37-12.bmp");
    //txUseAlpha (grassA);
    //txSaveImage ("image\\grassAnim37-12.bmp", grassA);



    int sizeX = txGetExtentX (grassA),
        sizeY = txGetExtentY (grassA) / 37;

    int t = 0;
    while (t < 250)
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 540, 600);

        txAlphaBlend (txDC(), 0,  50, 0, 0, grass0, 0, 0);

        txAlphaBlend (txDC(), 0, 250, sizeX, sizeY, grassA, 0, (t % 37) * sizeY);

        t ++;
        txSleep (20);
        }

    txDeleteDC (grassA);
    txDeleteDC (grass0);
    }
