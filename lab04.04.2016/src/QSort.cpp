#include "QSort.hh"

/*!
 *\brief QuickSort na tablicy
 *
 *\param[in] tablica-struktura przechowujaca tablice dynamiczna
 *\param[in] lewy- lewa granica sortowania (numer indeksu)
 *\param[in] prawy- prawa granica sortowania (numer indeksu)
 */
void QSort::Quicksort(Tab &tablica,int lewy,int prawy){
  int pivot=tablica.tab[(lewy+prawy)/2];
  int i,j,x;
  i=lewy;
  j=prawy;
  do{
    while(tablica.tab[i]<pivot) i++;
    while(tablica.tab[j]>pivot) j--;
    if(i<=j){
      x=tablica.tab[i];
      tablica.tab[i]=tablica.tab[j];
      tablica.tab[j]=x;
      i++; j--;
    }
  }while(i<=j);

  if(j>lewy) Quicksort(tablica,lewy,j);
  if(i<prawy) Quicksort(tablica,i,prawy);

}
