#include "opencv2/opencv.hpp"
#include <iostream>
#include <climits>

unsigned changeValue(unsigned value)
{ 
    value = value & UCHAR_MAX; //pixel value 0-255
    unsigned temp = value;
    for(unsigned i = 0; i < 3; i++)
    {
        temp = temp << 8;
        temp = temp | value;
    }
    return temp;
}

cv::Mat imageMinusValue(cv::Mat image, unsigned value)
{
    value = changeValue(value);
    unsigned imgSize = image.rows * image.cols * image.channels();
    uint32_t * imageData = (uint32_t*)image.data;

    for( unsigned i = 0; i < imgSize; i = i + 4)
    {
        *imageData++ -= value; 
    }
    return image;
}

int main( int argc, char** argv )
{
  cv::Mat image;
  image = cv::imread("../example_image.jpg");
  while ( ! image.isContinuous() )
  { 
      image = image.clone();
  }
  
  unsigned value = 200;
  image = imageMinusValue(image,value);  
  cv::imwrite("../transformed_image.jpg",image);

  return 0;
}
