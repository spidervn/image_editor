#ifndef IMAGEENGINE_INTERFACE_IMGPROCESS_IRANDOMNUMBER_H_
#define IMAGEENGINE_INTERFACE_IMGPROCESS_IRANDOMNUMBER_H_

class IRandomNumber
{
public:
    virtual ~IRandomNumber() {}
    virtual double nextNumber() = 0;
};

#endif