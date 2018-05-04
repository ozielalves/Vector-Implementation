/**
 * @file tests.cpp
 * @version 1.0
 * @date May, 01.
 * @author Daniel Guerra and Oziel Alves
 * @title Vector tests
 * @brief Tests of the TAD-Vector.
 */

#include "vector.hpp"

int main( ){

/*----------------------------- Test vectors --------------------------------*/
	
	sc::vector< std::string > v1;
	sc::vector< int > v2( 10 );

/*---------------------------- Testing emtpy() ------------------------------*/
	{
		assert( v1.empty() == true );
	    assert( v2.empty() == true );
	}

/*-------------------- Testing push_back and pop_back -----------------------*/
	{
	  	std::cout << "\n\t>>> Testing push_back & pop_back (Capacity defined)\n";
	    for( auto i(0) ; i < 10 ; ++i )
	    v1.push_back( i+1 );
	
		std::cout << "V1 Before pop_back: \n";
	    v1.print();

	    std::cout << "poping back V1... ";
	    while( not v1.empty() )
	    v1.pop_back();
	    std::cout << std::endl;

		std::cout << "V1 after pop_back: \n";
	    v1.print();
	    }

/*---------------------- Testing vector with string -------------------------*/
	{
	    std::cout << "\n\t>>> Testing string vector (Capacity not defined)\n";
	    sc::vector< std::string > ss;

		ss.print();
	    ss.push_back( "one" );
	    ss.print();
	    ss.push_back( "two" );
	    ss.print();
	    ss.push_back( "three" );
	    ss.print();
	    ss.push_back( "four" );
	    ss.print();
	    ss.push_back( "five" );
	    ss.print();
	 }

/*------------------- Testing push_front and pop_front ----------------------*/
	{
	    std::cout << "\n\t>>> Testing push_front & pop_front (Capacity not defined)\n";

	    sc::vector<int> v3;
	    v3.push_front(8);
	    v3.push_front(9);
	    v3.push_front(0);
	    v3.push_back(1);
	    v3.push_front(5);

		v3.print(); // Expected: 5 0 9 8 1
	    v3.pop_front();
	    v3.pop_front();

		v3.print(); // Expected: 9 8 1

	}   

/*-------------------- Testing assign(T) and clear() ------------------------*/
	{
	    std::cout << "\n\t>>> Testing assign(T) and clear()\n";

	    sc::vector<int> v;
	    v.push_front(8);
	    v.push_front(9);
	    v.push_front(0);
	    v.push_back(1);
	    v.push_front(5);

		v.print(); // Expected: 5 0 9 8 1

	    v.assign(4);

	    v.print(); // Expected: 4 4 4 4 4
	     
	    v.clear();

	    v.print(); // Expected: []

	 }

/*------------- Testing at(), operator[]() and shrink_to_fit() --------------*/
	 {
	    std::cout << "\n\t>>> Testing at() and operator[]()\n";

	    sc::vector<std::string> v;
	    v.push_back("me");
	    v.push_back("you");
	    v.push_back("he");
	    v.push_back("she");

	    v.print();
	    v[1] = "change1";
	    v.at(2) = "change2";
	    std::cout << "Element on index 0 = " << v[0] << std::endl; 
	    std::cout << "Element on index 1 = " << v.at(1) << std::endl; 
	    std::cout << "Element on index 2 = " << v[2] << std::endl; 
	    std::cout << "Element on index 3 = " << v.at(3) << std::endl; 
	    

	    std::cout << "\n\t>>> Testing shrink_to_fit()\n";
	    v.shrink_to_fit();
	    std::cout << "The unused space was removed, now capacity = len\n";
	    v.print();
	  }

/*------------------ Testing operator== and operator[] ----------------------*/
	  {
	    std::cout << "\n\t>>> Testing operator== and operator[]()\n";
	    std::cout << "\n\t>>> Initializing v2 with initializer_list\n";

	    sc::vector<float> v1;
	    sc::vector<float> v2 = { 0.1, 2.3, 0.8 };

		v1.push_back(0.1);
	    v1.push_back(2.3);
	    v1.push_back(0.8);

	    std::cout << "Vector 1: ";
	    v1.print();
	    std::cout << "Vector 2: ";
	    v2.print();

	    assert( v1 == v2 );
	    if( v1 == v2 )
	    std::cout << "Vector 1 and 2 are iqual.\n\n";
	    else
	    std::cout << "Vector 1 and 2 are different.\n\n";

	    v2[1] = 4.1;
	   	std::cout << "Vector 1: ";
	    v1.print();
	    std::cout << "Vector 2: ";
	    v2.print();

	    assert( v1 != v2 );
	    if( v1 == v2 )
	    std::cout << "Vector 1 and 2 are iqual.\n\n";
	    else
	    std::cout << "Vector 1 and 2 are different.\n\n";

		v1[1] = 4.1;
	    v1.push_back(2.0);

	    std::cout << "Vector 1: ";
	    v1.print();
	    std::cout << "Vector 2: ";
	    v2.print();

		assert( v1 != v2 );
	    if( v1 == v2 )
	    std::cout << "Vector 1 and 2 are iqual.\n\n";
	    else
	    std::cout << "Vector 1 and 2 são different.\n\n";
	}

/*------------------------- Testing constructors ----------------------------*/
	{
	    sc::vector<char> A = { 'a', 'b', 'c' };
	    sc::vector<char> B(A);
	    sc::vector<char> C = A;

		assert( A == B );
	    assert( A == C );

	    A.print();
	    B.print();
	    C.print();
	}
}