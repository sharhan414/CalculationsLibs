#include "reshtrigfunc.h"
#include <vector>
#include <cmath>
#include <iostream>
ReshTrigFunc::ReshTrigFunc()
{
    Error=false;
}
void ReshTrigFunc::CalculateTrigFunc(std::string& text)
{
    trigonometr(text);
}
std::string ReshTrigFunc::resheniya(std::string& Funk, std::string& Value)
{   
    std::cout<<"++++++++111111:"<<Value<<std::endl;
    double DoubleVal=stdString_toDouble(Value),Answer=0;

    if(Error)
    {
        return std::string();
    }
std::cout<<"++++++2222222222"<<std::endl;
    double ugol=UgolToRadians(DoubleVal);
    if (Funk == "sin")
    {
        std::cout<<"++++++++++aaaaaa"<<std::endl;
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
        std::cout<<"1 asin("<<DoubleVal<<")"<<std::endl;
        if(DoubleVal>1 || DoubleVal<-1)
        {
            Error=true;
            return std::string();
        }
        std::cout<<"  asin("<<DoubleVal<<")"<<std::endl;
        Answer=std::asin(DoubleVal);
    }
    else if (Funk == "acos")
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            Error=true;
            return std::string();
        }

        Answer=std::acos(DoubleVal);
    }
    else if (Funk == "atag")
    {
        Answer=std::atan(DoubleVal);
    }
std::cout<<"3333333333"<<std::endl;
    return to_stdString(Answer);
}

double ReshTrigFunc::UgolToRadians(double & x)
{
    return x/(180/Pi);
}

void ReshTrigFunc::trigonometr(std::string& text)
{
    std::vector<std::string> tr_funcs{"asin","acos","atag","sin","cos","tag"};

    for (auto tr_func:tr_funcs)
    {

        auto it =text.begin();
        while ((it=search(it, text.end(), tr_func.begin(), tr_func.end()) )!= text.end())//в условии проверяется есть ли данная фун-я в выражении
        {

            std::cout<<"TEXT="<<text<<std::endl;
            auto endIt = it ;
            std::string EndText = SearchEndText(text,tr_func,it,endIt);
            std::cout<<"END TEXT="<<EndText<<std::endl;
            std::string Answer = resheniya(tr_func, EndText);

            if(Error)
            {
                return ;
            }

            text.erase(it, endIt);
            it=text.insert(it, Answer.begin(), Answer.end());
         }
     }
}
