//kody agin peters 209500131
#ifndef _DECK_HPP_
#define _DECK_HPP_
#define Max_size 52
#include"Card.hpp"


class Deck
{
private:
    Card *Cards[Max_size];
    int Cardscount;
public:
    Deck();
    Deck(const Deck &other);
    Deck& operator=(const Deck& st);
    ~Deck();
    void shuffle();
    Card *draw();
    void populateDeckFromFile(const std::string& filename);
    void ADDcard( Card*& n_card);
    int getCardscount(){return Cardscount;}
    bool isEmpty();
};


#endif