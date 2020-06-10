#ifndef CANVAS_H
#define CANVAS_H
// Librery
#include <iostream>
#include <fstream>
#include <sstream>
#include <winbgim.h>
#include <Turtle.h>
#include <string.h>
#include <File.h>

#define max_x 800
#define max_y 600

class Canvas
{
    private:
        Turtle sammy;

    public:
        Canvas()
        {
            // Window Properties
            initwindow(1000, 700); // Size
            const char*title = "Dotorka Draw";
            setwindowtitle(title);
        }
        virtual ~Canvas() {}
        // -------------- Turtle --------------  //
        void home()
        {
            sammy.home();
            //getch();
        }
        void setheadlilne(int head)
        {
            sammy.headline(head);
            //getch();
        }
        void turn(int pix)
        {
            sammy.turn(pix);
            //getch();
        }
        void left(int pix)
        {
            sammy.left(pix);
            //getch();
        }
        void right(int pix)
        {
            sammy.right(pix);
            //getch();
        }
        void forward(int pix)
        {
            sammy.forward(pix);
            //getch();
        }
        void back(int pix)
        {
            sammy.back(pix);
            //getch();
        }
        void circleD(int pix)
        {
            sammy.circleD(30);
            //getch();
        }
        void pendown()
        {
            sammy.pendown();
            //getch();
        }
        void penup()
        {
            sammy.penup();
            //getch();
        }
        void pensize(int widht)
        {
            sammy.setWidth(widht);
            //getch();
        }
        void setpos(int x, int y)
        {
            sammy.setx(x);
            sammy.sety(y);
            //getch();
        }
        void setx(int x)
        {
            sammy.setx(x);
            //getch();
        }
        void sety(int y)
        {
            sammy.sety(y);
            //getch();
        }
        void getx()
        {
            sammy.xcor();
            //getch();
        }
        void gety()
        {
            sammy.ycor();
            //getch();
        }
        void pos()
        {
            sammy.getPos();
            //getch();
        }
        void heading()
        {
            sammy.heading();
            //getch();
        }
        void info()
        {
            sammy.pen();
            //getch();
        }
        void color(int R, int G, int B)
        {
            sammy.setColor(R,G,B);
            //getch();
        }
        // -------------- Canvas --------------  //
        void reset()
        {
            cleardevice();
            sammy.home();
            //getch();
        }
        void clear()
        {
            cleardevice();
            //getch();
        }
        void write(int size, string ptext)
        {
            settextstyle(0, 0, size);
            const char * text = ptext.c_str();
            outtextxy(100,100,text);
            //getch();
        }
        void exit()
        {
            closegraph();
        }
};

#endif // CANVAS_H
