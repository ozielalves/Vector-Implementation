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

/*------------------------ Testing Special Members --------------------------*/
	{
		sc::vector< std::string > v1 = {"ola", "bom dia", "funcionou", "uhu"};
		sc::vector< int > v2( 10 );
		sc::vector< std::string > v3(v1);
		sc::vector<int> v4 = {1,2,3,8,9};

		std::cout << "\n\e[36;4m>>> Testing Special Members Functions.\e[0m\n\n";
		std::cout << ">>> Showing vectors.\n";
	    v1.print();
	    v2.print();
	    v3.print();
	    v4.print();

	    v2 = v4;
	  //  sc::vector< int > v5(v4.begin(), v4.end());

	    v2.print();
	  //  v5.print();
	}

/*------------------------ Testing Capacity Methods -------------------------*/
	{
		std::cout << "\n\e[36;4m>>> Testing constructors Initializations\e[0m\n";
		std::cout << "\e[36;4m>>> Testing insert functions\e[0m\n\n";

	    sc::vector< char > A;

	    A.print();

	    A.push_back('5');
	    A.push_back('v');
	    A.push_back('a');
	    A.push_back('b');

	    A.print();

	    sc::vector< char > C = A;

	    std::cout << A.size() << " = Size of A\n";
	    std::cout << C.capacity() << " = Capacity of C\n";

	    A.clear();
	    C.push_back('c');
	    A.push_back('5');
	    A.push_back('v');
	    A.push_back('a');
	    A.push_back('b');

	    A.print();
	    C.print();
	}

/*------------------------ Testing vector with string -----------------------*/

		std::cout << "\n\e[36;4m>>> Testing Modifiers Methods\e[0m\n";
	{
	    std::cout << "\e[36;4m>>> Testing string vector (Capacity not defined)\e[0m\n\n";
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
	    
	    std::cout << "\n\e[36;4m>>> Testing push_front & pop_front (Capacity not defined)\e[0m\n\n";

	    sc::vector< int > a3;
	    
	    a3.push_front(8);
	    a3.push_front(9);
	    a3.push_front(0);
	    a3.push_back(1);
	    a3.push_front(5);

		a3.print(); // Expected: 5 0 9 8 1
	    a3.pop_front();
	    a3.pop_front();

		a3.print(); // Expected: 9 8 1

	} 

/*--------------------- Testing assign() and clear() ------------------------*/
	
	{
	    std::cout << "\n\e[36;4m>>> Testing assign() and clear()\e[0m\n\n";

	    sc::vector< int > v;
	    sc::vector< int > vv = {10,9,8,7,6};
	    v.push_back(8);
	    v.push_back(9);
	    v.push_back(0);
	    v.push_back(1);
	    v.push_back(5);

		v.print(); // Expected: 5 0 9 8 1

	    v.assign(4);
	    std::cout << "\nVector Assigned by 4: \n";
	    v.print(); // Expected: 4 4 4 4 4

	    v.assign({2,5,8,10});
	    std::cout << "\nVector Assigned by list: \n";
	    v.print();
	     
	    v.assign(vv.begin()+1, vv.end()-1);
	    std::cout << "\nVector Assigned by Iterator range: \n";
	    v.print();

	    v.clear();

	    v.print();


	    std::cout << "\n>>> Testing ERASE: \n";
	    sc::vector < char > vev;
	    vev.push_front('a');
	    vev.push_front('b');
	    vev.push_front('c');
	    vev.push_front('d');
	    vev.push_back('e');

	    vev.print();
	    std::cout << "\n>>> Erasing position 2. Suposed to erase 'b'.\n";
	    vev.erase(vev.begin()+2);
	    vev.print();

	    vev.push_front('l');
	    vev.push_front('z');
	    vev.print();
	    std::cout << "\n>>> Erasing positions 0 to 3. Suposed to erase 'z' 'l' 'd'.\n";
	    vev.erase(vev.begin(), vev.begin()+3);
	    vev.print();

	 }

