#include "procents.h"
#include <vector>
using namespace std;
Procents::Procents()
{

}
string Procents::resheniya2(string& Value) {

    double x=stdString_toDouble(Value) ;//  text.toDouble(&error);
    x=Procent(x);
    return to_stdString(x);
}
double Procents::PlusProcentorv(double d, double x)
{
    x /= 100;
    x += 1;
    d *= x;
    return d;
}
double Procents::MinusProcentorv(double d, double x)
{
    x /= 100;
    x = 1 - x;
    d *= x;
    return d;
}

double Procents::Procent(double x)
{
    return x/100;
}

string Procents::resheniya(string& beginText, string& endText, string& Func) {

    double x=stdString_toDouble(beginText) ;//BeginZnach.toDouble(&error);
    double y=stdString_toDouble(endText) ;

    if(!error){
        return string();
    }
    double otvet_d{0};
    if(Func=="+%"){
        otvet_d= PlusProcentorv(x,y);
            }
    if(Func == string("-%")){
        otvet_d= MinusProcentorv(x,y);
    }

    return  to_stdString(otvet_d);
}

void Procents::CalculatePercent(string& text) {

    vector<string> v{"+%","-%","%"};
    for (vector<string>::size_type j = 0; j != v.size(); ++j) {
        auto itBegin = text.end(), itEnd = text.end();
        auto it = text.begin();

    while ((it = search(it, text.end(), v[j].begin(), v[j].end())) != text.end()) {
        string beginText, endText;

        beginText=SearchBeginText(text,it,itBegin); //begin text
        if(v[j]=="%"){
            string otvet = resheniya2(beginText);
            text.erase(itBegin, it+1);
            it = text.insert(itBegin, otvet.begin(), otvet.end());
            continue;
        }

        endText=SearchEndText(text,v[j],it,itEnd);  //end text

        string otvet = resheniya(beginText, endText, v[j]);
        text.erase(itBegin, itEnd);
        it = text.insert(itBegin, otvet.begin(), otvet.end());
        }
    }
}
