#pragma once
#include <string>

class Storable
{

public:
    virtual void store(std::string file) = 0;
};




