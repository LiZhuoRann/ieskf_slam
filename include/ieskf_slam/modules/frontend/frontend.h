#pragma once
#include "ieskf_slam/modules/module_base.h"
#include "ieskf_slam/type/imu.h"
#include "ieskf_slam/type/base_type.h"
#include "ieskf_slam/type/pose.h"
// #include <iostream>


class FrontEnd : private ModuleBase {
public:
    using Ptr = std::shared_ptr<FrontEnd>
private:
    std::deque<IMU> imu_deque;
    std::deque<PointCloud> pointcloud_deque;
    std::deque<Pose> pose_deque;
    PCLPointCloud current_pointcloud;
public:
    FrontEnd(const std::string& config_file_path, const std::string prefix);
    ~FrontEnd();

    void addImu(const IMU& imu);
    void addPointCloud(const PointCloud& pointcloud);
    void addPose(const Pose& pose);

    bool track();

    const PCLPointCloud& readCurrentPointCloud();
};
