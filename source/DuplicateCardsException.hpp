#pragma once

#include <stdexcept>

class DuplicateCardsException : std::exception 
{

public:
    char * what();   
};