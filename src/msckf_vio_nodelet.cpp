/*
 * COPYRIGHT AND PERMISSION NOTICE
 * Penn Software MSCKF_VIO
 * Copyright (C) 2017 The Trustees of the University of Pennsylvania
 * All rights reserved.
 */

#include <msckf_vio/msckf_vio_nodelet.h>
#include <fstream>                                                                             // add

namespace msckf_vio {
void MsckfVioNodelet::onInit() {
    std::ofstream foutC("/home/vio/catkin_ws/src/msckf_vio/msckf_results_1.txt", std::ios::out);  // add
  foutC.close();                                                                               // add
  msckf_vio_ptr.reset(new MsckfVio(getPrivateNodeHandle()));
  if (!msckf_vio_ptr->initialize()) {
    ROS_ERROR("Cannot initialize MSCKF VIO...");
    return;
  }
  return;
}

PLUGINLIB_DECLARE_CLASS(msckf_vio, MsckfVioNodelet,
    msckf_vio::MsckfVioNodelet, nodelet::Nodelet);

} // end namespace msckf_vio

