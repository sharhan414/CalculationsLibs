#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "resh.h"
using namespace std;

int main()
{
string s="17+3*(6-2)+sin(30)+cos(60)";


 Resh resh;
 resh.resh(s);
 cout<<"Answer:"<<s<<endl;
    return 0;
}
