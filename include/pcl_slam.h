#ifndef PCL_SLAM_H
#define PCL_SLAM_H

#include <boost/make_shared.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/point_representation.h>

#include <pcl/io/pcd_io.h>

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>

#include <pcl/features/normal_3d.h>

#include <pcl/registration/icp.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>

#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>

#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>

class SLAMProcessor{

public:
	SLAMProcessor(int argc, char** argv);
	void addFrame(pcl::PointCloud<pcl::PointXYZ> &frame);
private:
	void showCloudsLeft(const pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_target, const pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_source);
	void showCloudsRight(const pcl::PointCloud<pcl::PointNormal>::Ptr cloud_target, const pcl::PointCloud<pcl::PointNormal>::Ptr cloud_source);
	void pairAlign (const pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src, const pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt, 
					pcl::PointCloud<pcl::PointXYZ>::Ptr output, Eigen::Matrix4f &final_transform, bool downsample = false);


/* please save */
/*	void computeSurfaceNormals (const pcl::PointCloud<pcl::PointXYZ>::Ptr &points, pcl::PointCloud<pcl::Normal>::Ptr &normals);
	void computeLocalFeatures (const pcl::PointCloud<pcl::PointXYZ>::Ptr &points, const pcl::PointCloud<pcl::Normal>::Ptr &normals, pcl::PointCloud<pcl::FPFHSignature33>::Ptr &features);
	static const float normal_radius = 0.02;
	static const float feature_radius = 0.002;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr search_method_xyz;

*/

	Eigen::Matrix4f m_sensorTransform ;
	std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr, Eigen::aligned_allocator<pcl::PointCloud<pcl::PointXYZ>::Ptr> > m_frames;
	pcl::PointCloud<pcl::PointXYZ>::Ptr m_globalCloud;
	//our visualizer
	pcl::visualization::PCLVisualizer *p;
	//its left and right viewports
	int vp_1, vp_2;
	int m_frameCount;

};

#endif