#ifndef IMAGEENGINE_COMMON_IMGSTRUCT_H_
#define IMAGEENGINE_COMMON_IMGSTRUCT_H_

#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

/* Image extensions */
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

    cv::Mat img;
};

#endif