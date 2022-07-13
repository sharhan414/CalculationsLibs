#ifndef RESHENIY_H
#define RESHENIY_H

#include <algorithm>

#include <string>
#include <cmath>
#include <iterator>

class MathExpFunction
{
public:
    enum class CalcFuncError
    {
        delNull,arcTrihFunc,notNatNumFactorial
    };
    MathExpFunction();
    bool isError()
    {
        return Error;
    }
    static constexpr  double Math_Pi=3.141592654;
    static std::string to_stdString(double);
    double stdString_toDouble(std::string strValues);

    template<class MathExp>
    static void replMathExp(MathExp &mathExp,MathExp Sign, MathExp newSign);//заменяет текст Sign из mathExp на newSign

protected:
    std::string SearchBeginText(std::string&,std::string::iterator&,std::string::iterator&) ;
    std::string SearchEndText(std::string&,std::string,std::string::iterator&,std::string::iterator&) ;
    bool Error=false;
    const std::string UserChars = "0123456789.";

};

#endif // RESHENIY_H
