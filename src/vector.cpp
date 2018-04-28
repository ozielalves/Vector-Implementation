/**  
 * @file vector.cpp  
 * @version 1.0  
 * @date April, 27. 
 * @author Daniel Guerra and Oziel Alves  
 * @title TAD Vector   
 * @brief Implementation of Vector's functions.  
 */

// agora e a parte legal

#include "vector.h"

using namespace sc;

/*--------------------------[I] Special Members------------------------------*/

vector<T>::vector( size_t size_ ){

	m_end = 0;
	m_capacity = size_;
	m_storage = new T[size_+1] /// +1 needed to 'end()' pos. 
}

template< typename T > // evoked when used.
vector< T >::vector(  ){

	m_end = 0;
	m_capacity = DEFAULT_SIZE;
	m_storage = new T[DEFAULT_SIZE + 1]; // 'end()' pos
}

template< typename T >
vector< T >::~vector(  ){ // Destructor, here wee will free memory space

	delete [] m_storage;
}

template< typename T >
vector< T >::vector( const vector< T > & vec_to_copy ){// Vector based on other

	m_end = vec_to_copy.m_end;
	m_capacity = vec_to_copy.m_capacity;
	m_storage = new T[ vec_to_copy.m_capacity + 1 ]; // 'end()' pos

	for( auto i = 0u; i < m_end; ++i /* better than i++ on this case */)
}

template< typename T >
/* Vector created based on a initializer list */
vector< T >::vector( std:: initializer_list< T > ilist ){

	m_end = ilist.size(  );
	m_capacity = ilist.size(  );
	m_storage = new T[ ilist.size(  ) + 1];

	for( auto i = 0u; i < m_end; ++i /* better than i++ */ ){
		m_storage[i] = *(ilist.begin(  ) + i);
}
}

/*-----------------------------[II] Iterators--------------------------------*/

/*-------------------------[III] Storage Capacity----------------------------*/

/*-----------------------------[IV] Modifiers--------------------------------*/

/*---------------------------[V] Element access------------------------------*/

/*-----------------------------[VI] Operators--------------------------------*/

/*--------------------------[VII] Friend functions---------------------------*/
