#include <memory>
#include "firma.hpp"

class game
{
public:
	game() : Firma{new firma()}, stan{ true } {};
	~game() { delete Firma; };
	bool getStan()
  {
	return stan;
  };
	void setStan(bool a)
  {
	stan = a;
  };
	void tick()
  {
  Firma->obliczPrzychod();
	Firma->otrzymajPrzychod();
	Firma->splacRaty();
	Firma->zaplacWynagrodzenie();
	std::cout << "Aktualny stan konta: " << Firma->getStanKonta() << "\n";
  Firma->setWartoscFirmy(Firma->ustalWartoscFirmy());
  std::cout << "Wartosc Firmy wynosi " << Firma->getWartoscFirmy() << "\n";
  if(Firma->getWartoscFirmy() - Firma->getZadluzenie() >= 10)
    {
      std::cout << "Gratulacje! Wygrales!\n";
      stan = false;
    }
    else if (Firma->getStanKonta() < 0)
    {
      std::cout << "Koniec gry. Przegrales.\n";
      stan = false;
    }
  };
	void akcja()
  {
    std::string action;
    std::cin >> action;
    if(action == "lp")
      for (auto a : Firma->get_prac())
      {
        a->print();
      }
      else if(action == "zinz")
        Firma->hireEng();
      else if(action == "zmag")
        Firma->hireMag();
      else if(action == "zmkt")
        Firma->hireMrk();
      else if(action == "zrob")
        Firma->hireRbt();
      else if(action == "kt")
        {
          tick();
        }
      else if(action == "kred")
      {
      double kwota = 0;
      int czas = 0;
        std::cin >> kwota >> czas;
        Firma->wez_kredyt(kwota, czas);
      }

  };
	
private:
	bool stan = 1;
	firma *Firma;

};