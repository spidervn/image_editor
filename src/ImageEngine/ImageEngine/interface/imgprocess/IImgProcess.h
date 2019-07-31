#ifndef IMAGEENGINE_INTERFACE_IMGPROCESS_IIMGPROCESS_H_
#define IMAGEENGINE_INTERFACE_IMGPROCESS_IIMGPROCESS_H_

#include "common\img_struct.h"
#include "common\imgproc_struct.h"

class IImgProcess
{
private:
    /* data */
public:
    virtual ~IImgProcess() {}

    virtual int convolves(const& ImgObject img1, const& ImgObject& img2) = 0;

    virtual int smoothing(BlurTypes type, ImgObject& img) = 0;
    virtual int morphologyTransformation(int morphologyType) = 0;
    
    /*  */
    virtual int eroding(ImgObject& img) = 0;
    virtual int dilating(ImgObject& img) = 0;
    virtual int openning(ImgObject& img) = 0;
    virtual int closing(ImgObject& img) = 0;
    virtual int tophat(ImgObject& img) = 0;
    virtual int blackHat(ImgObject& img) = 0;

    /*  */
    virtual int pyramid(ImgObject& img) = 0;
    virtual int threshold(ImgObject& img) = 0;
};


#endif 