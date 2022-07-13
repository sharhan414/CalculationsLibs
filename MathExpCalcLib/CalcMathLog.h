#ifndef LOG_H
#define LOG_H
#include "MathExpFunction.h"

class CalcMathLog:public MathExpFunction
{
public:
    CalcMathLog();

void CalculatehLog(std::string& mathExp);
private:
    std::string resheniya(std::string&,std::string&);
};

#endif // LOG_H
