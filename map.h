#pragma once
#include "square.h"
using namespace std;

class map {
public:
    map(); //default constructor
    ~map(); //destructor
    square* getSector(int index);
    //return the square of index
private:
    square sector[9]; //3x3 grid
};