#ifndef PROCENTS_H
#define PROCENTS_H
#include "resheniy.h"

class Procents:public Resheniy
{
public:
   Procents();
    void CalculatePercent(std::string& text);
private:

    std::string resheniya(std::string& beginText, std::string& endText, std::string& Func);
    std::string resheniya2(std::string& Znach);
    double PlusProcentorv(double, double );
    double MinusProcentorv(double, double);
    double Procent(double);
};

#endif // PROCENTS_H
