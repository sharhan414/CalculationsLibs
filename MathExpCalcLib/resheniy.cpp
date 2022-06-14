#include "resheniy.h"
#include <QString>
#include <iostream>
using namespace std;
Resheniy::Resheniy()
{
Error=false;
}

string Resheniy::to_stdString(double values)
{

    return QString::number(values).toStdString();
}

double Resheniy::stdString_toDouble(string strValues)
{
    cout<<"std="<<strValues<<endl;
    QString QStrVal=QString::fromStdString(strValues);
    auto answer=QStrVal.toDouble(&Error);
    Error= !Error;
    return answer;
}

std::string Resheniy::SearchBeginText(string& mathExp,string::iterator& it,string::iterator& itBegin)
{
    auto k = it;
    do {////////begin text
        --k;
        if (find(UserChars.begin(), UserChars.end(), *k) == UserChars.end())
        {
            string Textproc(k + 1, it);
            itBegin = k + 1;
            return Textproc;

        }
        else if (k == mathExp.begin())
        {
            string Textproc(k, it);
            itBegin = k;
            return Textproc;

        }

    } while (k != mathExp.begin());
}

string Resheniy::SearchEndText(string & mathExp,string funk,string::iterator &it, string::iterator &itEnd)
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


template<class Str>
void Resheniy::InsertNewSingExp(Str &mathExp, Str Sign,Str newSign)
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
