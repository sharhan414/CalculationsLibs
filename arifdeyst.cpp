#include "arifdeyst.h"
#include "resheniy.h"
#include <algorithm>
#include <iostream>
using namespace std;
ArifDeyst::ArifDeyst()
{

}


void ArifDeyst::ReshArifDeystUmnjAndDeln(vector<double>& v, vector<char>& w)
{
    string m = "*/";
    int a = 0,k=0;
    for (size_t i = 0; i != w.size(); ++i)
        if (w[i] == m.back() || w[i] == m.front())
            ++k;

    while(a<k)
    {
        for (size_t i = 0; i != w.size(); ++i)
        {
            if (w[i] == m.front())
            {
                v[i] = v[i] * v[i + 1];
                v.erase(v.begin() + i + size_t(1));
                w.erase(w.begin() + i);
                ++a;
                break;
            }
            else if (w[i] ==m.back())
            {
                v[i] = v[i]/v[i + 1];
                v.erase(v.begin() + i + size_t(1));
                w.erase(w.begin() + i);
                ++a;
                break;
            }
        }
    }
}

// функция для решения + - действий
double ArifDeyst::ReshArifDeystPlusAndMinus(vector<double>& Otvetes, vector<char>& w)
{
    int a = 0, k = 0;
    for (size_t i = 0; i != w.size(); ++i)
        if (w[i] == '+' || w[i] == '-' )
            ++k;

    while (a < k)
    {
        for (size_t i = 0; i != w.size(); ++i)
        {
            if (w[i] == '+')
            {
                Otvetes[i] = Otvetes[i] + Otvetes[i + 1];
                Otvetes.erase(Otvetes.begin() + i + 1);
                w.erase(w.begin() + i);
                ++a;
                break;
            }
            else if (w[i] == '-')
            {
                Otvetes[i] = Otvetes[i] - Otvetes[i + 1];
                Otvetes.erase(Otvetes.begin() + i + 1);
                w.erase(w.begin() + i);
                ++a;
                break;
            }
        }
    }
return Otvetes.front();
}
//new
//new
void ArifDeyst::getArifSignsForExp(string &text,vector<char>& ArithmeticSigns)
{
    text+='|';
    for(uint64_t i=1;i<text.size();++i)
    {
        if(text[i]=='+')
        {
            ArithmeticSigns.push_back('+');
            text[i]='|';
        }
        else if(text[i]=='*')
        {
            ArithmeticSigns.push_back('*');
            text[i]='|';
        }
        else if(text[i]=='/')
        {
            ArithmeticSigns.push_back('/');
            text[i]='|';
        }
        else if(text[i]=='-')
        {
            if(text[i-1]!='|')
            {
                ArithmeticSigns.push_back('-');
                text[i]='|';
            }
        }
    }
}

void ArifDeyst::getValuesForExp(string &text,vector<string>& ValuesForExp)
{
    while(!text.empty())
    {
        auto iter=find(text.begin(),text.end(),'|');
        string val(text.begin(),iter);
        ValuesForExp.push_back(val);
        text.erase(text.begin(),iter+1);
    }
}

void ArifDeyst::getDatesForExp(string& text,vector<string>& ValuesForExp,vector<char>& ArithmeticSigns)
{

    getArifSignsForExp(text,ArithmeticSigns);
    getValuesForExp(text,ValuesForExp);
}
/////
/// \brief ArifDeyst::arif_detstvie
/// \param otvet
/// \param TextAfidDeyst
///////////
void ArifDeyst::arif_detstvie(double& Answer,string text)
{
    vector<char> ArithmeticSigns;
    vector<string> ValuesForExp;
    getDatesForExp(text,ValuesForExp,ArithmeticSigns);
    vector<double> Otvetes;

    for(uint64_t i=0;i!=ValuesForExp.size();++i)
    {
        Otvetes.push_back(Resheniy::stdString_toDouble(ValuesForExp[i]));
    }

    ReshArifDeystUmnjAndDeln(Otvetes,ArithmeticSigns);//решаеть ариф.действия умножение и деление
    Answer=ReshArifDeystPlusAndMinus(Otvetes,ArithmeticSigns);//решаеть ариф.действия сложение и вычитание
}
