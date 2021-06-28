#include "TXLib.h"
//#include "..\Progi\BelskaiaEvgeniia.h"

int main ()
    {
    txCreateWindow (540, 600);

    HDC grass0 = txLoadImage ("image\\grass-2-2.bmp");
    //txTransparentBlt (txDC(), 0,  50, 0, 0, grass0, 0, 0);
    txAlphaBlend (txDC(), 0,  50, 0, 0, grass0, 0, 0);


    txDeleteDC (grass0);

    return 0;
    }
