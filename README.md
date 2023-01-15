## TemplateForImageProcess


### 模板简介


此模板是用于ROS中，适配Realsense摄像头。
本模板用于与摄像头通讯，通过此模板，可以实现

1. 读取，订阅摄像头的画面
2. 留有对每一帧照片进行处理的接口
3. 重新发布处理后的图片


### 依赖环境

环境：ROS-Noetic, Ubuntu 20.04, OpenCV4

确保已经配置好了Realsense的ROS接口(即可以运行如下指令)


```commandline
roslaunch realsense2_camera rs_camera.launch 
```


### 使用方法


