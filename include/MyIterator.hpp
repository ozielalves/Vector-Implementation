/**
 * @file MyIterator.hpp
 * @version 1.0
 * @date May, 02.
 * @author Daniel Guerra and Oziel Alves
 * @title Class MyIterator
 * @brief MyIterator class's declaration
 */
 
#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_


#include <iostream> // cin,cout
#include <algorithm> //copy
#include <iterator> // ostream_iterator
#include <cstdlib> // size_t
#include <initializar_list> // initializer_list
#include <cassert> // assert


template< typename T >

class MyIterator{

	public:

		MyIterator( );
		
		~MyIterator( );
		
		const T & operator* ( ) const;
		
		MyIterator & operator++ ( );	// ++it;
		
		MyIterator operator++ ( int );	// it++; 
		
		MyIterator & operator-- ( );	// --it;		
		
		MyIterator operator-- ( int );	// it--;
		
		bool operator== ( const MyIterator & rhs ) const;
		
		bool operator!= ( const MyIterator & rhs ) const;
		
		MyIterator operator+= ( int );
		
		MyIterator operator+ ( int );
		
		MyIterator operator-= ( int );
		
		MyIterator operator- ( int );


	private:

		T *current;

};
