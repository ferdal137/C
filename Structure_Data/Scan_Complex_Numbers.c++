#include <iostream>
using namespace std;

#define COMP_COMPLEJOS(X, Y) \
  (((X).re == (Y).re) && ((X).im == (Y).im))

struct complejos {
  double re;     
  double im;     
};

int main()
{
  struct complejos uI = {re:0.0, im:1.0}, uR = {re:1.0, im:0.0}, z;

  cout<<"Por leer un numero complejo.\nDigite la parte real: ";
  cin>>z.re;
  cout<<"Digite la parte imaginaria: ";
  cin>>z.im;

  if (COMP_COMPLEJOS(uI, z))
    cout<<"Digito la unidad imaginaria\n";
  else if (COMP_COMPLEJOS(uR, z))
    cout<<"Digito la unidad real\n";
  else
    cout<<"El numero complejo que digito fue: "<<z.re<<" + "<<z.im<<"\n";

  z.re += 3.0;

  cout<<"El numero complejo modificado es: "<<z.re<<" + "<<z.im<<"\n";

  return 0;


}