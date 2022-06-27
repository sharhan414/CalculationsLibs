#ifndef ARITHOPERATIONS_H
#define ARITHOPERATIONS_H
#include <vector>
#include <string>
#include "resheniy.h"

class ArithOperations:public Resheniy
{
public:
    ArithOperations();

    void arif_detstvie(double& otvet,std::string m);
private:
    void  CalcArithExpMultAndDiv(std::vector<double>&, std::vector<char>&);//решаеть ариф.действия умножение и деление
    double CalcArithExpPlusAndMinus(std::vector<double>&, std::vector<char>& );
    void getArifSignsForExp(std::string &mathExp,std::vector<char>& ArithmeticSigns);
    void getValuesForExp(std::string &mathExp,std::vector<std::string>& ValuesForExp);
    void getDatesForExp(std::string& mathExp,std::vector<std::string>& ValuesForExp,std::vector<char>& ArithmeticSigns);

};

#endif // ARITHOPERATIONS_H
