//kody agin peters 209500131
#include"Player.hpp"
Player::Player(const char *n)
{
    this->name = new char[strlen(n)+1];
    if (this->name == NULL)
    {
        cout<<"OUT OF MEMORY"<<endl;
        return;
    }
    
    Hand = Deck();
}
Player ::Player(const Player &other):Hand(other.Hand)
{
    this->name = new char[strlen(other.name)+1];
    if (name == NULL)
    {
        cout<<"OUT OF MEMORY"<<endl;
        return;
    }
    name = other.name;
}
Player& Player:: operator=(const Player& st)
{
    if (this == &st)
    {
        return *this;
    }
    Hand = st.Hand;
    name = new char[strlen(st.name)+1];
    if (name == NULL)
    {
        cout<<"OUT OF MEMORY"<<endl;
        exit(1);
    }
    
    name = st.name;
    return *this;
}
Player::~Player()
{
    delete []name;
}

void Player:: receiveCard(Card *c){
    Hand.ADDcard(c);
    return;
}
Card* Player:: playCard(){

    Card* temp = new Card();
    temp = Hand.draw();
    
    
    return temp;
}