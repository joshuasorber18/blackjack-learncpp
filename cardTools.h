//
// Created by Josh Sorber on 5/3/18.
//

#ifndef UNTITLED_CARDTOOLS_H
#define UNTITLED_CARDTOOLS_H
using namespace std;
enum class Suits {
    SPADES,
    CLUBS,
    DIAMONDS,
    HEARTS
};
enum class Ranks {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};
typedef struct {
    Ranks rank;
    Suits suit;
    bool dealt;
} Card;
void printCard(const Card &card) {
    char rankResolver[] = "A23456789TJKQ";
    char suitResolver[] = "SCDH";
    if(card.dealt) {
        cout << "INVALID CARD" << endl;
    } else {
        cout << rankResolver[static_cast<int>(card.rank)] << suitResolver[static_cast<int>(card.suit)] << endl;
    }
}
void printDeck(const array<Card, 52> &deck) {
    for (const auto &card : deck) {
        if(!card.dealt)
            printCard(card);
    }
}
void printHand(const vector<Card> &hand) {
    for (const auto &card : hand) {
        printCard(card);
    }
}
void swapCard(array<Card, 52> &deck, int c1, int c2) {
    Card card1 = deck[c1];
    deck[c1] = deck[c2];
    deck[c2] = card1;
}
int randomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 mersenne(rd()); // Create a mersenne twister, seeded using the random device

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution<> die(min, max);
    return die(mersenne);
}
void shuffleDeck(array<Card, 52> &deck) {
    for (int i = 0; i < 52; ++i) {
        int toSwap = randomNumber(0,51);
        swapCard(deck, i, toSwap);
    }
}
void createDeck(array<Card, 52> &deck) {
    int card = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck[card] = {static_cast<Ranks>(j), static_cast<Suits>(i), false};
            ++card;
        }

    }
}
bool isCardValid(Card &someCard) {
    if(someCard.dealt)
        return false;
    else
        return true;
}
int cardValue(const Card &card) {
    switch(card.rank) {
        case Ranks::ACE: return 11;
        case Ranks::TWO: return 2;
        case Ranks::THREE: return 3;
        case Ranks::FOUR: return 4;
        case Ranks::FIVE: return 5;
        case Ranks::SIX: return 6;
        case Ranks::SEVEN: return 7;
        case Ranks::EIGHT: return 8;
        case Ranks::NINE: return 9;
        case Ranks::TEN: return 10;
        case Ranks::JACK: return 10;
        case Ranks::QUEEN: return 10;
        case Ranks::KING: return 10;
    }
}
int tallyHand(vector<Card> &someHand) {
    int total = 0;
    for(const auto &card : someHand) {
        total += cardValue(card);
    }
    return total;
}
void dealHand(vector<Card> &someHand, array<Card, 52> &deck, int number) {
    // Take random cards from the deck, set dealt = true and add it to this hand
    // do while less then number AND vector size < number
    if(number > 0) {

        unsigned long startSize = someHand.size();
        unsigned int counter = 0;
        do {
            int randomIndex = randomNumber(0, 51);
            Card &randomCard = deck[randomIndex];
            if (!randomCard.dealt) {
                someHand.push_back(randomCard);
                deck[randomIndex].dealt = true;
                ++counter;
            }
        } while (counter < number && (someHand.size() != startSize + number));

    }
}
void status(vector<Card> hand) {
    cout << "==== CARDS ====" << endl;
    printHand(hand);
    cout << "Sum of Cards: " << tallyHand(hand) << endl;
}
#endif //UNTITLED_CARDTOOLS_H
