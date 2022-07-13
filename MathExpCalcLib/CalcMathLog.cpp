#include "CalcMathLog.h"
#include <cmath>
#include <vector>
using namespace  std;
CalcMathLog::CalcMathLog()
{

}

void CalcMathLog::CalculatehLog(string& mathExp)
{
    vector<string> v{"ln","log"};

    for (vector<string>::size_type j = 0; j != v.size(); ++j)
    {
        auto  itEnd = mathExp.end();
        auto it =mathExp.begin();

        while ((it= search(it, mathExp.end(), v[j].begin(), v[j].end()) )!= mathExp.end())
        {
            string endText=SearchEndText(mathExp,v[j],it,itEnd);
            string otvet = resheniya(endText, v[j]);
            if(Error)
                return;
            mathExp.erase(it, itEnd);
            it = mathExp.insert(it, otvet.begin(), otvet.end());
        }
    }
}

string CalcMathLog::resheniya(string& Value,string& Func)
{

   int value=int(stdString_toDouble(Value.c_str()));
    if(Error)
    {
        return string();
    }

    double y{0};
    if(Func=="log")
    {
        y=log10(value)   ;
    }
    if(Func=="ln")
    {
        y=log(value);
    }

    return to_stdString(y);
}
