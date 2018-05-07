//
// Created by Josh Sorber on 5/3/18.
//

#ifndef UNTITLED_BLACKJACK_H
#define UNTITLED_BLACKJACK_H
using namespace std;
enum class GameStatus {
    ACTIVE,
    ENDED_PWIN,
    ENDED_DWIN,
    ENDED_TIE
};
enum class Move {
    STAND,
    HIT
};
typedef struct {
    vector<Card> playerHand;
    vector<Card> dealerHand;
    GameStatus status;
    array<Card, 52> deck;
} Game;
void setupGame(Game &game) {
    dealHand(game.dealerHand, game.deck, 1);
    dealHand(game.playerHand, game.deck, 2);
    status(game.playerHand);
    cout << "Dealer Shows: ";
    printCard(game.dealerHand[0]);
    cout << "(" << cardValue(game.dealerHand[0]) << ")" << endl;
}
Move getMove() {
    while(true) {
        int someNumber;
        cout << "(1) Hit / (0) Stand: ";
        cin >> someNumber;

        if (cin.fail() || someNumber > 1 || someNumber < 0)
        {
            cin.clear();
            cin.ignore(32767, '\n');
        } else {
            if(someNumber == 1) {
                return Move::HIT; // Hit
            }
            if(someNumber == 0) {
                return Move::STAND; // Stand
            }

        }

    }
}
void bustCheck(Game &game) {
    int playerTally = tallyHand(game.playerHand);
    int dealerTally = tallyHand(game.dealerHand);
    if(dealerTally > 21 && playerTally <= 21) {
        game.status = GameStatus::ENDED_PWIN;
        cout << "Game Ended with win by Player" << endl;
    }
    if(playerTally > 21 && dealerTally <= 21) {
        game.status = GameStatus::ENDED_DWIN;
        cout << "Game Ended with win by Dealer" << endl;
    }
    if(playerTally > 21 && dealerTally > 21) {
        game.status = GameStatus::ENDED_TIE;
        cout << "Game Ended with Tie" << endl;
    }
}
void declareWinner(Game &game) {
    int playerTally = tallyHand(game.playerHand);
    int dealerTally = tallyHand(game.dealerHand);
    if(dealerTally > playerTally) {
        game.status = GameStatus::ENDED_DWIN;
        cout << "Game Ended with win by Dealer" << endl;
    }
    if(dealerTally < playerTally) {
        game.status = GameStatus::ENDED_PWIN;
        cout << "Game Ended with win by Player" << endl;
    }
    if(dealerTally == playerTally) {
        game.status = GameStatus::ENDED_TIE;
        cout << "Game Ended with Tie" << endl;
    }
}
void takeTurn(Game &game) {
    // ASK THE PLAYER FOR A TURN
        // if user has over 17, default to stand
    Move playerMove;
    Move dealerMove;
    int dealerTally = tallyHand(game.dealerHand);
    int playerTally = tallyHand(game.playerHand);
    if(playerTally >= 17) {
        playerMove = Move::STAND;
    }
    else {
        playerMove = getMove();
    }
    if(dealerTally < 17) {
        dealerMove = Move::HIT;
    } else {
        dealerMove = Move::STAND;
    }
    // COMMIT THE TURN
    if(playerMove == Move::HIT) {
        dealHand(game.playerHand, game.deck, 1);
        status(game.playerHand);
    }
    if(dealerMove == Move::HIT) {
        dealHand(game.dealerHand, game.deck, 1);
        cout << "Dealer hits!" << endl;
    }
    bustCheck(game);
    if(dealerMove == Move::STAND && playerMove == Move::STAND) {
        declareWinner(game);
    }

    // CHECK PLAYER AND UPDATE GAME STATUS ACCORDING
}
Game newGame() {
    vector<Card> playerHand;
    vector<Card> dealerHand;
    GameStatus status = GameStatus::ACTIVE;
    array<Card, 52> deck;
    Game game {playerHand, dealerHand, status, deck};
    createDeck(game.deck);

    shuffleDeck(game.deck);
    setupGame(game);
    //takeTurn(game);
    return game;
}

#endif //UNTITLED_BLACKJACK_H
