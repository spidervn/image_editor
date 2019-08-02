#include <stdafx.h>
#include "CImageFormatter.h"

#include <opencv2\core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

CImageFormatter::CImageFormatter(/* args */)
{}

CImageFormatter::~CImageFormatter()
{}


int CImageFormatter::bufferBGR_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img)
{
	int nIndex = 0;
	MatIterator_<Vec3b> it;
	img.create(cv::Size(w, h), CV_8UC3);
	it = img.begin<Vec3b>();

	for (int y = 0; y < w; ++y)
	{
		for (int x = 0; x < h; ++x)
		{
			(*it)[0] = pBanknote[nIndex++];
			(*it)[1] = pBanknote[nIndex++];
			(*it)[2] = pBanknote[nIndex++];
			it++;
		}
	}

    return 0;
}

int CImageFormatter::bitmap32_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img)
{
	int nIndex = 0;
	MatIterator_<Vec3b> it;
	img.create(cv::Size(w, h), CV_8UC3);
	it = img.begin<Vec3b>();

	for (int y = 0; y < w; ++y)
	{
		for (int x = 0; x < h; ++x)
		{
			(*it)[0] = pBanknote[nIndex++];
			(*it)[1] = pBanknote[nIndex++];
			(*it)[2] = pBanknote[nIndex++];
			nIndex++;
			it++;
		}
	}
    return 0;
}

int CImageFormatter::bufferMono_to_cvMat(int w, int h, unsigned char* pBanknote, cv::Mat& img)
{
	int nIndex = 0;
	MatIterator_<Vec3b> it;
	img.create(cv::Size(w, h), CV_8UC3);
	it = img.begin<Vec3b>();

	for (int y = 0; y < w; ++y)
	{
		for (int x = 0; x < h; ++x)
		{
			(*it)[0] = pBanknote[nIndex];
			(*it)[1] = pBanknote[nIndex];
			(*it)[2] = pBanknote[nIndex++];
			it++;
		}
	}

	return 0;
}

int CImageFormatter::bufferMono_to_CBitmap(int w, int h, unsigned char* pBanknote, CBitmap& bmp)
{
	unsigned char* pbuffer = (unsigned char*)malloc(sizeof(unsigned char*) * w * h * 4);

	if (pbuffer)
	{
		int datasize = w*h;
		int j;
		for (int i = 0, j=0; j < datasize; i += 4, j++)
		{
			pbuffer[i] = pBanknote[j];
			pbuffer[i + 1] = pBanknote[j];
			pbuffer[i + 2] = pBanknote[j];
			pbuffer[i + 3] = 0xFF;
		}

		bmp.DeleteObject();
		bmp.CreateBitmap(w, h, 1, 32, pbuffer);
		free(pbuffer);
		return 0;
	}
	else
	{
		return 1; // Error - could not allocate memory
	}

}

int CImageFormatter::cvMat_to_CBitmap(cv::Mat& img, CBitmap& bmp) 
{
	int nchannels = img.channels();
    int w = img.cols;
    int h = img.rows;
    unsigned char* pbuffer = (unsigned char*) malloc(sizeof(unsigned char*) * w * h * 4);
	if (nchannels == 1)
	{
		MatIterator_<uchar> it, end;
		int nindex = 0;
		for (it = img.begin<uchar>(), end = img.end<uchar>(); it != end; ++it)
		{
			pbuffer[nindex++] = *it;
			pbuffer[nindex++] = *it;
			pbuffer[nindex++] = *it;
			pbuffer[nindex++] = 0xFF;
		}

		bmp.DeleteObject();
		bmp.CreateBitmap(w, h, 1, 32, pbuffer);
	}
	else if (nchannels == 3)
	{
		MatIterator_<Vec3b> it, end;
		int nindex = 0;
		for (it = img.begin<Vec3b>(), end = img.end<Vec3b>(); it != end; ++it)
		{
			pbuffer[nindex++] = (*it)[0]; 
			pbuffer[nindex++] = (*it)[1];
			pbuffer[nindex++] = (*it)[2];
			pbuffer[nindex++] = 0xFF;
		}

		bmp.DeleteObject();
		bmp.CreateBitmap(w, h, 1, 32, pbuffer);
	}

    free(pbuffer);
    return 0;
}
