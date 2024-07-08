
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"

#include "./exercise2a/test.hpp"
#include "./exercise2b/test.hpp"

#include "./exercise3/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

typedef unsigned int uint;

/* ************************************************************************** */

void lasdtest()
{
  cout << endl
       << "~*~#~*~ Welcome to the LASD Test Suite ~*~#~*~ " << endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;

  loctestnum = 0;
  loctesterr = 0;
  testSimpleExercise1A(loctestnum, loctesterr);
  stestnum += loctestnum;
  stesterr += loctesterr;

  loctestnum = 0;
  loctesterr = 0;
  testSimpleExercise1B(loctestnum, loctesterr);
  stestnum += loctestnum;
  stesterr += loctesterr;

  cout << endl
       << "Exercise 1 (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";

  stestnum = 0;
  stesterr = 0;

  loctestnum = 0;
  loctesterr = 0;
  testSimpleExercise2A(loctestnum, loctesterr);
  stestnum += loctestnum;
  stesterr += loctesterr;

  loctestnum = 0;
  loctesterr = 0;
  testSimpleExercise2B(loctestnum, loctesterr);
  stestnum += loctestnum;
  stesterr += loctesterr;

  cout << endl
       << "Exercise 2 (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";

  stestnum = 0;
  stesterr = 0;

  loctestnum = 0;
  loctesterr = 0;
  testSimpleExercise3(loctestnum, loctesterr);
  stestnum += loctestnum;
  stesterr += loctesterr;

  cout << endl
       << "Exercise 3 (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";

  cout << endl
       << "Goodbye!" << endl;
}
