#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "MathExpCalcLib/mathexpressions.h"


using namespace std;

int main()
{

    QString str="(-30+15)-6+sin(-30)";
    MathExpressions calc;


    MathExpressions::ReplacingSigns(str);
    string st=str.toStdString();
    cout<<"-------------"<<endl;
    calc.CalculateMathExp(st);
    cout<<"-------------"<<endl;
    cout<<"Answer:"<<st<<endl;



    return 0;
}
