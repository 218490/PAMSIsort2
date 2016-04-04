#ifndef QSORT_HH
#define QSORT_HH

#include <iostream>
#include "IList.hh"
#include "SNode.hh"
#include "Tab.hh"
using namespace std;

/*!
 * \file
 *
 *  Plik zawiera definicję klasy implementującej algorytm szybkiego sortowania
 */

/*!
 * \brief QuickSort
 */
class QSort{
private:

public:
  void Quicksort(Tab &tablica,int lewy,int prawy);
};

#endif
