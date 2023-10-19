#include <iostream>
#include <string>
#include <limits>

int marbles = 12;

void WaitEnter()
{
	std::cout << "\nPress Enter to continue...";
	while (std::cin.get() != '\n');
}

void printBoard()
{
	std::cout << "\n";
	for (int i = 0; i < marbles; i++)
	{
		std::cout << "* ";
	}
}

void play()
{
	printBoard();
	while (marbles != 0)
	{
		int pMarbles;
		std::cout << "\nYour turn \n" << "Take 1, 2, or 3 marbles \n";
		while (!(std::cin >> pMarbles) || (pMarbles < 1 || pMarbles > 3)) {
			std::cin.clear();
			std::cout << "\n" << "Take 1, 2, or 3 marbles \n";
		}
		marbles = marbles - pMarbles;
		printBoard();

		std::cout << "\nDr. Nim's turn";
		std::cin.ignore();
		WaitEnter();
		std::cout << "\n";
		int nMarbles = 4 - pMarbles;
		marbles = marbles - nMarbles;
		printBoard();
		std::cout << "\nDr. Nim takes " << nMarbles << " marbles";
		WaitEnter();
		printBoard();
	}
	std::cout << "\nDr Nim wins!\n";
}

int main()
{
	std::cout << "Welcome to Dr. Nim";
	int decision;
	
	std::cout << "\n" << "1-Play \n2-Help \n";
	while (!(std::cin >> decision) || (decision < 1 || decision > 2)) {
		std::cin.clear();
		std::cout << "\n" << "1-Play \n2-Help \n";
	}

	if (decision == 1)
	{
		std::cout << "\n";
		play();
	}

	if (decision == 2)
	{
		std::cout << "\nTake turns with the computer. On each turn, you may take 1, 2, or 3 marbles.\
			          \nWhoever takes the last marble wins, so choose carefully!" << "\n";
		std::cin.ignore();
		WaitEnter();
		std::cout << "\n";

		play();
	}
	return 0;
}

