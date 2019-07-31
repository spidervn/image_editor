#ifndef IMAGEENGINE_INTERFACE_IMGPROCESS_IORBFEATURE_H_
#define IMAGEENGINE_INTERFACE_IMGPROCESS_IORBFEATURE_H_

#include <opencv2/imgproc.hpp>

class IORBFeature
{
private:
    /* data */
public:
    virtual ~IORBFeature() {}
    virtual int intensityCentroid(cv::Mat img, double& vx, double& vy)  = 0;
    virtual double momentOfPatch(cv::Mat mat, double p, double q) = 0;
    virtual double orientationOfPatch() = 0;
};

#endif