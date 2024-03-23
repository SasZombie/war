#include "card.hpp"

card::card(Rank rank, Suit suit) : r(rank), s (suit){}

card::Rank card::getRank()
{
    return this->r;
}

card::Suit card::getSuit()
{
    return this->s;
}