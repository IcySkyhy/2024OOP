/*************************************************************************
【文件名】						Face3D.hpp
【功能模块和目的】				定义Face3D类，实现三维空间中的（三角形）面
【开发者及日期】				胡延 2024.8.1
【更改记录】					2024.8.3 将Face3D类的数据成员改为vector<Point3D>类型
*************************************************************************/

#ifndef Face3D_hpp
#define Face3D_hpp

#include "Point3D.hpp"

/*************************************************************************
【类名】            		Face3D
【功能】             		定义Face3D类，实现三维空间中的（三角形）面
【接口说明】         		
用Point3D构造函数
重载运算符==和=
getter函数Area和Perimeter
常引用getter函数Points
setter函数SetPoint
【开发者及日期】     		胡延 2024.8.1
【更改记录】         		（若修改过则必需注明）
*************************************************************************/
class Face3D {
private:
	vector <Point3D> m_Points;
public:
	Face3D() = delete;
	Face3D(Point3D p1, Point3D p2, Point3D p3);
	// 运算符重载
	bool operator==(const Face3D& Face);
	Face3D& operator=(const Face3D& Face);
	// getter
	float Area() const;
	float Perimeter() const;
	const vector <Point3D>& Points{ m_Points };
	// setter
	void SetPoint(int Index, Point3D Point);
	~Face3D() {}
};

#endif /* Face3D_hpp */
