#ifndef IMAGEENGINE_COMMON_BUSINESS_STRUCT_H_
#define IMAGEENGINE_COMMON_BUSINESS_STRUCT_H_

#include "img_struct.h"

struct ViewModel
{
    cv::Mat matOrigin;
    cv::Mat matCurrent;

    int w;
    int h;
    double zoomLevel;

    ViewModel()
    {
        w = 0;
        h = 0;
        zoomLevel = 1;
    }
};

struct CopyObject
{
    BufferDataPtr copyData;
};

struct EditorOp
{
    int opType;
    BufferDataPtr opData;
};

#endif