#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std;
int main()
{
	string playerName;
	int balance; 
	int bet;
	int guess;
	int dice; 
	char choice;
	srand(time(0)); 

	cout << "\n\nWhat's your Name : ";
	getline(cin, playerName);
	cout << "\n\nEnter the starting balance to play game : $";
	cin >> balance;
	do
	{
		system("cls");
		cout << "\n\nYour current balance is $ " << balance << "\n";

		do
		{
			cout << "Hey, " << playerName << ", enter amount to bet : $";
			cin >> bet;
			if (bet > balance)
				cout << "Betting balance can't be more than current balance!\n"
				<< "\nRe-enter balance\n ";
		} while (bet > balance);

		do
		{
			cout << "Guess any betting number between 1 & 10 :";
			cin >> guess;
			if (guess <= 0 || guess > 10)
				cout << "\nNumber should be between 1 to 10\n"
				<< "Re-enter number:\n ";
		} while (guess <= 0 || guess > 10);
		dice = rand() % 10 + 1;
		if (dice == guess)
		{
			cout << "\n\nYou are in luck!! You have won Rs." << bet * 10;
			balance = balance + bet * 10;
		}
		else
		{
			cout << "Oops, better luck next time !! You lost $ " << bet << "\n";
			balance = balance - bet;
		}
		cout << "\nThe winning number was : " << dice << "\n";
		cout << "\n" << playerName << ", You have balance of $ " << balance << "\n";
		if (balance == 0)
		{
			cout << "You have no money to play ";
			break;
		}
		cout << "\n\n-->Do you want to play again (y/n)? ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	cout << "\n\n\n";
	cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
	return 0;
}
