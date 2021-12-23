#ifndef PROCENTS_H
#define PROCENTS_H
#include "resheniy.h"

class Procents:public Resheniy
{
public:
   Procents();
    void CalculatePercent(std::string& text);
private:

    std::string CalcPercentsFroExp(std::string& beginText, std::string& endText, std::string& Func);
    std::string getOnePercent(std::string& Value);
    double PlusPercens(double, double );
    double MinusPercens(double, double);
    double Percent(double);
};

#endif // PROCENTS_H