/*------------------------- Testing Acess Methods ---------------------------*/

	 {
	    std::cout << "\n\e[36;4m>>> Testing at() and operator[]()\e[0m\n";
	    std::cout << "\e[36;4m>>> Testing Acess Methods\e[0m\n\n";


	    sc::vector<std::string> v(10);
	    v.push_back("never");
	    v.push_back("gonna");
	    v.push_back("let");
	    v.push_back("you");
	    v.push_back("down");

	    v.print();
	    v[1] = "going to";
	    v.at(2) = "leave";
	    std::cout << "Element on index 0 = " << v[0] << std::endl; 
	    std::cout << "Element on index 1 = " << v.at(1) << std::endl; 
	    std::cout << "Element on index 2 = " << v[2] << std::endl; 
	    std::cout << "Element on index 3 = " << v.at(3) << std::endl; 
	    

	    std::cout << "\n\e[36;4m>>> Testing shrink_to_fit()\e[0m\n\n";
	    v.shrink_to_fit();
	    std::cout << "The unused space was removed, now capacity = len\n";
	    v.print();
	  }

/*------------------ Testing operator== and operator[] ----------------------*/

	  {
	    std::cout << "\n\e[36;4m>>> Testing operator== and operator[]()\e[0m\n\n";
	    
	    std::cout << "\n>>> Initializing v8 with initializer_list\n\n";

	    sc::vector< float > v7;
	    sc::vector< float > v8 = { 0.8, 2.3, 0.9, 6.81 }; // ilist

		v7.push_back(0.8);
	    v7.push_back(2.3);
	    v7.push_back(0.9);
	    v7.push_back(6.81);

	    std::cout << "Vector 7: ";
	    v7.print();
	    std::cout << "Vector 8: ";
	    v8.print();

	    std::cout << "Vector 7 front: " << v7.front() << "\n";
	    std::cout << "Vector 7 back: " << v7.back() << "\n";

	    std::cout << "Vector 8 front: " << v8.front() << "\n";
	    std::cout << "Vector 8 back: " << v8.back() << "\n";


	    assert( v7 == v8 );
	    if( v7 == v8 )
	    {
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
	}

/*------------------------- Testing constructors ----------------------------*/
	{
		std::cout << "\n\e[36;4m>>> Testing Constructors initialization\e[0m\n";
		std::cout << "\e[36;4m>>> Testing Insert functions\e[0m\n\n";

		sc::vector< char > A = { 'a', 'b', 'c', 'f', 'd', 'e', 'g' }; 
	    sc::vector< char > B(A);
	    sc::vector< char > C = A;

		assert( A == B );
	    assert( A == C );

	    A.print();
		B.print();
	    C.print();

	    A.insert(A.begin()+1, 'z');
	    B.insert(B.begin()+2, {'x', 'y', 'w'});
	    C.insert(C.begin(), A.begin(), A.end());
	    printf("\n");

	    A.print();
		B.print();
	    C.print();

	}
/*--------------------------- Testing Iterators -----------------------------*/
	{
		std::cout << "\n\e[36;4m>>> Operations with Iterators\e[0m\n\n";

		sc::vector< int > D = {1,2,3,4,5,6,7,8,9,10,11,12};
		sc::vector< int >::MyIterator iterator;
		sc::vector< int >::MyIterator it(D.cbegin()+5);
		sc::vector< int >::MyIterator ptr(it);


		iterator = D.begin();
		assert( ptr == it);
		assert( (iterator + 4) != it);

		std::cout << ">>> Elements between it and end of vector D.\n[ ";
		for(auto i(it); i != D.end(); i++){
			std::cout << *i << " ";
		}
		std::cout << "]\n";

		std::cout << ">>> it - iterator -> " << it - iterator << "\n";
		std::cout << ">>> it - ptr -> " << it - ptr << "\n";

		it -= 5;
		std::cout << ">>> Operator-=: it -= 5 executed.\n";

		assert(it == iterator);
		std::cout << ">>> Now iterator is ++ptr.\n";
		iterator = ++ptr;

		std::cout << ">>> Elements between it and iterator.\n[ ";
		for(auto i(it); i != iterator; i++ ){
			std::cout << *i << " ";
		}
		std::cout << "]\n";		

	}
/*------------------------ Testing Friend Functions -------------------------*/
/*	
	{
		sc::vector< double > f1 = {1.5, 2.5, 5.3, 6.7, 8.0, 9.5, 12.32};
		sc::vector< double > f2(f1);
		f2.pop_back();
		f2.pop_front();
		f2.push_back(11.22);

		f1.print();
		f2.print();

		swap(f1, f2);
	}
*/	
	std::cout << "\nFinished testing vector functions\n";
	std::cout << "\e[32;1mAuthors: Daniel Guerra and Oziel Alves\e[0m\n";
	return 1;
}
