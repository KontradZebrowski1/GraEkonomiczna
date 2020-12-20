
#include "WydzialGenerator.hpp"
#include <iostream>
#include <string>

class inzynier : public pracownik
{
public:
inzynier()
  {
  //wydzial = get_wydzial();
  srand((unsigned int)time(0));
  int nrWydzialu = rand()%4;
  switch(nrWydzialu)
  {
    case 0:
    wydzial = "MEiL";
    break;
    case 1:
    wydzial = "MiNI";
    break;
    case 2:
    wydzial = "EiTI";
    break;
    case 3:
    wydzial = "SiMR";
    break;
  }
  };
  double pInz = 1;
virtual void print()
    {
	  std::cout << imie << " z wydzialu " << wydzial << ", wynagrodzenie:" << pInz << "\n";
    };
private:
	std::string wydzial = "MEiL";
};