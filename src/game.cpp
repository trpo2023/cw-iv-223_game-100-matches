#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lib.h"


using namespace std;

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
