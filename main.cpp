#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
//#include "mathexpressions.h"

#include "calcpercents.h"
//#include "procents.h"
using namespace std;

int main()
{
/*    string s="2*(-2*(6-9))*(-1)";



    QString str="12×3-34÷2+3+√(64)+sin(30)+5!";
    MathExpressions calc;
    /*
    MathExpressions::ReplacingSigns(str);
    string st=str.toStdString();
    cout<<"st:"<<st<<endl;

    cout<<"-------------"<<endl;
    calc.CalculateMathExp(s);
    cout<<"-------------"<<endl;
    cout<<"Answer:"<<s<<endl;
*/

    string percent="100+%26";


  CalcPercents cl;
  cl.CalculatePercent(percent);
  cout<<"Percent:"<<percent<<endl;



    return 0;
}
