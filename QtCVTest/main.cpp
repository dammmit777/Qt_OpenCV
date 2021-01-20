#include<QCoreApplication>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    using namespace cv;
    Mat image=imread("/home/ssm/OpenCV_C++/addingImages/lena.jpg");
    imshow("Output",image);
    return a.exec();
}
