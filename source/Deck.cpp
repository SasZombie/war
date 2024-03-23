#pragma once
#include "Deck.hpp"
#include "DuplicateCardsException.hpp"


Deck::Deck(){}
Deck::Deck(std::vector<card> s) : cards(s){}

void Deck::removeTop()
{
    this->cards.pop_back();
}

void Deck::empty()
{
    this->cards.clear();
}

void Deck::addCard(card c)
{
    for(card card : this->cards)
        if(c.getRank() == card.getRank() && c.getSuit() == card.getSuit())
            throw DuplicateCardsException();
    
    this->cards.insert(this->cards.begin(), c);
}

void Deck::addCard(std::vector<card> c)
{
    for(card card1 : c){
        for(card card2 : this->cards)
            if(card1.getRank() == card2.getRank() && card1.getSuit() == card2.getSuit())
                throw DuplicateCardsException(); 
        this->cards.insert(this->cards.begin(), card1);
    }
}       

bool compareRank(card r, card l)
{
    return (r.getRank() < l.getRank());
}

bool compareSuit(card r, card l)
{
    return (r.getSuit() < l.getSuit());
}

void Deck::sortarea()
{

    std::sort(cards.begin(), cards.end(), compareRank);
    std::sort(cards.begin(), cards.end(), compareSuit);

}

void Deck::stergerea()
{
    this->cards.pop_back();
}

void Deck::display()
{
    for (card &i : cards)
    {
        std::cout<< i.getRank() << " " << i.getSuit()<<"\n";
    }
    
}

void Deck::store(std::string file)
{
    try
    {   
        std::ofstream g(file);
        for(card &i: cards)
            g<< i.getRank() << " " << i.getSuit()<<"\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int Deck::size()
{
    return this->cards.size();
}

bool Deck::isEmpty()
{
    if(this->cards.size() == 0)
        return true;
    return false;
}

card Deck::getCard(int i)
{
    return this->cards.at(i);
}

void Deck::shuffle()
{
    srand(time(NULL));
    for(int i = 0; i < cards.size()-1; i++)
        {
            int q = rand() % cards.size();
            
            card temp = this->cards.at(q);
            this->cards.at(q) = this->cards.at(i);
            this->cards.at(i) = temp;
        }
}