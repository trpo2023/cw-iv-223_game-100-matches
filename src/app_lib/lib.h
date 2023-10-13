#ifndef LIB_H
#define LIB_H

// Объявление переменных как extern
extern bool Correct;
extern int Player;
extern int count;
extern int num;

// Объявление функций
void initGame();
void startGame();
void showCreators();
void showRules();
int countMatchesOnTable();
bool takeMatches();
int bot_hard_move(int count);
int bot_easy_move();

#endif // LIB_H
