#pragma once
#ifndef BANGUMI_SUBJECT_H
#define BANGUMI_SUBJECT_H
//pragma once等价于ifndef ... endif,但ifndef是c++标准，支持更多的编译器
//但是有命名冲突的危险并且编译相对较慢
//#pragma once
//关于iostream已经内置了条件编译宏用来防止重复定义
#include <iostream>
//bangumi条目类
extern const int const_int;
//extern const int const_int_ex;
//[注意]有cpp和h的情况下,头文件不能包含定义的变量和函数体,cpp中一包含就会导致重定义
//extern void TestConstInBGMXX() {
//	std::cout << __FILE__ <<
//		" : " << const_int << std::endl;
//}
extern void TestConstInBGMXX();
extern const int x ;
class Bangumi_subject
{
public:
	//const 类型限定符：
	//1.不能修改数据成员 2.不能调用非const成员函数 3.mutable修饰的成员是可以修改的
	//否则编译器报错
	//mutable不可修饰函数
	int Id()const;
	int DoNum()const;
	int Score()const;
	Bangumi_subject();
	Bangumi_subject(int,int,int);
	//注意需要声明为友元函数
	//<<>>操作符两个函数签名不一样
	//友元函数可以访问类中的所有数据成员
	//注意：inline一定要在本文件中使用不能h cpp中使用
	//当用到>>模板重载时声明和实现都使用一个不同的模板
	friend std::ostream& operator <<(std::ostream& ,const Bangumi_subject &);
	friend std::istream& operator >>(std::istream&,Bangumi_subject &);
	//前置++没有参数区分，此处能发现前置++返回是一个引用，效率更高
	Bangumi_subject& operator ++();
	//后置++需要用一个参数区别
	Bangumi_subject operator++(int);
	//tip:
	//形参中的 Bangumi_subject* 和 Bangumi_subject& 的区别
	//*中调用为 func(&subject)实际传了一个存有地址的变量，消耗了地址的空间(申请，容量)
	//&中调用为 func(subject)直接使用别名，非变量
	Bangumi_subject operator+(const Bangumi_subject&);
	Bangumi_subject &operator+=(const Bangumi_subject&);
private:
	int id;
	int score;
	mutable int do_num;
	
};

inline std::ostream & operator<<(std::ostream &out, const Bangumi_subject &subject)
{
	out << "Bangumi ID : " << subject.id
		<< "\nBangumi Score : " << subject.score
		<< "\nBangumi Do : " << subject.do_num;

	return out;
}

inline std::istream & operator >> (std::istream &in, Bangumi_subject &subject)
{
	if (in >> subject.id >> subject.score >> subject.do_num) {
		
	}
	else {
		subject.id = 0;
		subject.score = 0;
		subject.do_num = 1;
	}

	return in;
}







#endif