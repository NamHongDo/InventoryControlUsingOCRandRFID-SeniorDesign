#include "opencv.h"
#include <iostream>
#include <exception>
#include <stdexcept>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

void shootit(){
    VideoCapture stream(0);
    stream.set(CAP_PROP_EXPOSURE,5);
    //stream.set(CAP_PROP_CONTRAST,30);
    if(!stream.isOpened()){
        cout<< "No camera :(\n";
    }

    Mat image;

    stream.read(image);

    imshow("pic",image);
    imwrite("/home/namdo/build-LabelScanner-Desktop_Qt_5_7_0_GCC_64bit-Debug/Label/img.png",image);
}

