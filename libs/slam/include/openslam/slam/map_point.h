#ifndef OPENSLAM_SLAM_MAP_POINT_H_
#define OPENSLAM_SLAM_MAP_POINT_H_

#include <openslam/slam/link_pragmas.h>
#include <list>
#include <memory>
#include <mutex>
#include <opencv2/core/core.hpp>

namespace openslam
{
	namespace slam
	{
		class Feature;

		class SLAM_IMPEXP MapPoint
		{
		public:
			MapPoint(const cv::Mat &pos, Feature * cur_obs);
			~MapPoint();
			/**���ӹ۲⵽�Ķ�Ӧ����*/
			void addFeatureRef(Feature* ftr);

			/** \brief �����ͬһ��mappoint���ж�Ӧ�����������������ӽ��д�����Ѱ�����������
			*/
			void computeDistinctiveDescriptors();

			/** \brief ����map point�ķ���������Ӧ���ܵ������С���
			*/
			void updateNormalAndDepth();

		public:
			long unsigned int id_;                                   //!< ��Ψһ��id
			static long unsigned int map_point_counter_;             //!< ������ļ�������������Ψһ��id
			cv::Mat world_position_;                                 //!<����������ϵ�е�λ��
			cv::Mat normal_vector_;                                  //!<ƽ���۲ⷽ��
			std::list<Feature*>   obs_;                              //!< ��Ӧ��������������
			Feature * cur_obs_;//!<��Ӧ���map point �ĵ�ǰ����
			int obs_num_;                                            //!< �۲쵽��map point�Ĺؼ�֡�ĸ���
			std::mutex mutex_features_;//!< �Ե��Ӧ��������д���п���
			std::mutex mutex_position_;//!< �Ե��Ӧ��λ�ý��ж�д����
			cv::Mat descriptor_;//!<�õ���map point ��Ӧ����������ӣ��������ؼ�֡�Ըõ�����������С��
			float min_distance_;//!<�߶Ȳ��䣬��Ч�۲������Сֵ
			float max_distance_;//!<�߶Ȳ��䣬��Ч�۲�������ֵ
		};

	}
}

#endif // OPENSLAM_SLAM_MAP_POINT_H_