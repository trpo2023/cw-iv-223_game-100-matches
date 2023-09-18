#include <iostream>
#include <sstream>
#include <cassert>
#include "../src/app_lib/lib.h"

using namespace std;

// Объявляем переменные, которые будем использовать в тестах
extern bool Correct;
extern int Player;
extern int count;
extern int num;

// Функция для выполнения тестов
bool testStartGame() {
    // Перед запуском игры, инициализируем начальное количество спичек
    initGame();

    // Тест 1: Проверка начала игры с 100 спичками
    int initialMatches = countMatchesOnTable();
    assert(initialMatches == 100);

    // Тест 2: Проверка начала игры с правильным текущим игроком (1)
    assert(Player == 1);

    // Тест 3: Проверка начала игры с нулевым количеством введенных спичек (0)
    assert(num == 0);

    // Тест 4: Проверка начала игры с неправильным флагом Correct (должен быть false)
    assert(!Correct);

    return true;
}

bool testCountMatchesOnTable() {
    // Тест 1: Проверка подсчета спичек на столе после инициализации
    initGame();
    int initialMatches = countMatchesOnTable();
    assert(initialMatches == 100);

    // Тест 2: Проверка подсчета спичек после некоторых ходов (например, после 3 ходов)
    Player = 1;
    num = 5;
    count -= num;
    Player = 2;
    num = 3;
    count -= num;
    Player = 1;
    num = 4;
    count -= num;
    int remainingMatches = countMatchesOnTable();
    assert(remainingMatches == 100 - 5 - 3 - 4);

    return true;
}

bool testPlayerTurn() {
    // Перед запуском игры, инициализируем начальное количество спичек
    initGame();

    // Тест 1: Проверка, что игрок 1 начинает игру
    assert(Player == 1);

    // Тест 2: Проверка, что игрок 2 ходит после игрока 1
    num = 3; // Ход игрока 1
    takeMatches(); // Игрок 1 ходит
    assert(Player == 2); // Теперь должен ходить игрок 2

    // Тест 3: Проверка, что игрок 1 снова ходит после игрока 2
    num = 5; // Ход игрока 2
    takeMatches(); // Игрок 2 ходит
    assert(Player == 1); // Теперь должен ходить игрок 1

    return true;
}

bool testMoveRules() {
    // Перед запуском игры, инициализируем начальное количество спичек
    initGame();

    // Тест 1: Проверка, что игрок не может взять больше 9 спичек
    num = 10;
    bool moveResult = takeMatches();
    assert(!moveResult); // Ход некорректен, должен вернуть false

    // Тест 2: Проверка, что игрок не может взять 0 спичек
    num = 0;
    moveResult = takeMatches();
    assert(!moveResult); // Ход некорректен, должен вернуть false

    // Тест 3: Проверка, что игрок не может взять больше спичек, чем на столе
    num = 101;
    moveResult = takeMatches();
    assert(!moveResult); // Ход некорректен, должен вернуть false

    // Тест 4: Проверка, что игрок может взять от 1 до 9 спичек
    num = 5;
    moveResult = takeMatches();
    assert(moveResult); // Ход корректен, должен вернуть true

    return true;
}

bool testShowCreators() {
    // Перенаправляем стандартный вывод в stringstream
    stringstream output;
    streambuf* oldCout = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Вызываем функцию, которую хотим протестировать
    showCreators();

    // Восстанавливаем стандартный вывод
    cout.rdbuf(oldCout);

    // Ожидаемая строка с информацией о создателях игры
    string expectedOutput = "Game creators:\nAnastasia Syryamina IV-223\nIlya Parshaev IV-223\n";

    // Сравниваем фактический вывод с ожидаемым
    assert(output.str() == expectedOutput);

    return true;
}

bool testShowRules() {
    // Перенаправляем стандартный вывод в stringstream
    stringstream output;
    streambuf* oldCout = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Вызываем функцию, которую хотим протестировать
    showRules();

    // Восстанавливаем стандартный вывод
    cout.rdbuf(oldCout);

    // Ожидаемая строка с правилами игры
    string expectedOutput = "Game rules:\nFrom the pile, players take turns taking from 1 to 9 matches, the player who takes the last match wins.\n";

    // Сравниваем фактический вывод с ожидаемым
    assert(output.str() == expectedOutput);

    return true;
}



int main() {
    // Запуск тестов
    if (testStartGame()) {
        cout << "TEST 1/6 LOGIC_TEST:testStartGame [OK]" << endl;
    } else {
        cout << "TEST 1/6 LOGIC_TEST:testStartGame [FAIL]" << endl;
    }

    if (testCountMatchesOnTable()) {
        cout << "TEST 2/6 LOGIC_TEST:testCountMatchesOnTable [OK]" << endl;
    } else {
        cout << "TEST 2/6 LOGIC_TEST:testCountMatchesOnTable [FAIL]" << endl;
    }
    
    if (testPlayerTurn()) {
        cout << "TEST 3/6 LOGIC_TEST:testPlayerTurn [OK]" << endl;
    } else {
        cout << "TEST 3/6 LOGIC_TEST:testPlayerTurn [FAIL]" << endl;
    }

    if (testMoveRules()) {
        cout << "TEST 4/6 LOGIC_TEST:testMoveRules [OK]" << endl;
    } else {
        cout << "TEST 4/6 LOGIC_TEST:testMoveRules [FAIL]" << endl;
    }

    if (testShowCreators()) {
        cout << "TEST 5/6 LOGIC_TEST:testShowCreators [OK]" << endl;
    } else {
        cout << "TEST 5/6 LOGIC_TEST:testShowCreators [FAIL]" << endl;
    }

    if (testShowRules()) {
        cout << "TEST 6/6 LOGIC_TEST:testShowRules [OK]" << endl;
    } else {
        cout << "TEST 6/6 LOGIC_TEST:testShowRules [FAIL]" << endl;
    }

    return 0;
}

