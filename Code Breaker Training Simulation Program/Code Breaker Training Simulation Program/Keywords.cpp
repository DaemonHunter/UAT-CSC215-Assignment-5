// KeyWords
// A Classic word jumble game with an IT twist!

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int correctAnswers = 0; // Declare and intitalize the integer <correctAnswers> to 0
int wrongAnswers = 0; // Declare and intitalize the integer <wrongAnswers> to 0
int totalAnswers = 0; // Declare and intitalize the integer <totalAnswers> to 0
string wordArray[3];


int main()
{
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
		
	cout << "\t\tInstructions\n\n";
	cout << "Greetings. Please use your codebreaking skills to help our country.\n";
	cout << "I am going to give you 3 different keywords to unscramble." << endl;
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'pass' to pass on the current word.\n\n";
	
	for (int i = 0; i < 3; ++i)
	{
		srand(time(0));
		int words = (rand() % NUM_WORDS);
		for (int c = 0; c < 3; ++c)
		{
			while (WORDS[words][WORD] == wordArray[c])
			{
				words = (rand() % NUM_WORDS);
			}
		}
		wordArray[i] = WORDS[words][WORD];

		string theWord = WORDS[words][WORD];  // word to guess
		string theHint = WORDS[words][HINT];  // hint for word
		string jumble = theWord;  // jumbled version of word
		int length = jumble.size();
		for (int j = 0; j < length; ++j)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

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
				totalAnswers++;
			}

			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			totalAnswers++;
			correctAnswers++;
			cout << "\nThat's it!  You guessed it!\n" << endl;
		}
	}

	cout << "\n\t\tStats" << endl;
	cout << "-------------------------------" << endl;
	cout << "You guessed " << correctAnswers << " words correctly this simulation." << endl;
	cout << "You guessed " << wrongAnswers << " words incorrectly this simulation." << endl;
	cout << "You guessed a total of " << totalAnswers << " words this simulation." << endl;
	string playAgain;
	cout << "Would you like to play again? Y/N" << endl;
	cin >> playAgain;
	
	while (true) {
		if (playAgain == "Y") {
			system("cls");
			main();
		}
		else if (playAgain == "N") {
			cout << "Thanks for playing!" << endl;
			Sleep(2000);
			exit(0);
		}
		else {
			cout << "Please input Y or N..." << endl;
			cin >> playAgain;
		}
	}
}