#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lib.h"


using namespace std;
bool Correct;
int Player, count, num;

void startGame()
{

	srand(time(0));
	int Player = 1, count = 100, num = 0;
	Player = 1;
	count = 100;
	do
	{
		if (Player == 1)
		{
			do
			{
				cout << "\nYour move. There are " << count << " matches on the table." << endl;
				cout << "How many matches will you take?\n" << endl;
				cin >> num;
				if (num >= 1 && num < 10 && num <= count)
					Correct = true;
				else
				{
					std::cout << "Wrong! Repeat the input!" << endl;
					Correct = false;
				}
			} while (!Correct);
		}
		else
		{
			if (count <= 9)
			{
				num = count;
			}
			else
			{
				num = rand() % 9 + 1;
			}
			cout << "\nMy move. I took " << num << " matches" << endl;
		}
		count -= num;
		if (Player == 1)
		{
			Player = 2;
		}
		else
		{
			Player = 1;
		}
	} while (count > 0);

	if (Player == 2)
	{
		cout << "You win!" << endl;
	}
	else
	{
		cout << "You lose!" << endl;
	}
	cout << "Game ended!\n";
}

void showCreators()
{
	cout << "Game creators:\n"
		<< "Anastasia Syryamina IV-223\n"
		<< "Ilya Parshaev IV-223\n";
}

void showRules()
{
	cout << "Game rules:\n"
		<< "From the pile, players take turns taking from 1 to 9 matches, the player who takes the last match wins.\n";
}

