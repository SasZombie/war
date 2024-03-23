#include "card.cpp"
#include "Deck.cpp"
#include "DuplicateCardsException.cpp"
#include <climits>
#include <map>

const int PLAYERS = 4, TOTALCARDS=52;
const int CARDS_PER_PLAYER = TOTALCARDS/PLAYERS;
int indexul = 0;

void add(Deck& a, Deck& b);
void makeMode(Deck& a1, Deck& a2, Deck& a3, Deck& a4);
Deck max(Deck& o1, Deck& o2);
void war(Deck& a1, Deck& a2, Deck& a3, Deck& a4);
int playGame(Deck& a1, Deck& a2, Deck& a3, Deck& a4);

std::ostream& operator<<(std::ostream& out, const card::Rank value)
{
    static std::map<card::Rank, std::string> strings;
    if (strings.size() == 0)
    {
#define INSERT_ELEMENT(p) strings[p] = #p
#define ONE card::ONE
#define TWO card::TWO
#define TREE card::TREE
#define FOUR card::FOUR
#define FIVE card::FIVE
#define SIX card::SIX
#define SEVEN card::SEVEN
#define EIGHT card::EIGHT
#define NINE card::NINE
#define TEN card::TEN
#define KNIGHT card::KNIGHT
#define ACE card::ACE
#define QUEEN card::QUEEN
#define KING card::KING

        INSERT_ELEMENT(ONE);     
        INSERT_ELEMENT(TWO);     
        INSERT_ELEMENT(TREE);     
        INSERT_ELEMENT(FOUR);  
        INSERT_ELEMENT(FIVE);     
        INSERT_ELEMENT(SIX);     
        INSERT_ELEMENT(SEVEN);     
        INSERT_ELEMENT(EIGHT);     
        INSERT_ELEMENT(NINE);
        INSERT_ELEMENT(TEN);
        INSERT_ELEMENT(ACE);
        INSERT_ELEMENT(KNIGHT);
        INSERT_ELEMENT(QUEEN);
        INSERT_ELEMENT(KING);  

#undef INSERT_ELEMENT
#undef ONE
#undef TWO
#undef TREE
#undef FOUR
#undef FIVE
#undef SIX
#undef SEVEN
#undef EIGHT
#undef NINE
#undef TEN
#undef ACE
#undef KNIGHT
#undef QUEEN
#undef KING
    }   

    return out << strings[value];
}

