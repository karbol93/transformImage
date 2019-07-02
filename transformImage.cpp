#include "opencv2/opencv.hpp"
#include <iostream>
 
int main( int argc, char** argv )
{
  cv::Mat image;
  image = cv::imread("../example_image.jpg");
  unsigned imgSize = image.rows * image.cols * image.channels(); 

  while ( ! image.isContinuous() )
  { 
      image = image.clone();
  }
  
  uint32_t * imageData = (uint32_t*)image.data;
  
  for( unsigned i = 0; i < imgSize; i = i + 4)
  {
      *imageData++ -= 3368601800; //image - 200
  }
  
  cv::imwrite("../transformed_image.jpg",image);

  return 0;
}
