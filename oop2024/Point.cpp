/*************************************************************************
【文件名】					Point.cpp
【功能模块和目的】				实现Point类中的成员函数
【开发者及日期】				胡延 2024.7.21
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#include "Point.hpp"

#include <vector>
#include <cmath>

using namespace std;

Point::Point(vector <float> Coords): m_Coords(), Coord(m_Coords) {
	// 用迭代器
	for (auto it = Coords.begin(); it != Coords.end(); it++) {
		m_Coords.push_back(*it);
	}
}

/*************************************************************************
【函数名称】				operator=
【函数功能】				重载=运算符，将一个点赋值给另一个点
【参数】					Point& p
【返回值】					Point&
【开发者及日期】			胡延 2024.7.21
【更改记录】
*************************************************************************/
Point& Point::operator=(const Point& p) {
	this->m_Coords = p.Coord;
	return *this;
}

/*************************************************************************
【函数名称】				operator==
【函数功能】				重载==运算符，判断两个点是否相等
【参数】					Point& p
【返回值】					bool
【开发者及日期】			胡延 2024.7.21
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
bool Point::operator==(const Point& p) const {
	for (int i = 0; i < Coord.size(); i++) {
		if (Coord[i] != p.Coord[i]) {
			return false;
		}
	}
	return true;
}

Point::~Point() {}

/*************************************************************************
【函数名称】				SetCoords
【函数功能】				设置点的坐标
【参数】					vector <float> Coords
【返回值】					void
【开发者及日期】			胡延 2024.7.21
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
void Point::SetCoords(vector <float> Coords) {
	this->m_Coords = Coords;
}

/*************************************************************************
【函数名称】				dist
【函数功能】				计算两点之间的距离
【参数】					Point& p
【返回值】					const float
【开发者及日期】			胡延 2024.7.21
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
float Point::dist(Point& p) const {
	float sum = 0;
	for (int i = 0; i < Coord.size(); i++) {
		sum += (Coord[i] - p.Coord[i]) * (m_Coords[i] - p.Coord[i]);
	}
	return sqrt(sum);
}

/*************************************************************************
【函数名称】				dist
【函数功能】				计算两点之间的距离
【参数】					Point p
【返回值】					const float
【开发者及日期】			胡延 2024.7.21
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
float Point::dist(Point p) const {
	float sum = 0;
	for (int i = 0; i < Coord.size(); i++) {
		sum += (Coord[i] - p.Coord[i]) * (m_Coords[i] - p.Coord[i]);
	}
	return sqrt(sum);
}
