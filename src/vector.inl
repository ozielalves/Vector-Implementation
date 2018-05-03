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

	template< typename T > // evoked when used.
	vector< T >::vector( size_t size_ ){

		m_end = 0;
		m_capacity = size_;
		m_storage = new T[size_+1]; /// +1 needed to 'end()' pos. 
	
	}

	template< typename T > 
	vector< T >::vector( ){

		m_end = 0;
		m_capacity = DEFAULT_SIZE;
		m_storage = new T[DEFAULT_SIZE + 1]; // 'end()' pos
	}

	template< typename T >
	vector< T >::~vector( ){ // Destructor, here wee will free memory space

		delete [] m_storage;
	}

	/// Copy Constructor
	template< typename T >
	vector< T >::vector( const vector< T > & vec_to_copy ){// Vector based on other

		m_end = vec_to_copy.m_end;
		m_capacity = vec_to_copy.m_capacity;
		m_storage = new T[ vec_to_copy.m_capacity + 1 ]; // 'end()' pos

		for( auto i = 0u; i < m_end; ++i /* better than i++ on this case */){
			
			m_storage[i] = vec_to_copy.m_storage[i];
		}
	}

	template< typename T >
	/* Vector created based on a initializer list */
	vector< T >::vector( std:: initializer_list< T > ilist ){

		m_end = ilist.size( );
		m_capacity = ilist.size( );
		m_storage = new T[ ilist.size( ) + 1];

		for( auto i = 0u; i < m_end; ++i /* better than i++ */ ){

			m_storage[i] = *(ilist.begin( ) + i);
		}

	}

	template< typename T >
	vector< const T > & vector< T >::operator=( const vector< T > & vector_ ){
		if( this->m_end < vector_.m_end ){
			this->reserve( vector_.m_end);
		}

		this->m_capacity = vector_.m_capacity
		this->m_end = vector_.m_end;
		this->m_storage = this->vector_.m_storage;

		for( int i = 0; i < vector_.m_end; i++ ){
			this->m_storage[i] = vector_.m_storage[i];
		}
		
		return *this;
	}

	template< typename T>
	vector< T > & vector< T >::operator=( std::initializer_list< T > ilist ){

		int tmp_capacity;
		if( ilist.size() > 2 ){
			tmp_capacity = pow( 2, int( log2(.size() ) ) );
			if( ilist.size() > tmp_capacity ){
				tmp_capacity *= 2;
			}
		}else{
			tmp_capacity = ilist.size();
		}

		this->elements = new T[tmp_capacity];

		int seta = 0;
		for( auto i(std::begin(ilist)); i!= std::end(ilist); i++, seta++){
			m_storage[seta] = *i;
		}

		this->m_capacity = tmp_capacity
		this->m_end = ilist.size()
		if(debug) std::cout <<" SAIU DA FUNCAO AMEM \n";
	}

/*-----------------------------[II] Iterators--------------------------------*/

	/// Was we discovered at class, we can make a 2 in 1 Constructor.
	/// Here, we have empty initialization and parameter initialization.
	template< typename T >
	vector< T >::iterator::MyIterator( T* ptr=nullptr ) : current( ptr )
	{ /* empty */}

	/// Default Destructor
	template < typename T >
	vector< T >::iterator::~MyIterator() = default;	

	/// Assign Operator
	template < typename T >
	typename vector< T >::iterator& vector< T >::iterator::operator=( const vector< T >::MyIterator& rhs ){
		
		this->current = rhs.current;
	}

	/// Copy Constructor
	template < typename T >
	vector< T >::iterator::MyIterator( const vector< T >::MyIterator& itr ) : current( itr.current)
	{/* empty */ }	

	/// Reference for MyIterator
	template < typename T >
	T & vector< T >::iterator::operator* ( void ) const{
		
		return *(this->current);
	}

	/// Operator++
	// ++it;
	template < typename T >
	typename vector< T >::iterator& vector< T >::iterator::operator++( void ){
		
		return ++(this->current);
	}

	///Operator++
	// it++;
	template < typename T >
	typename vector< T >::iterator vector< T >::iterator::operator++( int ){
		
		MyIterator temp( *this );
		++(this->current);
		return temp;
	} 	

	///Operator--
	// --it;
	template < typename T >
	typename vector< T >::iterator& vector< T >::iterator::operator--( void ){
		
		return --(this->current);
	}

	///Operator--
	// it--;
	template < typename T >
	typename vector< T >::iterator vector< T >::iterator::operator--( int ){
		
		MyIterator temp( *this );
		--(this->current);
		return temp;
	}

	///Bool for Operator==
	template < typename T >
	bool vector< T >::iterator::operator==( const vector< T >::MyIterator& rhs ) const{
		
		return this->current == rhs.current;
	}

	///Bool for Operator!=
	template < typename T >
	bool vector< T >::iterator::operator!=( const vector< T >::MyIterator& rhs ) const{
		
		return this->current != rhs.current;
	}

	/// Operator+=
	template < typename T >
	typename vector< T >::iterator vector< T >::iterator::operator+=( int x ){
		
		this->current = this->current + x;
		return this->current;
	}

	/// Operator+
	template < typename T >
	typename vector< T >::iterator vector< T >::iterator::operator+( int x ){
		
		return this->current + x;
	}

	/// Operator+
	// In case of another iterator
	template < typename T >
	int vector< T >::iterator::operator+( const vector< T >::MyIterator& rhs ){
		
		return this->current + rhs.current;
	}

	/// Operator-
	// In case of a int
	template < typename T >
	typename vector< T >::iterator vector< T >::iterator::operator-( int x )
	{
		
		return this->current - x;
	}

	/// Operator-
	//In case of another iterator
	template < typename T >
	int vector< T >::iterator::operator-( const vector< T >::MyIterator& rhs )
	{
		
		return this->current - rhs.current;
	}

	/// Operator-=
	template < typename T >
	typename vector< T >::iterator vector< T >::iterator::operator-=( int x ){
		
		this->current = this->current - x;
		return this->current;
	}	
