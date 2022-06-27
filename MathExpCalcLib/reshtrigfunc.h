#ifndef RESHTRIGFUNC_H
#define RESHTRIGFUNC_H
#include "resheniy.h"

class ReshTrigFunc:public Resheniy
{
public:

    ReshTrigFunc();
    void CalculateTrigFunc(std::string& mathExp);
    std::string resheniya(std::string&, std::string&);
//СalcTrigonometricFunc
private:
    double angleToRadians(double&);
    void trigonometr(std::string& mathExp);
    const double Pi= 3.141592653589;
};

#endif // RESHTRIGFUNC_H
