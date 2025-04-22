#include <iostream>

bool guess(const size_t& number, size_t attempts){
  size_t userGuess = 0;
  bool win = false;
  do{
    std::cout << "Enter your guess: ";
    std::cin >> userGuess;
    if (userGuess > number){
      std::cout << "Go lower.\n";
    } else if (userGuess < number){
      std::cout << "Go higher.\n";
    } else{
      std::cout << "You guessed it! Hooray!\n";
      win = true;
    }

    attempts--;
    if (!win){
      std::cout << "Attempts left: " << attempts << std::endl;
    }

  } while (userGuess != number && attempts > 0);

  return win;
}

int main(){
  srand(time(0));

  size_t maxRange = 0;
  while(maxRange <= 0){
    std::cout << "Enter max range for randomly picked number: ";
    std::cin >> maxRange;
  }

  size_t numAttempts = 0;
  while(numAttempts <= 0){
    std::cout << "Enter number of attempts: ";
    std::cin >> numAttempts;
  }

  size_t numToGuess = rand() % maxRange;

  if (!guess(numToGuess, numAttempts)){
    std::cout << "You lost. The number was " << numToGuess << ".\n";
  }
}
