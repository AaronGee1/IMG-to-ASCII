#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    if(img.cols > 100)
    {
        double scale_percent = 100.0/img.cols;
        cv::resize(img, img, cv::Size(), scale_percent, scale_percent);
    }

    for(auto i = 0; i < img.rows; i++)
    {
        for(auto j = 0; j < img.cols; j++)
        {
            double value = (int)img.at<uchar>(i,j);
            std::cout << ".,-~:;=!*#$@"[(int)((value)/255 * 8)] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
