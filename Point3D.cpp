/*************************************************************************
【文件名】					Point3D.cpp
【功能模块和目的】				实现Point3D类中的成员函数
【开发者及日期】				胡延 2024.7.31
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#include "Point3D.hpp"

#include <vector>
#include <iostream>

using namespace std;

Point3D::Point3D() : m_Index(0) {
	vector <float> Coords = { 0, 0, 0 };
	Point::SetCoords(Coords);
}

Point3D::Point3D(vector <float> Coords) : m_Index(0) {
	if (Coords.size() != 3) {
		throw invalid_argument("Point3D must have 3 coordinates");
	}
	Point::SetCoords(Coords);
}

Point3D::Point3D(float x, float y, float z) : m_Index(0) {
	vector <float> Coords = { x, y, z };
	Point::SetCoords(Coords);
}

/*************************************************************************
【函数名称】				operator==
【函数功能】				重载==运算符，判断两个点是否相等
【参数】					Point3D& Point
【返回值】					bool
【开发者及日期】			胡延 2024.7.31
*************************************************************************/
bool Point3D::operator==(const Point3D& Point) const {
	return Coord == Point.Coord;
}

/*************************************************************************
【函数名称】				operator=
【函数功能】				重载=运算符，将一个点赋值给另一个点
【参数】					Point3D& Point
【返回值】					Point3D&
【开发者及日期】			胡延 2024.7.31
*************************************************************************/
Point3D& Point3D::operator=(const Point3D& Point) {
	Point::SetCoords(Point.Coord);
	return *this;
}

/*************************************************************************
【函数名称】				SetCoords
【函数功能】				设置点的坐标
【参数】					float x, float y, float z
【返回值】					void
【开发者及日期】			胡延 2024.7.31
*************************************************************************/
void Point3D::SetCoords(float x, float y, float z) {
	vector <float> Coords = { x, y, z };
	Point::SetCoords(Coords);
}

/*************************************************************************
【函数名称】				SetIndex
【函数功能】				设置点的索引
【参数】					int Index
【返回值】					void
【开发者及日期】			胡延 2024.7.31
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
void Point3D::SetIndex(int Index) {
	m_Index = Index;
}

/*************************************************************************
【函数名称】				dist
【函数功能】				计算两点之间的距离
【参数】					Point3D& p
【返回值】					const float
【开发者及日期】			胡延 2024.7.31
*************************************************************************/
float Point3D::dist(Point3D& p) const {
	float sum = 0;
	for (int i = 0; i < Coord.size(); i++) {
		sum += (Coord[i] - p.Coord[i]) * (Coord[i] - p.Coord[i]);
	}
	return sqrt(sum);
}

/*************************************************************************
【函数名称】				dist
【函数功能】				计算两点之间的距离
【参数】					Point3D p
【返回值】					const float
【开发者及日期】			胡延 2024.7.31
*************************************************************************/
float Point3D::dist(Point3D p) const {
	float sum = 0;
	for (int i = 0; i < Coord.size(); i++) {
		sum += (Coord[i] - p.Coord[i]) * (Coord[i] - p.Coord[i]);
	}
	return sqrt(sum);
}