/*************************************************************************
【文件名】					Model3D.hpp
【功能模块和目的】			实现继承于Model的Model3D类，用于描述从Importer导入的三维模型
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若修改过则必需注明）
*************************************************************************/

#ifndef Model3D_hpp
#define Model3D_hpp

#include "Model.cpp"
#include "Line3D.cpp"
#include "Face3D.cpp"
#include<vector>

using namespace std;

/*************************************************************************
【类名】             Model3D
【功能】             实现继承于Model的Model3D类，用于描述从Importer导入的三维模型
【接口说明】
继承Model类的所有接口
添加点、线、面
删除点、线、面
修改点、线、面
检查线、面是否存在
检查索引是否合法
常引用getter函数Points、Lines、Faces
getter函数TotalArea、TotalLength、BoundingBoxVolume
更新索引UpdateIndex
【开发者及日期】     胡延 2024.8.1
【更改记录】         （若修改过则必需注明）
*************************************************************************/
class Model3D : public Model {
private:
	vector <Point3D> m_Points = {};
	vector <Line3D>	 m_Lines = {};
	vector <Face3D>  m_Faces = {};
public:
	Model3D();
	~Model3D() {}
	// getters 
	const vector <Point3D>& Points { m_Points };
	const vector <Line3D>&  Lines  { m_Lines };
	const vector <Face3D>&  Faces  { m_Faces };
	float TotalArea() const;
	float TotalLength() const;
	float BoundingBoxVolume() const;
	// getters-check
	bool CheckFace(Face3D Face) const;
	bool CheckLine(Line3D Line) const;
	bool CheckValidIndex(string Type, int Index, int Check) const;

	// setters
	string AddFace(int FaceIndex[]);
	string AddLine(int LineIndex[]);
	string AddPoint(float PointCoords[]);

	string DelPoint(int Index);
	string DelLine(int Index);
	string DelFace(int Index);

	string ModFace(int ModFaceIndex, int OldFaceIndex, int NewFaceIndex);
	string ModLine(int ModLineIndex, int OldLineIndex, int NewLineIndex);
	string ModPoint(int ModPointIndex, float* NewPointCoord);

	// 重载删除函数
	void DelPoint(Point3D Point);
	void DelLine(Line3D Line);
	void DelFace(Face3D Face);

	void UpdateIndex();
};

#endif /* Model3D_hpp */