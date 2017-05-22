// This is low-integrity driver.
// This driver will publish only transform from 3dunit_link to 3d_unit_rot_laser
// Another node will agragate everything to pointclound.
// High integirty driver containts build-in cpp code laser driver. This Driver can be used only with SICK range finders.
// High integrate driver is meant for porting driver from ROS to another systems.

#include <iostream>
#include "driverLib.hpp"
#include <string>
#include <fstream>
driver_m3d m3d;
double encoderOffset;

struct rt{
    rt(int i, int s, std::string n)
    {
        index = i;
        subindex = s;
        name = n;
    }
    std::string name;
    int index;
    int subindex;
    int value;
};

int main(int argc, char** argv)
{

    if (argc< 3)
    {
        std::cout << "usage : " <<argv[0] << " IP dictionaryFile outputFile \n";
        return -1;

    }

    std::string ip = argv[1];
    std::string dictFile = argv[2];
    std::string outFile = argv[3];

    std::cout << "Ip       : " << ip << "\n";
    std::cout << "dictFile : " << dictFile << "\n";
    std::cout << "outFile  : " << outFile << "\n";



    std::vector<rt> regs;

//    regs.push_back(rt(0x3000, 0x00, "DEV_CMD"));
//    regs.push_back(rt(0x3000, 0x01, "DEV_CMD_ExecOnChange"));
//    regs.push_back(rt(0x3000, 0x00, "DEV_CMD"));
//    regs.push_back(rt(0x3000, 0x00, "DEV_CMD"));
//    regs.push_back(rt(0x3000, 0x00, "DEV_CMD"));
//    regs.push_back(rt(0x3000, 0x00, "DEV_CMD"));
//    regs.push_back(rt(0x3000, 0x00, "DEV_CMD"));


    std::ifstream f_dict;
    f_dict.open(dictFile.c_str());
    std::ofstream f_dump;
    f_dump.open(outFile.c_str());

    std::string line;
    while (std::getline(f_dict, line))
    {
        if (line[0] == '#')
            continue;
        std::istringstream iss(line);
        int i,s;
        std::string d;
        iss >>std::hex>> i;
        iss >>std::hex>> s;
        iss >> d;
        regs.push_back(rt(i, s, d));
        // process pair (a,b)
    }




    if (!m3d.connect_to_m3d(ip))
    {
        std::cout << "Problem connecting to unit \n";
        return -1 ;
    }
      int i=0;
      for (std::vector<rt>::iterator it = regs.begin(); it != regs.end(); it++)
      {
         std::cout << "reading param "<< i++ << " of " << regs.size() <<"\n";
         m3d.getParam(it->index, it->subindex, it->value);
         f_dump << std::hex << it->index << "\t";
         f_dump << std::hex << it->subindex << "\t";
         f_dump << it->name << "\t";
         f_dump << std::dec << it->value <<"\n";


      }
    f_dump.close();
//    //m3d.setSpeed(10);

//    //sleep(5);
//    m3d.setSpeed(0);

}
