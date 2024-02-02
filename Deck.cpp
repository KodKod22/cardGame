//kody agin peters 209500131
#include"Deck.hpp"
Deck::Deck()
{
    Cardscount = 0;
    for (int i = 0; i < Max_size; i++)
    {
        Cards[i] = NULL;
    }
    
}
Deck::Deck(const Deck &other) : Cardscount(other.Cardscount){
    for (int i = 0; i < Max_size; i++)
    {
        Cards[i] = other.Cards[i];
    }
    
}
Deck& Deck:: operator=(const Deck& st){
    if (this == &st)
    {
        return *this;
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
    
}
void Deck:: shuffle(){
    
    for (int i = 0; i < Max_size; i++)
    {
        int j = rand() % Max_size;
        swap(Cards[i],Cards[j]);
    }
    
}
Card* Deck:: draw(){
    if (Cardscount == 0)
    {
        return NULL;

    }
    
    Card* temp = new Card();
    if (temp == NULL)
    {
        cout<<"out of memory"<<endl;
        exit(1);
    }
    
    temp = Cards[--Cardscount];
     
    return temp;
}

void Deck::ADDcard(Card*& n_card) {
    Card *temp[Max_size];

    for (int i = 0; i < Max_size; i++) {
        temp[i] = Cards[i];
    }

    Cards[0] = n_card;

    for (int i = 1; i < Max_size; i++) {
        Cards[i] = temp[i - 1]; 
    }

    this->Cardscount++;
    return;
}
bool Deck:: isEmpty(){
    if (Cardscount == 0)
    {
        return true;
    }
    return false;
}