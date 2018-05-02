/**  
 * @file MyIterator.inl  
 * @version 1.0  
 * @date May, 02. 
 * @authors Daniel Guerra and Oziel Alves  
 * @title TAD Vector Iterators class
 * @brief Implementation of MyIterator's functions.  
 */

#include "MyIterator.hpp"

/// Was we discovered at class, we can make a 2 in 1 Constructor.
/// Here, we have empty initialization and parameter initialization.
template< typename T >
MyIterator< T >::MyIterator( T* ptr=nullptr ) : current( ptr )
{ /* empty */}

/// Default Destructor
template < typename T >
MyIterator< T >::~MyIterator() = default;	

/// Assign Operator
template < typename T >
MyIterator< T >& MyIterator< T >::operator= ( const MyIterator& rhs )
{
	this->current = rhs.current;
}

/// Copy Constructor
template < typename T >
MyIterator< T >::MyIterator( const MyIterator& itr ) : current( itr.current)
{/* empty */ }	

/// Reference for MyIterator
template < typename T >
T& MyIterator< T >::operator* ( void ) const
{
	return *(this->current);
}

/// Operator++
// ++it;
template < typename T >
MyIterator< T >& MyIterator< T >::operator++( )
{
	return ++(this->current);
}

///Operator++
// it++;
template < typename T >
MyIterator< T > MyIterator< T >::operator++( int )
{
	MyIterator temp( *this );
	++(this->current);
	return temp;
} 	

///Operator--
// --it;
template < typename T >
MyIterator< T >& MyIterator< T >::operator--( )
{
	return --(this->current);
}

///Operator--
// it--;
template < typename T >
MyIterator< T > MyIterator< T >::operator--( int )
{
	MyIterator temp( *this );
	--(this->current);
	return temp;
}

///Bool for Operator==
template < typename T >
bool MyIterator< T >::operator==( const MyIterator& rhs ) const
{
	return this->current == rhs.current;
}

///Bool for Operator!=
template < typename T >
bool MyIterator< T >::operator!=( const MyIterator& rhs ) const
{
	return this->current != rhs.current;
}

/// Operator+=
template < typename T >
MyIterator< T > MyIterator< T >::operator+=( int x )
{
	this->current = this->current + x;
	return this->current;
}

/// Operator+
template < typename T >
MyIterator< T > MyIterator< T >::operator+( int x )
{
	return this->current + x;
}


/// Operator-=
template < typename T >
MyIterator< T > MyIterator< T >::operator-=( int x )
{
	this->current = this->current - x;
	return this->current;
}

/// Operator-
template < typename T >
MyIterator< T > MyIterator< T >::operator-(int x )
{
	return this->current - x;
}



