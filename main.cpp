#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>

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

std::string toASCII(cv::Mat image) {
    std::ostringstream ans;
    unsigned char *input = (unsigned char *) (image.data);
    for (int j = 0; j < image.rows; j++) {
        for (int i = 0; i < image.cols; i++) {
            const unsigned char b = input[image.step * j + i];
            const unsigned char g = input[image.step * j + i + 1];
            const unsigned char r = input[image.step * j + i + 2];
            const unsigned char average = (b + g + r) / 3;
            ans << toASCII(average);
        }
        ans << "\n";
    }
    return ans.str();
}

std::string inputDialog(const std::string &message, const std::string &default_) {
    std::cout << "Enter " << message << ": ";
    std::string ans;
    getline(std::cin, ans);
    if (ans.empty()) {
        std::cout << default_ << "\n";
        return default_;
    }
    return ans;
}

int main(int argc, char **argv) {
    const std::string filename = inputDialog("image filename (or capture)", "Lenna.png");
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("modified", cv::WINDOW_AUTOSIZE);
    if (filename == "capture") {
        cv::VideoCapture cap("drop.avi");
        if (!cap.isOpened()) {
            std::cerr << "No webcams";
            return 1;
        }
        while (1) {
            cv::Mat frame;
            bool ok = cap.read(frame);
            cv::imshow("original", frame);
            resize(frame, frame, cv::Size(80, 80));
            std::cout << "\n\n\n\n" << toASCII(frame);
            std::cout.flush();
            cv::imshow("modified", frame);
            if (cv::waitKey(100) >= 0) {
                break;
            }
        }
        return 0;
    }
    cv::Mat image = cv::imread(filename/*, CV_LOAD_IMAGE_GRAYSCALE*/);
    if (!image.data) {
        std::cerr << "No image data";
        return 1;
    }
    const int width = stoi(inputDialog("image width", "80"));
    const int height = stoi(inputDialog("image height", std::to_string(width * image.rows / image.cols)));
    cv::imshow("original", image);
    cv::cvtColor(image, image, CV_BGR2GRAY);
    resize(image, image, cv::Size(width, height));
    /*namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);

    waitKey(0);*/
    cv::imshow("modified", image);
    std::cout << toASCII(image);
    cv::waitKey(0);

    return 0;
}