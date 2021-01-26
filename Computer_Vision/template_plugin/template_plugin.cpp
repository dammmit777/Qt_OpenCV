#include "template_plugin.h"

#include "ui_plugin.h"

Template_plugin::Template_plugin()
{
    //Insert initialization codes here ...
}

Template_plugin::~Template_plugin()
{
    //Insert cleanup codes here ...
}

QString Template_plugin::title()
{
    return this->metaObject()->className();
}

QString Template_plugin::version()
{
    return "1.0.0";
}

QString Template_plugin::description()
{
    return "A <b>Template</b> plugin";
}

QString Template_plugin::help()
{
    return "This is a <b>Template</b> plugin. Clone and use it to create new plugins.";
}

void Template_plugin::setupUi(QWidget *parent)
{
    ui = new Ui::PluginGui;
    ui->setupUi(parent);

    //Connect signals for GUI elements manually here since they won't be connected by name in a plugin
    //...
    //emit updateNeeded();should be added whenever parameters on the plugin GUI change
}

void Template_plugin::processImage(const cv::Mat &inputImage, cv::Mat &outputImage)
{
    //Replace the following line with the actual image processing task
    inputImage.copyTo(outputImage);

    //Otherwise, if the process doesn't affect the output image, update plugin GUI here ...
}
