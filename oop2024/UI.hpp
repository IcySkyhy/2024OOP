/*************************************************************************
【文件名】					UI.hpp
【功能模块和目的】				用户界面类的定义
【开发者及日期】				胡延 2024.8.7
【更改记录】					
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1 // 屏蔽vs2022对fopen等函数的安全警告

#include "Controller.cpp"

#include <iostream>

using namespace std;

/*************************************************************************
【类名】					UI
【功能】					用户界面类的定义
【接口说明】				
UsersWelcome()：欢迎界面
UsersMenu()：用户菜单
MainShowInf()：主界面显示信息
MainModify()：主界面修改信息
【开发者及日期】				胡延 2024.8.7
【更改记录】
*************************************************************************/
class UI {
protected:
	string UsersWelcome();
	string UsersMenu(Controller& Controller);
	string MainShowInf(Controller& Controller);
	string MainModify(Controller& Controller);
public:
	UI();
	virtual ~UI() {}
};
