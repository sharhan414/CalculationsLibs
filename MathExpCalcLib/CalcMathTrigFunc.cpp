#include "CalcMathTrigFunc.h"
#include <vector>
#include <cmath>
#include <iostream>
CalcMathTrigFunc::CalcMathTrigFunc()
{
    Error=false;
}
void CalcMathTrigFunc::CalculateTrigFunc(std::string& text)
{
    trigonometr(text);
}
std::string CalcMathTrigFunc::resheniya(std::string& Funk, std::string& Value)
{   
    double DoubleVal=stdString_toDouble(Value),Answer=0;

    if(Error)
    {
        return std::string();
    }
    double ugol=angleToRadians(DoubleVal);
    if (Funk == "sin")
    {
        Answer=std::sin(ugol);
    }
    else if (Funk == "cos")
    {
        Answer=cos(ugol);
    }
    else if (Funk == "tag")
    {
        Answer=std::tan(ugol);
    }

    if (Funk == "asin")
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            Error=true;
            return std::string();
        }
        Answer=std::asin(DoubleVal)*(180/Math_Pi);    
    }
    else if (Funk == "acos")
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            Error=true;
            return std::string();
        }

        Answer=std::acos(DoubleVal)*(180/Math_Pi);
    }
    else if (Funk == "atag")
    {
        Answer=std::atan(DoubleVal)*(180/Math_Pi);
    }

    return to_stdString(Answer);
}

double CalcMathTrigFunc::angleToRadians(double & x)
{
    return x/(180/Math_Pi);
}

void CalcMathTrigFunc::trigonometr(std::string& mathExp)
{
    std::vector<std::string> tr_funcs{"asin","acos","atag","sin","cos","tag"};

    for (auto tr_func:tr_funcs)
    {

        auto it =mathExp.begin();
        while ((it=search(it, mathExp.end(), tr_func.begin(), tr_func.end()) )!= mathExp.end())//в условии проверяется есть ли данная фун-я в выражении
        {
            auto endIt = it ;
            std::string EndText = SearchEndText(mathExp,tr_func,it,endIt);

            std::string Answer = resheniya(tr_func, EndText);

            if(Error)
            {
                return ;
            }

            mathExp.erase(it, endIt);
            it=mathExp.insert(it, Answer.begin(), Answer.end());
         }
     }
}
