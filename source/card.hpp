#pragma once

struct card{
   
    enum Rank{
        ONE = 1, TWO, TREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ACE, KNIGHT, QUEEN, KING
    };

    enum Suit{
        CLUBS = 1, DIAOMONDS, HEARTHS, SPADES
    };
    
    Rank r;
    Suit s;
    card(Rank rank, Suit suit);
    Rank getRank();
    Suit getSuit();
};

