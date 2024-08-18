/*************************************************************************
【文件名】					ExporterOBJ.cpp
【功能模块和目的】				实现Exporter类中的成员函数
【开发者及日期】				胡延 2024.8.3
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#include "ExporterOBJ.hpp"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*************************************************************************
【函数名称】       			ExporterOBJ::Exporter()
【函数功能】       			导出模型信息到.obj文件
【参数】           			输入参数Model3D& Model
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::Exporter(Model3D& Model) {

	// 打开文件
	std::ofstream file("cube.obj");
	Model.UpdateIndex();	

	// 写入顶点
	for (auto& Point3D : Model.Points) {
		file << "v " << Point3D.Coord[0] << " " << Point3D.Coord[1] << " " << Point3D.Coord[2] << endl;
	}

	// 写入线
	for (auto& Line3D : Model.Lines) {
		file << "l ";
		for (const auto& Point3D : Line3D.Points) {
			file << Point3D.Index + 1 << " ";
		}
		file << endl;
	}

	// 写入面（OBJ中的面索引从1开始）
	for (auto& Face3D : Model.Faces) {
		file << "f ";
		for (const auto& Point3D : Face3D.Points) {
			file << Point3D.Index + 1 << " ";
		}
		file << endl;
	}

	// 关闭文件
	file.close();

	return "OBJ file has been created successfully.\nExporting model " + Model.Name + " to .obj file.\n";
}

/*************************************************************************
【函数名称】       			ExporterOBJ::ShowModel()
【函数功能】      			展示模型的信息
【参数】           			输入参数const Model3D& Model
							输出参数无
【返回值】      			string
【开发者及日期】  			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::ShowModel(const Model3D& Model) const {
	// 展示整个模型的信息
	cout << "Model Name: " << Model.Name << endl;
	// Point3D总数（空间坐标重叠的顶点重复计数）
	cout << "Points: " << Model.Points.size() << endl;
	// Line3D总数和总长度
	cout << "Lines: " << Model.Lines.size() << endl;
	cout << "Total Length:" << Model.TotalLength() << endl;
	// Face3D总数和总面积
	cout << "Faces: " << Model.Faces.size() << endl;
	cout << "Total Area: " << Model.TotalArea() << endl;
	// 包围盒体积（能框住所有Point3D的最小立方体体积，立方体各边分别与三维坐标轴平行）
	cout << "Bounding Box Volume: " << Model.BoundingBoxVolume() << endl;
	return "Successfully Shown.\n";
}

/*************************************************************************
【函数名称】       		ExporterOBJ::ShowFace()
【函数功能】       		展示所有面的信息
【参数】          		输入参数const Model3D& Model
【返回值】         		string
【开发者及日期】    	胡延 2024.8.3
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::ShowFace(const Model3D& Model) const {
	cout << "Model Name: " << Model.Name << endl;
	for (int i = 0; i < Model.Faces.size(); i++) {
		cout << "Face " << i + 1 << ": " << "Area: " << Model.Faces[i].Area() << " Points: ";
		for (int j = 0; j < Model.Faces[i].Points.size(); j++) {
			cout << Model.Faces[i].Points[j].Index << " ";
		}
		cout << endl;
	}
	return "Successfully Shown.\n";
}

/*************************************************************************
【函数名称】       		ExporterOBJ::ShowLine()
【函数功能】     		展示所有线的信息
【参数】           		输入参数const Model3D& Model
【返回值】         		string
【开发者及日期】   		胡延 2024.8.3
【更改记录】         	（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::ShowLine(const Model3D& Model) const {
	// 展示所有线的信息
	cout << "Model Name: " << Model.Name << endl;
	for (int i = 0; i < Model.Lines.size(); i++) {
		cout << "Line " << i + 1 << ":" << " Length: " << Model.Lines[i].Length() << " Points: ";
		for (int j = 0; j < Model.Lines[i].Points.size(); j++) {
			cout << Model.Lines[i].Points[j].Index << " ";
		}
		cout << endl;
	}
	return "Successfully Shown.\n";
}	

/*************************************************************************
【函数名称】       		ExporterOBJ::ShowFacePoints()
【函数功能】       		展示某个面的所有点的信息
【参数】          		输入参数const Model3D& Model, int Index
【返回值】         		string
【开发者及日期】   		胡延 2024.8.3
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::ShowFacePoints(const Model3D& Model, int Index) const {
	cout << "Face " << Index << ": ";
	// 输出每个点的索引和坐标
	for (int j = 0; j < Model.Faces[Index-1].Points.size(); j++) {
		cout << "Point " << Model.Faces[Index-1].Points[j].Index << " Coords: " << Model.Faces[Index-1].Points[j].Coord << endl;
	}
	cout << endl;
	return "Successfully Shown.\n";
}	

/*************************************************************************
【函数名称】       		ExporterOBJ::ShowLinePoints()
【函数功能】       		展示某个线的所有点的信息
【参数】          		输入参数const Model3D& Model, int Index
【返回值】         		string
【开发者及日期】   		胡延 2024.8.3
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::ShowLinePoints(const Model3D& Model, int Index) const {
	cout << "Line " << Index << ": ";
	// 输出每个点的索引和坐标
	for (int j = 0; j < Model.Lines[Index - 1].Points.size(); j++) {
		cout << "Point " << Model.Lines[Index - 1].Points[j].Index << " Coords: " << Model.Lines[Index - 1].Points[j].Coord << endl;
	}
	cout << endl;
	return "Successfully Shown.\n";
}	

/*************************************************************************
【函数名称】       		ExporterOBJ::ShowPointCoords()
【函数功能】       		展示某个点的坐标
【参数】          		输入参数const Model3D& Model, int Index
【返回值】        		string
【开发者及日期】  		胡延 2024.8.3
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
string ExporterOBJ::ShowPointCoords(const Model3D& Model, int Index) const {
	cout << "Point " << Index << ": ";
	// 输出每个点的索引和坐标
	cout << "Coords: " << Model.Points[Index - 1].Coord << endl;
	cout << endl;
	return "Successfully Shown.\n";
}

/*************************************************************************
【函数名称】       		operator<<
【函数功能】       		重载输出运算符，输出vector<float>类型的数据
【参数】           		输入参数ostream& out, const vector<float>& Vec
【返回值】         		ostream&
【开发者及日期】   		胡延 2024.8.3
【更改记录】       		（若有修改，则必需注明）
*************************************************************************/
ostream& operator<<(ostream& out, const vector<float>& Vec) {
	out << "(";
	for (const auto& i : Vec) {
		out << i << " ";
	}
	out << ")\n";
	return out;
}
