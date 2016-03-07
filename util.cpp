#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>

// convert grayscale value to char
char toASCII(unsigned char color) {
    if (color < 50) {
        return '@';
    } else if (color < 70) {
        return '#';
    } else if (color < 100) {
        return '8';
    } else if (color < 130) {
        return '&';
    } else if (color < 160) {
        return 'o';
    } else if (color < 180) {
        return ':';
    } else if (color < 200) {
        return '*';
    } else if (color < 230) {
        return '.';
    } else {
        return ' ';
    }
}

// convert image matrix to char matrix
std::string toASCII(cv::Mat image) {
    std::ostringstream ans;
    const unsigned char *input = (unsigned char *) (image.data);
    for (int j = 0; j < image.rows; j++) {
        for (int i = 0; i < image.cols; i++) {
            const unsigned char b = input[image.step * j + i];
            const unsigned char g = input[image.step * j + i + 1];
            const unsigned char r = input[image.step * j + i + 2];
            ans << toASCII((b + g + r) / 3);
        }
        ans << "\n";
    }
    return ans.str();
}

// convert image by filename to char matrix with 'width' cols and 'height' rows
std::string toASCII(const std::string &fileName, int width = 80, int height = -1) {
    cv::Mat image = cv::imread(fileName, CV_LOAD_IMAGE_GRAYSCALE);
    if (!image.data) {
        return "error"; // no image data
    }
    const double scale = (double) image.rows / image.cols;
    if (width <= 0 && height <= 0) {
        width = 80;
        height = width * scale;
    }
    if (width <= 0) {
        width = height / scale;
    }
    if (height <= 0) {
        height = width * scale;
    }
    resize(image, image, cv::Size(width, height));
    return toASCII(image);
}
