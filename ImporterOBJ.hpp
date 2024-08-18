/*************************************************************************
【文件名】					ImporterOBJ.hpp
【功能模块和目的】				基于抽象类Importer定义可以导入.obj文件的输入器
【开发者及日期】				胡延 2024.8.1
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef ImporterOBJ_hpp
#define ImporterOBJ_hpp

#include "Importer.hpp"
#include "Model3D.cpp"
#include <string>

using namespace std;

/*************************************************************************
【类名】					ImporterOBJ
【功能】					导入器的派生类，用于导入.obj文件
【接口说明】		
继承自Importer的所有接口		
通过路径导入函数
创建函数
【开发者及日期】				胡延 2024.8.1
【更改记录】					2024.8.1 定义导入器的派生类
*************************************************************************/
class ImporterOBJ : public Importer {
protected:
	Model3D ptd_Model;
public:
	ImporterOBJ() {}
	void Import() {}
	string Import(string& path);
	string Create();
	~ImporterOBJ() {}
};

#endif /* ImporterOBJ_hpp */
