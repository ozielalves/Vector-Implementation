/**  
 * @file vector.cpp  
 * @version 1.0  
 * @date 26/04/2018  
 * @author Daniel Guerra and Oziel Alves  
 * @title TAD Vector   
 * @brief Implementation of Vector's functions.  
 */

// agora e a parte legal

#include "vector.h"

using namespace sc;

/*--------------------------[I] Special Members------------------------------*/

vector<T>::vector( size_t sz ){

	m_len = 0;
	m_size = sz_;
	m_storage = new T[sz_+1] /// +1 needed to 'end()' pos. 
}

template< typename T > // evoked when used.
vector< T >::vector( size_t sz_ ){

	m_len = 0;
	m_size = DEFAULT_SIZE;
	m_data = new T[DEFAULT_SIZE + 1]; // 'end()' pos
}

template< typename T >
vector< T >::~vector(){ //Destructor, here wee will free memory space

	delete [] m_data;
}

template< typename T >
vector< T >::vector( std:: initializer_list< T > ilist ){

	
}

/*-----------------------------[II] Iterators--------------------------------*/

/*-------------------------[III] Storage Capacity----------------------------*/

/*-----------------------------[IV] Modifiers--------------------------------*/

/*---------------------------[V] Element access------------------------------*/

/*-----------------------------[VI] Operators--------------------------------*/

/*--------------------------[VII] Friend functions---------------------------*/
