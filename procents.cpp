#include "procents.h"
#include <vector>
using namespace std;
Procents::Procents()
{

}
string Procents::getOnePercent(string& Value)
{

    double x=stdString_toDouble(Value) ;//  text.toDouble(&error);
    x=Percent(x);
    return to_stdString(x);
}
double Procents::PlusPercens(double Value, double Percents)
{
    Percents /= 100;
    Percents += 1;
    Value *= Percents;
    return Value;
}
double Procents::MinusPercens(double Value, double Percents)
{
    Percents /= 100;
    Percents = 1 - Percents;
    Value *= Percents;
    return Value;
}

double Procents::Percent(double x)
{
    return x/100;
}

string Procents::CalcPercentsFroExp(string& strValue, string& strPercents, string& Func)
{

    double Value=stdString_toDouble(strValue) ;//BeginZnach.toDouble(&error);
    double Percents=stdString_toDouble(strPercents) ;

    if(Error)
    {
        return string();
    }
    double Answer=0;
    if(Func=="+%")
    {
        Answer= PlusPercens(Value,Percents);
            }
    if(Func == string("-%"))
    {
        Answer= MinusPercens(Value,Percents);
    }

    return  to_stdString(Answer);
}

void Procents::CalculatePercent(string& text)
{

    vector<string> TypesPercents{"+%","-%","%"};
    for(auto percent:TypesPercents)
    {
        auto itBegin = text.end(), itEnd = text.end();
        auto it = text.begin();

        while ((it = search(it, text.end(), percent, percent)) != text.end())
        {
            string beginStrValue, endStrValue;

            beginStrValue=SearchBeginText(text,it,itBegin); //begin text
            if(percent=="%")
            {
                string otvet = getOnePercent(beginStrValue);
                text.erase(itBegin, it+1);
                it = text.insert(itBegin, otvet.begin(), otvet.end());
                continue;
            }

            endStrValue=SearchEndText(text,percent,it,itEnd);  //end text

            string otvet = CalcPercentsFroExp(beginStrValue, endStrValue, percent);
            text.erase(itBegin, itEnd);
            it = text.insert(itBegin, otvet.begin(), otvet.end());
        }
    }
}
