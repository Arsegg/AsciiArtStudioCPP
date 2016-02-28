#ifndef UTIL_H
#define UTIL_H

#include <opencv2/opencv.hpp>

char toASCII(unsigned char color);
std::string toASCII(cv::Mat image);
std::string toASCII(const std::string &fileName, int width = 80, int height = -1);

#endif // UTIL_H
