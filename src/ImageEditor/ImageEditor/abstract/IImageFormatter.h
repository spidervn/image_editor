#pragma once
#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

class IImageFormatter
{
private:
    /* data */
public:
    virtual ~IImageFormatter() {}

    virtual int bufferBGR_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img) = 0;
    virtual int bitmap32_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img) = 0;
	virtual int bufferMono_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img) = 0;
	virtual int bufferMono_to_CBitmap(int w, int h, unsigned char* pBanknote, CBitmap& bmp) = 0;
	virtual int cvMat_to_CBitmap(cv::Mat& img, CBitmap& bmp) = 0;
};

typedef std::shared_ptr<IImageFormatter> IImageFormatterPtr;
