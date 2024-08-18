/*************************************************************************
【文件名】					Importer.hpp
【功能模块和目的】				定义并实现抽象类Importer，用于扩展不同类型的导入数据
【开发者及日期】				胡延 2024.7.21
【更改记录】					（若修改过则必需注明）
*************************************************************************/

#ifndef Importer_hpp
#define Importer_hpp

/*************************************************************************
【类名】					Importer
【功能】					作为ImporterOBJ的基类，是导入数据的抽象类
【接口说明】				虚函数Import()用于导入数据
						析构函数用于释放内存
【开发者及日期】			胡延 2024.7.21
【更改记录】				（若修改过则必需注明）
*************************************************************************/
class Importer {
public:
	Importer() {}
	virtual void Import() = 0;
	virtual ~Importer() {}
};

#endif /* Importer_hpp */
