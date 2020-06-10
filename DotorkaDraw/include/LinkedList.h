#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <Node.h>

using namespace std;

template <typename E>
class LinkedList
{
    private:
        Node<E> *head;
        Node<E> *tail;
        Node<E> *current;
        int size;
        // Para invertir
        Node<E> *frontPos;
    public:
        LinkedList(){
            head = new Node<E>;
            tail = head;
            current = head;
            size = 0;
        }
        virtual ~LinkedList()
        {
            clear();
            delete head;
        }
        void insert(E pElement)
        {
            current->next = new Node<E>(pElement, current->next);
            if(current == tail)
            {
                tail = tail->next;
            }
            size++;
        }
        void append(E pElement)
        {
            tail->next = new Node<E>(pElement);
            tail = tail->next;
            size++;
        }
        E remove() throw (runtime_error)
        {
            if(size == 0)
            {
                throw runtime_error("Error: Lista Vacia");
            }
            if(current==tail)
            {
                throw runtime_error("Error: Posicion fuera de rango.");
            }
            E res = current->next->element;
            Node<E> *temp = current->next;
            current->next = current->next->next;
            if(temp == tail)
            {
                tail = current;
            }
            delete temp;
            size--;
            return res;
        }

        void clear()
        {
            while (head->next != NULL)
            {
                current = head->next;
                head->next = head->next->next;
                delete current;
            }
            tail = current = head;
            size = 0;
        }

        E getElement() throw (runtime_error)
        {
            if(size==0)
            {
                throw runtime_error("Error: Lista Vacia");
            }

            if(current == tail)
            {
                throw runtime_error("Error: No existe el elemento.");
            }

            return current->next->element;
        }

        void goToStart()
        {
            current = head;
        }

        void goToEnd()
        {
            current = tail;
        }

        void goToPos(int pPos) throw (runtime_error)
        {
            if(pPos<0 || pPos > size)
            {
                throw runtime_error("Error: Posicion fuera de rango.");
            }
            current = head;
            for(int i = 0; i < pPos; i++)
            {
                current = current->next;
            }
        }

        void next()
        {
            if(current->next != NULL)
            {
                current = current->next;
            }
        }

        void previous()
        {
            if (current != head)
            {
                Node<E> *temp = head;
                while(temp->next != current)
                {
                    temp = temp->next;
                }
                current = temp;
            }
        }

        int getPos()
        {
            int pos = 0;
            Node<E> *temp = head;
            while(temp != current)
            {
                pos++;
                temp = temp->next;
            }
            return pos;
        }

        int getSize()
        {
            return size;
        }

        void printList()
        {
            int pos = getPos();
            goToStart();
            cout << "Mi Lista:\n    [";
            for(int i = 0; i < size;i++)
            {
                if(i == size-1)
                {
                    cout << current->next->element;
                    break;
                }
                if(i == pos)
                {
                    cout << "->" << current->next->element << "<-" << ", ";
                }else{
                    cout << current->next->element << ", ";
                }
                current = current->next;
            }

            cout << "]" << endl;
            goToPos(pos);
        }


        // Invertir
        void invertir() throw (runtime_error)
        {
            if (size == 0)
            {
                throw runtime_error ("Error: Lista Vacia");
            }

            //Almacenamiento Temporal
            E tempA;
            E tempZ;
            for(int i = 0; i < (size/2); i++)
            {
                goToPos(i);
                tempA = current->next->element;
                goToPos(size-i-1);
                tempZ = current->next->element;
                current->next->element = tempA;
                goToPos(i);
                current->next->element = tempZ;
            }
            current = head;
        }

        void concatenar(LinkedList<E> miLista2)
        {
            for(int i = 0;i < miLista2.getSize(); miLista2.next())
            {
                miLista2.goToPos(i);
                append(miLista2.getElement());
            }
        }

        void switchNode(int PosA, int PosB) throw (runtime_error)
        {
            if (PosA > size)
            {
                throw runtime_error("Error: Primera posición mayor al tamaño de la lista.\nReiniciar Proceso.");
            }
            if (PosB > size)
            {
                throw runtime_error("Error: Segunda posición mayor al tamaño de la lista.\nReiniciar Proceso.");
            }
            // Nodos iguales
            if (PosA == PosB)
            {
                throw runtime_error("Alerta: Posiciones Iguales, el intercambio de nodos es irrelevante.");
            }

            // Ver cual nodo es menor y cual mayor y acomodarlos
            if (PosB < PosA)
            {
                int temp;
                temp = PosA - 2;
                PosA = PosB;
                PosB = temp;
            }
            // Temporales
            Node<E>* tempA;
            Node<E>* tempB;
            goToPos(PosA);
            tempA = current->next;
            goToPos(PosB);
            tempB = current->next;
            // Sustituir el nodo de mayor posicion en el de menor posicion
            goToPos(PosA);
            current->next = current->next->next;
            goToPos(PosB);
            tempA->next = current->next->next;
            current->next = tempA;
            goToPos(PosA);
            tempB->next = current->next;
            current->next = tempB;
        }
};
#endif // LINKEDLIST_H

