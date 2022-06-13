#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

void displayHeaderBlock();
void displayMenu();
void printToTerminal(std::string filePath = "");

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        printToTerminal(argv[1]);
        return 0;
    }
    displayHeaderBlock();
    displayMenu();

    return 0;
}

void displayHeaderBlock()
{
    std::cout << "===================" << std::endl;
    std::cout << "IMG to ASCII" << std::endl;
    std::cout << "By Aaron Gee 2022" << std::endl;
    std::cout << "===================" << std::endl;
}

void displayMenu()
{
    std::cout << "IMG to ASCII -- Main Menu:" << std::endl;
    std::cout << "1. Display Image in Command Line" << std::endl;
    // std::cout << "2. Output ASCII Image in text file" << std::endl;
    std::cout << "q. Exit" << std::endl;

    char input;
    std::cin >> input;

    switch(input)
    {
        case '1':
            std::cout << "1" << std::endl;
            printToTerminal();
            break;
        case '2':
            std::cout << "2" <<std::endl;
            break;
        case 'q':
            std::cout << "q" << std::endl;
            break;
        default:
            std::cout << "Error invalid input" << std::endl;
            displayMenu();
    }
}

void printToTerminal(std::string filePath)
{
    if( filePath.empty())
    {
        std::cout << "Enter image file path" << std::endl;
        std::cin >> filePath;
    }

    cv::Mat img = cv::imread(filePath, cv::IMREAD_GRAYSCALE);

    if(img.cols > 100)
    {
        double scale_percent = 100.0/img.cols;
        std::cout << "Image resolution to high to output to terminal..." << std::endl;
        std::cout << "Scaling image down " << static_cast<int>(scale_percent*100) << "%" << std::endl;
        std::cout << "For a full resolution image output to a text file" << std::endl;

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
}