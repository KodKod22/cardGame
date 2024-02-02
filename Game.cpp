//kody agin peters 209500131
#include"Game.hpp"
#define TEMP_SIZE 4

Game::Game(Player p1,Player p2)
{
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

Game::~Game(){}

void Game::playRound() {
    
    Card* pilled1[TEMP_SIZE];
    Card* pilled2[TEMP_SIZE];

    Card* cardp1 = p1.playCard();
    if (cardp1 == NULL)
    {
        return;   
    }
    
    Card* cardp2 = p2.playCard();

    if (cardp2 == NULL)
    {
        return;
    }
    

    if (strcmp(cardp1->getRank(), cardp2->getRank()) > 0)
    {
        p1.receiveCard(cardp2);

        p1.receiveCard(cardp1);

        return;
    } else if (strcmp(cardp1->getRank(), cardp2->getRank()) < 0)
    {
        p2.receiveCard(cardp1);

        p2.receiveCard(cardp2);

        return;
    } else {
        pilled1[0] = cardp1;
        pilled2[0] = cardp2;
        for (int i = 1; i < TEMP_SIZE; i++) {
            pilled1[i] = p1.playCard();
            if (pilled1[i] == NULL)
            {
                return;
            }
            
            pilled2[i] = p2.playCard();
            if (pilled2[i] == NULL)
            {
                return;
            }
            
        }
        cardp1 = p1.playCard();
        if (cardp1 == NULL)
        {
            return;
        }
        
        cardp2 = p2.playCard();
        if (cardp2 == NULL)
        {
            return;
        }
        

        if (strcmp(cardp1->getRank(), cardp2->getRank()) > 0)
        {
            for (int i = 0; i < TEMP_SIZE; i++)
            {
                p1.receiveCard(pilled1[i]);
            }
            for (int i = 0; i < TEMP_SIZE; i++)
            {
                p1.receiveCard(pilled2[i]);
            }
            return;
        } else if (strcmp(cardp1->getRank(), cardp2->getRank()) < 0)
            {
                for (int i = 0; i < TEMP_SIZE; i++)
                {
                    p2.receiveCard(pilled2[i]);
                }

                for (int i = 0; i < TEMP_SIZE; i++)
                {
                    p2.receiveCard(pilled1[i]);
                }

            return;
        }else
        {
            playRound();
            return;
        }
        return;
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
