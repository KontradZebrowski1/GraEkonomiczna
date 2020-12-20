#include "pracownik.hpp"
#include <iostream>
#include "RandomNameGenerator.hpp"


#include "inzynier.hpp"
#include "magasiner.hpp"
#include "mrkt.hpp"
#include "robt.hpp"

#include <vector>
#include "game.hpp"

int main()
{
game Gra;
while(Gra.getStan())
  Gra.akcja();
}