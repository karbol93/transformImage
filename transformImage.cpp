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

int main( int argc, char** argv )
{
  cv::Mat image;
  image = cv::imread("../example_image.jpg");
  unsigned value = 200;
  value = changeValue(value);
  unsigned imgSize = image.rows * image.cols * image.channels(); 

  while ( ! image.isContinuous() )
  { 
      image = image.clone();
  }
  
  uint32_t * imageData = (uint32_t*)image.data;
  
  for( unsigned i = 0; i < imgSize; i = i + 4)
  {
      *imageData++ -= value; 
  }
  
  cv::imwrite("../transformed_image.jpg",image);

  return 0;
}
