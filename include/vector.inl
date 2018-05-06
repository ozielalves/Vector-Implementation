#include "vector.hpp"

/**  
 * @file vector.inl  
 * @version 1.0  
 * @date May, 01. 
 * @author Daniel Guerra and Oziel Alves  
 * @title TAD Vector   
 * @brief Implementation of Vector's functions.  
 */

using namespace sc;

/*--------------------------[I] Special Members------------------------------*/

	template< typename T > // evoked when used.
	vector< T >::vector( size_t size_ ){

		m_capacity = size_;
		m_storage = new T[size_];
		for(int i=0; i < m_capacity; i++)
		{
			*(m_storage+i) = DEFAULT_SIZE;
		}
		m_end = 0;
	}

	template< typename T > 
	vector< T >::vector( ){

		m_end = 0;
		m_capacity = DEFAULT_SIZE+1;
		m_storage = new T[m_capacity];
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
		m_storage = new T[ vec_to_copy.m_capacity ]; // 'end()' pos

		for( auto i = 0; i < m_end; i++){
			
			*(m_storage+i) = *(vec_to_copy.m_storage+i);
		}
	}

	template< typename T >
	/* Vector created based on a initializer list */
	vector< T >::vector( std::initializer_list<T> ilist )
	{/*
		int tmp_capacity;
		std::cout << ilist.size() << "\n";	
		if( ilist.size() > 2 ){
			tmp_capacity = pow( 2, (int) log2( ilist.size() ) );			
			if( ilist.size() > tmp_capacity ){
				std::cout << "tem qqu entrar\n";
				tmp_capacity *= 2;		
			}
		} else {
			tmp_capacity = ilist.size();	
		}
		std::cout << m_capacity << "\n";
		reserve( tmp_capacity );
		std::cout << m_capacity << "\n";

		int carambola = 0;
		for( auto i(ilist.begin()); i != ilist.end(); i++, carambola++ ){
			*(m_storage + carambola) = *i;
		}

		m_end = ilist.size() - 1;
		m_capacity = tmp_capacity;*/

		m_end  = ilist.size();
		m_capacity = ilist.size();
		m_storage = new T[ ilist.size() + 1];

		for (auto i = 0u; i < m_end; i++)
		{
			*(m_storage+i) = *(ilist.begin()+ i);
		}
	}

	template< typename T >
	vector< T >& vector< T >::operator=( const vector< T > & vector_ ){
		if( m_capacity < vector_.m_capacity )
		{
			this->reserve( vector_.m_capacity );
		}

		m_capacity = vector_.m_capacity;
		m_end = vector_.m_end;

		for( int i = 0; i < vector_.m_end; i++ ){
			*(m_storage+i) = *(vector_.m_storage+i);
		}
		
		return *this;
	}

/*-----------------------------[II] Iterators--------------------------------*/

	template< typename T >
	vector< T >::MyIterator::MyIterator( T* ptr)
	{ 
		current = ptr;
	}

	template< typename T >
	vector< T >::MyIterator::MyIterator( )
	{ 
		current = nullptr;
	}

	/// Default Destructor
	template < typename T >
	vector< T >::MyIterator::~MyIterator() = default;	

	/// Assign Operator
	template < typename T >
	typename vector< T >::MyIterator& vector< T >::MyIterator::operator=( const vector< T >::MyIterator& rhs ){
		
		this->current = rhs.current;
	}

	/// Copy Constructor
	template < typename T >
	vector< T >::MyIterator::MyIterator( const vector< T >::MyIterator& itr )
	{
		current = itr.current;
	}	

	/// Reference for MyIterator
	template < typename T >
	T & vector< T >::MyIterator::operator* ( void ) const{
		
		return *(this->current);
	}

	/// Operator++
	// ++it;
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator++( void ){
		
		return ++(this->current);
	}

	///Operator++
	// it++;
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator++( int ){
		
		MyIterator temp( *this );
		++(this->current);
		return temp;
	} 	

	///Operator--
	// --it;
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator--( void ){
		
		return --(this->current);
	}

	///Operator--
	// it--;
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator--( int ){
		
		MyIterator temp( *this );
		--(this->current);
		return temp;
	}

	///Bool for Operator==
	template < typename T >
	bool vector< T >::MyIterator::operator==( const vector< T >::MyIterator& rhs ) const{
		
		return this->current == rhs.current;
	}

	///Bool for Operator!=
	template < typename T >
	bool vector< T >::MyIterator::operator!=( const vector< T >::MyIterator& rhs ) const{
		
		return this->current != rhs.current;
	}

	/// Operator+=
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator+=( int x ){
		
		this->current = this->current + x;
		return this->current;
	}

	/// Operator+
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator+( int x ){
		
		return this->current + x;
	}

	/// Operator-
	// In case of a int
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator-( int x )
	{
		
		return this->current - x;
	}

	/// Operator-
	//In case of another iterator
	template < typename T >
	int vector< T >::MyIterator::operator-( const vector< T >::MyIterator& rhs )
	{
		
		return this->current - rhs.current;
	}

	/// Operator-=
	template < typename T >
	typename vector< T >::MyIterator vector< T >::MyIterator::operator-=( int x ){
		
		this->current = this->current - x;
		return this->current;
	}

