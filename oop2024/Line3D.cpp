/*************************************************************************
【文件名】					Line3D.cpp
【功能模块和目的】				实现Line3D类中的成员函数
【开发者及日期】				胡延 2024.8.1
【更改记录】					2024.8.3 修改成员函数使之适配vector
*************************************************************************/

#include "Line3D.hpp"

#include <vector>

using namespace std;

Line3D::Line3D(Point3D p1, Point3D p2) : m_Points(), Points(m_Points) {
	this->m_Points.push_back(p1);
	this->m_Points.push_back(p2);	
}

/*************************************************************************
【函数名称】				operator==
【函数功能】				重载==运算符判断两条线段是否相等
【参数】					Line3D& Line
【返回值】					bool
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
bool Line3D::operator==(const Line3D& Line) {
	return (m_Points[0] == Line.m_Points[0] && m_Points[1] == Line.m_Points[1]) ||
		(m_Points[0] == Line.m_Points[1] && m_Points[1] == Line.m_Points[0]);
}

/*************************************************************************
【函数名称】				operator=
【函数功能】				重载=运算符，将一条线段赋值给另一条线段
【参数】					Line3D& Line
【返回值】					Line3D&
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
Line3D& Line3D::operator=(const Line3D& Line) {
	m_Points = Line.m_Points;
	return *this;
}

/*************************************************************************
【函数名称】				Length
【函数功能】				计算线段的长度(两端点之间的距离)
【参数】					无
【返回值】					float
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
float Line3D::Length() const {
	return Points[0].dist(Points[1]);
}

/*************************************************************************
【函数名称】				SetPoint
【函数功能】				设置线段的端点
【参数】					int Index, Point3D Point
【返回值】					void
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
void Line3D::SetPoint(int Index, Point3D Point) {
	// 查询vector中是否有Index对应的元素
	for (auto i = m_Points.begin(); i != m_Points.end(); i++) {
		if (i->Index == Index) {
			*i = Point;
			return;
		}
	}
}

