#define CTEST_MAIN
#include "../lib/thirdparty/ctest.h"
#include "../src/app_lib/lib.h"
#include <iostream>

using namespace std;

CTEST(initGame, playerAndCountInitialization)
{
    initGame();
    ASSERT_EQUAL(Player, 1);
    ASSERT_EQUAL(count, 100);
}

CTEST(takeMatches, invalidMove)
{
    initGame();
    num = 0; // Некорректное количество спичек
    bool result = takeMatches();
    ASSERT_EQUAL(result, false);
}

CTEST(takeMatches, validMove)
{
    initGame();
    num = 5; // Корректное количество спичек
    bool result = takeMatches();
    ASSERT_EQUAL(result, true);
    ASSERT_EQUAL(count, 100 - 5);
}

CTEST(countMatchesOnTable, initialCount)
{
    initGame();
    int initialCount = countMatchesOnTable();
    ASSERT_EQUAL(initialCount, 100);
}

CTEST(countMatchesOnTable, updatedCount)
{
    initGame();
    num = 7;
    takeMatches();
    int updatedCount = countMatchesOnTable();
    ASSERT_EQUAL(updatedCount, 100 - 7);
}

CTEST(bot_move, not_last_move)
{
    const int count = 95;
    const int result = bot_easy_move();
    ASSERT_INTERVAL(1, 10, result);
}

CTEST(bot_move, last_move)
{
    const int count = 8;
    const int result = bot_hard_move(count);
    const int expected = 8;
    ASSERT_EQUAL(result, expected);
}

int main(int argc, const char** argv)
{
    int result = ctest_main(argc, argv);
    return result;
}
