// KeyWords
// A Classic word jumble game with an IT twist!

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int correctAnswers = 0;


int main()
{
	int wrongAnswers = 0;
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"packet", "A formatted unit of measure for networking."},
		{"bandwidth", "How much of this can you handle at once?"},
		{"phishing", "What are you looking for here?"},
		{"processor", "This piece of computing hardware is working as hard as you are!"},
		{"virus", "Something you DONT want to download!"},
		{"domain", "Where are you?"},
		{"gateway", "How do I get out of here?"},
		{"encryption", "These characters dont make any sense..."},
		{"compression", "Your chances of figuring this out are getting smaller!"},
		{"virtual", "Is the word actually there?"},
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];  // word to guess
	string theHint = WORDS[choice][HINT];  // hint for word

	string jumble = theWord;  // jumbled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
			wrongAnswers++;
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{
		correctAnswers++;
		cout << "\nThat's it!  You guessed it!\n";
		cout << "\n             Stats" << endl;
		cout << "-------------------------------" << endl;
		cout << "You had " << wrongAnswers << " incorrect answers before you were able to guess the word " << theWord << endl;
		string playAgain;
		cout << "Would you like to play again? Y/N" << endl;
		cin >> playAgain;
		while (true) {
			if (playAgain == "Y") {
				main();
			}
			else if (playAgain == "N") {
				cout << "You guessed " << correctAnswers << " words correctly this game! Nice Job!";
				cout << "Thanks for playing!" << endl;
				Sleep(3000);
				exit(0);
			}
			else {
				cout << "Please input Y or N..." << endl;
				cin >> playAgain;
			}
		}
	}
}