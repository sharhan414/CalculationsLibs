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
    std::string m_fLog="log";
    std::string m_fLn="ln";
};

#endif // LOG_H
