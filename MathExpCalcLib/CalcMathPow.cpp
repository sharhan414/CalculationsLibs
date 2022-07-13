#include "CalcMathPow.h"
#include <iterator>

using namespace std;
CalcMathPow::CalcMathPow()
{

}

string CalcMathPow::resheniya(string& StrBeginValue,string& StrEndValue)
{

    double DBeginValue=stdString_toDouble(StrBeginValue);//приобразем behinText в число
    double DEndValue= stdString_toDouble(StrEndValue);//приобразем endText в число

    if(Error)
        return string();

    double DOtvet=pow(DBeginValue,DEndValue);

    return to_stdString(DOtvet);
}

void CalcMathPow::CalculatePow(string& mathExp)
{
    string pow = "^";

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it = mathExp.begin();

    while ((it = search(it, mathExp.end(), pow.begin(), pow.end())) != mathExp.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(mathExp,it,itBegin); // search begin text
        endText=SearchEndText(mathExp,pow,it,itEnd);   // search end text

        string otvet = resheniya(beginText, endText);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}

