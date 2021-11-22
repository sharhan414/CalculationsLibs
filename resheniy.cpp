#include "resheniy.h"
#include <QString>
using namespace std;
Resheniy::Resheniy()
{

}

string Resheniy::to_stdString(double values)
{
    return QString::number(values).toStdString();
}

double Resheniy::stdString_toDouble(string strValues)
{
  QString str=QString::fromStdString(strValues);
  return str.toDouble();
}

std::string Resheniy::SearchBeginText(string& text,string::iterator& it,string::iterator& itBegin)
{
    auto k = it;
    do {////////begin text
        --k;
        if (find(UserChars.begin(), UserChars.end(), *k) == UserChars.end()) {
            string Textproc(k + 1, it);
            itBegin = k + 1;
            return Textproc;

        }
        else if (k == text.begin()) {
            string Textproc(k, it);
            itBegin = k;
            return Textproc;

        }

    } while (k != text.begin());
}

string Resheniy::SearchEndText(string & text,string funk,string::iterator &it, string::iterator &itEnd)
{

     for (auto i = it + int(funk.size()); i != text.end(); ++i) {
         if (find(UserChars.begin(), UserChars.end(), *i) == UserChars.end()) {
             string Textproc(it + int64_t(funk.size()), i);
             itEnd = i;
             return Textproc;

             }
         else if (i == text.end() - 1) {
             string Textproc(it + int64_t(funk.size()), i + 1);
             itEnd = i + 1;
             return Textproc;

         }
     }

}

