/*************************************************************************
【文件名】					Point3D.hpp
【功能模块和目的】				在Point类的基础上定义Point3D类，实现三维点的功能
【开发者及日期】				胡延 2024.7.31
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef Point3D_hpp
#define Point3D_hpp

#include "Point.cpp"

#include <vector>

/*************************************************************************
【类名】					Point3D
【功能】					作为Point类的派生类，实现三维点的功能
【接口说明】				通过SetCoords()函数设置坐标，dist()函数计算两点之间的距离，通过SetIndex()函数设置点的索引
						通过Index引用获取点的索引，由Point类继承而来的Coords引用获取点的坐标
【开发者及日期】			胡延 2024.7.31
【更改记录】				（若修改过则必需注明）
*************************************************************************/
class Point3D: public Point {
private:
	int m_Index = 0;
public:
	Point3D();
	Point3D(vector <float> Coords);
	Point3D(float x, float y, float z);
	// 重载赋值运算符
	bool operator==(const Point3D& Point) const;
	Point3D& operator=(const Point3D& Point);
	// getters
	float dist(Point3D& p) const;
	float dist(Point3D p) const;
	const int& Index { m_Index };
	// setters
	void SetCoords(float x, float y, float z);
	void SetIndex(int Index);
	~Point3D() {}
};

#endif /* Point3D_hpp */