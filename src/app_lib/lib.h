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

#endif // LIB_H
