//kody agin peters 209500131
#include"Deck.hpp"
Suit convertFromstring(const string& name){
    if (name == "Hearts")
    {
        return Hearts;
    }
    else if (name == "Spades")
    {
        return Spades;
    }
    else if(name == "Diamonds")
    {
        return Diamonds;
    }else if (name == "Clubs")
    {
        return Clubs;
    }else
    {
        return Erro;
    }
    
    
}
void Deck::populateDeckFromFile(const string& filename) {
    std::ifstream file(filename);
    std::string line;
    string Suit_;
    string rank_;
    Suit n_sut;
    while (std::getline(file, line))
    {
        
            istringstream iss(line);
            if (getline(iss,Suit_, ','))
            {
                getline(iss,rank_, ',');
            }
        n_sut = convertFromstring(Suit_);
        
        if (n_sut == Erro)
        {
            cout<<"ERRO SUIT"<<endl;
            return;
        }
        
        char* newString = new char[rank_.size()+1];
        if (newString == NULL)
        {
            cout<<"OUT OF MEMORY"<<endl;
            return;
        }
        strcpy(newString,rank_.c_str());
        Card* n_card = new Card(n_sut,newString);
        if (n_card == NULL)
        {
            cout<<"OUT OF MEMORY"<<endl;
            return;
        }
        
        this->ADDcard(n_card);
        delete []newString;
    }
    
    file.close();
}