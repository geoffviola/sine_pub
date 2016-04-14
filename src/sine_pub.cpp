#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "sin_pub");

    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("sine", 1000);
    ros::Rate loop_rate(10);
    double x_radians = 0.0;
    while (ros::ok())
    {
        static double const DELTA_X_RADIANS = 0.1;

        std_msgs::Float64 new_msg;
        new_msg.data = sin(x_radians);
        chatter_pub.publish(new_msg);

        ros::spinOnce();
        loop_rate.sleep();
        x_radians += DELTA_X_RADIANS;
    }
	return 1;
}
