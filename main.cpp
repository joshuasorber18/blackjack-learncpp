#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <random>
#include "cardTools.h"
#include "Blackjack.h"
using namespace std;


// 1 turn , player ask hit or stand, if hit, deal and check
// then dealer, if less than 17 hit
int main() {
    Game game = newGame();
    do {
        takeTurn(game);
    } while(game.status == GameStatus::ACTIVE);
    return 1;
}