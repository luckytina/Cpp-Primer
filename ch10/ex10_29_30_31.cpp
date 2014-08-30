//! @Alan
//!
//! Exercise 10.29:
//! Write a program using stream iterators to read a text file into a vector of strings.
//!
//! Exercise 10.30:
//! Use stream iterators, sort, and copy to read a sequence of integers from the standard
//! input, sort them, and then write them back to the standard output.
//!
//! Exercise 10.31:
//! Update the program from the previous exercise so that it prints only the unique elements.
//! Your program should use unqiue_copy (§ 10.4.1, p. 403).
//!

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

//! Exercise 10.29
void
write2vecStr(const std::string &s, std::vector<std::string> &v);

//! Excercise 10.30
void
input2output(std::istream &is, std::ostream &os);

//! Excercise 10.31
void input2output_unique(std::istream &is, std::ostream &os);
int main()
{
    //! test for ex10.29
    std::vector<std::string> v;
    write2vecStr("test.txt",v);

    std::ostream_iterator<std::string> fout_iter(std::cout);
    for(auto e :v)
        *fout_iter++ = e;
    std::cout << "\n=================\n";

    //! test for ex10.30
    input2output(std::cin,std::cout);
    std::cout << "\n=================\n";

    //! test for ex10.31
    input2output_unique(std::cin, std::cout);
    std::cout << "\n=================\n";
    return 0;
}

//! Exercise 10.29
void
write2vecStr(const std::string &s, std::vector<std::string> &v)
{
    std::ifstream fin(s);
    std::istream_iterator<std::string> fin_iter(fin),   eof;
    while(fin_iter != eof)
    {
        v.push_back(*fin_iter++);
    }
}

//! Exercise 10.30
//! read a sequence of integers from the standard
//! input, sort them, and then write them back to the standard output.
void input2output(std::istream &is, std::ostream &os)
{
    std::istream_iterator<int>  sin(is),  eof;
    std::vector<int>    v;
    //! read into vector
    while(sin != eof && *sin != 999)    v.push_back(*sin++);
    //! sort it
    std::sort(v.begin(), v.end());

    std::ostream_iterator<int> sout(os,"\n");
    std::copy(v.begin(), v.end(), *sout++);
}

//! Excercise 10.31
void input2output_unique(std::istream &is, std::ostream &os)
{
    std::istream_iterator<int>  sin(is),  eof;
    std::vector<int>    v;

    //! read into vector
    while(sin != eof && *sin != 999)
        v.push_back(*sin++);

    //! sort it
    std::sort(v.begin(), v.end());

    //! write into output
    std::ostream_iterator<int>  sout(os,"\n");
    std::unique_copy(v.begin(), v.end(), *sout++);
}

