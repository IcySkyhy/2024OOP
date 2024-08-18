/*************************************************************************
【文件名】					UI.cpp
【功能模块和目的】			用户界面类的实现
【开发者及日期】			胡延 2024.8.13
【更改记录】				
*************************************************************************/
#include "UI.hpp"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

UI::UI() {
	Controller Controller;
	cout << UsersWelcome(Controller);
}

/*************************************************************************
【函数名称】				UsersWelcome()
【函数功能】				用户主界面
【参数】					输入：Controller& Controller
【返回值】					字符串，表示退出程序
【开发者及日期】			胡延 2024.8.3
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string UI::UsersWelcome(Controller& Controller) {
	int Option = 0;
	cout << "------Welcome to the 3D Model World!------\n";
	while (Option < 1 || Option > 3) {
		cout << "----------Please select an option---------\n";
		cout << "1. Import a 3D model\n";
		cout << "2. Create a new 3D model\n";
		cout << "3. Exit\n";
		cin >> Option;
		while (Option < 1 || Option > 3) {
			cout << "Invalid option, please try again:\n";
			cin >> Option;
		}
		switch (Option) {
			case 1:
			{
				// 导入模型
				string Path;
				cout << "Please input the path of the file you want to import: \n";
				cin.get();	// 清空缓冲区,防止getline()读取到回车符
				getline(cin, Path);
				string situation = Controller.Import(Path);
				if (situation != "Failed to open the file.\n") {
					cout << UsersMenu(Controller);
				}
				cout << situation;
				break;
			}
			case 2:
			{
				// 创建模型
				Controller.Create();
				cout << "Successfully Created.\n";
				cout << UsersMenu(Controller);
				break;
			}
			case 3:
				break;
		}
		if (Option != 3) {
			cout << "Quit?\n1.Yes 2.No\n";
			cin >> Option;
			Option += 2;
		}
		system("cls");
		cout << "------Welcome to the 3D Model World!------\n";
	}
	return "Goodbye!";
}

/*************************************************************************
【函数名称】				MainShowInf()
【函数功能】				显示模型信息的主页面
【参数】					输入：Controller& Controller
【返回值】				字符串，表示返回上一级函数
【开发者及日期】			胡延 2024.8.3
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string UI::UsersMenu(Controller& Controller) {
	int Option = 0;
	cout << "------Welcome to the 3D Model World!------\n";
	while (Option < 1 || Option > 4) {
		cout << "----------Please select an option---------\n";
		cout << "1. Show the information\n";
		cout << "2. Modify the model\n";
		cout << "3. Export the model\n";
		cout << "4. Back\n";
		cin >> Option;
		while (Option < 1 || Option > 4) {
			cout << "Invalid option, please try again:\n";
			cin >> Option;
		}
		switch (Option) {
			case 1:
			{
				// 显示模型信息菜单
				cout << MainShowInf(Controller);
				break;
			}
			case 2:
			{
				// 编辑模型菜单
				cout << MainModify(Controller);
				break;
			}
			case 3:
			{
				// 导出模型选项
				Controller.Export();
				break;
			}
		}
		if (Option != 4) {
			cout << "Back to the main menu?\n1.Yes 2.No\n";
			cin >> Option;
			Option += 3;
		}
		system("cls");
	}
	return "Back to the main menu.\n";
}

/*************************************************************************
【函数名称】				MainShowInf()
【函数功能】				显示模型信息的主页面
【参数】					输入：Controller& Controller
						输出：下一级页面的选项（调用ShowInf()）
【返回值】				字符串，表示返回上一级函数
【开发者及日期】			胡延 2024.8.3
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string UI::MainShowInf(Controller& Controller) {
	int OptNum = 0;
	while (OptNum < 1 || OptNum > 6) {
		cout << "==Please Select An Option:==\n";
		cout << "1. Show The Whole Model\n";
		cout << "2. Show The Face Part\n";
		cout << "3. Show Points in Face Part\n";
		cout << "4. Show The Line Part\n";
		cout << "5. Show Points in Line Part\n";
		cout << "6. Back\n";
		cin >> OptNum;
		int Index = 0;
		switch (OptNum)
		{
		case 3:
			{
			// 通过输入的面的索引来显示面的信息
			cout << "Please input the index of the face you want to show: ";
			cin >> Index;
			break;
			}
		case 5:
			{
			// 通过输入的线的索引来显示线的信息
			cout << "Please input the index of the line you want to show: ";
			cin >> Index;
			break;
			}
		default:
			break;
		}
		cout << Controller.ShowInf(OptNum, Index);
		if (OptNum != 6) {
			cout << "Back to the ModelMenu?\n1.Yes 2.No\n";
			cin >> OptNum;
			OptNum += 5;
		}
		system("cls");
	}
	return "Back to the ModelMenu.\n";
}

/*************************************************************************
【函数名称】				MainModify()
【函数功能】				显示模型编辑的主页面
【参数】					输入：Controller& Controller
						输出：下一级页面的选项（调用Modify()）
【返回值】				字符串，表示返回上一级函数
【开发者及日期】			胡延 2024.8.3
【更改记录】				（若有修改，则必需注明）
*************************************************************************/
string UI::MainModify(Controller& Controller) {
	int OptNum = 0;
	while (OptNum < 1 || OptNum > 4) {
		cout << "==Please Select An Option:==\n";
		cout << "1. Addition\n";
		cout << "2. Modification\n";
		cout << "3. Deposition\n";
		cout << "4. Back\n";
		cin >> OptNum;
		while (OptNum < 1 || OptNum > 4) {
			cout << "Invalid option, please try again:\n";
			cin >> OptNum;
		}
		switch (OptNum) {
			// 选择1：添加元素
			case 1:
			{
				cout << "Addition Type:\n1. Add a Face\n2. Add a Line\n3. Add a Point\n4. None\n";
				cin >> OptNum;
				// 输入检查
				while (OptNum < 1 || OptNum > 4) {
					cout << "Invalid option, please try again:\n";
					cin >> OptNum;
				}
				switch (OptNum) {
					// 选择1：通过3个特定的点索引添加面
					case 1:
					{
						cout << "Please input the points of the face you want to add (3 points):\n";
						int AddFaceIndex[3] = { 0 };
						for (int i = 0; i < 3; i++) {
							cout << "Point " << i + 1 << ": ";
							cin >> AddFaceIndex[i];
						}
						cout << Controller.AddFace(AddFaceIndex);
						break;
					}
					// 选择2：通过2个特定的点索引添加线
					case 2:
					{
						cout << "Please input the points of the line you want to add (2 points):\n";
						int AddLineIndex[2] = { 0 };
						for (int i = 0; i < 2; i++) {
							cout << "Point " << i + 1 << ": ";
							cin >> AddLineIndex[i];
						}
						cout << Controller.AddLine(AddLineIndex);
						break;
					}
					// 选择3：通过3个坐标添加点
					case 3:
					{
						cout << "Please input the coordinates of the point you want to add (x, y, z):\n";
						float Coords[3] = { 0 };
						for (int i = 0; i < 3; i++) {
							cout << "Coord " << i + 1 << ": ";
							cin >> Coords[i];
						}
						cout << Controller.AddPoint(Coords);
						break;
					}
					// 选择4：防止返回上一级，减1
					case 4:
					{
						OptNum--;
						break;
					}
				}
				break;
			}
			// 选择2：修改元素
			case 2:
			{
				cout << "Modification Type:\n1. Modify a Face\n2. Modify a Line\n3. Modify a Point\n4. None\n";
				cin >> OptNum;
				// 输入检查
				while (OptNum < 1 || OptNum > 4) {
					cout << "Invalid option, please try again:\n";
					cin >> OptNum;
				}
				switch (OptNum)
				{
					// 选择1：通过索引修改面上的一个点
					case 1:
					{
						int ModFaceIndex = 0;
						int OldFaceIndex = 0;
						int NewFaceIndex = 0;
						cout << "Please input the index of the face you want to modify:\n";
						cin >> ModFaceIndex;
						cout << Controller.ShowFaceInModify(ModFaceIndex);
						cout << "Please input the point of the face you want to modify (index of 1 point):\n";
						cin >> OldFaceIndex;
						cout << "Please input the new points of the face (index of 1 point):\n";
						cin >> NewFaceIndex;
						cout << Controller.ModFace(ModFaceIndex, OldFaceIndex, NewFaceIndex);
						break;
					}
					// 选择2：通过索引修改线上的一个点
					case 2:
					{
						int ModLineIndex = 0;
						int OldLineIndex = 0;
						int NewLineIndex = 0;
						cout << "Please input the index of the line you want to modify:\n";
						cin >> ModLineIndex;
						cout << Controller.ShowLineInModify(ModLineIndex);
						cout << "Please input the points of the line you want to modify (index of 1 points):\n";
						cin >> OldLineIndex;
						cout << "Please input the new points of the line (index of 1 points):\n";
						cin >> NewLineIndex;
						cout << Controller.ModLine(ModLineIndex, OldLineIndex, NewLineIndex);
						break;
					}
					// 选择3：通过索引修改点的坐标
					case 3:
					{
						int ModPointIndex = 0;
						float NewCoords[3] = { 0 };
						cout << "Please input the index of the point you want to modify:\n";
						cin >> ModPointIndex;
						cout << Controller.ShowPointInModify(ModPointIndex);
						cout << "Please input the new coordinates of the point (x, y, z):\n";
						for (int i = 0; i < 3; i++) {
							cout << "Coord " << i + 1 << ": ";
							cin >> NewCoords[i];
						}
						cout << Controller.ModPoint(ModPointIndex, NewCoords);
						break;
					}
					// 选择4：防止返回上一级，减1
					case 4:
					{
						OptNum--;
						break;
					}
				}
				break;
			}
			// 选择3：删除元素
			case 3:
			{
				cout << "Delete Type:\n1. Delete a Face\n2. Delete a Line\n3. Delete a Point\n4. None\n";
				cin >> OptNum;
				// 输入检查
				while (OptNum < 1 || OptNum > 4) {
					cout << "Invalid option, please try again:\n";
					cin >> OptNum;
				}
				switch (OptNum)
				{
					// 选择1：通过索引删除面
					case 1:
					{
						cout << "Please input the index of the face you want to delete:\n";
						int DelFaceIndex;
						cin >> DelFaceIndex;
						cout << Controller.DelFace(DelFaceIndex);
						break;
					}
					// 选择2：通过索引删除线
					case 2:
					{
						cout << "Please input the index of the line you want to delete:\n";
						int DelLineIndex;
						cin >> DelLineIndex;
						cout << Controller.DelLine(DelLineIndex);
						break;
					}
					// 选择3：通过索引删除点
					case 3:
					{
						cout << "Please input the index of the point you want to delete:\n";
						int DelPointIndex;
						cin >> DelPointIndex;
						cout << Controller.DelPoint(DelPointIndex);
						break;
					}
					// 选择4：防止返回上一级，减1
					case 4:
					{
						OptNum--;
						break;
					}
				}
				break;
			}
		}
		// 返回上一级页面
		if (OptNum != 4) {
			cout << "Back to the ModelMenu?\n1.Yes 2.No\n";
			cin >> OptNum;
			OptNum += 3;
		}
		system("cls");
	}
	return "Back to the ModelMenu.\n";
}