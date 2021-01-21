#ifndef GAUSSIAN_FILTER_PLUGIN_H
#define GAUSSIAN_FILTER_PLUGIN_H

#include "gaussian_filter_plugin_global.h"
#include "cvplugininterface.h"

class GAUSSIAN_FILTER_PLUGINSHARED_EXPORT Gaussian_filter_plugin:
        public QObject, public CvPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.amin.cvplugininterface")
    Q_INTERFACES(CvPluginInterface)

public:
    Gaussian_filter_plugin();
    ~Gaussian_filter_plugin();
    QString description();
    void processImage(const cv::Mat &inputImage,
                      cv::Mat &outputImage);
};

#endif // GAUSSIAN_FILTER_PLUGIN_H
