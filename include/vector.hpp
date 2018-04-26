/**
 * @file vector.hpp
 * @version 1.0
 * @date April 26
 * @authors Daniel Guerra and Oziel Alves
 * @title Class sc::vector
 * @brief Vector class's declaration
 */

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream> // cin,cout
#include <algorithm> //copy
#include <iterator> // ostream_iterator
#include <cstdlib> // size_t
#include <initializar_list> // initializer_list
#include <cassert> // assert

namespace sc{

	template< typename T >
	class vector{

	private:
		
		size_t m_end; //<! last valid element index (vector current size)
		size_t m_capacity; //<! Vector storage capacity.
		const static size_t DEFAULT_SIZE = 0; //!< Vector start size.
		T * m_storage //<!Dynamic vector data storage.

		using iterator = MyIterator< T > //
		using const_iterator = MyIterator< const T > //

	public:
		
/*--------------------------[I] Special Members------------------------------*/	
		/*! @brief Creates the vector with the 'a' size setted. */
		vector( size_t a );

		/*! @brief Creates a default start_size vector size. */ 
		vetor(  );

		/*! @brief Destructs the vector. */
		~vector(  );

		/*! @brief Copy constructor, creats a vector based on the param */ 
		vector( const vector<T> & vec_to_copy );

		/*! @brief Creates a vector based on a initializer list 'ilist'.*/
		vector( std::initializer_list<T> ilist );
		
		//...
/*----------------------------[II] Iterators---------------------------------*/

		//...

/*----------------------------[III] Modifiers--------------------------------*/

		//...

/*-------------------------[III] Storage Capacity----------------------------*/

		/*! @brief Shows the current vector size. */
		size_t size(  ) const;

		/*! @brief Show the vector storage capacity */
		size_t storage_cap(  )const;

		/*! @brief Tells if the vector is empty. */
		bool empty(  )const;

		/*! @brief Informs if the vector is full o not */
		bool full (  )const;

		/*! @brief Remove all the elements from the vector */
		void clear(  );

		/*! @brief Add a value to the front of the vector */
		void push_front(  );

		/*! @brief Add a value to the end of the vector */
		void push_back(  );

		/*! @brief Remove the element at the end of the vector */
		void pop_back(  );

		/*! @brief Remove the front of the vector*/
		void pop_front(  );
		
		/*! @brief Increase the storage capacity to a param value */
		void reserve( size_t new_cap );

		/*! @brief Reduce the capacity() to size() */
		void to_fit(  );

		/*! @brief





/*----------------------------[III] Modifiers--------------------------------*/

	//...

/*---------------------------[V] Element access------------------------------*/
	
	//...

/*-----------------------------[VI] Operators--------------------------------*/

	//...
	
/*--------------------------[VII] Friend functions---------------------------*/

	//... 

	};
}

