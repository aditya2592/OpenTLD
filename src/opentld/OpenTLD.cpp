/*  Copyright 2011 AIT Austrian Institute of Technology
*
*   This file is part of OpenTLD.
*
*   OpenTLD is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   OpenTLD is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with OpenTLD.  If not, see <http://www.gnu.org/licenses/>.
*
*/

/**
  * @author Georg Nebehay
  */

#include "Main.h"
#include "Config.h"
#include "ImAcq.h"
#include "Gui.h"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using tld::Config;
using tld::Gui;
using tld::Settings;
using namespace cv;


void callback(const sensor_msgs::ImageConstPtr& msg)
{

    cv_bridge::CvImagePtr cv_ptr;
    try
    {
         cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }
    Mat img1 = (cv_ptr->image);
    IplImage* img2;
    img2 = cvCreateImage(cvSize(img1.cols,img1.rows),8,3);
    IplImage ipltemp=img1;
    cvCopy(&ipltemp,img2);

    cvNamedWindow("image", CV_WINDOW_AUTOSIZE);
    cvShowImage("image", img2);
    cvWaitKey();
    cvDestroyWindow("image");

}
int main(int argc, char **argv)
{

   // Main *main = new Main();
    ros::init(argc, argv, "opentld");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("ardrone/bottom/image_raw", 1000, callback);

    ros::spin();
//    Config config;
//    ImAcq *imAcq = imAcqAlloc();
//    Gui *gui = new Gui();

//    main->gui = gui;
//    main->imAcq = imAcq;

//    if(config.init(argc, argv) == PROGRAM_EXIT)
//    {
//        return EXIT_FAILURE;
//    }

//    config.configure(main);

//    srand(main->seed);

//    imAcqInit(imAcq);

//    if(main->showOutput)
//    {
//        gui->init();
//    }

//    main->doWork(n);

//    delete main;
//    main = NULL;
//    delete gui;
//    gui = NULL;

 //   return EXIT_SUCCESS;
    return 1;
}
