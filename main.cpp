#include <iostream>
#include <ctime>
#include <cstdlib>


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
		<< "...\n";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "Welcome to 100 matches game!\n\n";
        cout << "1. Start\n";
        cout << "2. Creators\n";
        cout << "3. Rules\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            startGame();
            break;
        case 2:
            showCreators();
            break;
        case 3:
            showRules();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}
