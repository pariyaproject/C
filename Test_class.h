#pragma once
#ifndef TEST_CLASS_H
#define TEST_CLASS_H
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
//类的基本思想是数据抽象和封装
//数据抽象是依赖于接口和实现分离的编程技术
//首先定义一个抽象数据类型(通过接口来使用)
//而一个简单的struct不是一个抽象数据类型,它允许用户直接访问它的数据成员
//要想把它变成抽象数据类型,需要定义一些操作以供类的用户使用,一旦定义了它自己的操作,我们
//就可以封装(隐藏它的数据成员了)

//成员函数的声明必须在类的内部,它的定义则可以在内部或者外部
//而作为接口组成部分的非成员函数 如 read print,它们的定义和声明都在外部
class Test_class
{
public:
protected:
private:
};
//用于存储集的结构体
struct EPS {
	//构造函数
	//初始化类对象的数据成员,无论何时只要类的对象被创建,就会执行构造函数
	//名字和类名相同,没有返回类型,可以有多个(相当于重载)
	//构造函数不能被声明为const
	//当创建类的一个const对象时,直到构造函数完成初始化过程,对象才能真正取得其常量的属性
	//因此,构造函数在const对象的构造过程中可以向其写值 [实际直接赋值不行,具体不明]
	//默认构造函数 无须任何实参,可以隐式地提供 也可显示重写
	//编译器创建的构造函数又被称为合成的默认构造函数
	//它按照如下规则初始化类的数据成员
	//1.如果存在类内的初始值 用它来初始化成员
	//2.否则默认初始化该成员
	//[注意 只有当类没有声明任何构造函数时,编译器都会合成默认构造函数]
	//含有内置类型或或复合类型成员的类应该在类的内部初始化
	//只有当类内的内置精英全都被赋了类内初始值,这个类才适合使用默认的构造函数
	//有些时候编译器无法生成默认的构造函数,包含一个没有提供默认构造函数的类时
	//EPS() = default; 定义这个构造函数是为了既有默认也有自定义的构造函数,作用完成等同于合成默认构造函数
	//c++11中 如果需要默认的行为,那么可以通过在参数列表后面写上 =default 来要求编译器生成构造函数
	//和其它函数一样,如果在内部出现,则默认构造函数是内联的,在外部默认不是内联的
	EPS() { avg_score = 0.0; eps_score = {}; eps_name = {};}
	//构造函数初始值列表
	//负责为新创建的对象的一个或几个数据成员赋初值
	//当某个数据成员被初始初始值列表忽略时 它将以合成默认构造函数相同的方式隐式初始化
	//在类的外部定义构造函数
	EPS(std::vector<std::string> na, std::vector<double> sc) 
		:eps_name(na),eps_score(sc)
	{
		BroadcastChanged();
	}
	double avg_score;
	std::vector<double> eps_score;
	std::vector<std::string> eps_name;
	//这里一旦出现了const成员  就会引发一个错误  这与拷贝构造函数有关
	//error C2280 : “EPS &EPS::operator =(const EPS &)” : 尝试引用已删除的函数
	//test_class.h(97): note: 编译器已在此处生成“EPS::operator =”
	//const std::string From = "China";
	//const int password = 999;

