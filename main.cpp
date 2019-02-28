#include <iostream>
#include <ctime>

void PlayGameAtDifficulty(int difficulty)
{
  std::cout << "==================================================" << std::endl;
  std::cout << "You're a secret agent breaking into LEVEL " << difficulty << " server room" << std::endl;
  std::cout << "Your SuperHacker 2000 tells you the following information..." << std::endl;

  srand(time(NULL));  // create new random sequence based on time of day
  const int a = rand() % difficulty + 2;
  const int b = rand() % difficulty + 2;
  const int c = rand() % difficulty + 2;

  const int sum = a + b + c;
  const int product = a * b * c;

  std::cout << std::endl;
  std::cout << "+ There are three numbers in the code" << std::endl;
  std::cout << "+ The codes add-up to " << sum << std::endl;
  std::cout << "+ The codes multiply to give " << product << std::endl;

  std::cout << std::endl;
  std::cout << "Enter the three code numbers followed by x" << std::endl;
  std::cout << std::endl;

  int answer;
  int trialSum = 0;
  int trialProduct = 1;  // Note required starting product

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
    std::cout << std::endl;
    std::cout << "BOOM :-( You failed miserably, and died horribly." << std::endl;
    std::cout << std::endl;
  }
}

int main()
{
  std::system("clear");
  int difficulty = 2;
  int maxDifficulty = 10;
  while (difficulty < maxDifficulty)
  {
    PlayGameAtDifficulty(difficulty);
    std::cin.clear();  //clears the failbit
    std::cin.ignore();  //discards the buffer
    ++difficulty;
  }
  std::cout << "WOW - You're a master hacker!" << std::endl;
}