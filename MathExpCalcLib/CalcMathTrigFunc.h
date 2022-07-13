#ifndef RESHTRIGFUNC_H
#define RESHTRIGFUNC_H
#include "MathExpFunction.h"
/*

ReshTrigFunc- класс для вычисления тригонометрических фунций из математического выражения.







  */
class CalcMathTrigFunc:public MathExpFunction
{
public:

    CalcMathTrigFunc();
    void CalculateTrigFunc(std::string& mathExp);
    std::string resheniya(std::string&, std::string&);
//СalcTrigonometricFunc
private:
    double angleToRadians(double&);
    void trigonometr(std::string& mathExp);
};

#endif // RESHTRIGFUNC_H
