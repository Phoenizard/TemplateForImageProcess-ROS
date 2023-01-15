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

1. 确保你已经存在一个工作空间并且添加环境变量：

    ```commandline
    cd ~/workspace/src
    catkin_init_workspace
    cd ~/workspace
    catkin_make
    ```

2. 拷贝模板，注意模板是一个软件包，安装在src中

    ```commandline
    cd workspace_name/src
    git clone git@github.com:Phoenizard/TemplateForImageProcess-ROS.git 
    ```

3. 自定义CMakeLists的项目名称以及程序中的变量命名后，编译：
    
    ```commandline
    cd workspace_name/src
    catkin_make
    ```
