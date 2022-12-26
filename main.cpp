#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "MathExpCalcLib/mathexpressions.h"

using namespace std;

int main()
{
    cout.precision(17);
//1,1857777*10-6
    QString str="(6.67*10^-11*80000*45000)/450^2";

    cout<<(6.67*std::pow(10,-11)*80000*45000)/(std::pow(450,2))<<endl;
    //QString str="(1.3473*6.4356)";
    MathExpressions calc;

    //cout<<"asin="<<std::asin(0.5)*(180/3.14159)-25<<std::endl;
    MathExpressions::ReplacingSigns(str);
    string st=str.toStdString();
    cout<<"-------------"<<endl;
    calc.CalculateMathExp(st);
    cout<<"-------------"<<endl;
    cout<<"Answer:"<<st<<endl;



    return 0;
}