/*---------------------------------------------------------------------------*/
	template < typename T >
	typename vector< T >::MyIterator vector< T >::begin( void ){
		
		return vector< T >::MyIterator(&m_storage[0]);
	}

	template < typename T >
	typename vector< T >::MyIterator vector< T >::end( void ){
		
		return vector< T >::MyIterator(&m_storage[m_capacity]);
	}

	template < typename T >
	typename vector< T >::MyIterator vector< T >::cbegin( void ) const{
		
		return vector< T >::MyIterator(&m_storage[0]);
	}

	template < typename T >
	typename vector< T >::MyIterator vector< T >::cend( void ) const{
		
		return vector< T >::MyIterator(&m_storage[m_capacity]);
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
		std::cout << m_end << "\n";
		return m_end == 0;
	}

	template< typename T > // Tells if the vector is full (making it easier)
	bool vector< T >::full( ) const{

		return m_end == m_capacity;
	}

/*-----------------------------[IV] Modifiers--------------------------------*/
			
	template< typename T > 
	void vector< T >::clear( ){

		delete [] m_storage;
		m_end = 0;
		m_capacity = 0;
		m_storage = new T[DEFAULT_SIZE + 1];
	}

	template< typename T > 
	void vector< T >::push_front( const T & value ){
		
		if( full( ) ){
			reserve( 1 + m_capacity  ); // The capacity will be increased
		}

		for (auto i(m_end); i > 0; i--){
			m_storage[i] = m_storage[i-1]; 
		}

		m_storage[0] = value;
		m_end++;
	}

	template< typename T > 
	void vector< T >::push_back( const T & value ){
		
		if( full( ) ){
			reserve( 1 + m_capacity ); // The capacity will be increased
		}

		m_storage[m_end] = value;
		m_end++;
	}

	template< typename T > 
	void vector< T >::pop_back( ){ // Removing element from the back part
		
		if( empty(  ) == true ){
			throw std::out_of_range("[pop_back()]: Impossible to access an empty vector!");
		}

		m_end--;
		m_capacity--;
	}

	template< typename T > 
	void vector< T >::pop_front( ){ // Removing element from the front part

		if( empty(   ) == true  ){
			throw std::out_of_range("[pop_front()]: Impossible to access an empty vector!");
		}

		for( auto i = 0; i < m_end-1; i++ ){
			*(m_storage+i) = *(m_storage+i+1);
		}

		m_end--;
		m_capacity--;
	}

	template < typename T >
	typename vector< T >::MyIterator vector< T >::insert( MyIterator itr, const T& value)
	{

		if( full() ) {
			reserve(1 + m_capacity); //Increases capacity
		}

		m_end++;

		// Iterator to the last element with atributed value in vector
		auto it_temp(begin( ) + m_end-1);

		for(auto i(it_temp); i != itr; i--)
		{
			*i = *(i-1);
		}

		*itr = value;
		return itr;
	}

	template< typename T >
	typename vector< T >::MyIterator vector< T >::insert( MyIterator itr, MyIterator first, MyIterator last )
	{
		int distance = last-first;

		if(m_end-1 + distance >= m_capacity)
		{
			reserve(m_end + distance);
		}


		// Iterator to the last element with atributed value in vector
		auto it_temp(begin( ) + m_end-1);

		for(auto i(it_temp); i != (itr-1); i--)
		{
			*(i+distance) = *i;
		}

		for(auto j(first); j != last && j != end(); j++)
		{
			*itr = *j;
			itr++;
		}
		
		m_end += distance;
		return itr;
	}

	template <typename T>
	typename vector<T>::MyIterator vector<T>::insert( MyIterator itr, std::initializer_list< T > ilist )
	{

		int indcInsert = itr - &m_storage[0];
		if(m_end-1 + ilist.size() >= m_capacity){
			reserve(m_end + ilist.size());
		}


		// Iterator to the last element with atributed value in vector
		auto it_temp(begin( ) + m_end-1);
		for(auto i(it_temp); i != (itr-1); i--)
		{
			*(i + ilist.size()) = *i;
		}

		std::copy(ilist.begin(), ilist.end(), m_storage+indcInsert);

		m_end += ilist.size();
		return m_storage + indcInsert; 
	}

	template< typename T >
	void vector< T >::reserve( size_t new_capacity ){

		if( new_capacity <= m_capacity ) return; // Nothing to do 

		m_capacity = new_capacity;
		T * tmp = new T[new_capacity];
		std::copy(m_storage, m_storage + m_end, tmp);

		delete [] m_storage;

		m_storage = new T[m_capacity];
		for( auto i(0); i < m_end; i++ ){
			*(m_storage+i) = *(tmp+i);
		}

		delete [] tmp;
	}

	template< typename T >
	void vector< T >::shrink_to_fit( ){ /* As it says, reduzes the vector capacity to fit */
		
		m_capacity = m_end; // -> what will make the 'fit' stuff

		T *tmp = new T[m_capacity];
		std::copy(m_storage, m_storage + m_end, tmp);
		delete [] m_storage;

		m_storage = new T[m_capacity];
		for( auto i = 0; i < m_end; i++ ){
			*(m_storage+i) = *(tmp+i);
		}

		delete [] tmp;
	}	
	
	template< typename T >
	void vector< T >::assign( const T & value ){ /* Replaces the vector with copies */
		for( auto i(0u); i < m_end; i++ ){
			*(m_storage+i) = value;
		}
	}
	
	template <typename T>
	void vector<T>::assign( MyIterator first, MyIterator last ){

		m_capacity = 0;
		int distance = last-first;
		reserve(distance);

		int j = 0;
		for (auto i(first);  i != last; i++, j++ ) {
			*(m_storage+j) = *i;	
		}
		m_end = distance;
	}

	template < typename T >
	void vector< T >::assign( std::initializer_list< T > ilist ){
		if(m_capacity < ilist.size()){
			reserve(ilist.size());
		}

		m_capacity = ilist.size();
		m_end = ilist.size();
		std::copy(ilist.begin(), ilist.end(), m_storage);
	}

	template< typename T >
	typename vector< T >::MyIterator vector< T >::erase( MyIterator pos ){
		
		for(auto i(pos+1); i != end(); i++){
			if( i == begin() ){
				continue;
			}
			*(i - 1) = *i;
		}
		m_end--;

		return pos;
	} 

	template < typename T >
	typename vector< T >::MyIterator vector< T >::erase( MyIterator first, MyIterator last ){
		
		MyIterator j(first);

		for(auto i(last); i != end(); i++){
			*(j++) = *i;
		}
		int diff = last - first;
		//int diff = last - first; to see if operator '-' works.

		m_end = m_end - diff;

		return first;
	} 

