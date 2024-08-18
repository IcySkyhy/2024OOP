/*************************************************************************
【文件名】					Controller.hpp
【功能模块和目的】				定义Controller类，用于控制程序的流程
【开发者及日期】				胡延 2024.8.3
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef Controller_hpp
#define Controller_hpp

#include "ExporterOBJ.cpp"
#include "ImporterOBJ.cpp"
#include <string>

using namespace std;

/*************************************************************************
【类名】            		Controller
【功能】             		控制器类，用于控制程序的流程
【接口说明】 
继承ExporterOBJ类和ImporterOBJ类的所有接口        		
常函数展示信息
添加面、线、点
删除面、线、点
展示修改面、线、点
修改面、线、点
导出
【开发者及日期】     		胡延 2024.8.1
【更改记录】         		
*************************************************************************/
class Controller : public ExporterOBJ, public ImporterOBJ {
public:
	Controller();
	// getter
	string ShowInf(int Option, int Index) const;
	string ShowFaceInModify(int Index) const;
	string ShowLineInModify(int Index) const;
	// setter
	string ShowPointInModify(int Index) const;
	string AddFace(int* AddFaceIndex);
	string AddLine(int* AddLineIndex);
	string AddPoint(float* AddPointCoord);
	string DelPoint(int DelPointIndex);
	string DelLine(int DelLineIndex);
	string DelFace(int DelFaceIndex);
	string ModFace(int ModFaceIndex, int OldFaceIndex, int NewFaceIndex);
	string ModLine(int ModLineIndex, int OldFaceIndex, int NewFaceIndex);
	string ModPoint(int Index, float Coord[]);

	void Export();
	~Controller() {}
};

#endif /* Controller_hpp */
