//! @Alan
//!
//! Exercise 7.31:
//! Define a pair of classes X and Y, in which X has a pointer to Y,
//! and Y has an object of type X.
//!


#include <iostream>
#include <string>


//!
//! @brief class declaration used for the pointer inside the definition body.
//!
class X;
class Y;

class X
{
    Y* p2y;
};

class Y
{
    X* p2x;
};



int main()
{


    return 0;
}

