
#include <cstdlib>
#include <ctime>
#include <iostream>
class mrkt :
	public pracownik
{
public:
	mrkt(){
	srand((unsigned int)time(0));
	followers = rand();
};

	virtual void print(){
	std::cout << imie << ", followersow: " << followers << ", wynagrodzenie:" << pMrk << "\n" ;
};
double pMrk = 1.;

private:	
	
	int followers = 0;
};