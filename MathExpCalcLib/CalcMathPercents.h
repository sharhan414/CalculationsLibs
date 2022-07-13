#ifndef CALCPERCENTS_H
#define CALCPERCENTS_H
#include "MathExpFunction.h"

class CalcMathPercents:public MathExpFunction
{
public:
   CalcMathPercents();
    void CalculatePercent(std::string& text);
private:

    std::string CalcPercentsByValues(std::string& beginStrValues, std::string& endStrValues, std::string& Func);
    std::string getOnePercent(std::string& Value);
    double PlusPercens(double, double );
    double MinusPercens(double, double);
    double Percent(double);
    void CalcPercentsFroExp(std::string& mathExp, std::string percentType);
};

#endif // CALCPERCENTS_H
