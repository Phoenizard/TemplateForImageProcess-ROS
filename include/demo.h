#ifndef TEMPLATEFORIMAGEPROCESS_DOME_H
#define TEMPLATEFORIMAGEPROCESS_DOME_H

#include <ros/ros.h>
#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <sensor_msgs/CompressedImage.h>
#include <sensor_msgs/image_encodings.h>
using namespace std;
using namespace cv;

class SubPuber
{
private:
    ros::NodeHandle nodeHandle;
    ros::Subscriber imgSub;
    ros::Publisher publisher_name;
    Mat ProcessImg(Mat rawImage);
public:
    SubPuber()
    {
        imgSub = nodeHandle.subscribe("/camera/color/image_raw", 1, &SubPuber::solveTransform, this);
        // set to subscribe image form the camera
        // topic: "/camera/color/image_raw" you can change to your camera's topic
        publisher_name = nodeHandle.advertise<sensor_msgs::Image>("/publish_name", 1);
        // set to publish the processed image
        // topic: "/publish_name" you can change its name
    }

    void TransformImage(const sensor_msgs::ImageConstPtr &frontRGBImg)
    {
        Mat image;
        try
        {
            image = cv_bridge::toCvShare(frontRGBImg, "bgr8")->image;
        }
        catch (cv_bridge::Exception& e)
        {
            ROS_ERROR("Could not convert to image!");
            return;
        }
        image = ProcessImg(image);
        //sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", image).toImageMsg();
        // use it when the image is grey
        sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
        // use it when the image is RGB
        publisher_name.publish(*msg);
    }
};
#endif //TEMPLATEFORIMAGEPROCESS_DOME_H
