#include "kredyt.hpp"
#include <memory>
#include <variant>
#include <vector>
#include <algorithm>
#include <list>

using pracownik_t = std::variant<mrkt, inzynier, robt, magasiner>;

class firma
{
public:
	firma()
  {
    hireEng();
    hireMag();
    hireMrk();
    hireRbt();
    stanKonta = 10;
    std::cout << "Aktualny stan konta: " << getStanKonta() << "\n";
  };
	
	const void drukujPracownikow()
  {
    for(auto a : prac)
      {
      a->print();
      }
  };
	double getStanKonta()
  {
    return stanKonta;
  };
	const double obliczPrzychod()
  {
    double prod = cRob * (double)nRob;
    double magazyn = cMag * (double)nMag;
    double popyt = cMrk * (double)nMrk;
    double cena = cInz * (double)nInz;
    prod = std::min(prod,magazyn);
    prod = std::min(prod,popyt);
    double przychod = cena * prod;
    historiaPrzychodow.emplace_back(przychod);
    if (historiaPrzychodow.size() > 5)
    historiaPrzychodow.pop_front();
    return przychod;
  };
	void splacRaty()
  {
    for(auto a : kredyty)
    {
      stanKonta = stanKonta - a->splac_rate();
      zadluzenie = zadluzenie - a->splac_rate();
      if (a->czy_splacony() == 1)
      kredyty.remove(a);
    }
  };
	void otrzymajPrzychod()
  {
    stanKonta = stanKonta + historiaPrzychodow.back();
  };
	void zaplacWynagrodzenie()
  {
    double wynagrodzenie = pensja_inz*nInz+pensja_mag*nMag+pensja_mrk*nMrk+pensja_rob*nRob;
    stanKonta = stanKonta - wynagrodzenie;
  };
 	void hireEng()
  {
    inzynier *inz = new inzynier();
    prac.emplace_back(inz);
    prac.back()->print();
    nInz += 1;
  };
  void hireMrk()
  {
    mrkt *pr = new mrkt();
    prac.emplace_back(pr);
    prac.back()->print();
    nMrk +=1;
  };
  void hireMag()
  {
    magasiner *pr = new magasiner();
    prac.emplace_back(pr);
    prac.back()->print();
    nMag += 1;
  };
  void hireRbt()
  {
    robt *pr = new robt();
    prac.emplace_back(pr);
    prac.back()->print();
    nRob += 1;
  };
  std::vector<pracownik*> get_prac()
  {
    return prac;
  };
	void wez_kredyt(double kwota, int czasSplaty)
  {
    kredyty.emplace_back(new kredyt(kwota,czasSplaty));
    zadluzenie = zadluzenie + kwota;
  };
	double ustalWartoscFirmy()
  {
    double wartosc = 0;
    for (auto a : historiaPrzychodow)
    {
      wartosc += a;
    }
    double wartoscSpolki = wartosc / historiaPrzychodow.size();
    return wartoscSpolki;
  };
  double getWartoscFirmy()
  {
    return wartoscFirmy;
  };
  void setWartoscFirmy(double a)
  {
    wartoscFirmy = a;
  };
  double getZadluzenie()
  {
    return zadluzenie;
  };

private:
	double stanKonta = 0;
	int liczbaKredytow = 0;
	std::list<kredyt*> kredyty;
  double zadluzenie = 0;
	int liczbaPracownikow = 0;
	std::vector<pracownik*> prac ;
	std::list<double> historiaPrzychodow;
	double wartoscFirmy = 0;

	const double pensja_inz = 1.;
	const double pensja_mrk = 1.;
	const double pensja_mag = 1.;
	const double pensja_rob = 1.;

	const double cInz = 1.;
	const double cMrk = 1.;
	const double cMag = 1.;
	const double cRob = 1.;

  int nInz = 0;
  int nMrk = 0;
  int nMag = 0;
  int nRob = 0;
};

