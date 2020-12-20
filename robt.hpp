#include <iostream>
class robt : public pracownik
{
public:
	robt()
  {
	std::uniform_real_distribution<double> unif(35., 45.);
	std::default_random_engine re;
	nmrButa = unif(re);
  };

	virtual void print(){
	std::cout << imie << ", o numerze buta " << nmrButa  << ", wynagrodzenie:" << pRob << "\n";
};
double pRob = 1.;

private:
	double nmrButa = 40;
};