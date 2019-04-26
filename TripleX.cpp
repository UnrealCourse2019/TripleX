#include <iostream>

void PrintIntroduction()
{
    std::cout << "\n\nYou are a secret agent breaking into a secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame()
{
    PrintIntroduction();

    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win!";
        return true;
    }
    else
    {
        std::cout << "\nYou lose!";
        return false;
    }
}

int main()
{
    while(true)
    {
        bool bLevelComplete = PlayGame();
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer
    }

    return 0;
}