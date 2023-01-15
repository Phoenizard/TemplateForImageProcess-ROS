#include 'demo.h'

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_name");
    ROS_INFO("Build Successfully");
    SubPuber _name;
    // change the name
    ros::spin();
    return 0;
}