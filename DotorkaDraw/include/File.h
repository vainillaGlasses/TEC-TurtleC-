#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <LinkedList.h>
#include <Instruction.h>

using namespace std;

class File
{
private:
    LinkedList<Instruction> fileLines;
    string lineaEnArchivo;
    Instruction tempC;
    string comando;
    int pixel;

public:
    File() {}
    virtual ~File() {}

    /* C:\Users\Sammy\Desktop\Pro2.mt"; */
    LinkedList<string> readFile(string fileIn )
    {
        LinkedList<string> misLineas;
        const char * fileName = fileIn.c_str();

        ifstream toOpen (fileName);
        if (toOpen.is_open())
        {
            while ( getline (toOpen,lineaEnArchivo) )
            {
                misLineas.append(lineaEnArchivo);
            }
            toOpen.close();
            cout << "Successful UpLoad\n";
        }else{
            cout << "Unable to open file";
        }
        return misLineas;
    }
};

#endif // FILE_H
