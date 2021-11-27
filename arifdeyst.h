#ifndef ARIFDEYST_H
#define ARIFDEYST_H

#include <vector>
#include <string>

class ArifDeyst
{
public:
    ArifDeyst();

    void arif_detstvie(double& otvet,std::string m);
private:
    void  ReshArifDeystUmnjAndDeln(std::vector<double>&, std::vector<char>&);//решаеть ариф.действия умножение и деление
    double ReshArifDeystPlusAndMinus(std::vector<double>&, std::vector<char>& );
    void getArifSignsForExp(std::string &text,std::vector<char>& ArithmeticSigns);
    void getValuesForExp(std::string &text,std::vector<std::string>& ValuesForExp);
    void getDatesForExp(std::string& text,std::vector<std::string>& ValuesForExp,std::vector<char>& ArithmeticSigns);

};

#endif // ARIFDEYST_H
