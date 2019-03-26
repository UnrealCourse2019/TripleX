#include <iostream>
#include <ctime>

void PlayGameAtDifficulty(int difficulty)
{
  std::cout << "You're a secret agent breaking into LEVEL " << difficulty << " server room\n";
  std::cout << "Your SuperHacker 2000 tells you the following information...\n";

  srand(time(NULL)); // create new random sequence based on time of day
  const int a = rand() % difficulty + difficulty;
  const int b = rand() % difficulty + difficulty;
  const int c = rand() % difficulty + difficulty;

  const int sum = a + b + c;
  const int product = a * b * c;

  std::cout << std::endl;
  std::cout << "+ There are three numbers in the code\n";
  std::cout << "+ The codes multiply to give " << product << std::endl;
  std::cout << "+ The codes add-up to " << sum << std::endl;

  std::cout << std::endl;
  std::cout << "Enter the three code numbers followed by x\n";
  std::cout << std::endl;

  int answer;
  int trialSum = 0;
  int trialProduct = 1;  // Note required starting product

  // Process the numbers in the input
  while(std::cin >> answer)
  {
    trialSum += answer;
    trialProduct *= answer;
  }

  std::cout << std::endl;
  if (trialSum == sum && trialProduct == product)
  {
    std::cout << "CONGRATULATIONS, YOU'RE IN. Now hurry before anyone finds you.\n";
    std::cout << "==============================================================\n";
  }
  else
  {
    std::cout << "BOOM :-( You failed miserably, and died horribly.\n";
  }
  std::cout << std::endl;
}

int main()
{
  std::system("clear");  // clears the terminal

  int difficulty = 2;
  int maxDifficulty = 10;
  while (difficulty <= maxDifficulty)
  {
    PlayGameAtDifficulty(difficulty);
    std::cin.clear();  // clears the failbit
    std::cin.ignore();  // discards the buffer
    ++difficulty;
  }

  std::cout << "WOW - You're a master hacker!\n";
  return 0;  // exit with no error code
}