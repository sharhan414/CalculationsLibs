#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "mathexpressions.h"

#include "calcpercents.h"

using namespace std;

int main()
{

    QString str="sin(-30)";
    MathExpressions calc;


    MathExpressions::ReplacingSigns(str);
    string st=str.toStdString();
    cout<<"-------------"<<endl;
    calc.CalculateMathExp(st);
    cout<<"-------------"<<endl;
    cout<<"Answer:"<<st<<endl;



    return 0;
}
