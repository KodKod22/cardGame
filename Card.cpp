#include"Card.hpp"
Card::Card(Suit s,char* r)
{
    this->suit = s;
    this->rank = new char[strlen(r)+1];
    if (rank == NULL)
    {
        cout<<"OUT OF MEMORY";
        return;
    }
    
    rank = r;
}
Card:: Card(const Card &other) : suit(other.suit)
{
    this->rank = new char[strlen(other.rank)+1];
    if (rank == NULL)
    {
        cout<<"OUT OF MEMORY";
        return;
    }
    strcpy(rank,other.rank);
}
Card& Card:: operator=(const Card& st){
    if (this == &st)
    {
        return *this;
    }
    if (st.suit != suit)
    {
        delete []rank;
        rank = new char[strlen(st.rank)+1];
    }
    strcpy(rank,st.rank);
    suit = st.suit;
    return *this;
}
Card::~Card()
{
    delete[]rank;
}
