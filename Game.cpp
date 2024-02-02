#include"Game.hpp"
#define TEMP_SIZE 3
Game::Game(Player p1,Player p2){
    this->p1 = p1;
    this->p2 = p2;
}
Game::Game(char *p1,char *p2)
{
    this->p1 = Player(p1);
    this->p2 = Player(p2);
}
Game::Game(const Game &other):
p1(other.p1),p2(other.p2),mainDeck(other.mainDeck){
    
    
}
Game::~Game()
{
}

void Game:: playRound(){
    Card *pilled1;
    Card *pilled2;

    Card cardp1(p1.playCard());
    Card cardp2(p2.playCard());

    if (strcmp(cardp1.getRank(),cardp2.getRank()) > 0)
    {
        p1.receiveCard(cardp2);
        p1.receiveCard(cardp1);
        return;

    }else if (strcmp(cardp1.getRank(),cardp2.getRank()) < 0)
    {
        p2.receiveCard(cardp1);
        p2.receiveCard(cardp2);
        return;
    }else
    {
        for (int i = 0; i < TEMP_SIZE; i++)
        {
            pilled1[i] = p1.playCard();
            pilled2[i] = p2.playCard();
        }
        if (strcmp(p1.playCard().getRank(),p2.playCard().getRank()) > 0)
        {
            for (int i = 0; i < TEMP_SIZE; i++)
            {
                p1.receiveCard(pilled1[i]);
            }
            for (int i = 0; i < 3; i++)
            {
                p1.receiveCard(pilled2[i]);
            }
            return;
            
        }else if(strcmp(p1.playCard().getRank(),p1.playCard().getRank()) < 0)
        {
            for (int i = 0; i < 3; i++)
            {
                p2.receiveCard(pilled2[i]);
            }
            for (int i = 0; i < 3; i++)
            {
                p2.receiveCard(pilled1[i]);
            }
            return;
        }
    }
}
int Game:: checkWinner(){
    if (p1.getDeck().isEmpty() == true)
    {
        return 2;
    }else if (p2.getDeck().isEmpty() == true)
    {
        return 1;
    }
    return 0;
    
}