/*---------------------------[V] Element access------------------------------*/

	template< typename T >
	const T & vector< T >::back( ) const{ // Access the back element

		if( empty(  ) == true ){
			throw std::out_of_range( "[back()]: Impossible to access an empty vector!");
		}

		return m_storage[m_end-1];
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

		if( pos < 0 or pos >= m_end ){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}
		
		return m_storage[pos];
	}

	template< typename T >
	const T & vector< T >::operator[]( size_t pos ) const{

		if( pos < 0 or pos >= m_end ){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}
		return m_storage[pos];
	}

	template< typename T >
	const T & vector< T >::at( size_t pos ) const{

		if( pos < 0 or pos >= m_end ){
			throw std::out_of_range("[at()]: Position required is out of range!");
		}

		return m_storage[pos];
	}

	template< typename T >
	T & vector< T >::at( size_t pos ){
		
		if( pos < 0  or pos >= m_end ){
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
		std::cout<< "], number of elements: " << m_end << ", capacity: " << m_capacity << ".\n";
	}
	
/*-----------------------------[VI] Operators--------------------------------*/

	template< typename T >
	bool vector< T >::operator==( const vector< T > & vec ) const{

		/* If the size is different of couse they are different */
		if( (m_end != vec.m_end) ) 
			return false;
		
		for( auto i(0u); i < m_end; i++ ){ // compare each pos on the vector
			if( m_storage[i] != vec.m_storage[i] ) 
				return false;
		}

		return true;
	}

	template< typename T >
	bool vector< T >::operator!=( const vector< T > & vec ) const{

		return not operator==( vec );
	}

/*--------------------------[VII] Friend functions---------------------------*/
/*
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


	std::ostream& operator<<( std::ostream os_, const vector< T >& v_ )
	{
		os_ << "[ ";
		for( auto i(0u); i < v_.m_end; i++)
		{
			os << *(v_.m_storage+i) << " ";
		}
		os_ << "]";
		return os_;
	}
*/