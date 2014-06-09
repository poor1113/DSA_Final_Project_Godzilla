/* DSA Final Proj non-class functions : func.cpp */

#include "headers.h"
#include "func.h"
using namespace std;

/* 

The Following two functions are from 
http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string 
*/


string trim(const string& str,
                 const string& whitespace )
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

string reduce(const string& str,
                   const string& fill ,
                   const string& whitespace )
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}