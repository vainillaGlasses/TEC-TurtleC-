#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>

using namespace std;

class Instruction
{
    private:
        string name;
        string txt;
        int pixeles;
        int x;
        int y;
        int R;
        int G;
        int B;

    public:
        Instruction() {}
        virtual ~Instruction() {}
        // SET
        void setName(string pName)
        {
            name = pName;
        }

        void setPix(int pPix)
        {
            pixeles = pPix;
        }

        void setR(int pR)
        {
            R = pR;
        }

        void setG(int pG)
        {
            G = pG;
        }

        void setB(int pB)
        {
            B = pB;
        }

        void setX(int pX)
        {
            x = pX;
        }

        void setY(int pY)
        {
            y = pY;
        }

        void setTxt(string pTxt)
        {
            txt = pTxt;
        }
        // GET
        string getName()
        {
            return name;
        }

        int getPix()
        {
            return pixeles;
        }

        int getR()
        {
            return R;
        }

        int getG()
        {
            return G;
        }

        int getB()
        {
            return B;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        string getTxt()
        {
            return txt;
        }

};

#endif // INSTRUCTION_H
