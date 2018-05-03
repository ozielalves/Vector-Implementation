/**
 * @file tests.cpp
 * @version 1.0
 * @date May, 01.
 * @author Daniel Guerra and Oziel Alves
 * @title Vector tests
 * @brief Tests of the TAD-Vector.
 */

#include "vector.hpp"

int main(  ){

/*----------------------------- Test vectors --------------------------------*/
	
	sc::vector< std::string > V1;
	sc::vector< int > V2( 10 );

/*------------------- Testing push_front and push_back ----------------------*/
	
	std::cout << "Testing push()\n\n";

	sc::vector< int > V3;
	V3.push_front(3);
	V3.push_front(2);
	V3.push_front(1);
	
	V3.push_back(4);
	V3.push_back(5);
	V3.push_back(6);
	
	std::cout << "Expected: [ 1 2 3 4 5 6 ]\n";
	V3.print(); // Out: [ 1 2 3 4 5 6 ]

/*--------------------- Testing pop_front and pop_back ----------------------*/
	
	std::cout << "\nTesting pop()\n\n";
	V3.pop_front();
	V3.pop_front();
	V3.pop_back();

	std::cout << "\nExpected: [ 3 4 5 ]\n";
	V3.print(); // Out: [ 3 4 5 ]

/*------- Testing at(), operator [](), operator ==(), operator =!() ---------*/
	
	sc::vector< int > V4;

	V4.push_back(9);
	V4.push_back(8);
	V4.push_back(7);
	V4.push_back(6);
	V4.push_back(5);
	
	std::cout << "\nTesting Operator '[]'\n\n"; 
	std::cout << "Pos = 0, Element expected: 9 <<<<"<< V4[0] << "\n";
	std::cout << "Pos = 4, Element expected: 5 <<<<"<< V4[4] << "\n";

	sc::vector< int > V5(V4);

	std::cout << "\nTesting at()\n\n"; 
	std::cout << "Pos = 1, Element expected: 8 <<<<"<< V4.at(1) << "\n";

	/*V4.at(2) = 0;
	V4.at(0) = 0;
	V4.at(4) = 0;

	std::cout << "Expected: [ 0 8 0 6 0 ]\n";
	V4.print(); // Out [ 0 8 0 6 0 ]*/

	std::cout << "\nTesting Operator == and =!\n\n";

	std::cout << "Vector one:\n";
	V4.print();
	std::cout << "Vector two:\n";
	V5.print();
	
	assert( V4 != V5 ); // Execution continues if works
	if( V4 == V5 ) 
		std::cout << "The vectors are iqual\n\n";
	else 
		std::cout << "The vectos are different\n\n";
	
/*------------------ Testing Assign(), clear() and empty() ------------------*/

	std::cout << "\nTesting Assign ( T )\n\n";

	std::cout << "\nSample Vector:\n";
	V5.print();

	V5.assign(1);
	std::cout << "\nAssigned Vector:\n";
	V5.print();

	std::cout << "\nLets now clear the whole Vector\n";
	V5.clear();
	
	std::cout << "\nClean Vector:\n";
	V5.print();

	if( V5.empty() == true )
		std::cout << "The vector is empty!\n";

/*------------------------- Testing constructors ----------------------------*/

	/* String Vector */

	/*sc::vector< std::string > hi = {'how', 'is', 'it', 'going'};
	sc::vector< std::string > hello(hi);
	sc::vector< std::string > hey = hi;

	assert( hi == hey );
	assert( hey == hello );
	std::cout << "\nConstructors are working!\n";

	hi.print();
	hello.print();
	hey.print();*/

	
}
