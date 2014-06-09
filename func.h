/* DSA Final Proj non-class functions : func.h */
using namespace std;

#ifndef TRIM_REDUCE
#define TRIM_REDUCE
string trim(const string& str,
                 const string& whitespace = " \t");

string reduce(const string& str,
                   const string& fill = " ",
                   const string& whitespace = " \t");
#endif