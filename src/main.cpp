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
	std::cout << "\n\t>>> Initializing some vectors for the tests\n";
	sc::vector< std::string > v1;
	sc::vector< int > v2( 10 );

/*---------------------------- Testing emtpy() ------------------------------*/
	{
		assert( v1.empty() );
			std::cout << "The Vetor 01 is empty\n";
		assert( v2.empty() );
			std::cout << "The Vetor 02 is empty\n";
	}

	std::cout << v1.empty() << "\n";

/*-------------------- Testing push_back and pop_back -----------------------*/
	{
	  	std::cout << "\n\t>>> Testing push_back & pop_back (Capacity defined)\n";
	    for( auto i(1) ; i < 10 ; ++i )
	    {
	    	v2.push_back( i );
		}
		std::cout << "V2 Before pop_back: \n";
	    v2.print();

	    std::cout << "poping back V2... ";
	    
	    v2.pop_back();
	    v2.pop_back();
	    v2.pop_back();
	    v2.pop_back();
	    v2.pop_back();
	    
		std::cout << "\nV2 after pop_back: \n";
	    v2.print();
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

	    sc::vector< int > v3;
	    
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

	    sc::vector< int > v;
	    v.push_back(8);
	    v.push_back(9);
	    v.push_back(0);
	    v.push_back(1);
	    v.push_back(5);

		v.print(); // Expected: 5 0 9 8 1

	    v.assign(4);
	    std::cout << "\nVector Assigned by 4: \n";
	    v.print(); // Expected: 4 4 4 4 4
	     
	    v.clear();

	    v.print(); // Expected: []

	 }

/*------------- Testing at(), operator[]() and shrink_to_fit() --------------*/
	 {
	    std::cout << "\n\t>>> Testing at() and operator[]()\n";

	    sc::vector<std::string> v(10);
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
	    
	    std::cout << "\n\t>>> Initializing v8 with initializer_list\n";

	    sc::vector< float > v7;
	    sc::vector< float > v8 = { 0.8, 2.3, 0.9 }; // ilist

		v7.push_back(0.8);
	    v7.push_back(2.3);
	    v7.push_back(0.9);

	    std::cout << "Vector 7: ";
	    v7.print();
	    std::cout << "Vector 8: ";
	    v8.print();

	    assert( v7 == v8 ); // ASSERT É UMA AFIRMAÇÃO SE NÃO FOR VDD ELE DA UM ERRO
	    if( v7 == v8 )	// EU TROQUEI A CONDIÇÃO PRA VOCE VER O ERRO NO INITIALIZER
	    {
	    	// A MINHA FUNC TA COMETADA ABAIXO DA SUA, OBSERVE!
	    	std::cout << "Vector 7 and 8 are iqual.\n\n";
	    }
	    else
	    {
	    	std::cout << "Vector 7 and 8 are different.\n\n";
	    }

	    v8[1] = 4.1;
	   	std::cout << "Vector 7: ";
	    v7.print();
	    std::cout << "Vector 8: ";
	    v8.print();
	    assert( v7 != v8 );
	    if( v7 == v8 )
	    {
	    	std::cout << "Vector 7 and 8 are iqual.\n\n";
	    }
	    else
	    {
	    	std::cout << "Vector 7 and 8 are different.\n\n";
	    }

		v7[1] = 4.1;
	    v7.push_back(3.1);

	    std::cout << "Vector 7: ";
	    v7.print();
	    std::cout << "Vector 8: ";
	    v8.print();

		assert( v7 != v8 );
	    if( v7 == v8 ){
	    	std::cout << "Vector 7 and 8 are iqual.\n\n";
	    }
	    else{
	    	std::cout << "Vector 7 and 8 are different.\n\n";
	    }
	    std::cout << "MEUCU\n";
	}

/*------------------------- Testing constructors ----------------------------*/
	{
		std::cout << "oi pomba\n";
		sc::vector< char > A = { 'a', 'b', 'c' }; //SERÁ PRECISO ENTÃO MUDAR ESTA INICIALIZAÇÃO?
		std::cout << "oi pomba 2\n";
	    sc::vector< char > B(A);
	    std::cout << "oi pomba 3\n";
	    sc::vector< char > C = A;

	    std::cout << "oi pomba 4\n";
		assert( A == B );
	    assert( A == C );

	    A.print();
		B.print();
	    C.print();
	}
}
