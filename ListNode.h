

#include <iostream>
#include <stdexcept>

using namespace std;

// estructura del nodo
template <class F>
struct node
{
    F val;
    node<F> *next;
};

//metodos para insertar en el nodo
template <class P>
void pushP(node<P> **pn, P info)
{
    node<P> *n = new node<P>;

    n->val = info;
    n->next = *pn;
    *pn = n;
}

template <class P>
void pushBack(node<P> **pn, P info)
{
    node<P> *n = new node<P>;
    n->val = info;
    n->next = nullptr;

    if (!*pn)
    {
        *pn = n;
    }
    else
    {
        node<P> *aux = *pn;

        while (aux->next)
            aux = aux->next;

        aux->next = n;
    }
}
template <class P>
bool RemovedAt(node<P> **pn, int position)
{
    bool deleted = false;
    int curr = 0;
    node<P> *aux = *pn;
    if (position == 0)
    {
        *pn = aux->next;
        free(aux);
        deleted = true;
    }
    while (curr < position)
    {

        if (curr == position - 1)
        {
            
            node<P> * auxToDelete = aux->next;
            aux->next = auxToDelete->next;
            deleted = true;  
            
            free(auxToDelete);
            
            curr++;
        }
        else
        {
            curr++;
            aux = aux->next;
        }
    }
    return deleted;
}

//clase para manejar listas con nodos
template <class T>
class ListNode
{
private:
    node<T> *nodo = nullptr;
    int size;
    //iterador para recorrer la lista de forma eficiente
    int iterator;
    node<T> **it;
    /* data */
public:
    void pushF(T nTinsert)
    {
        pushP(&this->nodo, nTinsert);
        this->size++;
    }

    void push(T insertB)
    {
        pushBack(&this->nodo, insertB);
        this->size++;
    }

    bool deleteAt(int position){
        if(position > this->size - 1){
            return false;
        }else{
            return RemovedAt(&this->nodo, position);
        }
    }

    int getSize()
    {
        return size;
    }

    int getIndexIterator()
    {
        return this->iterator;
    }

    void resetIterator()
    {
        this->iterator = 0;
        this->it = &this->nodo;
    }
    //metodo para obtener el nodo que se encuentra en el iterador y aumenta uno
    node<T> *Next()
    {
        
        if (*this->it != nullptr)
        {
            node<T> *position = *this->it;
            this->it = &(*this->it)->next;
            this->iterator++;
            return position;
        }
        else
        {
            this->resetIterator();
            return nullptr;
        }
    }
    //muestra el nodo que se encuentra en el iterador
    node<T> *Current()
    {
        
        return (*this->it);
    }

    node<T> *operator[](int x)
    {
        if (this->size >= (x + 1))
        {
            int cont = 0;
            node<T> *search = nodo;
            while (cont != x)
            {
                search = search->next;
                cont++;
            }
            return search;
        }
        else
        {
            throw invalid_argument("invalid index! higher than size");
        }
    }

    ListNode(/* args */);
    ~ListNode();
};

template <class T>
ListNode<T>::ListNode(/* args */)
{
    this->it = &this->nodo;
    this->size = 0;
    this->iterator = 0;
}

template <class T>
ListNode<T>::~ListNode()
{
}
