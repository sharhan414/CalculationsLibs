#include "CalcMathFactorial.h"
using namespace std;
CalcMathFactorial::CalcMathFactorial()
{

}
void CalcMathFactorial::CalculateFactorial(string& mathExp)
{
    string factorials = "!";
    auto itBegin = mathExp.end();
    auto it = mathExp.begin();

    while ((it= search(it, mathExp.end(), factorials.begin(), factorials.end())) != mathExp.end())
    {
        string beginText=SearchBeginText(mathExp,it,itBegin);
        string otvet = resheniya(beginText);
        mathExp.erase(itBegin, it+1);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}
string CalcMathFactorial::resheniya(string& Znachenie)
{    
    int value= atoi(Znachenie.c_str());//QStrText.toInt(&error);
    int fact=factorial(value);
    return to_stdString(fact);
}
