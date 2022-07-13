#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "MathExpCalcLib/mathexpressions.h"


using namespace std;

int main()
{

    QString str="asin(0.5)+5×(8-13)";
    MathExpressions calc;

cout<<"asin="<<std::asin(0.5)*(180/3.14159)<<std::endl;
    MathExpressions::ReplacingSigns(str);
    string st=str.toStdString();
    cout<<"-------------"<<endl;
    calc.CalculateMathExp(st);
    cout<<"-------------"<<endl;
    cout<<"Answer:"<<st<<endl;



    return 0;
}
