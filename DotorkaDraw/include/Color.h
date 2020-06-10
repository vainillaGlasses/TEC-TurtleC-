#ifndef COLOR_H
#define COLOR_H
#include <algorithm>
#include <string>


class Color
{
    private:
        int R;
        int G;
        int B;

    public:
        Color()
        {
            R = 255;
            G = 255;
            B = 255;
        }

        virtual ~Color() {}

        bool setColor(string pColor)
        {
            transform(pColor.begin(), pColor.end(), pColor.begin(), ::tolower);
            if(pColor == "white")
            {
                R = 255;
                G = 255;
                B = 255;
            }
            if(pColor ==  "black")
            {
                R = 0;
                G = 0;
                B = 0;
            }
            if(pColor == "blue")
            {
                R = 0;
                G = 0;
                B = 255;
            }
            if(pColor == "green")
            {
                R = 0;
                G = 255;
                B = 0;
            }
            if(pColor == "cyan")
            {
                R = 0;
                G = 255;
                B = 255;
            }
            if(pColor == "red")
            {
                R = 255;
                G = 0;
                B = 0;
            }
            if(pColor == "magenta")
            {
                R = 255;
                G = 0;
                B = 255;
            }
            if(pColor == "brown")
            {
                R = 165;
                G = 042;
                B = 042;
            }
            if(pColor == "lightgray")
            {
                R = 211;
                G = 211;
                B = 211;
            }
            if(pColor == "darkgray")
            {
                R = 169;
                G = 169;
                B = 169;
            }
            if(pColor == "lightblue")
            {
                R = 173;
                G = 216;
                B = 230;
            }
            if(pColor == "lightgreen")
            {
                R = 144;
                G = 238;
                B = 144;
            }
            if(pColor == "lightcyan")
            {
                R = 224;
                G = 255;
                B = 255;
            }
            if(pColor == "lightred")
            {
                R = 255;
                G = 174;
                B = 185;
            }
            if(pColor == "lightmagenta")
            {
                R = 255;
                G = 66;
                B = 249;
            }
            if(pColor == "yellow")
            {
                    R = 255;
                    G = 255;
                    B = 0;
            }else{
                cout << "ERROR. Color: Nombre invalido." << endl;
                    return false;
                }
            return true;
        }

        int  getR()
        {
            return R;
        }

        int  getG()
        {
            return G;
        }

        int  getB()
        {
            return B;
        }
};

#endif // COLOR_H
