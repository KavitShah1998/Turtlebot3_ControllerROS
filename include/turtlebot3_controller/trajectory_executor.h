# pragma once

# include <vector>
# include <string>
# include "turtlebot3_controller/controller_pid.h"

class TrajectoryExecutor{

    public:

        /**
		 * \brief      initializes node & controller onject
         * 
         * \param      nh - nodehandle for ROS related operations
		 */
        TrajectoryExecutor(ros::NodeHandle& nh);


        /**
		 * \brief      destroys the controller object
		 */
        ~TrajectoryExecutor();


        /**
		 * \brief      destroys the controller object
         * 
         * \param      path - the trajectory to be executed
		 */
        void setPath(std::vector<geometry_msgs::Point>& path);


        /**
		 * \brief      executes the set-point path
		 */
        std::vector<geometry_msgs::Point> executePath();


        /**
		 * \brief      executes the set-point path
         * 
         * \param      path - the vector of trajectory points
		 */
        void printPathVector(std::vector<geometry_msgs::Point>& path);


        /**
         * \brief      returns the remaining path back to the planner
         */
        std::vector<geometry_msgs::Point> getPath();

    private:

        int _goalIndex{0};
        bool _b_isCollisionImminent{false};
        
        ros::NodeHandle _nh;
    
        std::vector<geometry_msgs::Point> _path;

        std::string _planner{"global"};
        
        PID* _controller;


        /**
		 * \brief      eliminates the achieved path
		 */
        void _updatePath();

        
};