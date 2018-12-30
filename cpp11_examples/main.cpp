#include <initializer_list>
#include <vector>
#include <functional>
#include <iostream>
#include <random>


#include "type_interface.hpp"
#include "main.h"
using namespace std;

struct Object
{
	float first;
	int second;
};


struct BasicStruct {
	int x;
	double y;
};

struct AltStruct {
	AltStruct(int x, double y) : x_(x), y_(y) {}

private:
	int x_;
	double y_;
};

struct IdString
{
	std::string name;
	int identifier;
};

IdString GetString()
{
	return { "SomeName", 4 }; // Обратите внимание на отсутствие явного указания типов
}



int main()
{
	//===================  INITIALIZATION LISTS ===================================
	//simple init
	Object scalar = { 0.43f, 1 };
	Object anArray[] = { {13.4f, 3}, {43.28f, 29}, {5.934f, 17} };

	//containers init
	std::vector<std::string> vect_int = { "123","456" };
	vect_int.push_back("1");
	



	BasicStruct var1{ 5, 3.2 };
	AltStruct var2{ 2, 4.3 };


	IdString st = GetString();
	//============END  INITIALIZATION LISTS ===================================


	//=================== TYPE EINTERFACE ===================================
	//auto someStrangeCallableType = std::bind(&SomeFunction, _2, _1, someObject);

	//----
	int n = 7;
	using namespace std::placeholders;

	//cref is "constant " used for putting refference to n,
	//auto is a varriable type
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	auto res  = f1(1, 2, 1001);// 1 is bound by _1, 2 is bound by _2, 1001 is unused

	//-----
	auto otherVariable = "1";
	otherVariable = "2123";

	//--
	int MyCustomIntegerType;
	decltype(MyCustomIntegerType) otherIntegerVariable = 5;
	
	vector<int> myvec = {1,2,3};

	//old style
	for (vector<int>::const_iterator itr = myvec.cbegin(); itr != myvec.cend(); ++itr)
		cout << *itr << endl;

	//new style
	for (auto itr = myvec.cbegin(); itr != myvec.cend(); ++itr)
		cout << *itr << endl;

	//---
	const std::vector<int> v(1);
	auto a = v[0];        // a has type int
	decltype(v[0]) b = 1; // b has type const int&, the return type of
						  //   std::vector<int>::operator[](size_type) const
	auto c = 0;           // c has type int
	auto d = c;           // d has type int
	decltype(c) e;        // e has type int, the type of the entity named by c
	decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
	decltype(0) g;        // g has type int, because 0 is an rvalue
	

	//=================== END TYPE EINTERFACE ===================================


	//================== RANGE-BASED FOR LOOP ======================================



	//================== END RANGE-BASED FOR LOOP ======================================

	return 0;
}