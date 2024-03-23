#include "DuplicateCardsException.hpp"

char* DuplicateCardsException ::what(){
    return "Cards cannot have duplicates";
}