/*************************************************************************
【文件名】					Controller.cpp
【功能模块和目的】				实现Controller类中的成员函数
【开发者及日期】				胡延 2024.8.3
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#include "Controller.hpp"

Controller::Controller() {}

/*************************************************************************
【函数名称】       			Controller::ShowInf
【函数功能】       			显示信息主函数
【参数】          			int Option
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ShowInf(int Option) const { 
	switch (Option) {
	case 1:
		//向下传递，显示点的信息
		cout << ShowModel(ptd_Model);
		break;
	case 2:
		//向下传递，显示面的信息
		cout << ShowFace(ptd_Model);
		break;
	case 3:
	{
		// 通过输入的面的索引来显示面的信息
		cout << "Please input the index of the face you want to show: ";
		int Index = 0;
		do {
			cin >> Index;
			if (Index < 0 || Index >= ptd_Model.Faces.size()) {
				cout << "Invalid Index, please try again: ";
			}
		} while (Index < 0 || Index >= ptd_Model.Faces.size());
		cout << ShowFacePoints(ptd_Model, Index);
		break;
	}
	case 4:
		//向下传递，显示线的信息
		cout << ShowLine(ptd_Model);
		break;
	case 5:
	{
		// 通过输入的线的索引来显示线的信息
		cout << "Please input the index of the line you want to show: ";
		int Index;
		do {
			cin >> Index;
			if (Index < 0 || Index >= ptd_Model.Lines.size()) {
				cout << "Invalid Index, please try again: ";
			}
		} while (Index < 0 || Index >= ptd_Model.Lines.size());
		cout << ShowLinePoints(ptd_Model, Index);
		break;
	}
	case 6:
		return "Back.\n";
		break;
	default:
		return "Invalid Option.\n";
		break;
	}
	return "Successfully Shown.\n";
}

/*************************************************************************
【函数名称】       			Controller::Export
【函数功能】       			函数传递，调用Exporter类中的Exporter函数，将模型导出
【参数】           			无
【返回值】         			void
【开发者及日期】   			胡延 2024.8.3
*************************************************************************/
void Controller::Export() {
	cout << ExporterOBJ::Exporter(ptd_Model);
}

/*************************************************************************
【函数名称】       			Controller::AddFace
【函数功能】       			添加面
【参数】           			int* AddFaceIndex
【返回值】         			string
【开发者及日期】  			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::AddFace(int* AddFaceIndex) {
	return ptd_Model.AddFace(AddFaceIndex);
}

/*************************************************************************
【函数名称】       			Controller::AddLine
【函数功能】     	   		添加线
【参数】           			int* AddLineIndex
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::AddLine(int* AddLineIndex) {
	return ptd_Model.AddLine(AddLineIndex);
}

/*************************************************************************
【函数名称】       			Controller::AddPoint
【函数功能】       	        添加点
【参数】                    float* AddPointCoord
【返回值】                  string
【开发者及日期】            胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::AddPoint(float* AddPointCoord) {
	return ptd_Model.AddPoint(AddPointCoord);
}

/*************************************************************************
【函数名称】       			Controller::DelFace
【函数功能】        		删除面
【参数】           			int DelFaceIndex
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::DelFace(int DelFaceIndex) {
	return ptd_Model.DelFace(DelFaceIndex);
}

/*************************************************************************
【函数名称】       			Controller::DelLine
【函数功能】       			删除线
【参数】           			int DelLineIndex
【返回值】       			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::DelLine(int DelLineIndex) {
	return ptd_Model.DelLine(DelLineIndex);
}

/*************************************************************************
【函数名称】       			Controller::DelPoint
【函数功能】       			删除点
【参数】           			int DelPointIndex
【返回值】        			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::DelPoint(int DelPointIndex) {
	return ptd_Model.DelPoint(DelPointIndex);
}

/*************************************************************************
【函数名称】       			Controller::ShowModel
【函数功能】       			展示模型中的指定面（修改时展示）
【参数】          			const Model3D& Model
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ShowFaceInModify(int Index) const {
	return ShowFacePoints(ptd_Model, Index);
}

/*************************************************************************
【函数名称】       			Controller::ShowLineInModify
【函数功能】      			展示模型中的指定线（修改时展示）
【参数】          			const Model3D& Model
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ShowLineInModify(int Index) const {
	return ShowLinePoints(ptd_Model, Index);
}

/*************************************************************************
【函数名称】       			Controller::ShowPointInModify
【函数功能】       			展示模型中的特定点（修改时展示）
【参数】           			const Model3D& Model
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ShowPointInModify(int Index) const {
	return ShowPointCoords(ptd_Model, Index);
}

/*************************************************************************
【函数名称】       			Controller::ModFace
【函数功能】       			修改面
【参数】           			int ModFaceIndex, int OldFaceIndex, int NewFaceIndex
【返回值】       			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ModFace(int ModFaceIndex, int OldFaceIndex, int NewFaceIndex) {
	return ptd_Model.ModFace(ModFaceIndex, OldFaceIndex, NewFaceIndex);
}

/*************************************************************************
【函数名称】       			Controller::ModLine
【函数功能】       			修改线
【参数】           			int ModLineIndex, int OldLineIndex, int NewLineIndex
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ModLine(int ModLineIndex, int OldLineIndex, int NewLineIndex) {
	return ptd_Model.ModLine(ModLineIndex, OldLineIndex, NewLineIndex);
}

/*************************************************************************
【函数名称】       			Controller::ModPoint
【函数功能】       			修改点
【参数】           			int ModPointIndex, float* NewPointCoord
【返回值】         			string
【开发者及日期】   			胡延 2024.8.3
【更改记录】       			（若有修改，则必需注明）
*************************************************************************/
string Controller::ModPoint(int ModPointIndex, float NewPointCoord[]) {
	return ptd_Model.ModPoint(ModPointIndex, NewPointCoord);
}