#include "CRandomNumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

CRandomNumber::CRandomNumber(/* args */)
{
}

CRandomNumber::~CRandomNumber()
{
}

double CRandomNumber::f_probability(double x)
{
    // Normal distribution here
    return exp(-x*x/2);
}

double CRandomNumber::nextNumber()
{
    return 0;
}