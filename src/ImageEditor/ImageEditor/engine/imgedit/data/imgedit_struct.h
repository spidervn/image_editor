#pragma once

#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

struct CopyObject
{
    unsigned char* pCopyData;
};

struct EditorOperationObj
{
    int opType;
    unsigned char* opData;
};

struct ImageModel
{
    ImageModel model;
};


