/**  
 * @file vector.inl  
 * @version 1.0  
 * @date May, 01. 
 * @author Daniel Guerra and Oziel Alves  
 * @title TAD Vector   
 * @brief Implementation of Vector's functions.  
 */

#include "vector.hpp"

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

	//TODO

/*-------------------------[III] Storage Capacity----------------------------*/

	template< typename T > // Vector's size
	size_t vector< T >::size(  ) const{
		
		return m_end;
	}

	template< typename T > // Vector's capacity
	size_t vector< T >::capacity(  ) const{

		return m_capacity;
	}

	template< typename T > // Tells if the vector is empty
	bool vector< T >::empty(  ) const{

		return m_end == 0;
	}

	template< typename T > // Tells if the vector is full (making it easier)
	bool vector< T >::full(  ) const{

		return m_end == m_capacity;
	}

/*-----------------------------[IV] Modifiers--------------------------------*/

	template< typename T > 
	void vector< T >::clear(  ){

		delete [] m_storage;
		m_end = 0;
		m_capacity = new T[DEFAULT_SIZE + 1];
	}

	template< typename T > 
	void vector< T >::push_front( const T & value_ ){

		if( full(  ) == true ){
			reserve( 1 + 2 * m_capacity ); // The capacity will be doubled 
		}
		
		for( auto i = m_end; i > 0; --i ){ // Dynamizing the vector
			m_storage[i] = m_storage[i-1];
		}

		m_storage[0] = value;
		m_end++;
	}

	template< typename T > 
	void vector< T >::push_back( const T & value ){
		
		if( full(  ) == true ){
			reserve( 1 + 2 * m_capacity ); // The capacity will be doubled
		}

		m_storage[m_end + 1] = value;
	}

	template< typename T > 
	void vector< T >::pop_back(  ){ // Removing element from the back part
		
		if( empty(  ) == true ){
			throw std::out_of_range("[pop_back()]: Impossible to access an empty vector!");
		}

		--m_end;
	}

	template< typename T > 
	void vector< T >::pop_front(  ){ // Removing element from the front part

		if( empty(   ) == true  ){
			throw std::out_of_range("[pop_front()]: Impossible to access an empty vector!");
		}

		for( auto i(0u); i < m_end; ++i ){
			m_storage[i] = m_storage[i+1];
		}

		m_end--;
	}

	template< typename T >
	void vector< T >::reserve( size_t new_capacity ){

		if( new_capacity <= m_capacity ) return; // Nothing to do 

		T * tmp = m_storage;
		m_capacity = new_capacity;
		m_storage = new T[new_capacity + 1];

		for( auto i(0u); i < m_end; ++i ){
			m_storage[i] = tmp[i];
		}

		delete [] tmp;
	}

	template< typename T >
	void vector< T >::shrink_to_fit(  ){ /* As it says, reduzes the vector
											capacity to fit */
		
		T * tmp = m_storage;
		m_capacity = m_end; // -> what wil make the 'fit' stuff
		m_storage = new T[m_end + 1];

		for( auto i(0u); i < m_end; ++i ){
			m_storage[i] = temp[i];
		}

		delete [] tmp;
	}	

	template< typename T >
	void vector< T >::assign( const T & value ){ /* Replaces the vector with
													copies */
		for( auto i(0u); i < m_end; ++i){
			m_storage[i] = value;
		}
	}

/*---------------------------[V] Element access------------------------------*/

	template< typename T >
	const T & vector< T >::back(  ) const{ // Access the back element

		if( empty(  ) == true ){
			throw std::out_of_range( "[back()]: Impossible to access an empty vector!");
		}

		return m_storage[m_end - 1];
	}

	template< typename T >
	const T & vector< T >::front (  ) const{ // Access the front element

		if( empty(  ) == true ){
			throw std::out_of_range( "[front()]: Impossible to access an empty vector!" );
		}

		return m_storage[0];
	}

	template< typename T >
	const T & vector< T >::operator[]( size_t pos ) const{

		return m_storage[pos];
	}

	template< typename T >
	T & vector< T >::at( size_t pos ) const{

		if( pos < 0 or pos > (m_end - 1)){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}

		return m_storage[pos];
	}

	template< typename T >
	T & vector< T >::at( size_t pos ){
		
		if( pos <  or pos > (m_end - 1)){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}

		return m_storage[pos];
	}

	template< typename T >
	T * vector< T >::data(  ){

		return m_storage;
	}

	template< typename T >
	const T & vector< T >::data(  ) const{

		return m_storage
	}

	template< typename T >
	void vector< T >::print(  ) const{

		std::cout<< "[";
		std::copy( &m_storage[0], &m_storage[m_end], std::ostream_iterator< T >(std::cout, " "));
		std::cout<< "], size: " <<m_end<< ", capacity: " <<m_capacity<<".\n";
	}
	
/*-----------------------------[VI] Operators--------------------------------*/

	template< typename T >
	bool vector< T >::operator==( const vector< T > & vec ) const{

		/* If the size is different of couse they are different */
		if( m_end != vec.m_end ) return false;
		
		for( auto i(0u); i < m_end; ++i ){ // compare each pos on the vector
			if( m_storage[i] != vec.m_storage[i] ) return false;
		}

		return true;
	}

	template< typename T >
	bool vector< T >::operator!=( const< T > & vec ) const{

		// if( m_end == vec.m_end ) return false;

		for (auto i = 0u; i < m_end; ++i){
			if( m_storage[i] == vec.m_storage[i] ) return false;
		}
			return true;
	}

/*--------------------------[VII] Friend functions---------------------------*/

	//TODO

