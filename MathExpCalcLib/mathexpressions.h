#ifndef MATHEXPRESSIONS_H
#define MATHEXPRESSIONS_H

#include <string>
#include <iterator>
#include "reshtrigfunc.h"
#include "arithoperations.h"
#include "log.h"
#include "factorial.h"
#include "sqrt.h"
#include "pow.h"
#include <QString>
#include "calcpercents.h"
class MathExpressions
{
public:
    MathExpressions();
    void CalculateMathExp(std::string&);
    static void ReplacingSigns(QString&);

private:
    void OpeningBrackets(std::string& mathExp, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    std::string ApplicationFuncCalc(std::string mathExp);
    bool  getTextFromBrackets(std::string& mathExp, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    static void InsertNewSingExp(std::u16string& mathExp,std::u16string Sign,std::u16string newSign);

private:
    ReshTrigFunc calcTrigFunc;
    CalcPercents calcPercent;
    ArithOperations arithAct;
    Log log;
    Factorial factorial;
    Sqrt qsrt;
    Pow pow;

};

#endif // MATHEXPRESSIONS_H
