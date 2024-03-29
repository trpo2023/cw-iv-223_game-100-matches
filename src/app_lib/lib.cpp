#include "lib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

bool Correct;
int Player;
int count;
int num;
int bot_hard_move(int count);
int bot_easy_move();

void initGame()
{
    srand(time(0));
    Player = 1;
    count = 100;
    num = 0;
    Correct = false;
}

void startGame()
{
    initGame();
    do {
        if (Player == 1) {
            do {
                cout << "\nYour move. There are " << count
                     << " matches on the table." << endl;
                cout << "How many matches will you take?\n" << endl;
                cin >> num;
                if (num >= 1 && num < 10 && num <= count)
                    Correct = true;
                else {
                    std::cout << "Wrong! Repeat the input!" << endl;
                    Correct = false;
                }
            } while (!Correct);
        } else {
            if (count <= 9) {
                num = bot_hard_move(count);
            } else {
                num = bot_easy_move();
            }
            cout << "\nMy move. I took " << num << " matches" << endl;
        }
        count -= num;
        Player = (Player == 1) ? 2 : 1;
    } while (count > 0);

    if (Player == 2) {
        cout << "You win!" << endl;
    } else {
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
         << "From the pile, players take turns taking from 1 to 9 matches, the "
            "player who takes the last match wins.\n";
}

int countMatchesOnTable()
{
    return count;
}

bool takeMatches()
{
    // Проверка на правильное количество спичек для взятия (от 1 до 9)
    if (num < 1 || num > 9 || num > count) {
        return false; // Ход был некорректным
    }

    // Уменьшение количества спичек на столе на выбранное количество
    count -= num;

    // Переключение текущего игрока
    Player = (Player == 1) ? 2 : 1;

    return true; // Ход был успешным
}

int bot_hard_move(int count)
{
    return count;
}

int bot_easy_move()
{
    return rand() % 9 + 1;
}
