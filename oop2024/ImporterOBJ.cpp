/*************************************************************************
【文件名】					ImporterOBJ.cpp
【功能模块和目的】				实现ImporterOBJ类中的成员函数
【开发者及日期】				胡延 2024.8.1
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#include "ImporterOBJ.hpp"

#include <fstream>
#include <iostream>
#include <vector>
#include<string>

using namespace std;

/*************************************************************************
【函数名称】				Import
【函数功能】				通过路径导入.obj文件
【参数】					string& path
【返回值】					string
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
ImporterOBJ::ImporterOBJ(const string& path) {
	if (path == "Create") {		
		// 创建新的模型
	}
	else{
			// 以路径读取文件
		ifstream File(path);
		if (!File.is_open()) {
			cout << "Failed to open the file.\n";
		}

		// 读取文件内容
		string Line;
		while (getline(File, Line)) {
			// 读取顶点
			if (Line[0] == 'v') {
				// 读取顶点坐标
				if (Line[1] == ' ') {
					float Coords[3] = {0};
					sscanf(Line.c_str(), 
						"v %f %f %f", &Coords[0], &Coords[1], &Coords[2]);
					ptd_Model.AddPoint(Coords);
				}
			}
			// 读取面
			else if (Line[0] == 'f') {
				// 读取面的顶点索引
				if (Line[1] == ' ') {
					int a, b, c;
					sscanf(Line.c_str(), 
						"f %d %d %d", &a, &b, &c);
					int FaceIndex[3] = {a, b, c};
					ptd_Model.AddFace(FaceIndex);
				}
			}
			else if (Line[0] == 'l') {
				// 读取线的顶点索引
				if (Line[1] == ' ') {
					int a, b;
					sscanf(Line.c_str(), "l %d %d", &a, &b);
					int LineIndex[2] = {a, b};
					ptd_Model.AddLine(LineIndex);
				}
			}
			else if (Line[0] == 'g') {
				// 读取组名
				if (Line[1] == ' ') {
					string Name = Line.substr(2);
					ptd_Model.SetName(Name);
				}
			}
			else {
				// 其他情况
			}
		}

		ptd_Model.UpdateIndex();

		File.close();
		system("cls");
		cout << "Imported successfully.\n";
	}
}

string ImporterOBJ::Import(const string& path) {
	// 以路径读取文件
	ifstream File(path);
	if (!File.is_open()) {
		return "Failed to open the file.\n";
	}

	// 读取文件内容
	string Line;
	while (getline(File, Line)) {
		// 读取顶点
		if (Line[0] == 'v') {
			// 读取顶点坐标
			if (Line[1] == ' ') {
				float Coords[3] = {0};
				sscanf(Line.c_str(), 
					"v %f %f %f", &Coords[0], &Coords[1], &Coords[2]);
				ptd_Model.AddPoint(Coords);
			}
		}
		// 读取面
		else if (Line[0] == 'f') {
			// 读取面的顶点索引
			if (Line[1] == ' ') {
				int a, b, c;
				sscanf(Line.c_str(), "f %d %d %d", &a, &b, &c);
				int FaceIndex[3] = {a, b, c};
				ptd_Model.AddFace(FaceIndex);
			}
		}
		else if (Line[0] == 'l') {
			// 读取线的顶点索引
			if (Line[1] == ' ') {
				int a, b;
				sscanf(Line.c_str(), "l %d %d", &a, &b);
				int LineIndex[2] = {a, b};
				ptd_Model.AddLine(LineIndex);
			}
		}
		else if (Line[0] == 'g') {
			// 读取组名
			if (Line[1] == ' ') {
				string Name = Line.substr(2);
				ptd_Model.SetName(Name);
			}
		}
		else {
			// 其他情况
		}
	}

	ptd_Model.UpdateIndex();

	File.close();
	system("cls");
	return "Imported successfully.\n";

}

/*************************************************************************
【函数名称】				Create
【函数功能】				创建新的模型
【参数】					无
【返回值】					string
【开发者及日期】			胡延 2024.8.1
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string ImporterOBJ::Create() {
	return "Model created successfully.\n";
}

