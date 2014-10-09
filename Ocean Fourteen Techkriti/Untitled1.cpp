#ifdef __BORLANDC__
#pragma hdrstop            // borland specific
#include <condefs.h>
#pragma argsused
USEUNIT("Tserial.cpp");
#endif
#include "conio.h"
#include "Tserial.cpp"
#include <time.h>
#include "cv.h"
#include"highgui.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define PI 3.14159265


int main()
{
    int i=0;
    Tserial *com;
    char ch;
    com = new Tserial();
    com->connect("COM21", 9600, spNONE);
    cvWaitKey(5000);
    cvWaitKey(0);
    com->sendChar('d');
    com->disconnect();
}
