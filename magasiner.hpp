//#include "pracownik.hpp"
#include <iostream>
class magasiner :
	public pracownik
{
public:
	magasiner()
{
	srand((unsigned int)time(0)); wozek = rand()%2;
}
  virtual 	void print(){
	if (wozek == 1)
	{
		std::cout << imie << ", umie w wozek, pensja:" << pMag << "\n";
	}
	else
	{
		std::cout << imie << ", nie umie w wozek, pensja:" << pMag << "\n";
	}
};
double pMag = 1;
private:
	bool wozek = 0;
};