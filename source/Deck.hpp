#pragma once
#include "DuplicateCardsException.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "card.hpp"
#include "Storable.hpp"

class Deck : public Storable
{
private:
    std::vector<card> cards;
public:
    Deck();
    Deck(std::vector<card> cards);
    void empty();
    void addCard(card c);
    void addCard(std::vector<card> carduri);
    void sortarea();
    void stergerea();
    void display();
    void store(std::string s);
    int size();
    bool isEmpty();
    card getCard(int i);
    void shuffle();
    void removeTop();
};


