#pragma once

#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

/*
enum class ImageExt
{
    JPG,
    PNG,
    BMP
};

struct BufferData
{
    private:
        unsigned char* pbuffer;

    public:
        BufferData()
        {
            pbuffer = NULL;
        }

		~BufferData()
		{
			if (pbuffer != NULL)
			{
				free(pbuffer);
				pbuffer = NULL;
			}
		}

        void create_buffer(int size)
        {
            if (pbuffer != NULL)
            {
                free(pbuffer);
            }

            pbuffer = (unsigned char*)malloc(size);
        }

		void manage_buffer(unsigned char* pAlreadyBuffer)
		{
			if (pbuffer != NULL)
			{
				free(pbuffer);
			}

			pbuffer = pAlreadyBuffer;
		}

        unsigned char* getBuffer() const
        {
            return pbuffer;
        }
};

typedef std::shared_ptr<BufferData> BufferDataPtr;

struct ImgObject
{
    ImageExt format_ext;
    int w;
    int h;

    BufferDataPtr bufferImg;
};

struct ViewModel
{
    cv::Mat matOrigin;
    CBitmap bmp;

    int w;
    int h;

    ViewModel()
    {
        w = 0;
        h = 0;
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
*/

struct ViewModel
{
	cv::Mat matOrigin;
	cv::Mat matCurrent;

	CBitmap bmpCurrent;

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
};

struct EditorOp
{
	int opType;
};
