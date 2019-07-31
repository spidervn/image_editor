#ifndef IMAGEENGINE_IMPL_IMGPROCESS_CIMGPROCESS_H_
#define IMAGEENGINE_IMPL_IMGPROCESS_CIMGPROCESS_H_

#include "interface/imgprocess/IImgProcess.h"

class CImgProcess: public IImgProcess
{
private:
    /* data */
public:
    CImgProcess(/* args */);
    virtual ~CImgProcess();

    virtual int convolves(const& ImgObject img1, const& ImgObject& img2);
    int smoothing(BlurTypes type, ImgObject& img);
    int morphologyTransformation(int morphologyType, ImgObject& img);
};

#endif