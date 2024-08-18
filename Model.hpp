/*************************************************************************
【文件名】					Model.hpp
【功能模块和目的】				实现Model类作为模型基类，用于描述模型的基本信息
【开发者及日期】				胡延 2024.8.1
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef Model_hpp
#define Model_hpp

#include <string>

using namespace std;

/*************************************************************************
【类名】             Model
【功能】             实现Model类作为模型基类，用于描述模型的基本信息
【接口说明】
常引用getter函数Name
setter函数SetName
【开发者及日期】     胡延 2024.8.1
【更改记录】         （若修改过则必需注明）
*************************************************************************/
class Model {
private:
	string m_Name = "";
public:
	Model();
	~Model() {}
	// getter
	const string& Name {m_Name};
	// setter
	void SetName(string name);
};

#endif /* Model_hpp */
