#include <iostream>

void PlayGameAtDifficulty(int difficulty)
{
  std::cout << "==================================================" << std::endl;
  std::cout << "You're a secret agent breaking into level " << difficulty << " server room" << std::endl;
  std::cout << "Your SuperHacker 2000 tells you the following information..." << std::endl;
  std::cout << std::endl;
  std::cout << "+ There are three numbers in the code" << std::endl;

  srand(time(NULL));  // create new random sequence based on time of day
  const int a = rand() % difficulty + 2;
  const int b = rand() % difficulty + 2;
  const int c = rand() % difficulty + 2;

  int sum = a + b + c;
  int product = a * b * c;

  std::cout << "+ The codes add-up to " << sum << std::endl;
  std::cout << "+ The codes multiply to give " << product << std::endl;

  int answer, trialSum, trialProduct = 1; // Note required starting product

  std::cout << std::endl;
  std::cout << "Type the code numbers with spaces between" << std::endl;
  std::cout << "Type Ctrl+D on new line to enter code" << std::endl;

  while(std::cin >> answer)
  {
    trialSum += answer;
    trialProduct *= answer;
  }

  if (trialSum == sum && trialProduct == product)
  {
    std::cout << "CONGRATULATIONS, YOU'RE IN. Now hurry before anyone finds you." << std::endl;
  }
  else
  {
    std::cout << "You failed miserably, and died horribly." << std::endl;
  }
}

int main()
{
  PlayGameAtDifficulty(2);
  PlayGameAtDifficulty(3);
  // PlayGameAtDifficulty(5);
  // PlayGameAtDifficulty(7);
  // PlayGameAtDifficulty(10);
}