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
    void raspredDeystAndValues(std::vector<std::string>&,std::vector<char>&,std::string&);
    void  ReshArifDeystUmnjAndDeln(std::vector<double>&, std::vector<char>&);//решаеть ариф.действия умножение и деление
    double ReshArifDeystPlusAndMinus(std::vector<double>&, std::vector<char>& );
};

#endif // ARIFDEYST_H