	double Score() const { return avg_score; }
	//发生改变
	void BroadcastChanged() {
		CalScore();
	}
	void CalScore() {
		double all_score = 0.0;
		for (auto i : eps_score) {
			all_score += i;
		}
		avg_score = all_score / eps_score.size();
#ifndef NDEBUG
		std::cout << "######\navg_score: "
			<< avg_score
			<< "\n######\n"
			<< std::endl;
#endif
	}
	EPS& Combine(const EPS& other);
	void Add(std::string name, double score) {
		eps_name.push_back(name);
		eps_score.push_back(score);
		BroadcastChanged();
	};
	//移除最后一个元素
	void Remove() {
		//
		eps_name.erase(eps_name.cend() - 1);
		eps_score.erase(eps_score.cend() - 1);
		BroadcastChanged();
	};
	//移除指定的元素
	void Remove(std::string name) {
		//首先找到位置
		auto site = std::find(cbegin(eps_name), cend(eps_name), name);
		//根据位置找到下标
		int index = static_cast<int>(std::distance(site, cbegin(eps_name)));
		//移除对应下标
		eps_name.erase(eps_name.cbegin() + index);
		eps_score.erase(eps_score.cbegin() + index);
		BroadcastChanged();
	};
	//重载输入输出流
	//在定义中可能出错: 包含<string>头文件
	friend std::ostream& operator << (std::ostream&, const EPS&);
	friend std::istream& operator >> (std::istream&, EPS&);
	//重载+
	EPS operator + (const EPS &eps1);
};
//注意 重载一个输出流时 尽量不要最后再加上std::endl
inline std::ostream & operator<<(std::ostream &os, const EPS &eps)
{
	assert(eps.eps_name.size() == eps.eps_score.size());
	auto num = eps.eps_name.size();
	if (num == 0) {
		std::cout << "No eps" ;
	}
	else {
		if(num >1)
		for (decltype(num) i = 0; i < num-1; ++i) {
			std::cout << "EPS: "
				<< eps.eps_name[i]
				<< "  SCORE: "
				<< eps.eps_score[i]
				<< std::endl;
		}
		//最后一个不输出换行
		if (true) {
			std::cout << "EPS: "
				<< eps.eps_name[num-1]
				<< "  SCORE: "
				<< eps.eps_score[num-1];
				//<< std::endl;
		}
	}


	return os;
}

inline std::istream & operator >> (std::istream &is, EPS &eps)
{
	std::string nname;
	double nscore;
	bool has_enter = false;
	while (!has_enter) {
		if (std::cin >> nname >> nscore) {

			has_enter = true;
			eps.Add(nname, nscore);
			std::cout << "EPS: "
				<< nname
				<< "  SCORE: "
				<< nscore
				<< "  Get!"
				<< std::endl;
		}
		else {
			std::cout << "Bad Input" << std::endl;
		}
	}

	return is;
}
//改进的Bangumi_data
//定义在类内部的函数是隐式的inline函数
//编译器分两步处理类: 首先编译成员的声明,然后才轮到成员函数体,因此成员函数体可以随意使用类中的
//其他成员而无须在意成员出现的次序
struct New_bangumi_data {
	//const成员函数 常量成员函数
	//函数结尾处使用了const关键字:修改隐式this指针的类型
	//默认下 this的类型是指向类类型非常版本的常量指针(New_bangumi_data * const)
	//这会导致一个常量的New_bangumi_data不能调用一个普通成员函数(const不能赋给非常量)
	//使用const后 便可另常量类调用,同时在函数内也不能修改类的数据 提高了灵活性
	std::string Name() const { return name; } //定义在类内
	unsigned Id() const { return ip_id; }
	New_bangumi_data &Combine(const New_bangumi_data&);
	double AvgScore()const;

	std::string name;
	unsigned ip_id;
	double score;
	EPS eps;
};
//非成员接口函数
New_bangumi_data add(const New_bangumi_data&, const New_bangumi_data&);
//注意IO类型属于不能被拷贝类型,因此只能通过引用传递
std::ostream &print(std::ostream& os, const New_bangumi_data&);
std::istream &read(std::istream&, New_bangumi_data&);

//成员函数通过一个名为this的额外的隐式参数来访问它的那个对象.
//当我们调用一个成员函数时,用请求该函数的对象地址初始化this,
//例如: test.Id();
//编译器负责把total的地址传递给Id的隐式形参this,可以等价地认为编译器将该调用重写成了
//New_bangumi_data::Id(&test);//这是伪代码
//在成员函数的内部,可以直接使用调用该函数的对象的成员,而无须通过成员访问运算符,因为this所指的
//正是这个对象,任何对类成员的直接访问都被看作this的隐式引用
//因此任何自定义名为this的参数或变量的行为都是非法的
//this是一个常量指针 总是指向这个对象


#endif
