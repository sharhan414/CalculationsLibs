#ifndef FACTORIAL_H
#define FACTORIAL_H
#include "MathExpFunction.h"

class Factorial:public Resheniy
{
public:
    Factorial();
     void CalculateFactorial(std::string&);
private:
    std::string resheniya(std::string& );
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        else
            return n * factorial(n - 1);
    }
};

#endif // FACTORIAL_H
