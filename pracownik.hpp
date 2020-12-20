#include "RandomNameGenerator.hpp"
#include <string>

class pracownik
{
public:
	pracownik() {imie = get_random_name();};
	//~pracownik();
	std::string imie;
  virtual void print() = 0;
};
