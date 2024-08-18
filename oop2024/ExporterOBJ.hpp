/*************************************************************************
【文件名】					ExporterOBJ.hpp
【功能模块和目的】				在Exporter类的基础上，实现ExporterOBJ类，用于导出信息和.obj格式的文件
【开发者及日期】				胡延 2024.8.3
【更改记录】					（若修改过则必需注明）
*************************************************************************/
#ifndef ExporterOBJ_hpp
#define ExporterOBJ_hpp

#include "Exporter.hpp"

/*************************************************************************
【类名】            	ExporterOBJ
【功能】             	在Exporter类的基础上，实现ExporterOBJ类，用于导出信息和.obj格式的文件
【接口说明】         		
重载运算符<<
导出模型信息
展示模型信息
展示面信息
展示线信息
展示面的点信息
展示线的点信息
展示点的坐标信息
【开发者及日期】     		胡延 2024.8.1
【更改记录】         		2024.8.3 将函数分离至ExporterOBJ类中
*************************************************************************/
class ExporterOBJ : public Exporter {
public:
	ExporterOBJ() {}
	// 重载运算符<<
	friend ostream& operator<<(ostream& os, const vector<float>& Vec);
	// 导出模型信息
	string Exporter(Model3D& Model);
	// getters
	string ShowModel(const Model3D& Model) const;
	string ShowFace(const Model3D& Model) const;
	string ShowLine(const Model3D& Model) const;
	string ShowFacePoints(const Model3D& Model, int Index) const;
	string ShowLinePoints(const Model3D& Model, int Index) const;
	string ShowPointCoords(const Model3D& Model, int Index) const;

	~ExporterOBJ() {}
};

#endif /* ExporterOBJ_hpp */