#include "MathExpFunction.h"
#include <QString>
#include <iostream>
using namespace std;
MathExpFunction::MathExpFunction()
{
    Error=false;
}

string MathExpFunction::to_stdString(double values)
{

    return QString::number(values).toStdString();
}

double MathExpFunction::stdString_toDouble(string strValues)
{

    QString QStrVal=QString::fromStdString(strValues);
    auto answer=QStrVal.toDouble(&Error);
    Error= !Error;
    return answer;
}

std::string MathExpFunction::SearchBeginText(string& mathExp,string::iterator& it,string::iterator& itBegin)
{
    auto n_it = it;
    do {////////begin text
        --n_it;
        if (find(UserChars.begin(), UserChars.end(), *n_it) == UserChars.end())
        {
            string Textproc(n_it + 1, it);
            itBegin = n_it + 1;
            return Textproc;

        }
        else if (n_it == mathExp.begin())
        {
            string Textproc(n_it, it);
            itBegin = n_it;
            return Textproc;

        }

    } while (n_it != mathExp.begin());
}

string MathExpFunction::SearchEndText(string & mathExp,string funk,string::iterator &it, string::iterator &itEnd)
{

    for (auto i = it + int(funk.size()); i != mathExp.end(); ++i)
    {
        if(*(it+ int(funk.size()))=='-')//если после фун-и стоить знак -, то его включаем а значение
        {
             i++;
        }
        if (find(UserChars.begin(), UserChars.end(), *i) == UserChars.end())
        {
            string Textproc(it + int64_t(funk.size()), i);
            itEnd = i;
            return Textproc;
        }
        else if (i == mathExp.end() - 1)
        {
            string Textproc(it + int64_t(funk.size()), i + 1);
            itEnd = i + 1;
            return Textproc;
        }
    }
}


template<class MathExp>
void MathExpFunction::replMathExp(MathExp &mathExp, MathExp Sign,MathExp newSign)
{

    auto iter=mathExp.begin();
    while(iter!=mathExp.end())
    {

        iter=search(iter,mathExp.end(),Sign.begin(),Sign.end());
        if(iter==mathExp.end())
        {
            break;
        }
        iter=mathExp.erase(iter,iter+Sign.size());
        iter=mathExp.insert(iter,newSign.begin(),newSign.end());
    }
}
