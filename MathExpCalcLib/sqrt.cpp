#include "sqrt.h"

using namespace std;
Sqrt::Sqrt()
{

}

void Sqrt::CalculateSqrt(string& mathExp)
{
    CalculateNSqtn(mathExp);
    Calculate2Sqrt(mathExp);
}

void Sqrt::CalculateNSqtn(string& mathExp){
    string nsqrn = "nsqrt";

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it =mathExp.begin();

    while ((it=search(it, mathExp.end(), nsqrn.begin(), nsqrn.end())) != mathExp.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(mathExp,it,itBegin); // search begin text
        endText=SearchEndText(mathExp,nsqrn,it,itEnd);   // search end text
        string otvet = resheniya(beginText, endText);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}
void Sqrt::Calculate2Sqrt(string& mathExp)
{
    string Sqrt = "sqrt";
    auto it = search(mathExp.begin(), mathExp.end(), Sqrt.begin(), Sqrt.end());

    while (it != mathExp.end())
    {
        auto endIt = it;
        string strValue = SearchEndText(mathExp,Sqrt,it,endIt);
        string Answer = getMathSqrtAnswer(strValue);
        it=mathExp.erase(it,it+Sqrt.size()+strValue.size());
        it=mathExp.insert(it,Answer.begin(),Answer.end());
        it = search(mathExp.begin(), mathExp.end(), Sqrt.begin(), Sqrt.end());
    }
}
string Sqrt::getMathSqrtAnswer(string& strValue)
{
    double Value=stdString_toDouble(strValue);
    double AnswerVal=sqrt(Value);
    return to_stdString(AnswerVal);
}

string Sqrt::resheniya(string& beginText, string& endText)
{
    if(beginText.empty())
    {
        Error=true;
        return string();
    }

    double DBeginValue=stdString_toDouble(beginText);
    double DEndValue=stdString_toDouble(endText);
    double D_Answer=nsqrt(DEndValue,DBeginValue);

    return to_stdString(D_Answer);
}
