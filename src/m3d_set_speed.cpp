// This is low-integrity driver.
// This driver will publish only transform from 3dunit_link to 3d_unit_rot_laser
// Another node will agragate everything to pointclound.
// High integirty driver containts build-in cpp code laser driver. This Driver can be used only with SICK range finders.
// High integrate driver is meant for porting driver from ROS to another systems.

#include <iostream>
#include "driverLib.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <string>
driver_m3d m3d;
double encoderOffset;


int main(int argc, char** argv)
{

    if (argc< 2)
    {
        std::cout << "usage : " <<argv[0] << " IP velocity \n";
        return -1;

    }

    std::string ip = argv[1];
    std::string velocity = argv[2];

    std::cout << "Ip       : " << ip << "\n";
    std::cout << "velocity : " << velocity << "\n";

    int v = std::stoi(velocity);

    if (!m3d.connect_to_m3d(ip))
    {
        std::cout << "Problem connecting to unit \n";
        return -1 ;
    }
    m3d.setSpeed(v);

//    //m3d.setSpeed(10);

//    //sleep(5);
//    m3d.setSpeed(0);

}
