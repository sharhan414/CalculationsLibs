#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "mathexpressions.h"

#include "calcpercents.h"

using namespace std;

int main()
{
    string s="2*(-2*(6-9))*(-1)";



    QString str="12×3-34÷2+3+√(64)+sin(30)+5!";
    MathExpressions calc;

    MathExpressions::ReplacingSigns(str);
    string st=str.toStdString();
    cout<<"st:"<<st<<endl;

    cout<<"-------------"<<endl;
    calc.CalculateMathExp(st);
    cout<<"-------------"<<endl;
    cout<<"Answer:"<<st<<endl;




    return 0;
}
