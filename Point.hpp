/*************************************************************************
【文件名】					Point.hpp
【功能模块和目的】				定义Point类作为Point3D类的基类，可扩展到不同的维度
【开发者及日期】				胡延 2024.7.21
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef Point_hpp
#define Point_hpp

#include <vector>

using namespace std;

/*************************************************************************
【类名】					Point
【功能】					作为Point3D类的基类，实现点的基本功能
【接口说明】				通过SetCoords()函数设置坐标，dist()函数计算两点之间的距离
							通过Coords引用获取点的坐标
【开发者及日期】			胡延 2024.7.21
【更改记录】				（若修改过则必需注明）
*************************************************************************/
class Point {
private:
	vector <float> m_Coords = {};
public:
	Point() {}
	Point(vector <float> coords);
	// 重载赋值运算符
	Point& operator=(const Point& p);
	bool operator==(const Point& p) const;
	// getters
	const vector <float>& Coord { m_Coords};
	float dist(Point& p) const;
	float dist(Point p) const;
	// setter
	void SetCoords(vector <float> Coords);
	~Point();
};

#endif /* Point_hpp */
