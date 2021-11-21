#include "sqrt.h"
#include <vector>
using namespace std;
Sqrt::Sqrt()
{

}

void Sqrt::CalculateSqrt(string& text)
{
    CalculateNSqtn(text);
    Calculate2Sqrt(text);
}

void Sqrt::CalculateNSqtn(string& text){
    string nsqrn = "nsqrt";

    auto itBegin = text.end(), itEnd = text.end();
    auto it =text.begin();

    while ((it=search(it, text.end(), nsqrn.begin(), nsqrn.end())) != text.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(text,it,itBegin); // search begin text
        endText=SearchEndText(text,nsqrn,it,itEnd);   // search end text
        string otvet = resheniya(beginText, endText);
        text.erase(itBegin, itEnd);
        it = text.insert(itBegin, otvet.begin(), otvet.end());
    }
}
void Sqrt::Calculate2Sqrt(string& text)
{
    string Sqrt = "sqrt";
    auto it = search(text.begin(), text.end(), Sqrt.begin(), Sqrt.end());

    while (it != text.end())
    {
        auto endIt = it;
        string funkZnachenie = SearchEndText(text,Sqrt,it,endIt);
        string otvet = resheniya(Sqrt, funkZnachenie);
        it = search(it, text.end(), Sqrt.begin(), Sqrt.end());
    }
}
string Sqrt::resheniya(string& text)
{

    double DText=atoi(text.c_str());
    double DOtvet=sqrt(DText);
    return to_stdString(DOtvet);
}

string Sqrt::resheniya(string& behinText, string& endText)
{

    if(behinText.empty())
    {
        error=false;
        return string();
    }
    string otvet;

    double DBeginText=stdString_toDouble(behinText);
    double DEndText=stdString_toDouble(endText);
    double DOtvet=nsqrt(DEndText,DBeginText);

    return to_stdString(DOtvet);
}
