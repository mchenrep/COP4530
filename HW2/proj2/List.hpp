#ifndef LIST_HPP
#define LIST_HPP
#include "List.h"

using namespace std;
using namespace cop4530;

// const_iterator definitions

template <typename T>
List<T>::const_iterator::const_iterator(): current{nullptr}
{}

template <typename T>
const T & List<T>::const_iterator::operator* () const
{ return retrieve(); }

template <typename T>
const T* List<T>::const_iterator::operator->() const
{return &(retrieve());}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++ ()         // prefix
{
  current = current->next;
  return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++ (int)			// postfix
{
  const_iterator old = *this;
  ++( *this );
  return old;
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator-- ()
{
  current = current->prev;
  return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator-- ( int )
{
  const_iterator old = *this;
  --( *this );
  return old;
}

template <typename T>
bool List<T>::const_iterator::operator== ( const const_iterator & rhs ) const
{ return current == rhs.current; }

template <typename T>
bool List<T>::const_iterator::operator!= ( const const_iterator & rhs ) const
{ return !( *this == rhs ); }

template<typename T>
T & List<T>::const_iterator::retrieve() const
{ return current->data; }

template<typename T>
List<T>::const_iterator::const_iterator( Node *p ) :  current{p}
{}

// iterator definitions

template<typename T>
List<T>::iterator::iterator() { }

template<typename T>
T & List<T>::iterator::operator* ( )
{ return const_iterator::retrieve( );}

template<typename T>
const T & List<T>::iterator::operator* ( ) const
{ return const_iterator::operator*();}

template<typename T>
T* List<T>::iterator::operator->()
{return &(const_iterator::retrieve());}

template<typename T>
const T* List<T>::iterator::operator->() const
{return &(const_iterator::retrieve());}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++ ( )
{
  this->current = this->current->next;
  return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator:: operator++ ( int )
{
  iterator old = *this;
  ++( *this );
  return old;
}

template<typename T>
typename List<T>::iterator::iterator& List<T>::iterator::operator-- ( )
{
  this->current = this->current->prev;
  return *this;
}

template<typename T>
typename List<T>::iterator::iterator List<T>::iterator::operator-- ( int )
{
  iterator old = *this;
  --( *this );
  return old;
}

template<typename T>
List<T>::iterator::iterator( Node *p ) : const_iterator{ p }
{ }


// list function definitions

template <typename T>
List<T>::List( )
{ init( ); }

template <typename T>
List<T>::List( const List & rhs )			
{
  init( );
  for( auto & x : rhs )
    push_back( x );
}

template <typename T>
List<T>::List( List && rhs ) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
{
  rhs.theSize = 0;
  rhs.head = nullptr;
  rhs.tail = nullptr;
}

template <typename T>
List<T>::List(int num, const T& val) 
{
  init();
  for(int i = 0; i < num; i++)
  {
    push_back(val);
  }
}

template <typename T>
List<T>::List(const_iterator start, const_iterator end) 
{
  init();
  for(auto i = start; i != end; ++i)
  {
    push_back(*i);
  }
}
template <typename T>
List<T>::~List( )
{
  clear( );
  delete head;
  delete tail;
}
template <typename T>
const List<T>& List<T>::operator= ( const List & rhs )		// copy assignment operator=
{
  List copy = rhs;
  std::swap( *this, copy );
  return *this;
}

template <typename T>
List<T>& List<T>::operator= ( List && rhs )			// move assignment operator=
{    
  std::swap( theSize, rhs.theSize );
  std::swap( head, rhs.head );
  std::swap( tail, rhs.tail );
  return *this;
} 

template <typename T>
int List<T>::size( ) const
{ return theSize; }

template <typename T>
bool List<T>::empty( ) const
{ return size( ) == 0; }

template <typename T>
void List<T>::clear( )
{
  while( !empty( ) )
    pop_front( );
}

template <typename T>
void List<T>::reverse() 
{
  List x;
  for(auto i = this->begin(); i != this->end(); ++i)
  {
    x.push_front(*i);
  }
  *this = x;
}

template <typename T>
T & List<T>::front( )
{ return *begin( ); }

template <typename T>
const T & List<T>::front( ) const
{ return *begin( ); }

template <typename T>
T & List<T>::back( )
{ return *--end( ); }

template <typename T>
const T & List<T>::back( ) const
{ return *--end( ); }

template <typename T>
void List<T>::push_front( const T & x ) // copy		
{ insert( begin( ), x ); }

template <typename T>
void List<T>::push_back( const T & x ) // copy	
{ insert( end( ), x ); }

template <typename T>
void List<T>::push_front( T && x )		// move
{ insert( begin( ), std::move( x ) ); }

template <typename T>
void List<T>::push_back( T && x )		// move
{ insert( end( ), std::move( x ) ); }

template <typename T>
void List<T>::pop_front( )
{ erase( begin( ) ); }

template <typename T>
void List<T>::pop_back( )
{ erase( --end( ) ); }

template <typename T>
void List<T>::remove(const T &val) 
{
  for(auto i = begin(); i != end(); ++i)
  {
    if(*i == val)
    {
      erase(i);
    }
  }
}

template <typename T>
void List<T>::print(std::ostream& os, char ofc) const 
{
  for(auto i = this->begin(); i != this->end(); ++i)
  {
    os << *i << ofc;
  }
}

template <typename T>
typename List<T>::iterator List<T>::begin( )
{ return iterator( head->next ); }

template <typename T>
typename List<T>::const_iterator List<T>::begin( ) const
{ return const_iterator( head->next ); }

template <typename T>
typename List<T>::iterator List<T>::end( )
{ return iterator( tail ); }

template <typename T>
typename List<T>::const_iterator List<T>::end( ) const
{ return const_iterator( tail ); }

template <typename T>
typename List<T>::iterator List<T>::insert( iterator itr, const T & x )
{
  Node *p = itr.current;
  ++theSize;
  return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
}

template <typename T>
typename List<T>::iterator List<T>::insert( iterator itr, T && x )
{
  Node *p = itr.current;
  ++theSize;
  return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
}

template <typename T>
typename List<T>::iterator List<T>::erase( iterator itr )
{
  Node *p = itr.current;
  iterator retVal( p->next );
  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;
  --theSize;
  return retVal;
}

template <typename T>
typename List<T>::iterator List<T>::erase( iterator from, iterator to )
{
  for( iterator itr = from; itr != to; )
    itr = erase( itr );
  return to;
}

template <typename T>
void List<T>::init( )
{
  theSize = 0;
  head = new Node;
  tail = new Node;
  head->next = tail;
  tail->prev = head;
}

template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
  if(lhs.size() != rhs.size())
    return false;
  else{
    auto i = lhs.begin();
    auto j = rhs.begin();
    while((i != lhs.end()) & (j != rhs.end()))
    {
      if(*i != *j)
        return false;
      ++i;
      ++j;
    }
    return true;
  }
}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
  return (!(lhs==rhs));
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &l)
{
  for (auto &x : l)
    os << x << " ";
  return os;
}

#endif

