#ifndef RESHENIY_H
#define RESHENIY_H

#include <algorithm>

#include <string>
#include <cmath>
#include <iterator>

class Resheniy
{
public:
    enum class CalcFuncError
    {
    delNull,arcTrihFunc,notNatNumFactorial
    };
    Resheniy();
    bool isError()
    {
        return Error;
    }
    const  double Math_Pi=3.141592654;
    static std::string to_stdString(double);
    double stdString_toDouble(std::string strValues);
    template<class Str>
    void InsertNewSingExp(Str &mathExp,Str Sign, Str newSign);

protected:
    std::string SearchBeginText(std::string&,std::string::iterator&,std::string::iterator&) ;
    std::string SearchEndText(std::string&,std::string,std::string::iterator&,std::string::iterator&) ;
    bool Error=false;
    const std::string UserChars = "0123456789.";

};

#endif // RESHENIY_H
