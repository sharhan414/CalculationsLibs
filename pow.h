#ifndef POW_H
#define POW_H
#include "resheniy.h"

class Pow:public Resheniy
{
public:
    Pow();

    void CalculatePow(std::string&);
private:
    std::string resheniya(std::string&,std::string&);

};

#endif // POW_H
