#include"Deck.hpp"

Deck::Deck()
{
    Cardscount = 0;
    for (int i = 0; i < Max_size; i++)
    {
        char *sample = "sample";
        Suit t_suit = Diamonds;
        Cards[i] = Card(t_suit,sample);
    }
    
}
Deck::Deck(const Deck &other) : Cardscount(other.Cardscount){
    for (int i = 0; i < Max_size; i++)
    {
        Cards[i] = Card(other.Cards[i]);
    }
    
}
Deck& Deck:: operator=(const Deck& st){
    if (this == &st)
    {
        return *this;
    }
    if (st.Cardscount != Cardscount)
    {
        delete []Cards;
        Cards = new Card[Cardscount];
    }
    for (int i = 0; i < Max_size; i++)
    {
        Cards[i] = st.Cards[i];
    }
    Cardscount = st.Cardscount;
    return *this;
}
Deck::~Deck()
{
    delete []Cards;
}
void Deck:: shuffle(){
    
    for (int i = 0; i < Max_size; i++)
    {
        int j = rand() % Max_size;
        swap(Cards[i],Cards[j]);
    }
    
}
Card Deck:: draw(){

    Card temp;
    temp = Cards[Cardscount-1];
    Cardscount--;
    return temp;
}

void Deck::ADDcard(Card n_card){
    Card temp[Max_size];
    
    for (int i = 0; i < Cardscount; i++)
    {
        temp[i] = Cards[i];
    }

    Cardscount++;

    Cards[0] = n_card;

    for (int i = 1; i < Cardscount ; i++)
    {
        Cards[i] = temp[i];
    }

    return;
}
bool Deck:: isEmpty(){
    if (Cardscount == 0)
    {
        return true;
    }
    return false;
}