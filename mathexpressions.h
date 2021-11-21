#ifndef MATHEXPRESSIONS_H
#define MATHEXPRESSIONS_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "reshtrigfunc.h"
#include "arifdeyst.h"
#include "procents.h"
#include "log.h"
#include "factorial.h"
#include "sqrt.h"
#include "pow.h"
#include <QString>

class MathExpressions
{
public:
    MathExpressions();
    void CalculateMathExp(std::string&);
    static void ReplacingSigns(QString&);

private:
    void OpeningBrackets(std::string& text, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    std::string ApplicationFuncCalc(std::string text);
    bool  getTextFromBrackets(std::string& text, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);


private:
    ReshTrigFunc trig;
    Procents Proc;
    ArifDeyst arif;
    Log log;
    Factorial factorial;
    Sqrt qsrt;
    Pow pow;
};

#endif // MATHEXPRESSIONS_H
