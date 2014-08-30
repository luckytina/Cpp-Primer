/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       20  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.38:
//! Write a class that tests whether the length of a given string matches a
//! given bound. Use that object to write a program to report how many words
//! in an input file are of sizes 1 through 10 inclusive.
//!
//! Exercise 14.39:
//! Revise the previous program to report the count of words that are sizes
//! 1 through 9 and 10 or more.
//! 	
//! Exercise 14.41:
//! Why do you suppose the new standard added lambdas? Explain when you would
//! use a lambda and when you would write a class instead.
//  IMO, lambda is quite handy to use. Lambda can be used when the functor is 
//  not used frequently nor complicated, whereas functor is supposed to call
//  more times than lambda or quite complicated to implement as a lambda.	
//! 	

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class BoundTest
{
public:
    BoundTest(std::size_t l = 0, std::size_t u = 0) :
        lower(l), upper(u)
    {}

    bool operator() (const std::string& s)
    { return s.length() >= lower && s.length() <= upper ;}

private:
    std::size_t lower;
    std::size_t upper;
};


int main()
{
    std::size_t l = 2;
    std::size_t u = 3;

    std::ifstream fin ("s.txt");
    std::string word;
    std::size_t quantity = 0;
    BoundTest test(l, u);

    while(fin >> word)
        if (test(word)) ++quantity;

    std::cout << quantity << "\n";
    return 0;
}







