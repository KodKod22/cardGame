#ifndef _GAME_HPP
#define _GAME_HPP
#include"Player.hpp"

class Game
{
private:
    Player p1;
    Player p2;
    Deck mainDeck;
public:
    Game(char *p1,char *p2);
    Game(Player p1,Player p2);
    Game(const Game &other);
    ~Game();
    void playRound();
    int checkWinner();
};

#endif