bool operator==(Deck value0, Deck value)
{
    if(value0.size() != value.size())
        return false;

    for(int i = 0; i < value.size() ;i++)
    {   
        if(value0.getCard(i).getRank() != value.getCard(i).getRank()  && value0.getCard(i).getSuit() != value.getCard(i).getSuit())
            return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const card::Suit value)
{
    static std::map<card::Suit, std::string> strings;
    if (strings.size() == 0)
    {
#define INSERT_ELEMENT(p) strings[p] = #p
#define SPADES card::SPADES
#define HEARTHS card::HEARTHS
#define DIAMONDS card::DIAOMONDS
#define CLUBS card::CLUBS

        INSERT_ELEMENT(SPADES);     
        INSERT_ELEMENT(HEARTHS);     
        INSERT_ELEMENT(DIAMONDS);     
        INSERT_ELEMENT(CLUBS);    
                   
#undef INSERT_ELEMENT
#undef SPARDES
#undef DIAMONDS
#undef CLUBS
#undef HEARTHS
    }   

    return out << strings[value];
}
int main()
{
    Deck deku;
    const int NR_OF_GAMES = 10;

    try
    {
        for(int i = 1; i <= 4;i++)
            for(int j = 1; j <=14;j++)
                deku.addCard(card((card::Rank)i,(card::Suit)j));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    Deck player1, player2, player3, player4;
    int max = INT_MIN, min = INT_MAX;

    
    
    
    try
        {
           for(int i = 0; i < NR_OF_GAMES;i++){
            
            deku.shuffle();

            add(player1, deku);
            add(player2, deku);
            add(player3, deku);
            add(player4, deku);

            int q = playGame(player1, player2, player3, player4);
            if(q < min)
                min =q;
            if(q > max)
                max = q; 
            
            indexul = 0;

            player1.empty();
            player2.empty();
            player3.empty();
            player4.empty();
        
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout<<'\n' << min << " " << max << " "<< (float)(min+max)/2;
}

void add(Deck& a, Deck& b)
{
    try
    {
        for(int i = 0; i < CARDS_PER_PLAYER; i++)
            a.addCard(b.getCard(i+indexul));
        indexul = indexul + CARDS_PER_PLAYER;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void makeMode(Deck& a1, Deck& a2, Deck& a3, Deck& a4)
{
    a1.addCard(a2.getCard(a2.size()-1));
    a1.addCard(a3.getCard(a3.size()-1));
    a1.addCard(a4.getCard(a4.size()-1));

    a2.removeTop();
    a3.removeTop();
    a4.removeTop();

}


Deck max(Deck& o1, Deck& o2)
{
    Deck o3;
    if(o1.isEmpty())
        return o2;
    if(o2.isEmpty())
        return o1;
    if(o1.getCard(o1.size()-1).getRank() == o2.getCard(o2.size()-1).getRank())
        return o3;
    if(o1.getCard(o1.size()-1).getRank() < o2.getCard(o2.size()-1).getRank())
        return o2;
    return o1;    
}

void war(Deck& a1, Deck& a2, Deck& a3, Deck& a4)
{
    std::vector<card> cardsToBeAdded;
    while (a1.size() != 0 && a2.size() != 0 && a3.size() != 0 && a4.size() != 0)
    {
        Deck temp = max(a1, a2);
        Deck temp1 = max(a3, temp);
        Deck temp2 = max(a3, temp1);
        
        cardsToBeAdded.push_back(a1.getCard(a1.size()-1));
        cardsToBeAdded.push_back(a2.getCard(a2.size()-1));
        cardsToBeAdded.push_back(a3.getCard(a3.size()-1));
        cardsToBeAdded.push_back(a4.getCard(a4.size()-1));
        
        a1.removeTop();
        a2.removeTop();
        a3.removeTop();
        a4.removeTop();

        if(!temp2.isEmpty())
        {
            if(temp2 == a1)
                a1.addCard(cardsToBeAdded);
            else if(temp2 == a2)
                a2.addCard(cardsToBeAdded);
            else if(temp2 == a3)
                a3.addCard(cardsToBeAdded);
            else
                a4.addCard(cardsToBeAdded);
            
            return;
        }

    }   
    
}


int playGame(Deck& a1, Deck& a2, Deck& a3, Deck& a4)
{

    int i = 0;
    while (a1.size() != 0 && a2.size() != 0 && a3.size() != 0 && a4.size() != 0)
    {
        std::cout<<"Player1 has " << a1.size() << " cards \n";
        std::cout<<"Player2 has " << a2.size() << " cards \n";
        std::cout<<"Player3 has " << a3.size() << " cards \n";
        std::cout<<"Player4 has " << a4.size() << " cards \n";
        std::cout<<"Next Round: \n";

        Deck temp = max(a1, a2);
        Deck temp1 = max(a3, temp);
        Deck temp2 = max(a3, temp1);
        
        if(temp2.size() == 0)
            war(a1, a2, a3, a4);
        else if(temp2 == a1)
            makeMode(a1, a2, a3, a4);
        else if(temp2 == a2)
            makeMode(a2, a1, a3, a4);
        else if(temp2 == a3)
            makeMode(a3, a1, a2, a4);
        else  
            makeMode(a4, a1, a2, a3);
        i++;

    }
    std::cout<< "The looser is: ";
    if(a1.size() == 0)
        std::cout<< "player1";
    else if(a2.size() == 0)
        std::cout<< "player2";
    else if(a3.size() == 0)
        std::cout<< "player3";
    else 
        std::cout<<"player4";
    std::cout<<'\n';
    return i;

}
