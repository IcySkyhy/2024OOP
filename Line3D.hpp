/*************************************************************************
【文件名】					Line3D.hpp
【功能模块和目的】				定义Line3D类，实现两三维点之间的线段
【开发者及日期】				胡延 2024.8.1
【更改记录】					2024.8.3 将Line3D类的数据成员改为vector<Point3D>类型
*************************************************************************/

#ifndef Line3D_hpp
#define Line3D_hpp

#include "Point3D.cpp"

/*************************************************************************
【类名】             	Line3D
【功能】             	定义Line3D类，实现两三维点之间的线段
【接口说明】
用Point3D构造函数
重载运算符==和=
重载运算符=
getter函数Length
常引用getter函数Points
setter函数SetPoint
【开发者及日期】     	胡延 2024.8.1
【更改记录】         	（若修改过则必需注明）
*************************************************************************/
class Line3D {
private:
	vector <Point3D> m_Points = {};
public:
	Line3D() = delete;
	Line3D(Point3D p1, Point3D p2);
	// 重载运算符
	bool operator==(const Line3D& Line);
	Line3D& operator=(const Line3D& Line);
	// getter
	const vector <Point3D>& Points { m_Points };
	float Length() const;
	// setter
	void SetPoint(int Index, Point3D Point);
	~Line3D() {}
};

#endif /* Line3D_hpp */