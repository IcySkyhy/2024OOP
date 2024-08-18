/*************************************************************************
【文件名】					Face3D.cpp
【功能模块和目的】				实现Face3D类中的成员函数
【开发者及日期】				胡延 2024.8.1
【更改记录】					2024.8.3 将成员函数改为可适配vector<Point3D>类型数据成员
*************************************************************************/

#include "Face3D.hpp"

#include <vector>

using namespace std;

Face3D::Face3D(Point3D p1, Point3D p2, Point3D p3) : m_Points(), Points(m_Points) {
	this->m_Points.push_back(p1);
	this->m_Points.push_back(p2);
	this->m_Points.push_back(p3);
}

/*************************************************************************
【函数名称】       			operator==
【函数功能】				重载==运算符，判断两个面是否相等
【参数】					Face3D& Face
【返回值】					bool
【开发者及日期】			胡延 2024.8.1
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
bool Face3D::operator==(const Face3D& Face) {
	return (m_Points[0] == Face.m_Points[0] && m_Points[1] == Face.m_Points[1] && m_Points[2] == Face.m_Points[2]) ||
		(m_Points[0] == Face.m_Points[1] && m_Points[1] == Face.m_Points[2] && m_Points[2] == Face.m_Points[0]) ||
		(m_Points[0] == Face.m_Points[2] && m_Points[1] == Face.m_Points[0] && m_Points[2] == Face.m_Points[1]);	
}

/*************************************************************************
【函数名称】       			operator=
【函数功能】				重载=运算符，将一个面赋值给另一个面
【参数】					Face3D& Face
【返回值】					Face3D&
【开发者及日期】			胡延 2024.8.1
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
Face3D& Face3D::operator=(const Face3D& Face) {
	m_Points = Face.m_Points;
	return *this;
}

/*************************************************************************
【函数名称】       		Area
【函数功能】			计算三角形的面积
【参数】				无
【返回值】				float
【开发者及日期】		胡延 2024.8.1
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
float Face3D::Area() const {
	// 海伦-秦九韶公式计算三角形面积
	float a = Points[0].dist(Points[1]);
	float b = Points[1].dist(Points[2]);
	float c = Points[2].dist(Points[0]);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

/*************************************************************************
【函数名称】       		Perimeter
【函数功能】			计算三角形的周长
【参数】				无
【返回值】				float
【开发者及日期】		胡延 2024.8.1
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
float Face3D::Perimeter() const {
	float a = Points[0].dist(Points[1]);
	float b = Points[1].dist(Points[2]);
	float c = Points[2].dist(Points[0]);
	return a + b + c;
}

/*************************************************************************
【函数名称】       		SetPoint
【函数功能】			通过索引设置面的顶点
【参数】				int Index, Point3D Point
【返回值】				void
【开发者及日期】		胡延 2024.8.1
【更改记录】			（若有修改，则必需注明）
*************************************************************************/
void Face3D::SetPoint(int Index, Point3D Point) {
	// 查询vector中是否有Index对应的元素
	for (auto i = m_Points.begin(); i != m_Points.end(); i++) {
		if (i->Index == Index) {
			*i = Point;
			return;
		}
	}
}
