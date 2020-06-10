/*
    Tecnologico de Costa Rica
    Escuela de Ingenieria en Computacion
    Estructuras de Datos

    Programa: DotorkaDraw
    Autor   : Samantha Arburola Leon
    Fecha   : 18.abril.2015

    Dibujar mediante instrucciones ingresadas en la consola

*/
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <strings.h>
#include <Instruction.h>
#include <LinkedList.h>
#include <Color.h>
#include <Canvas.h>
#include <File.h>

using namespace std;
/*--------------------------------------------------*/
/* ---------------- VARIBLES GLOBALES ------------- */
LinkedList<string> myHistory;
LinkedList<string> fromFile;
LinkedList<Instruction> fileInstructions;
LinkedList<Instruction> repeatList;
Canvas myCanvas;
/*--------------------------------------------------*/
void help()
{
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|                           ~~ HELP ~~                            |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|       INSTRUCCION       |        DESCRIPCION                    |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|   Instruciones para la tortuga                                  |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "| forward N               | dibuja hacia adelante                 |" << endl;
	cout << "| back    N               | dibuja hacia atras                    |" << endl;
	cout << "| right   grados          | gira a la derecha                     |" << endl;
	cout << "| left    grados          | gira a la izquierda                   |" << endl;
	cout << "| setpos  X Y             | posiciona a tortuga                   |" << endl;
	cout << "| setx    X               | nueva posicion horizontal             |" << endl;
	cout << "| sety    Y               | nueva posicion vertical               |" << endl;
	cout << "| setheading grados       | direciona la tortuga                  |" << endl;
	cout << "| color R G B             | color en codigo R G B                 |" << endl;
	cout << "| color nombre            | color del dibujo*                     |" << endl;
	cout << "| pensize grosor          | grosor de la linea de dibujo          |" << endl;
	cout << "| pendown                 | permite que el lapiz dibuje           |" << endl;
	cout << "| penup                   | evita que el lapiz dibuje             |" << endl;
	cout << "| home                    | posicion inicial de la tortuga        |" << endl;
	cout << "| circle radio            | dibuja un circulo                     |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "| * Nombres de colores aceptados: white                           |" << endl;
	cout << "|   black** blue green cyan red magenta brown lightgray darkgray  |" << endl;
	cout << "|   lightblue lightgreen lightcyan lightred lightmagenta yellow   |" << endl;
	cout << "| **Tome en cuenta que el fondo del lienzo es negro               |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|   Ver propiedades de la tortuga en consola                      |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "| pos                     | posicion actual                       |" << endl;
	cout << "| xcor                    | punto (x,0)                           |" << endl;
	cout << "| ycor                    | punto (0,Y)                           |" << endl;
	cout << "| heading                 | rumbo acutal                          |" << endl;
	cout << "| pen                     | propiedades del lapiz                 |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|   Instruciones del programa                                     | " << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "| help                    | muestra este cuadro de ayuda          |" << endl;
	cout << "| reset                   | limpiar la ventana y toutuga          |" << endl;
	cout << "| clear                   | limpiar la ventana de dibujo          |" << endl;
	cout << "| write tamaño texto      | texto a mostrar en el dibujo          |" << endl;
	cout << "| repeat N[instrucciones] | N veces las instruciones dentro de [] |" << endl;
	cout << "| loadfile nombreArchivo  | carga un archivo .txt                 |" << endl;
	cout << "| exec                    | ejecutar contenido del archivo        |" << endl;
	cout << "| history                 | ver el historial                      |" << endl;
	cout << "| clearhistory            | limpiar el historial                  |" << endl;
	cout << "| exit                    | salir del lienzo                      |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "|                      ~~ Ejemplo de Uso ~~                       |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
	cout << "| <+> forward 100                |      NO RECIBEN PARAMETROS     |" << endl;
	cout << "| <+> back    50                 | <+> home                       |" << endl;
	cout << "| <+> right   14                 | <+> pos                        |" << endl;
	cout << "| <+> left    210                | <+> xcor                       |" << endl;
	cout << "| <+> setpos  30 70              | <+> ycor                       |" << endl;
	cout << "| <+> setx    30                 | <+> pen                        |" << endl;
	cout << "| <+> sety    70                 | <+> heading                    |" << endl;
	cout << "| <+> setheading 145             | <+> exec                       |" << endl;
	cout << "| <+> color 255 0 255            | <+> clear                      |" << endl;
	cout << "| <+> color black                | <+> reseat                     |" << endl;
	cout << "| <+> pensize 7                  | <+> history                    |" << endl;
	cout << "| <+> pendown                    | <+> clearhistory               |" << endl;
	cout << "| <+> penup                      | <+> help                       |" << endl;
	cout << "| <+> circle 30                  | <+> exit                       |" << endl;
	cout << "| <+> write 10 Hi Turtle         |                                |" << endl;
	cout << "| <+> repeat 5[forwar 10 left 5]                                  |" << endl;
	cout << "| <+> loadfile C: \ Users \ Sammy \ Desktop \ MiCode.txt          |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl;
}
/*--------------------------------------------------*/
bool isIn(string word){
    /* Verificar si es una instruccion
    Entrada: string word
    Salida : true,  es una instruccion
             false, no es  instruccion
    */
    LinkedList<string> myCommands;
    myCommands.append("forward");
    myCommands.append("back");
    myCommands.append("right");
    myCommands.append("left");
    myCommands.append("setpos");
    myCommands.append("setx");
    myCommands.append("sety");
    myCommands.append("setheading");
    myCommands.append("home");
    myCommands.append("circle");
    myCommands.append("pos");
    myCommands.append("xcor");
    myCommands.append("ycor");
    myCommands.append("heading");
    myCommands.append("pendown");
    myCommands.append("penup");
    myCommands.append("pensize");
    myCommands.append("color");
    myCommands.append("pen");
    myCommands.append("reset");
    myCommands.append("clear");
    myCommands.append("write");
    myCommands.append("repeat");
    myCommands.append("loadfile");
    myCommands.append("exec");
    myCommands.append("history");
    myCommands.append("clearhistory");
    myCommands.append("help");
    myCommands.append("exit");

    transform(word.begin(), word.end(), word.begin(), ::tolower); // Pasar el string a minisculas
    for(myCommands.goToStart();myCommands.getPos() < myCommands.getSize();myCommands.next())
    {
        if(word == myCommands.getElement())
        {
            return true;
        }
    }
    return false;
}
/*--------------------------------------------------*/
LinkedList<string> split(string myString)
{
    /* Separar palabras
    Entrada: string
    Salida : Lista con las palabras separadas por espacio
    */
    LinkedList<string> myLine;
    istringstream iss(myString);
    do
    {
        string sub;
        iss >> sub;
        myLine.append(sub);
    } while (iss);// Mientras haya string

    return myLine;
}
/*--------------------------------------------------*/
int toInt(string stringInt)
{
    /* Obtener el int escrito en un string
    Entrada: string
    Salida : int
    */
    const char * geTemp = stringInt.c_str();
    return atoi(geTemp);
}
/*--------------------------------------------------*/
string takeOut(string myString, char myChar)
{
    string newString;
    for(int i = 0; i < myString.size();i++)
    {
        if (myString[i] != myChar)
        {
            newString += myString[i];
        }
    }
    return newString;
}
/*--------------------------------------------------*/
Instruction getInstruction(LinkedList<string>& myInstructionLine)
{
	/* Instanciar una Instruccion a partir de una lista con los datos
	*/
	Instruction myInstruction;
	myInstructionLine.goToStart();
	string nameInstruction = myInstructionLine.remove(); //temporal para identificar el comando
	if(isIn(nameInstruction) == true)
    {
        if(nameInstruction == "help")
        {
            myInstruction.setName(nameInstruction);
        }
		if(nameInstruction == "forward")
		{
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction == "back")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction == "right")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction == "left")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "setpos")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setX(toInt(myInstructionLine.remove()));
			myInstruction.setY(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "setx")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setX(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "sety")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setY(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "setheading")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "home")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "circle")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "pos")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "xcor")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "ycor")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "heading")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "pendown")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "penup")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "pensize")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
		}

		if(nameInstruction ==  "color")
        {
            Color myColor;
			myInstruction.setName(nameInstruction);
			// Si el color entra en string para pasarlo a RGB
			if(myInstructionLine.getSize() == 1)
			{
				if(myColor.setColor(myInstructionLine.remove()) == true)
				{
					myInstruction.setR(myColor.getR());
					myInstruction.setG(myColor.getG());
					myInstruction.setB(myColor.getB());
				}
			}
			// Si el valor entra en RGB, validarlo y guardarlo
			if(myInstructionLine.getSize() >= 3)
			{
				int r = toInt(myInstructionLine.remove());
				int g = toInt(myInstructionLine.remove());
				int b = toInt(myInstructionLine.remove());
				//Valida Colores
				if (0 <= r && r <= 255)
				{
					myInstruction.setR(r);
				}else{
					cout << "Error. Color: Codigo R de RGB invalido" << endl;
				}
				if (0 <= g && g <= 255)
				{
					myInstruction.setR(g);
				}else{
					cout << "Error. Color: Codigo G de RGB invalido" << endl;
				}
				if (0 <= b && b <= 255)
				{
					myInstruction.setR(b);
				}else{
					cout << "Error. Color: Codigo B de RGB invalido" << endl;
				}

			}
		}

		if(nameInstruction ==  "pen")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "reset")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "clear")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "write")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setPix(toInt(myInstructionLine.remove()));
			string tempWrite="";
			while(0 < myInstructionLine.getSize())
            {
                tempWrite.append(myInstructionLine.remove());
                tempWrite.append(" ");
            }
			myInstruction.setTxt(tempWrite);
		}

		if(nameInstruction ==  "repeat")
        {
			myInstruction.setName(nameInstruction);
			myInstructionLine.goToStart();
			string cantRepeat = takeOut(myInstructionLine.remove(),'[');
			myInstruction.setPix(toInt(cantRepeat));
//			string cantRepeat = takeOut(myInstructionLine.getElement(),']');
            //myInstructionLine.goToStart();
            while(myInstructionLine.getSize() > 0)
            {
                repeatList.append(getInstruction(myInstructionLine));
            }
		}

		if(nameInstruction ==  "loadfile")
        {
			myInstruction.setName(nameInstruction);
			myInstruction.setTxt(myInstructionLine.remove());
		}

		if(nameInstruction ==  "exec")
        {
			myInstruction.setName(nameInstruction);
		}

		if(nameInstruction ==  "history")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction == "clearhistory")
        {
			myInstruction.setName(nameInstruction);
        }

		if(nameInstruction ==  "exit")
        {
			myInstruction.setName(nameInstruction);
        }
	}else{
		cout << "ERROR. Instruccion: Nombre de instruccion invalido." << endl;
	}
	return myInstruction;
}
/*--------------------------------------------------*/
void welcomeDraw()
{
    cout << "        _.._    _"              << endl;
    cout << "      .'(__)'./`_)      HOLA"   << endl;
    cout << "    _(__(__)__)/       Dotorka" << endl;
    cout << "     (_)''''(_))        Draw"   << endl;
}
/*--------------------------------------------------*/
void ejecutarInstruccion(Instruction pInstruc)
{
    string indicador = pInstruc.getName();

    if(indicador == "forward")
    {
        myCanvas.forward(pInstruc.getPix());
    }

    if(indicador == "back")
    {
        myCanvas.back(pInstruc.getPix());
    }

    if(indicador == "right")
    {
        myCanvas.right(pInstruc.getPix());
    }

    if(indicador == "left")
    {
        myCanvas.left(pInstruc.getPix());
    }

    if(indicador ==  "setpos")
    {
        myCanvas.setx(pInstruc.getX());
        myCanvas.sety(pInstruc.getY());
    }

    if(indicador ==  "setx")
    {
        myCanvas.setx(pInstruc.getX());
    }

    if(indicador ==  "sety")
    {
        myCanvas.sety(pInstruc.getY());
    }

    if(indicador ==  "setheading")
    {
        myCanvas.setheadlilne(pInstruc.getPix());
    }

    if(indicador ==  "home")
    {
        myCanvas.home();
    }

    if(indicador ==  "circle")
    {
        myCanvas.circleD(pInstruc.getPix());
    }

    if(indicador ==  "pos")
    {
        myCanvas.pos();
    }

    if(indicador ==  "xcor")
    {
        myCanvas.getx();
    }

    if(indicador ==  "ycor")
    {
        myCanvas.gety();
    }

    if(indicador ==  "heading")
    {
        myCanvas.heading();
    }

    if(indicador ==  "pendown")
    {
        myCanvas.pendown();
    }

    if(indicador ==  "penup")
    {
        myCanvas.penup();
    }

    if(indicador ==  "pensize")
    {
        myCanvas.pensize(pInstruc.getPix());
    }

    if(indicador ==  "color")
    {
        myCanvas.color(pInstruc.getR(), pInstruc.getG(), pInstruc.getB());
    }

    if(indicador ==  "pen")
    {
        myCanvas.info();
    }

    if(indicador ==  "reset")
    {
        myCanvas.reset();
    }

    if(indicador ==  "clear")
    {
        myCanvas.clear();
    }

    if(indicador ==  "write")
    {
        myCanvas.write(pInstruc.getPix(),pInstruc.getTxt());
    }

    if(indicador ==  "repeat")
    {
        for(repeatList.goToStart();repeatList.getPos() < pInstruc.getPix(); repeatList.next())
            {
                ejecutarInstruccion(repeatList.getElement());
            }
    }

    if(indicador ==  "loadfile")
    {
        File myFile;
        fromFile = myFile.readFile(pInstruc.getTxt());
        for(fileInstructions.goToStart();fileInstructions.getPos() < fileInstructions.getSize(); fileInstructions.next())
        {
            myHistory.append(fromFile.getElement());
            LinkedList<string> lineInstruction = split(fromFile.getElement());
            Instruction newInstru = getInstruction(lineInstruction);
            fileInstructions.append(newInstru);
        }
    }

    if(indicador ==  "exec")
    {
        if(fileInstructions.getSize() == 0)
        {
            cout << "ERROR. Ejecutar Archivo: No Archivo en Memoria."<<endl;
        }else{
            for(fileInstructions.goToStart(); fileInstructions.getPos()<fileInstructions.getSize();fileInstructions.next())
            {
                ejecutarInstruccion(fileInstructions.getElement());
            }
        }
    }

    if(indicador ==  "history")
    {
        for(myHistory.goToStart(); myHistory.getPos() < myHistory.getSize(); myHistory.next())
        {
            cout << myHistory.getElement();
        }
    }

    if(indicador == "clearhistory")
    {
        myHistory.clear();
    }
}
/*--------------------------------------------------*/
int main()
{
    string input;
    welcomeDraw();
    do{
        // Entrada Consola
        cout << "<+>: "; // indicacion de entrada de comando
        cin.getline((char*)input.c_str(),256); // almacenamiento de toda la tira de entrada
        myHistory.append(input);
        LinkedList<string> myInstructionLine = split(input.c_str()); // separacion de elementos
        // FIN ENTRADA CONSOLA
        // Ejecuta instrucction
        Instruction instruccionActual = getInstruction(myInstructionLine);
        if(instruccionActual.getName() == "help")
        {
            help();
        }
        if(instruccionActual.getName() == "exit")
        {
            myCanvas.exit();
            break;
        }else{
            ejecutarInstruccion(instruccionActual);

        }
    }while(!kbhit());//salir != true);
    return 0;
}
