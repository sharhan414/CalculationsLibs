#include "mathexpressions.h"
#include <iterator>
#include <algorithm>
#include<QDebug>
using namespace std;
MathExpressions::MathExpressions()
{

}

void MathExpressions::CalculateMathExp(string & mathExp)
{
    string::iterator b=mathExp.begin(),e=mathExp.end(),e2=mathExp.end();
    OpeningBrackets(mathExp,b,e,e2);
}

string MathExpressions::ApplicationFuncCalc(string mathExp)
{

    factorial.CalculateFactorial(mathExp);//вычисляет фактириалы
    calcTrigFunc.CalculateTrigFunc(mathExp);//вычисляет тригонометрических функций
    if(calcTrigFunc.isError())//проверка на наличие ошибки при произведения действия
    {
        qDebug()<<"v trig error";
    }

    calcPercent.CalculatePercent(mathExp);//вычисляет процент

    log.CalculatehLog(mathExp);//вычисляет логарифм
    qsrt.CalculateSqrt(mathExp);//вычисляет корней
    pow.CalculatePow(mathExp);//вычисляет спепеней
    double answer=arithAct.calcArithExp(mathExp);

    return QString::number(answer).toStdString();
}

/////////////////////////////////////
/// \brief MathExpressions::sleep
/// \param text
/// \param begin
/// \param end
/// \param verhEnd
/////////////////////////////////////////////////////
void MathExpressions::OpeningBrackets(string& mathExp, string::iterator& begin, string::iterator& end, string::iterator& verhEnd)
{
//функция для раскрытия скобок

    if(!getTextFromBrackets(mathExp, begin, end, verhEnd ))
        return;
    int bracket_close = 0, bracket_open = 0;//переменные для подсчёта открых и закрытых скобок
    auto c = mathExp.end();
    auto i = begin;

    while (i != end)
    {

        if (*i == '(')
        {           //подсчитывает количество открытых скобок
            ++bracket_open;
            if (c == mathExp.end())
                c = i;                  //сохраняет позицию первой открытой скобки
        }
        else if (*i == ')')
        {      //подсчитывает количество закрытых скобок
            ++bracket_close;
        }
        if (bracket_close != 0 && bracket_open == bracket_close)
        {        //если количество окрытых и закрытых скобок равно, то
            int64_t ras1 = int64_t(mathExp.size());
            OpeningBrackets(mathExp, ++c, i,end);
            int64_t ras2 = int64_t(mathExp.size());     //
            int64_t ras =  ras1-ras2;
            verhEnd -= ras;
            if (!getTextFromBrackets(mathExp, begin,end, verhEnd))
                return;		//закрываем нашу функцию
            c = mathExp.end();
            bracket_close = 0;
            bracket_open = 0;
        }
        ++i;//увеличиваем счетшик на 1
    }
}
bool  MathExpressions::getTextFromBrackets(string& mathExp, string::iterator& begin, string::iterator& end, string::iterator& verhEnd)
{

    string textskobky(begin, end);//вычисляется текст нашей скобки
    int64_t sizeIshodText = int64_t(mathExp.size());

    if (find(textskobky.begin(), textskobky.end(), '(') == textskobky.end() && !textskobky.empty()) //если в нашем тексте нету скобок то
    {
        string ansewr = ApplicationFuncCalc(textskobky);//вычисляем ответ арифметических действий в нашем тексте и ответ сохраняем в переменной "otvet"

        if (begin == mathExp.begin() && end==mathExp.end())
        {//
            mathExp.clear();
            mathExp = ansewr;
            begin = mathExp.begin();
            end = mathExp.end();
            verhEnd = end;

         }
        else
        {
            if (begin != mathExp.begin() && end != mathExp.end())
                end = mathExp.erase(begin - 1, end + 1);
            else if (begin == mathExp.begin() && end != mathExp.end())
                end = mathExp.erase(begin , end + 1);
            else if (begin != mathExp.begin() && end == mathExp.end())
                end = mathExp.erase(begin-1, end );

            mathExp.insert(end, ansewr.begin(), ansewr.end());
            end = begin;
            if (begin != mathExp.begin())
                --end;
                int64_t sizeKonechText = int64_t(mathExp.size());
                int64_t raznica = sizeIshodText - sizeKonechText;
                verhEnd = verhEnd - raznica;
         }
             return false;
    }
        else
        return true;
}

void MathExpressions::InsertNewSingExp(u16string &mathExp,u16string Sign, u16string newSign)
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

void MathExpressions::ReplacingSigns(QString & text)//заменят знаки
{
    auto str=text.toStdU16String();
    InsertNewSingExp(str,u"/√",u"nsqrt");
    InsertNewSingExp(str,u"×",u"*");
    InsertNewSingExp(str,u"÷",u"/");
    InsertNewSingExp(str,u"√",u"sqrt");
    text=text.fromStdU16String(str);
}
