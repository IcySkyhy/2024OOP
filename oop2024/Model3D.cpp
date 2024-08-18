/*************************************************************************
【文件名】					Model3D.cpp
【功能模块和目的】				实现Model3D类中的成员函数
【开发者及日期】				胡延 2024.8.1
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef Model3D_cpp
#define Model3D_cpp

#include "Model3D.hpp"

#include <cmath>

Model3D::Model3D() : m_Faces(), m_Lines(), m_Points(), 
	Faces(m_Faces), Lines(m_Lines), Points(m_Points) {}

/*************************************************************************
【函数名称】				CheckFace()
【函数功能】				检查面是否合法
【参数】					输入：Face3D Face 输出：无
【返回值】					布尔值，表示面是否合法
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
bool Model3D::CheckFace(Face3D Face) const {
	//检查面的三个顶点是否重合，顺序不同也算重合
	for (auto it = m_Faces.begin(); it != m_Faces.end(); it++) {
		int Check = 0;
		for (int i = 0; i < 3; i++) {
			int Judge = 0;
			for (int j = 0; j < 3; j++) {
				if (Face.Points[i] == it->Points[j]) {
					Judge ++;
				}
			}
			if (Judge != 0) {
				Check ++;
			}
		}
		if (Check == 3) {
			return true;
		}
	}
	return false;
}

/*************************************************************************
【函数名称】				CheckLine()
【函数功能】				检查线是否合法
【参数】					输入：Line3D Line 输出：无
【返回值】					布尔值，表示线是否合法
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
bool Model3D::CheckLine(Line3D Line) const {
	//线段的两个端点不能重合，顺序不同也算重合
	for (auto it = m_Lines.begin(); it != m_Lines.end(); it++) {
		int Check = 0;
		for (int i = 0; i < 2; i++) {
			int Judge = 0;
			for (int j = 0; j < 2; j++) {
				if (Line.Points[i] == it->Points[j]) {
					Judge++;
				}
			}
			if (Judge != 0) {
				Check++;
			}
		}
		if (Check == 2) {
			return true;
		}
	}
	return false;
}

/*************************************************************************
【函数名称】				AddFace()
【函数功能】				通过点索引添加面
【参数】					输入：int FaceIndex[] 输出：无
【返回值】					字符串，表示添加面是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::AddFace(int FaceIndex[]) {
	//通过三个点构造一个面
	//检查三个点是否在范围内
	if (FaceIndex[0] > m_Points.size() 
		|| FaceIndex[1] > m_Points.size() 
		|| FaceIndex[2] > m_Points.size()
		|| FaceIndex[0] < 1 || FaceIndex[1] < 1 || FaceIndex[2] < 1) {
		return "Failed to add face. Invalid Point.\n";
	}
	Face3D Face(Points[FaceIndex[0] - 1], Points[FaceIndex[1] - 1], Points[FaceIndex[2] - 1]);
	//防止三个点共线
	if (Face.Area() == 0) {
		return "Failed to add face. Three points are on the same line.\n";
	}
	//防止两个面的三个顶点重合
	if (CheckFace(Face)) {
		return "Failed to add face. Two faces have the same three points.\n";
	}
	m_Faces.push_back(Face);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				AddLine()
【函数功能】				通过点索引添加线
【参数】					输入：int LineIndex[] 输出：无
【返回值】					字符串，表示添加线是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::AddLine(int LineIndex[]) {
	//通过两个点构造一条线
	//检查两个点是否在范围内
	if (LineIndex[0] > m_Points.size() || LineIndex[1] > m_Points.size() 
		|| LineIndex[0] < 1 || LineIndex[1] < 1) {
		return "Failed to add line. Invalid Point.\n";
	}
	//防止两个点重合
	if (LineIndex[0] == LineIndex[1]) {
		return "Failed to add line. Two points are the same.\n";
	}
	Line3D Line(Points[LineIndex[0] - 1], Points[LineIndex[1] - 1]);
	//防止两条线的两个端点重合
	if (CheckLine(Line)) {
		return "Failed to add line. Two lines have the same two points.\n";
	}
	m_Lines.push_back(Line);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				AddPoint()
【函数功能】				通过坐标添加点
【参数】					输入：float PointCoords[] 输出：无
【返回值】					字符串，表示添加点是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::AddPoint(float PointCoords[]) {
	//通过坐标构造一个点
	Point3D Point(PointCoords[0], PointCoords[1], PointCoords[2]);
	m_Points.push_back(Point);
	UpdateIndex();
	return "Success.\n";
}

/*************************************************************************
【函数名称】				DelPoint()
【函数功能】				通过索引删除点
【参数】					输入：int Index 输出：无
【返回值】					字符串，表示删除点是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::DelPoint(int Index) {
	//通过Index删除一个点
	if (Index < 1 || Index > m_Points.size()) {
		return "Failed to delete point. Invalid Index.\n";
	}
	m_Points.erase(m_Points.begin() + Index - 1);
	UpdateIndex();
	return "Success.\n";
}

/*************************************************************************
【函数名称】				DelLine()
【函数功能】				通过索引删除线
【参数】					输入：int Index 输出：无
【返回值】					字符串，表示删除线是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::DelLine(int Index) {
	//通过Index删除一条线
	if (Index < 1 || Index > m_Lines.size()) {
		return "Failed to delete line. Invalid Index.\n";
	}
	m_Lines.erase(m_Lines.begin() + Index - 1);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				DelFace()
【函数功能】				通过索引删除面
【参数】					输入：int Index 输出：无
【返回值】					字符串，表示删除面是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::DelFace(int Index) {
	//通过Index删除一个面
	if (Index < 1 || Index > m_Faces.size()) {
		return "Failed to delete face. Invalid Index.\n";
	}
	m_Faces.erase(m_Faces.begin() + Index - 1);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				DelPoint()
【函数功能】				通过查找特定点进行删除
【参数】					输入：Point3D Point 输出：无
【返回值】					无
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
void Model3D::DelPoint(Point3D Point) {
	//通过搜索删除一个点
	for (auto it = m_Points.begin(); it != m_Points.end(); it++) {
		if (*it == Point) {
			m_Points.erase(it);
			break;
		}
	}
	UpdateIndex();
}

/*************************************************************************
【函数名称】				DelLine()
【函数功能】				通过查找线进行删除
【参数】					输入：Line3D Line 输出：无
【返回值】					无
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
void Model3D::DelLine(Line3D Line) {
	//通过搜索删除一条线
	for (auto it = m_Lines.begin(); it != m_Lines.end(); it++) {
		if (*it == Line) {
			m_Lines.erase(it);
			break;
		}
	}
	UpdateIndex();
}

/*************************************************************************
【函数名称】				DelFace()
【函数功能】				通过查找面进行删除
【参数】					输入：Face3D Face 输出：无
【返回值】					无
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
void Model3D::DelFace(Face3D Face) {
	//通过搜索删除一个面
	for (auto it = m_Faces.begin(); it != m_Faces.end(); it++) {
		if (*it == Face) {
			m_Faces.erase(it);
			break;
		}
	}
	UpdateIndex();
}

/*************************************************************************
【函数名称】				UpdateIndex()
【函数功能】				更新点的Index
【参数】					无
【返回值】					无
【开发者及日期】			胡延 2024.8.12
*************************************************************************/
void Model3D::UpdateIndex() {
	//更新点的Index
	for (int i = 0; i < m_Points.size(); i++) {
		m_Points[i].SetIndex(i);
	}
}

