#include <algorithm>

class kredyt
{
public:
	kredyt(double kwota, int czas)
  {
    //dlug = kwota;
    pozostale_raty = czas;
    rata = kwota/(double)czas * (1. + (double)czas / 100.);
  };
	double splac_rate()
  {   //double pozostalo = dlug;
      //dlug = std::max(0, dlug - rata);
      if(pozostale_raty > 0)
      {
      pozostale_raty = pozostale_raty - 1;
      return rata;
      }
      else
      return 0.;
  };
  bool czy_splacony()
  {
    if(pozostale_raty == 0)
      return true;
      else
      return false;
  };
private:
	//double dlug;
  double rata;
	int pozostale_raty;
};
