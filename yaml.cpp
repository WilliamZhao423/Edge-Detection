/**
 * Copyright (c) Hofsta University  - All Rights Reserved
 * Created on: @16/03/2021
 *     Author: Yimin.Zhao <yimin.zhao@hofstra.edu>
 */

// Assumptions: Opecv is installed  
// Opencv version: OpenCV 3.1


#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<string>
#include<iostream>


int main()
{

    //Modified from source: https://github.com/MicrocontrollersAndMore/OpenCV_3_Windows_10_Installation_Tutorial
    cv::Mat imgOriginal;        // input image
    cv::Mat imgGrayscale;        // grayscale of input image
    cv::Mat imgBlurred;            // intermediate blured image
    cv::Mat imgCanny;            // Canny edge image

    std::cout << "Please enter an image filename : ";
    std::string img_addr;
    std::cin >> img_addr;

    std::cout << "Searching for " + img_addr << std::endl;

    imgOriginal = cv::imread(img_addr);            // open image

    if (imgOriginal.empty()) {                                    // if unable to open image
        std::cout << "error: image not read from file\n\n";        // show error message on command line
        return(0);                                                // and exit program
    }

    cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);        // convert to grayscale

    cv::GaussianBlur(imgGrayscale,            // input image
        imgBlurred,                            // output image
        cv::Size(7, 7),                        // smoothing window width and height in pixels
        1.0);                                // sigma value, determines how much the image will be blurred

    cv::Canny(imgBlurred,            // input image
        imgCanny,                    // output image
        10,                        // low threshold
        30, 3);                        // high threshold


    // Declare windows
    // Note: you can use CV_WINDOW_NORMAL which allows resizing the window
    // or CV_WINDOW_AUTOSIZE for a fixed size window matching the resolution of the image
    // CV_WINDOW_AUTOSIZE is the default
    cv::namedWindow("imgOriginal", CV_WINDOW_AUTOSIZE);        
    cv::namedWindow("imgCanny", CV_WINDOW_AUTOSIZE);

    //Show windows
    cv::imshow("imgOriginal", imgOriginal);        
    cv::imshow("imgCanny", imgCanny);

    cv::waitKey(0);                    // hold windows open until user presses a key
    return 0;
}
