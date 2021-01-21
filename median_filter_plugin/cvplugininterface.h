#ifndef CVPLUGININTERFACE_H
#define CVPLUGININTERFACE_H

#include <QObject>
#include<QString>

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

class CvPluginInterface
{
public:
    virtual ~CvPluginInterface(){}
    virtual QString description()=0;
    virtual void processImage(const cv::Mat &inputImage, cv::Mat &outputImage)=0;
};

#define CVPLUGININTERFACE_IID "com.amin.cvplugininterface"
Q_DECLARE_INTERFACE(CvPluginInterface,CVPLUGININTERFACE_IID)
#endif // CVPLUGININTERFACE_H
