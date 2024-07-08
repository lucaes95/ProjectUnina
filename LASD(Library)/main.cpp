
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

int main()
{
  cout << "Lasd Libraries 2024" << endl;

  char i = '0';

  while (true)
  {
    cout << endl;
    cout << "Ditiga [1-2, (other keywords for exit)]: " << endl;
    cout << "1: Simple Test of the professor. " << endl;
    cout << "2: Personal Test. " << endl;
    cin >> i;

    switch (i)
    {
    case '1':
      lasdtest();
      break;

    case '2':
      mytest();
      break;

    default:
      system("cls");
      cout << "Terminated.";
      exit(0);
    }
  }
  return 0;
}
