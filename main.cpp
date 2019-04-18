#include <iostream>
#include <ctime>

struct FCodeStruct
{
  int Sum;
  int Product;
};

struct FGuessStruct
{
  int GuessA;
  int GuessB;
  int GuessC;
};

void PrintIntroduction(int Strength)
{
  std::system("clear");  // clears the terminal
  std::cout << "You're a secret agent breaking into a level " << Strength << " server room\n";
  std::cout << "Your SuperHacker 2000 tells you the following information...\n";
}

FCodeStruct CreateCodeWithStrength(int Strength)
{
  srand(time(NULL)); // create new random sequence based on time of day
  const int CodeA = rand() % Strength + Strength; // TODO simplify
  const int CodeB = rand() % Strength + Strength;
  const int CodeC = rand() % Strength + Strength;
  
  FCodeStruct CodeThisGame;
  CodeThisGame.Product = CodeA * CodeB * CodeC;
  CodeThisGame.Sum = CodeA + CodeB + CodeC;

  return CodeThisGame;
}

void PrintHint(FCodeStruct Code)
{
  std::cout << std::endl;
  std::cout << "+ There are three numbers in the Code\n";
  std::cout << "+ The Codes multiply to give " << Code.Product << std::endl;
  std::cout << "+ The Codes add-up to " << Code.Sum << std::endl;
  std::cout << std::endl;
  std::cout << "Enter the three Code numbers followed by x\n";
}

FGuessStruct GetPlayerGuess()
{
  FGuessStruct PlayerGuess;
  std::cin >> PlayerGuess.GuessA;
  std::cin >> PlayerGuess.GuessB;
  std::cin >> PlayerGuess.GuessC;

  return PlayerGuess;
}

bool IsCodeValid(FGuessStruct Guess, FCodeStruct Code)
{
  const int GuessSum = Guess.GuessA + Guess.GuessB + Guess.GuessC;
  const int GuessProduct = Guess.GuessA * Guess.GuessB * Guess. GuessC;
  return (GuessSum == Code.Sum && GuessProduct == Code.Product);
}

void PrintResults(bool IsCorrect)
{
  if (IsCorrect)
  {
    std::cout << "CONGRATULATIONS, YOU'RE IN. Now hurry before anyone finds you.\n";
    std::cout << "==============================================================\n";
  }
  else
  {
    std::cout << "BOOM :-( You failed miserably, and died horribly.\n";
  }
}

int main()
{
  const int Difficulty = 3;
  PrintIntroduction(Difficulty);
  const FCodeStruct PublicCode = CreateCodeWithStrength(Difficulty);
  PrintHint(PublicCode);
  const FGuessStruct PlayerGuess = GetPlayerGuess();
  PrintResults(IsCodeValid(PlayerGuess, PublicCode));
  return 0;
}