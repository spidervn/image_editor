#ifndef IMAGEENGINE_IMPL_IMGPROCESS_CRANDOMNUMBER_H_
#define IMAGEENGINE_IMPL_IMGPROCESS_CRANDOMNUMBER_H_

#include "ImageEngine/interface/imgprocess/IRandomNumber.h"

class CRandomNumber: public IRandomNumber
{
private:
    /* data */
    double f_probability(double x);

public:
    CRandomNumber(/* args */);
    virtual ~CRandomNumber();



    double nextNumber();
};

#endif