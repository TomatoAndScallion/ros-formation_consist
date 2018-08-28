#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <nav_msgs/Path.h>
#include <quad_serial/UavAngle.h>
#include <quad_serial/UavState.h>

int main (int argc, char** argv)
{
    ros::init(argc, argv, "formation_control");
    ros::NodeHandle nh;
    ros::Subscriber sub_pose_feedback = nh.subscribe("pose_feedback",10,pose_feedback_Callback);
    ros::Subscriber sub_pose_des = nh.subscribe("pose_des",10,pose_des_Callback);
    ros::Subscriber sub_vel_des = nh.subscribe("vel_des",10,vel_des_Callback);

    ros::Publisher pub_pose = nh.advertise<geometry_msgs::PoseStamped>("local_pose", 10);
    ros::Publisher pub_vel = nh.advertise<geometry_msgs::TwistStamped>("local_vel",10);
    
  
    ros::Rate loop_rate(20);
    while(ros::ok()){
        
    ros::spinOnce();
	loop_rate.sleep();
        
    }
    return 0;
}
