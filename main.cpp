#include <iostream>

using namespace std;

int main()
{
  std::cout << "You're a secret agent breaking into a server room." << endl;
  std::cout << "Your SuperHacker 2000 tells you the following information" << endl;
  std::cout << "+ There are three numbers in the code" << endl;

  const int a = 3;
  const int b = 4;
  int sum = a + b;
  int product = a * b;

  std::cout << "+ The codes add-up to " << sum << endl;
  std::cout << "+ The codes multiply to give " << product << endl;
  
  int answer, trialSum, trialProduct = 1;  // Note required starting product

  std::cout << "Type the code numbers with spaces between" << endl;
  std::cout << "Type Ctrl+D to enter code" << endl;

  while(std::cin >> answer)
  {
    trialSum += answer;
    trialProduct *= answer;
  }

  std::cout << trialSum << endl;
  std::cout << trialProduct << endl;
}