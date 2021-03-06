#include "QSortTest.hh"

/*!
 *Uzupelnia liste liczbami oznaczajacymi ile elementow ma byc zapisane do
 *tablicy w procesie testowania
 */
void QSortTest::Przygotuj(){
  lista.AddFront(1000000000);
  lista.AddFront(1000000);
  lista.AddFront(10000);
  lista.AddFront(1000);
  lista.AddFront(10); 
}

/*!
 *Wypelnia tablice i sortuje jej elementy
 */
void QSortTest::Testuj(){
  StoperZZapisem stoper;
  srand(time(NULL));

  while(!lista.IsEmpty()){ 
    Tab tablica;
    for(int i=0;i<lista.Front();i++){  
      tablica.ZapiszNowy(rand()%1000+1);
    }
    lista.RemoveFront();

    stoper.Start();
    Quicksort(tablica,0,tablica.Rozmiar()-1);  //SORTOWANIE
    stoper.Stop();

    stoper.SaveAverageTimeToBuffer(stoper.GetElapsedTime()); 

    ofstream StrmPlikowy;
    const char* nazwa="pomiary.dat";
    StrmPlikowy.open(nazwa,ios::app);
    
    stoper.DumpTimesToFile(StrmPlikowy);
    StrmPlikowy.close();
    stoper.CleanBuffer();
  }

}
