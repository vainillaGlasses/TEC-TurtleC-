#ifndef NODELL_H
#define NODELL_H


// Clase Nodo(para Double Link Array)
template <typename E>
class Node
{
    public:
    // Atributos
    E element;
    Node<E>* next;
    // Contructor (1) Inicia
    Node(E pElement, Node<E>* pNext = NULL)
    {
        element = pElement;
        next = pNext;
    }
    // Constructor (2) Con nodos Existentes
    Node(Node<E>* pNext = NULL)
    {
        next = pNext;
    }
};

#endif // NODELL_H