/*************************************************************************
【函数名称】				CheckValidIndex()
【函数功能】				检查Index是否在范围内
【参数】					输入：string Type, int Index, int Check 输出：无
【返回值】					布尔值，表示Index是否在范围内
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
bool Model3D::CheckValidIndex(string Type, int Index, int Check) const {
	//检查元素的Index是否在范围内
	if (Type == "Point") {
		if (Index < 1 || Index > m_Points.size()) {
			return false;
		}
	}
	// 寻找Index是否能匹配到Line的两个Point或Face的三个Point中的一个，而不是直接判断Index是否在范围内
	else if (Type == "Line") {
		if (Check == m_Lines[Index - 1].Points[0].Index || Check == m_Lines[Index - 1].Points[1].Index) {
			return false;
		}
	}
	else if (Type == "Face") {
		if (Check == m_Faces[Index - 1].Points[0].Index 
			|| Check == m_Faces[Index - 1].Points[1].Index 
			|| Check == m_Faces[Index - 1].Points[2].Index) {
			return false;
		}
	}
	return true;
}

/*************************************************************************
【函数名称】				ModFace()
【函数功能】				输入要修改的点的索引，通过新索引更改面
【参数】					输入：int ModFaceIndex, int OldFaceIndex, int NewFaceIndex 输出：无
【返回值】					字符串，表示修改面是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::ModFace(int ModFaceIndex, int OldFaceIndex, int NewFaceIndex) {
	//通过索引更改来修改面
	//检查Index是否在范围内
	if (CheckValidIndex("Face", ModFaceIndex, OldFaceIndex) 
		|| NewFaceIndex < 1 || NewFaceIndex > m_Points.size()) {
		return "Failed to modify face. Invalid Index.\n";
	}
	m_Faces[ModFaceIndex - 1].SetPoint(OldFaceIndex, m_Points[NewFaceIndex - 1]);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				ModLine()
【函数功能】				输入要修改的点的索引，通过新索引更改线
【参数】					输入：int ModLineIndex, int OldLineIndex, int NewLineIndex 输出：无
【返回值】					字符串，表示修改线是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::ModLine(int ModLineIndex, int OldLineIndex, int NewLineIndex) {
	//通过索引更改来修改线
	//检查Index是否在范围内
	if (CheckValidIndex("Line", ModLineIndex, OldLineIndex) 
		|| NewLineIndex < 1 || NewLineIndex > m_Points.size()) {
		return "Failed to modify line. Invalid Index.\n";
	}
	m_Lines[ModLineIndex - 1].SetPoint(OldLineIndex, m_Points[NewLineIndex - 1]);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				ModPoint()
【函数功能】				输入要修改的点的索引，通过新坐标更改点
【参数】					输入：int ModPointIndex, float NewPointCoord[] 输出：无
【返回值】					字符串，表示修改点是否成功
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string Model3D::ModPoint(int ModPointIndex, float* NewPointCoord) {
	//修改特定索引点的坐标
	//检查Index是否在范围内
	if (ModPointIndex < 1 || ModPointIndex > m_Points.size()) {
		return "Failed to modify point. Invalid Index.\n";
	}
	m_Points[ModPointIndex - 1].SetCoords(NewPointCoord[0], NewPointCoord[1], NewPointCoord[2]);
	return "Success.\n";
}

/*************************************************************************
【函数名称】				TotalArea()
【函数功能】				计算所有面的面积之和
【参数】					无
【返回值】					浮点数，表示所有面的面积之和
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
float Model3D::TotalArea() const{
	//计算所有面的面积之和
	float Area = 0;
	for (int i = 0; i < m_Faces.size(); i++) {
		Area += m_Faces[i].Area();
	}
	return Area;
}

/*************************************************************************
【函数名称】				TotalLength()
【函数功能】				计算所有线的长度之和
【参数】					无
【返回值】					浮点数，表示所有线的长度之和
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
float Model3D::TotalLength() const {
	//计算所有线的长度之和
	float Length = 0;
	for (int i = 0; i < Lines.size(); i++) {
		Length += Lines[i].Length();
	}
	return Length;
}

/*************************************************************************
【函数名称】				BoundingBoxVolume()
【函数功能】				计算包围盒的体积
【参数】					无
【返回值】					浮点数，表示包围盒的体积
【开发者及日期】			胡延 2024.8.12
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
float Model3D::BoundingBoxVolume() const {
	//计算包围盒的体积
	if (m_Points.empty()) {
		return 0;
	}
	float MinX = 1e9, MinY = 1e9, MinZ = 1e9;
	float MaxX = -1e9, MaxY = -1e9, MaxZ = -1e9;
	for (const auto& Point : m_Points) {
		MinX = min(MinX, Point.Coord[0]);
		MinY = min(MinY, Point.Coord[1]);
		MinZ = min(MinZ, Point.Coord[2]);
		MaxX = max(MaxX, Point.Coord[0]);
		MaxY = max(MaxY, Point.Coord[1]);
		MaxZ = max(MaxZ, Point.Coord[2]);
	}
	float Length = max(max(MaxX - MinX, MaxY - MinY), MaxZ - MinZ);
	return (MaxX - MinX) * (MaxY - MinY) * (MaxZ - MinZ);
}

#endif /* Model3D_cpp */
