#include "CalcMathPercents.h"
#include <iostream>
using namespace std;
CalcMathPercents::CalcMathPercents()
{

}


string CalcMathPercents::getOnePercent(string& strValue)
{

    double x=stdString_toDouble(strValue) ;//  text.toDouble(&error);
    x=Percent(x);
    return to_stdString(x);
}
double CalcMathPercents::PlusPercens(double Value, double Percents)
{
    Percents /= 100;
    Percents += 1;
    Value *= Percents;
    return Value;
}
double CalcMathPercents::MinusPercens(double Value, double Percents)
{
    Percents /= 100;
    Percents = 1 - Percents;
    Value *= Percents;
    return Value;
}

double CalcMathPercents::Percent(double x)
{
    return x/100;
}

void CalcMathPercents::CalcPercentsFroExp(string &mathExp,string percentType)
{

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it = mathExp.begin();

    while ((it = search(it, mathExp.end(), percentType.begin(), percentType.end())) != mathExp.end())
    {
        string beginStrValue, endStrValue;

        beginStrValue=SearchBeginText(mathExp,it,itBegin); //begin text

        if(percentType=="%")
        {
            string otvet = getOnePercent(beginStrValue);
            mathExp.erase(itBegin, it+1);
            it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
            continue;
        }

        endStrValue=SearchEndText(mathExp,percentType,it,itEnd);  //end text

        string strAnswer = CalcPercentsByValues(beginStrValue, endStrValue, percentType);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, strAnswer.begin(), strAnswer.end());

    }
}

string CalcMathPercents::CalcPercentsByValues(string& strValue, string& strPercents, string& Func)
{
    double Value=stdString_toDouble(strValue) ;//BeginZnach.toDouble(&error);
    double Percents=stdString_toDouble(strPercents) ;
    if(!Error)
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

void CalcMathPercents::CalculatePercent(string& mathExp)
{
    CalcPercentsFroExp(mathExp,"+%");
    CalcPercentsFroExp(mathExp,"-%");
    CalcPercentsFroExp(mathExp,"%");
}
