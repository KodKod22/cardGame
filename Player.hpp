#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include"Deck.hpp"
class Player
{
private:
    char *name;
    Deck Hand;
public:
    Player(){};
    Player(const char *n);
    Player(const Player &other);
    Player& operator=(const Player& st);
    ~Player();
    void receiveCard(Card c);
    Card playCard();
    Deck getDeck(){return Hand;};
};

#endif