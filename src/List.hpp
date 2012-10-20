#ifndef LIST_H
#define LIST_H

#include <cstdlib>

template <typename T>
class List;

template <typename T>
struct node
{
    T data;
    node<T>* pNext;
    node<T>* pPrev;
};

template <typename T>
class node_iterator
{
    friend class List<T>;

    public:
        node_iterator();
        node_iterator(node<T>*);
        ~node_iterator();
        
        // Prefix
        node_iterator<T> operator++ (); 
        node_iterator<T> operator-- ();

        // Postfix
        node_iterator<T> operator++ (int);
        node_iterator<T> operator-- (int); 

        T operator* ();

        bool operator== (const node_iterator<T> &other) const;
        bool operator!= (const node_iterator<T> &other) const;

    private:
        node<T>* pCur_;
};

template <typename T>
class List
{
    friend void testList ( void );

    public:
        typedef node_iterator<T> iterator;
        List ();
        List (List<T> &);
        ~List ();
        void insert_at(T, node_iterator<T>&);
        void insert_front(T);
        void insert_back(T);

        void remove_at(node_iterator<T>&);
        void remove_front();
        void remove_back();
        node_iterator<T> begin();
        node_iterator<T> end();
        int size();
        void empty();

    private:
    node<T>* pHead_;
    node<T>* pEnd_;
    int size_;
};

///
///  LIST ITERATOR
///
//______________________________________________________________________________
template <typename T>
node_iterator<T>::node_iterator() : pCur_ (NULL)
{}

//______________________________________________________________________________
template <typename T>
node_iterator<T>::node_iterator(node<T>* node) : pCur_ (node)
{}

//______________________________________________________________________________
template <typename T>
node_iterator<T>::~node_iterator()
{}

//______________________________________________________________________________
template <typename T>
node_iterator<T>
node_iterator<T>::operator++ ()
{
    if ( this->pCur_->pNext != NULL )
        this->pCur_ = this->pCur_->pNext;

    return *this;
}

//______________________________________________________________________________
template <typename T>
node_iterator<T> // Postfix
node_iterator<T>::operator++ (int)
{
    node_iterator<T> self = *this;
    ++(*this);
    return self;
}

//______________________________________________________________________________
template <typename T>
node_iterator<T>
node_iterator<T>::operator-- ()
{
    if ( this->pCur_->pPrev != NULL )
        this->pCur_ = this->pCur_->pPrev;
        
    return *this;
}

//______________________________________________________________________________
template <typename T>
node_iterator<T> // Postfix
node_iterator<T>::operator-- (int)
{
    node_iterator<T> self = *this;
    --(*this);
    return self;
}

//______________________________________________________________________________
template <typename T>
T 
node_iterator<T>::operator* ()
{    return this->pCur_->data;    }

//______________________________________________________________________________
template <typename T>
bool
node_iterator<T>::operator== (const node_iterator<T> &other) const
{    return (this->pCur_ == other.pCur_);    }

//______________________________________________________________________________
template <typename T>
bool
node_iterator<T>::operator!= (const node_iterator<T> &other) const
{    return !( (*this) == other);    }

///
///  LIST
///

//______________________________________________________________________________
template <typename T>
List<T>::List ()
{
    this->pHead_ = this->pEnd_ = new node<T>;

    //this->pHead_->data    = NULL;
    this->pHead_->pNext = NULL;
    this->pEnd_->pPrev    = NULL;
    this->size_ = 0;
}

//______________________________________________________________________________
template <typename T>
List<T>::List (List<T> &rhs)
{
    this->pHead_ = this->pEnd_ = new node<T>;

    this->pHead_->pNext = NULL;
    this->pEnd_->pPrev  = NULL;
    this->size_ = 0;

    List<T>::iterator it = rhs.begin();

    for(; it != rhs.end();it++)
        this->insert_back(*it);
}

//______________________________________________________________________________
template <typename T>
List<T>::~List ()
{
    this->empty();
    delete this->pEnd_;
}

//______________________________________________________________________________
template <typename T>
void
List<T>::empty ()
{
    List<T>::iterator it = this->begin();
    while ( it != this->end() )
        this->remove_at( it );
}

//______________________________________________________________________________
template <typename T>
void
List<T>::insert_at(T item, node_iterator<T> &pos)
{
    node<T>* pMem = NULL;
    
    pMem = new node<T>;
    pMem->data = item;
    pMem->pPrev = pos.pCur_->pPrev;
    pMem->pNext = pos.pCur_;

    if ( pos.pCur_->pPrev )
        pos.pCur_->pPrev->pNext = pMem;
    
    pos.pCur_->pPrev = pMem;

    if ( pos == this->begin() )
        this->pHead_ = pMem;

    pos.pCur_ = pMem;
    this->size_++;
    pos;
}

//______________________________________________________________________________
template <typename T>
void
List<T>::insert_front(T item)
{    
    List<T>::iterator it = this->begin();
    this->insert_at(item, it);
}

//______________________________________________________________________________
template <typename T>
void
List<T>::insert_back(T item)
{    
    List<T>::iterator it = this->end();
    this->insert_at(item, it);
}

//______________________________________________________________________________
template <typename T>
void
List<T>::remove_at(node_iterator<T> &pos)
{
    node<T>* pMem = pos.pCur_;

    if ( pMem->pPrev )
        pMem->pPrev->pNext = pMem->pNext;
    if ( pMem->pNext )
        pMem->pNext->pPrev = pMem->pPrev;
    if ( pos == this->begin() )
        this->pHead_ = pMem->pNext;

    pos.pCur_ = pMem->pNext;

    delete pMem;
    this->size_--;
    pos;
}

//______________________________________________________________________________
template <typename T>
void
List<T>::remove_front()
{    
    List<T>::iterator it = this->begin();
    this->remove_at(it);
}

//______________________________________________________________________________
template <typename T>
void
List<T>::remove_back()
{    
    List<T>::iterator it = this->end();
    this->remove_at(it);
}

//______________________________________________________________________________
template <typename T>
node_iterator<T>
List<T>::begin()
{    return List<T>::iterator(this->pHead_);    }

//______________________________________________________________________________
template <typename T>
node_iterator<T>
List<T>::end()
{    return List<T>::iterator(this->pEnd_);    }

//______________________________________________________________________________
template <typename T>
int
List<T>::size()
{    return this->size_;    }
#endif
