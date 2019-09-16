#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
  
  bool playing = true;

  char consent = 'y';

  int real;
  int max;
  int input;
  int tries;

  while (consent == 'y') {

    playing = true;
    max = 100;
    input = max + 69;
    tries = 0;
  
    //Generating the random number
    srand(time(NULL));
    real = rand() % max;

    //Start the game
    std::cout << "...Hello sir/ma'am, please enter a number between 1 and " << max << ": " << endl;

    while (playing) {
  
      //Ask for number input                                                        
      try {
        std::cin >> input;
      }
      catch (int ex) {}

      //If input is invalid, keep trying until the stupid user finally gives you a correct input
      while (input > max || input < 0) {
        std::cout << "That input is invalid, please enter a number between 1 and " << max << ":" << endl;
        try {
          std::cin >> input;
        }
        catch (int ex) {}
      }

      //Compare their guess to the number, and return an output
      if (input > real) {
        std::cout << "Too high, guess again: " << endl;
        tries++;
      }
      if (input < real) {
        std::cout << "Too low, guess again: " << endl;
        tries++;
      }
      //If they guessed the right number
      if (input == real) {
	playing = false;
	consent = '?';
        std::cout << "Congratulations, you have successfully guessed the number " << real << " in only " << tries << " tries." << endl;
        if (tries > 7)
	  std::cout << "Silly human." << endl;
	//Ask if they would like to play again
	while (consent != 'y' && consent != 'n') {
	  std::cout << "Would you like to play again? (y/n)" << endl;
	  try {
	    std::cin >> consent;
	  } 
	  catch (int ex) {}
	}
      }
      input = max + 69;
    }
  }
  return 0;
}
