/**
 * @file vector.hpp
 * @version 1.0
 * @date May, 03.
 * @author Daniel Guerra and Oziel Alves
 * @title Class sc::vector
 * @brief Vector class's declaration
 */

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream> // cin,cout
#include <exception> // out_of_range throw
#include <algorithm> //copy
#include <iterator> // ostream_iterator
#include <cstdlib> // size_t
#include <initializer_list> // initializer_list
#include <cassert> // assert

namespace sc{

	template < typename T >
	class vector{

		private:
			
			size_t m_end; //<! last valid element index (vector current size).
			size_t m_capacity; //<! Vector storage capacity.
			const static size_t DEFAULT_SIZE = 0; //!< Vector start size.
			T * m_storage; //<! Dynamic vector data storage.

		public:
			
/*--------------------------[I] Special Members----------------------------------*/	
			
			/*! @brief Creates the vector with the 'a' size setted. */
			vector( size_t size_ );

			/*! @brief Creates the vector with the elements in defined range. */
			//vector( T *first, T *last );

			/*! @brief Creates a default start_size vector size. */ 
			vector( );

			/*! @brief Destructs the vector. */
			~vector( );

			/*! @brief Copy constructor, creats a vector based on the param. */ 
			vector( const vector<T> & vec_to_copy );

			/*! @brief Creates a vector based on a initializer list 'ilist'.*/
			vector( std::initializer_list<T> ilist );
				
			/*! @brief */
			vector<T> & operator=( const vector< T > & vector_ ); 

/*-----------------------------[II] Iterators------------------------------------*/
			
			class MyIterator{

				public:

					/*! @brief Iterator parameter initialization. */
					MyIterator( T* );
				
					/*! @brief Iterator empty initialization. */
					MyIterator( );

					/*! @brief Iterator destrutor. */
					~MyIterator( );

					//! @brief Iterator Assign Operator.
					MyIterator & operator=( const MyIterator& rhs );

					//! @brief Iterator Copy Constructor.
					MyIterator( const MyIterator & itr );
				
					/*! @brief Iterator operator '*'. */
					T & operator* ( ) const;
				
					/*! @brief Iterator operator '++A'. */
					MyIterator operator++ ( );	// ++it;
				
					/*! @brief Iterator operator 'A++'. */
					MyIterator operator++ ( int );	// it++; 
					
					/*! @brief Iterator operator 'A--'. */
					MyIterator operator-- ( );	// --it;		
					
					/*! @brief Iterator operator 'A--'. */
					MyIterator operator-- ( int );	// it--;
					
					/*! @brief Iterator operator '=='. */
					bool operator== ( const MyIterator & rhs ) const;
					
					/*! @brief Iterator operator '!='. */
					bool operator!= ( const MyIterator & rhs ) const;
					
					/*! @brief Iterator operator '+='. */
					MyIterator operator+= ( int );
					
					/*! @brief Iterator operator '+'. */
					MyIterator operator+ ( int );
				
					/*! @brief Iterator operator '-='. */
					MyIterator operator-= ( int );
				
					/*! @brief Iterator operator '-'. */
					MyIterator operator- ( int );

					/*! @brief Iterator operator '-' using a const iterator. */
					int operator- ( const vector< T >::MyIterator& rhs );

				private:

					T *current; //!< Pointer to a vector index.

			};

			/*! @return A pointer to the vector's begin. */
			typename vector< T >::MyIterator begin();
			
			/*! @return A pointer to the vector's end. */
			typename vector< T >::MyIterator end();
			
			/*! @return A const pointer to the vector's begin. */
			typename vector< T >::MyIterator cbegin() const;
			
			/*! @return A const pointer to the vector's end. */
			typename vector< T >::MyIterator cend() const;

	/*-------------------------[III] Storage Capacity----------------------------*/

			/*! @brief Shows the current vector size. */
			size_t size( ) const;

			/*! @brief Show the vector storage capacity. */
			size_t capacity( )const;

			/*! @brief Tells if the vector is empty. */
			bool empty( )const;

			/*! @brief Informs if the vector is full o not. */
			bool full ( )const;

	/*-----------------------------[IV] Modifiers--------------------------------*/

			/*! @brief Remove all the elements from the vector. */                  
			void clear( );                                       
				           
			/*! @brief Add a value to the front of the vector. */                   
			void push_front( const T & value );                                   
			
			/*! @brief Add a value to the end of the vector. */                     
			void push_back( const T & value );
			
			/*! @brief Remove the element at the end of the vector. */              
			void pop_back( ); 
			
			/*! @brief Remove the front of the vector.*/                            
			void pop_front( );

			/*! @brief Insert a value on the vector. */
			typename vector< T >::MyIterator insert( MyIterator itr, const T & value );

			/*! @brief Insert an especific range on the vector. */
			typename vector< T >::MyIterator insert( MyIterator itr, MyIterator first, MyIterator last );

			/*! @brief Inserter from an initializer list. */
			typename vector< T >::MyIterator insert( MyIterator itr, std::initializer_list<T> ilist );
			
			/*! @brief Increase the storage capacity to a param value. */           
			void reserve( size_t new_capacity  );  

			/*! @brief Reduce the capacity() to size(). */                          
			void shrink_to_fit( );    
			
			/*! @brief Replaces the vector content with 'value' copies. */          
			void assign( const T & value  ); 

			/*! @brief Replaces the vector content based on initializer list. */
			void assign( std::initializer_list< T > ilist);

			/*! @brief Replaces the vector content based on initializer list. */
			void assign( MyIterator first, MyIterator last);

			/*! @brief Iterator position eraser. */
			typename vector< T >::MyIterator erase( MyIterator pos);

			/*! @brief Iterator range eraser. */
			typename vector< T >::MyIterator erase( MyIterator first, MyIterator last );

	/*---------------------------[V] Element access------------------------------*/
			
			/*! @return The element at the end of the vector. */
			const T & back ( ) const;
			
			/*! @return The element at the front of the vector. */ 
			const T & front ( ) const;

			/*! @return The element object at the 'pos' index in the vector.
			 * No bounds checking.
			 */ 
			const T & operator[]( size_t pos ) const;
			
			/*! @return The element at the 'pos' indez in the vector.
			 * No bounds checking.
			 */ 
			T & operator[]( size_t pos );

			/*! @return The const element at the 'pos' index in the vector.
			 * Bounds checking.
			 */ 
			const T & at(size_t pos) const;

			/*! @return The elemente at the 'pos' index in the vector.
			 * Bounds checking.
			 */ 
			T & at( size_t pos );

			/*! @return A pointer to the first element in the vector used 
			 * internally by the vector.
			 */ 
			T * data( );

			/*! @return A const pointer to the first element in the vector used
			 * internally by the vector.
			 */ 
			const T & data( ) const;

			/*! @brief Prints the vector, vector's lenght and capacity. */ 
			void print( ) const;


	/*-----------------------------[VI] Operators--------------------------------*/

			/*! @brief iqual operator*/ 
			bool operator==( const vector<T> & vec ) const;
		
			/*! @brief difference operator*/ 
			bool operator!=( const vector<T> & vec ) const;

	/*--------------------------[VII] Friend functions---------------------------*/

			/*! @brief Printer. */
			friend std::ostream & operator<<( std::ostream & os_, const vector< T > & v_ );
			
			/*! @brief Makes swaps between vectors. */
			friend void swap( vector< T > & first_, vector< T > & second_ );

	};
}

//Source Code
#include "vector.inl" // All the class function, operators and stuff like that

#endif
