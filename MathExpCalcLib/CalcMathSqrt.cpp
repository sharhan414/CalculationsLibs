#include "CalcMathSqrt.h"

using namespace std;
CalcMathSqrt::CalcMathSqrt()
{

}

void CalcMathSqrt::CalculateSqrt(string& mathExp)
{
    CalculateNSqtn(mathExp);
    Calculate2Sqrt(mathExp);
}

void CalcMathSqrt::CalculateNSqtn(string& mathExp){

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it =mathExp.begin();

    while ((it=search(it, mathExp.end(), m_nSqrt.begin(), m_nSqrt.end())) != mathExp.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(mathExp,it,itBegin); // search begin text
        endText=SearchEndText(mathExp,m_nSqrt,it,itEnd);   // search end text
        string otvet = resheniya(beginText, endText);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}
void CalcMathSqrt::Calculate2Sqrt(string& mathExp)
{
    auto it = search(mathExp.begin(), mathExp.end(), m_Sqrt.begin(), m_Sqrt.end());

    while (it != mathExp.end())
    {
        auto endIt = it;
        string strValue = SearchEndText(mathExp,m_Sqrt,it,endIt);
        string Answer = getMathSqrtAnswer(strValue);
        it=mathExp.erase(it,it+m_Sqrt.size()+strValue.size());
        it=mathExp.insert(it,Answer.begin(),Answer.end());
        it = search(mathExp.begin(), mathExp.end(), m_Sqrt.begin(), m_Sqrt.end());
    }
}
string CalcMathSqrt::getMathSqrtAnswer(string& strValue)
{
    double Value=stdString_toDouble(strValue);
    double AnswerVal=sqrt(Value);
    return to_stdString(AnswerVal);
}

string CalcMathSqrt::resheniya(string& beginText, string& endText)
{
    if(beginText.empty())
    {
        m_Error=true;
        return string();
    }

    double DBeginValue=stdString_toDouble(beginText);
    double DEndValue=stdString_toDouble(endText);
    double D_Answer=nsqrt(DEndValue,DBeginValue);

    return to_stdString(D_Answer);
}
