#include "arithoperations.h"

#include "resheniy.h"
#include <algorithm>
#include <iostream>
using namespace std;
ArithOperations::ArithOperations()
{

}

// функция для произведения умножения и деления (*,/) т.е. этих действий
void ArithOperations::CalcArithExpMultAndDiv(vector<double>& Values, vector<char>& ArithmeticSigns)
{
    string m = "*/";
    int NumActions = 0,ComplActions=0;//переменные для хранения кол.действий в выраж. и пер. подсчёта выпол-х действий
    for (uint64_t i = 0; i != ArithmeticSigns.size(); ++i)
        if (ArithmeticSigns[i] == m.back() || ArithmeticSigns[i] == m.front())
            ++ComplActions;

    while(NumActions<ComplActions)
    {
        for (size_t i = 0; i != ArithmeticSigns.size(); ++i)
        {
            if (ArithmeticSigns[i] == m.front())
            {
                Values[i] = Values[i] * Values[i + 1];
                Values.erase(Values.begin() + i + size_t(1));
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
            else if (ArithmeticSigns[i] ==m.back())
            {
                Values[i] = Values[i]/Values[i + 1];
                Values.erase(Values.begin() + i + size_t(1));
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
        }
    }
}

// функция для решения + - действий
double ArithOperations::CalcArithExpPlusAndMinus(vector<double>& Answers, vector<char>& ArithmeticSigns)
{
    int NumActions = 0, ComplActions = 0;//переменные для хранения кол.действий в выраж. и пер. подсчёта выпол-х действий
    for (uint64_t i = 0; i != ArithmeticSigns.size(); ++i)
        if (ArithmeticSigns[i] == '+' || ArithmeticSigns[i] == '-' )
            ++ComplActions;


    while (NumActions < ComplActions)
    {
        for (uint64_t i = 0; i != ArithmeticSigns.size(); ++i)
        {
            if (ArithmeticSigns[i] == '+')
            {
                Answers[i] = Answers[i] + Answers[i + 1];
                Answers.erase(Answers.begin() + i + 1);
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
            else if (ArithmeticSigns[i] == '-')
            {
                Answers[i] = Answers[i] - Answers[i + 1];
                Answers.erase(Answers.begin() + i + 1);
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
        }
    }
    return Answers.front();
}
//функция для
void ArithOperations::getArifSignsForExp(string &mathExp,vector<char>& ArithmeticSigns)
{
    mathExp+='|';
    for(uint64_t i=1;i<mathExp.size();++i)
    {
        if(mathExp[i]=='+')
        {
            ArithmeticSigns.push_back('+');
            mathExp[i]='|';
        }
        else if(mathExp[i]=='*')
        {
            ArithmeticSigns.push_back('*');
            mathExp[i]='|';
        }
        else if(mathExp[i]=='/')
        {
            ArithmeticSigns.push_back('/');
            mathExp[i]='|';
        }
        else if(mathExp[i]=='-')
        {
            if(mathExp[i-1]!='|')
            {
                ArithmeticSigns.push_back('-');
                mathExp[i]='|';
            }
        }
    }
}

void ArithOperations::getValuesForExp(string &text,vector<string>& ValuesForExp)
{
    while(!text.empty())
    {
        auto iter=find(text.begin(),text.end(),'|');
        string val(text.begin(),iter);
        ValuesForExp.push_back(val);
        text.erase(text.begin(),iter+1);
    }
}

void ArithOperations::getDatesForExp(string& text,vector<string>& ValuesForExp,vector<char>& ArithmeticSigns)
{

    getArifSignsForExp(text,ArithmeticSigns);
    getValuesForExp(text,ValuesForExp);
}
/////
/// \brief ArifDeyst::arif_detstvie
/// \param otvet
/// \param TextAfidDeyst
///////////
void ArithOperations::arif_detstvie(double& Answer,string mathExp)
{
    vector<char> ArithmeticSigns;
    vector<string> ValuesForExp;
    getDatesForExp(mathExp,ValuesForExp,ArithmeticSigns);
    vector<double> Answers;

    for(uint64_t i=0;i!=ValuesForExp.size();++i)
    {

        Answers.push_back(stdString_toDouble(ValuesForExp[i]));
    }

    CalcArithExpMultAndDiv(Answers,ArithmeticSigns);//решаеть ариф.действия умножение и деление
    Answer=CalcArithExpPlusAndMinus(Answers,ArithmeticSigns);//решаеть ариф.действия сложение и вычитание
}
