#ifndef _CARD_HPP_
#define _CARD_HPP_
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include<sstream>
#include<iostream>
#include<cstring>

using namespace std;
enum Suit
{
    Hearts,
    Spades,
    Diamonds,
    Clubs,
    Erro
};
class Card
{
private:
    Suit suit;
    char* rank;
public:
    Card(){}
    Card(Suit s,char* r);
    Card(const Card &other);
    Card& operator=(const Card& st);
    ~Card();
    char *getRank(){return rank;};
};


#endif