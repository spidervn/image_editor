#pragma once

#include "../abstract/IImageFormatter.h"

#define CImageFormatterPtrNew std::make_shared<CImageFormatter>()

class CImageFormatter: public IImageFormatter
{
private:
    /* data */
public:
    CImageFormatter(/* args */);
    ~CImageFormatter();
    
    int bufferBGR_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img);
    int bitmap32_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img);
	int bufferMono_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img);
	int bufferMono_to_CBitmap(int w, int h, unsigned char* pBanknote, CBitmap& bmp);
    int cvMat_to_CBitmap(cv::Mat& img, CBitmap& bmp);

};