//------------=--------KKEEEKK------------=----------//
	template < typename T >
	typename vector< T >::iterator vector< T >::begin( void ){
		
		return vector< T >::iterator(&m_storage[0]);
	}

	template < typename T >
	typename vector< T >::iterator vector< T >::end( void ){
		
		return vector< T >::iterator(&m_storage[m_capacity]);
	}

	template < typename T >
	typename vector< T >::const_iterator vector< T >::cbegin( void ) const{
		
		return vector< T >::const_iterator(&m_storage[0]);
	}

	template < typename T >
	typename vector< T >::const_iterator vector< T >::cend( void ) const{
		
		return vector< T >::const_iterator(&m_storage[m_capacity]);
	}

/*-------------------------[III] Storage Capacity----------------------------*/

	template< typename T > // Vector's size
	size_t vector< T >::size( ) const{
		
		return m_end;
	}

	template< typename T > // Vector's capacity
	size_t vector< T >::capacity( ) const{

		return m_capacity;
	}

	template< typename T > // Tells if the vector is empty
	bool vector< T >::empty( ) const{

		return m_end < 0;
	}

	template< typename T > // Tells if the vector is full (making it easier)
	bool vector< T >::full( ) const{

		return m_end == m_capacity;
	}

/*-----------------------------[IV] Modifiers--------------------------------*/

	//TODO
/*	
	iterator insert( ****iterator**** , const value );

	template < typename InputItr >
	iterator insert( ****iterator**** , InputItr , InputItr );

	iterator insert( ****iterator****, std::initializer_list< T > ilist);
*/
	template< typename T >
	typename vector< T >::iterator vector< T >::erase( iterator pos ){
		
		for(auto i(pos); i != end(); i++){
			if( i == begin() ){
				continue;
			}
			*(i - 1) = *i;
		}
		m_end--;
		m_capacity--;

		return pos;
	} 

	template < typename T >
	typename vector< T >::iterator vector< T >::erase( iterator first, iterator last ){
		
		iterator j(first);
		int counter = 0;
		for(auto i(last); i != end(); i++){
			*(j++) = *i;
			counter ++;
		}
		int diff = last.current - first.current;
		//int diff = last - first; to see if operator '-' works.

		m_end = m_end - diff;
		m_capacity = m_capacity - diff;

		return first;
	} 
			
	template< typename T > 
	void vector< T >::clear(  ){

		delete [] m_storage;
		m_end = 0;
		m_capacity = 0;
		m_storage = new T[DEFAULT_SIZE + 1];
	}

	template< typename T > 
	void vector< T >::push_front( const T & value ){

		if( full(  ) == true ){
			reserve( 1 + m_capacity ); // The capacity will be doubled 
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
			reserve( 1 + m_capacity ); // The capacity will be doubled
		}

		m_storage[m_end++] = value;
		
	}

	template< typename T > 
	void vector< T >::pop_back( ){ // Removing element from the back part
		
		if( empty(  ) == true ){
			throw std::out_of_range("[pop_back()]: Impossible to access an empty vector!");
		}

		--m_end;
	}

	template< typename T > 
	void vector< T >::pop_front( ){ // Removing element from the front part

		if( empty(   ) == true  ){
			throw std::out_of_range("[pop_front()]: Impossible to access an empty vector!");
		}

		for( auto i(0u); i < m_end; ++i ){
			m_storage[i] = m_storage[i+1];
		}

		m_end--;
	}

	template < typename T >
	typename vector< T >::iterator vector< T >::insert( iterator itr, const T& value)
	{

		if(m_end == m_capacity) {
			reserve(1 + m_capacity); //Increases capacity
		}

		// Iterator to the last element with atributed value in vector
		vector<T>::iterator it_temp;
		it_temp = this->.begin() + (m_end + 1);

		for(auto i(it_temp); i != itr; i--)
		{
			*i = *(i-1);
		}
		
		*itr = value;
		return itr;
	}

	template< typename T >
	typename vector< T >::iterator vector< T >::insert( iterator itr, iterator first, iterator last )
	{
		int distance = last-first;
		T *tmp = new T[distance];

		if(m_end + distance >= m_capacity)
		{
			this->reserve(m_end+distance);
		}
		int j = 0;
		for(auto i(first); i != last && i != end(); i++, j++)
		{
			*(tmp+j) = *i;
		}

		


		m_end += distance;
		m_capacity += distance;

		return itr;
	}

	template< typename T >
	void vector< T >::reserve( size_t new_capacity ){

		if( new_capacity <= m_capacity ) return; // Nothing to do 

		T * tmp = m_storage;
		m_capacity = new_capacity;
		m_storage = new T[new_capacity +1];

		for( auto i(0u); i < m_end; i++ ){
			m_storage[i] = tmp[i];
		}

		delete [] tmp;
	}

	template< typename T >
	void vector< T >::shrink_to_fit( ){ /* As it says, reduzes the vector capacity to fit */
		
		T * tmp = m_storage;
		m_capacity = m_end; // -> what wil make the 'fit' stuff
		m_storage = new T[m_end + 1];

		for( auto i(0u); i < m_end; ++i ){
			m_storage[i] = tmp[i];
		}

		delete [] tmp;
	}	
	
	template< typename T >
	void vector< T >::assign( const T & value ){ /* Replaces the vector with copies */
		for( auto i(0u); i < m_end; ++i){
			m_storage[i] = value;
		}
	}

