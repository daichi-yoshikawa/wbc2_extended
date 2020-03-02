#include <iostream>
#include <memory>
#include "Eigen/Dense"

#include "wbc2/robot/robot.hpp"
#include "wbc2_extended/timer.hpp"

using namespace wbc2::robot;
using namespace wbc2::ext;

int main(int argc, char** argv)
{
  Timer timer = Timer();
  timer.test();

  Eigen::Matrix3d m;
  std::cout << m << std::endl;

  RobotPtr robot = std::make_shared<Robot>("sample_arm");
  robot->test();

  return 0;
}
