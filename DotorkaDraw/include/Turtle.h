#ifndef TURTLE_H
#define TURTLE_H

#include <math.h>
#include <iostream>
#include <winbgim.h>

using namespace std;

class Turtle
{
private:
    int x;
    int y;
    int rumbo;
    int R;
    int G;
    int B;
    bool paint = true;
    int width;

public:
    Turtle()
    {
        x = 500;
        y = 350;
        rumbo = 0;
        R = 255;
        G = 255;
        B = 255;
        paint = true;
        width = 1;
    }

    //Rotations
    void home()
    {
        x = 500;
        y = 350;
        rumbo = 0;
        R = 255;
        G = 255;
        B = 255;
        paint = true;
        width = 1;
    }

    void headline(int grados)
    {
        rumbo = 360 - grados;
    }

    void turn(int c)
    {
        rumbo += c;
    }

    void left(int c)
    {
        rumbo-=c;
    }

    void right(int c)
    {
        rumbo += c;
    }

    // Move
    void forward(int c)
    {
        int x2 = cos((rumbo* M_PI) / 180) * c;
        int y2 = sin((rumbo* M_PI) / 180) * c;
        setcolor(COLOR(R,G,B));
        setlinestyle(0,0,width);
        if(paint == true)
        {
            setfillstyle(SOLID_FILL, COLOR(R,G,B));
            line (x,y,x+x2,y+y2);
        }
        x = x + x2;
        y = y + y2;
    }

    void back(int c)
    {
        c = -c;
        int x2 = cos((rumbo* M_PI) / 180) * c;
        int y2 = sin((rumbo* M_PI) / 180) * c;
        setcolor(COLOR(R,G,B));
        setlinestyle(0,0,width);
        if(paint == true)
        {
            setfillstyle(SOLID_FILL, COLOR(R,G,B));
            line (x,y,x+x2,y+y2);
        }
        x = x + x2;
        y = y + y2;
    }

    void circleD(int radio)
    {
        if(radio>0)
        {
            int tempx = x;
            int tempy = y;
            penup();
            right(90);
            forward(radio);
            pendown();
            x = tempx;
            y = tempy;
            circle(x,y,radio);

        }
        if(radio<0)
        {
            int tempx = x;
            int tempy = y;
            penup();
            left(90);
            forward(radio);
            pendown();
            x = tempx;
            y = tempy;
            circle(x, y, radio);
        }
    }

    // Pen
    void pendown()
    {
        paint = true;
    }

    void penup()
    {
        paint = false;
    }

    void setx(int newX)
    {
        x = newX;
    }

    void sety(int newY)
    {
        y = newY;
    }

    void getPos()
    {
        cout << "Lapiz ubicado en X = " << x << " &  Y = " << y << endl;
    }

    void xcor()
    {
        cout << "Lapiz ubicado en  X = " << x << endl;
    }

    void ycor()
    {
        cout << "Lapiz ubicado en  Y = " << y << endl;
    }

    void heading()
    {
        cout << "Lapiz ubicado a  " << rumbo << "°" << endl;
    }

    void pen()
    {
        string state;
        if (paint == true){state = "abajo";}
        else{state = "arriba";}

        cout << "El lapiz se encuentra "<<state<<", con grosor "<<width<<" y color "<<R<<" "<<G<<" "<<B<<endl;
    }

    void setWidth(int pWidth)
    {
        width = pWidth;
    }

    void setColor(int pR, int pG, int pB)
    {
        R=pR;
        G=pG;
        B=pB;
    }
};

#endif // TURTLE_H
