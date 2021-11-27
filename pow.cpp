#include "pow.h"
#include <iterator>

using namespace std;
Pow::Pow()
{

}

string Pow::resheniya(string& behinText,string& endText)
{

    double DBeginText=stdString_toDouble(behinText);//приобразем behinText в число
    double DEndText= stdString_toDouble(endText);//приобразем endText в число

    if(Error)
        return string();

    double DOtvet=pow(DBeginText,DEndText);

    return to_stdString(DOtvet);
}

void Pow::CalculatePow(string& text)
{
    string pow = "^";

    auto itBegin = text.end(), itEnd = text.end();
    auto it = text.begin();

    while ((it = search(it, text.end(), pow.begin(), pow.end())) != text.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(text,it,itBegin); // search begin text
        endText=SearchEndText(text,pow,it,itEnd);   // search end text

        string otvet = resheniya(beginText, endText);
        text.erase(itBegin, itEnd);
        it = text.insert(itBegin, otvet.begin(), otvet.end());      
    }
}