// TA AQUI PORRAA >>>>>>>>>>>>>>--------------------<<<<<<<<<<<<<<<
	
	template < typename T >
	void vector< T >::assign( std::initializer_list< T > ilist ){
		for( auto i(0u); i < m_end; ++i){
			m_storage[i] = ilist;
		}
	}

/*---------------------------[V] Element access------------------------------*/

	template< typename T >
	const T & vector< T >::back( ) const{ // Access the back element

		if( empty(  ) == true ){
			throw std::out_of_range( "[back()]: Impossible to access an empty vector!");
		}

		return m_storage[m_end - 1];
	}	

	template< typename T >
	const T & vector< T >::front ( ) const{ // Access the front element

		if( empty(  ) == true ){
			throw std::out_of_range( "[front()]: Impossible to access an empty vector!");
		}

		return m_storage[0];
	}

	template< typename T >
	T & vector< T >::operator[]( size_t pos ){
		
		return m_storage[pos];
	}

	template< typename T >
	const T & vector< T >::operator[]( size_t pos ) const{

		return m_storage[pos];
	}



	template< typename T >
	const T & vector< T >::at( size_t pos ) const{

		if( pos < 0 or pos > m_end - 1){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}

		return m_storage[pos];
	}

	template< typename T >
	T & vector< T >::at( size_t pos ){
		
		if( pos < 0  or pos > m_end - 1){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}

		return m_storage[pos];
	}

	template< typename T >
	T * vector< T >::data( ){

		return m_storage;
	}

	template< typename T >
	const T & vector< T >::data( ) const{

		return m_storage;
	}

	template< typename T >
	void vector< T >::print( ) const{

		std::cout<< "[ ";
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
	bool vector< T >::operator!=( const vector< T > & vec ) const{

		// if( m_end == vec.m_end ) return false;

		for (auto i = 0u; i < m_end; ++i){
			if( m_storage[i] == vec.m_storage[i] ) return false;
		}
			return true;
	}

/*--------------------------[VII] Friend functions---------------------------*/

	void swap( vector< T >& first_, vector< T >& second_){

		T *tmp_storage1 = first_.m_storage;
		T *tmp_storage2 = second_.m_storage;

		std::swap(first_.m_capacity, second_.m_capacity);

		delete [] first_.m_storage;
		delete [] second_.m_storage;

		first_.m_storage = new T[first_.m_capacity];
		second_.m_storage = new T[second_.m_capacity];
		
		for(int i = 0; i < first_.m_end; i++) {
			*(second_.m_storage+i) = *(tmp_storage1+i);
		}
		
		for(int i = 0; i < second_.m_end; i++) {
			*(first_.m_storage+i) = *(tmp_storage2+i);
		}

		std::swap(first_.m_end, second_.m_end);	
	}


	std::ostream& operator<<( std::ostream os, const vector< T >& rhs )
	{
		os << "[ ";
		for( auto i(0u); i < rhs.m_end; i++)
		{
			os << *(rhs.m_storage+i) << " ";
		}
		os << "]";
		return os;
	}
