#include <initializer_list>
#include <vector>

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
	Object scalar = { 0.43f,0.1 };
	Object anArray[] = { {13.4f, 3}, {43.28f, 29}, {5.934f, 17} };

	//containers init
	std::vector<std::string> v = { "123","456" };
	v.push_back("1");
	



	BasicStruct var1{ 5, 3.2 };
	AltStruct var2{ 2, 4.3 };


	IdString st = GetString();
	//============END  INITIALIZATION LISTS ===================================
	return 0;
}