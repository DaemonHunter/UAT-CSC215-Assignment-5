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

int currentTurn = 0;

int main()
{
	int wrongAnswers = 0;
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"keyword", "A word or identifier that has a particular meaning to the programming language."},
		{"encryption", "A method of scrambling the data so that it is unreadable without the key."},
		{"scramble", "The act of making (something) jumbled or muddled."},
		{"training", "The action of teaching a person or animal a particular skill or type of behavior."},
		{"simulation", "The action of pretending."},
		{"cryptography", "The practice and study of techniques for secure communication in the presence of third parties called adversaries."},
		{"code", "A system of rules to convert information."},
		{"recruit", "A person newly enlisted, and not yet fully trained."},
		{"transmission", "The process of sending and propagating an analogue or digital information signal."},
		{"decode", "The reverse process of encoding, converting code symbols back into a form that the recipient understand, such as English or Spanish."},
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
	cout << "\t\tOfficial CIA Use ONLY!\n\n";
	cout << "After graduating UAT, you are hired as a coder for the CIA." << endl;
	cout << "The current automated programs that the CIA uses to decode enemy transmissions" << endl;
	cout << "have always worked well until recently. " << endl;
	cout << "Recently the enemy is using single scrambled low - tech keywords to signal other" << endl;
	cout << "enemies to start attacks which our current code decryption programs have not been successful against." << endl;
	cout << "At the CIA they are developing a new code breaking team which relies on human expertise to detect" << endl;
	cout << "these low tech scrambled keywords." << endl;
	cout << "We are turning back the clock with this new team of human code breakers.\n" << endl;


	cout << "\t\tInstructions\n\n";
	cout << "Greetings. Please use your codebreaking skills to help our country.\n";
	cout << "I am going to give you 3 different keywords to unscramble." << endl;
	cout << "You will only have one guess at each word so make your decision wisely!\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'pass' to pass on the current word.\n\n";
	cout << "The keyword is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "pass"))
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

		cout << "\n\t\tStats" << endl;
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
				cout << "You guessed " << correctAnswers << " words correctly this game! Nice Job!\n";
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