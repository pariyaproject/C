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
//extern const int const_int;
//extern const int const_int_ex = 555;
//extern const int const_int ;
//extern const int const_int_ex;
//void TestConstInClass() {
//	std::cout << __FILE__ <<
//		" : " << const_int << std::endl;
//}
const int jkljkl = 1;
class EPS;
class Test_class
{
public:
	void TestFriendCall(EPS& eps) {};
protected:
private:
};
//访问控制与封装
//使用访问控制符来加强类的封闭性
//struct和class的默认访问权限不一样
//唯一区别:在第一个访问说明符之前定义成员:类的话默认是private 结构体默认是public
//出于风格的考虑 如果希望定义的成员都是public用struct 否则使用class
//经过将struct转换成class的操作后 编译会出错,这是因为访问权限不同
//如果类想把一个函数作为它的友元,只需增加一条以friend关键字开始的函数声明即可(一般在开头或结尾声明较好)
//友元不受访问限定符的约束
//[注意:友元指定了访问的权限,而非通常意义上的函数声明,如果希望类的用户能够调用某个友元函数,那么必须在声明之外再专门对函数进行一次声明]
//用于存储集的结构体
//除了定义数据和函数成员之外,类还可以自定义某种类型在类中的别名,由类定义的类型名字和其他成员一样有访问限制
//public 中 用户可以使用这个别名
//[注意:定义的类型别名不同普通类成员必须先定义再使用,因此通常出现在类的开始地方]
class EPS {
	//如果提示友元函数声明无效,是因为没有这个类或函数的初始声明,这里的声明仅仅是友元的标识
	//如果是友元类的声明 一定是 friend class XXXX;
	//友元函数是friend 函数原型
	//为了使友元对类的用户可见.我们通常把友元的声明与类本身放置在同一个头文件中(类的外部)
	//因此头文件应该为read print add提供独立的声明(除了类内部的友元声明之外)
	friend class New_bangumi_data;
	//除了友元类,还可以声明一个友元成员函数,一定注意friend + 完整的声明[注意要在这个类声明之后,总之定义的顺序较为复杂]
	//这个时候就可以使用前向声明
	//对于一个有重载的函数,一定要为每个重载都声明一次
	friend void Test_class::TestFriendCall(EPS &);
	//类和非成员函数的声明不是必须在它们的友元声明之前,当一个名字第一次出现在一个友元的声明中时,
	//隐式地假定该名字在当前作用域是可见的,然而友元本身不一定真的声明在当前作用域中
	//总之一句话:友元函数的声明仅仅用于友元的标识,不可能真正地声明了这个函数,需要自身声明
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
public:
	EPS() { avg_score = 0.0; eps_score = {}; eps_name = {}; ANew(); }
	//构造函数初始值列表
	//负责为新创建的对象的一个或几个数据成员赋初值
	//当某个数据成员被初始初始值列表忽略时 它将以合成默认构造函数相同的方式隐式初始化
	//在类的外部定义构造函数
	EPS(std::vector<std::string> na, std::vector<double> sc) 
		:eps_name(na),eps_score(sc)
	{
		ANew();
		BroadcastChanged();
	}
	//拷贝赋值和析构 如果不主动定义,编译器会合成
	//拷贝:初始变量以及以值的方式传递或返回一个对象
	//赋值:使用赋值运算符
	//析构:当对象不再存在时销毁
	//当vector对象销毁时存储在其中的对象也会被销毁
	//一般来说,编译器生成的版本将对对象的每个成员执行拷贝 赋值和销毁操作
	//如: total = trans;
	//等价: total.bookNo = trans.bookNo;
	//total.units_sold = trans.units_sold;
	//total.revenue = trans.revenue;
	//某些类不能依赖合成的版本
private:
	//默认值,但是如果构造函数可以重新覆盖,这里这个就没有意义,否则没有覆盖则使用1.0
	double avg_score = 1.0;
	std::vector<double> eps_score;
	std::vector<std::string> eps_name;
	//可变数据成员(mutable data member)永远不会是const,即使它是const对象的成员
	//但是本身不能是const,也就是说在const函数中也能改变all_time
	//c++ 11 新标准中,拥有一个默认初始化的值的最好的方式是声明成一个类内初始值
	//提供类内初始值时 必须用 = 或者 {}的直接初始化形式
	mutable unsigned all_time = 0;
	//这里一旦出现了const成员  就会引发一个错误  这与拷贝构造函数有关
	//error C2280 : “EPS &EPS::operator =(const EPS &)” : 尝试引用已删除的函数
	//test_class.h(97): note: 编译器已在此处生成“EPS::operator =”
	//const std::string From = "China";
	//const int password = 999;
	//test mutable
	void ANew()const { all_time++; }
public:
	//mutable 甚至可以返回其引用
	unsigned& Times() const { return all_time; }
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
	//显式内联[但是inline成员函数也应该与相应的类定义在同一个头文件中]
	//也可在类的定义处指定为inline,和这里等价
	inline EPS& Combine(const EPS& other);
	//定义在类内的直接默认内联
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
		os << "No eps" ;
	}
	else {
		if(num >1)
		for (decltype(num) i = 0; i < num-1; ++i) {
			os << "EPS: "
				<< eps.eps_name[i]
				<< "  SCORE: "
				<< eps.eps_score[i]
				<< std::endl;
		}
		//最后一个不输出换行
		if (true) {
			os << "EPS: "
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
	//IO流有四种条件状态，分别用位来控制。

	//	cin.badbit :  001   1   表示系统级错误，一旦被置位，流就无法再使用了
	//	cin.eofbit : 010    2   表示流已经读完，到达尾部了
	//	cin.failbit : 100    4     可恢复错误，如期望读取数值却读出一个字符等错误，或者已经到达流的尾部
	//	cin.goodbit : 000   0   可用状态


	//	当一个流遇到数据类型不一致的错误而不可用时，我们可以使其恢复为有效状态（置换eof和fail位）

	//	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);   //cin.rdstate()表示流当前的状
	//is.setstate(std::istream::badbit);
	while (!has_enter) {
		//
		if (is >> nname >> nscore) {

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
			//此处如下清除cin的状态,以正确接受下次的输入,否则当前cin返回bool false导致一直输出Bad Input
			//std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
			is.clear();
		}
	}

	return is;
}
//改进的Bangumi_data
//定义在类内部的函数是隐式的inline函数
//编译器分两步处理类: 首先编译成员的声明,然后才轮到成员函数体,因此成员函数体可以随意使用类中的
//其他成员而无须在意成员出现的次序
class New_bangumi_data {
	//friend 声明
	friend New_bangumi_data add(const New_bangumi_data&, const New_bangumi_data&);
	//注意IO类型属于不能被拷贝类型,因此只能通过引用传递
	friend std::ostream &print(std::ostream& os, const New_bangumi_data&);
	friend std::istream &read(std::istream&, New_bangumi_data&);
	//const成员函数 常量成员函数
	//函数结尾处使用了const关键字:修改隐式this指针的类型
	//默认下 this的类型是指向类类型非常版本的常量指针(New_bangumi_data * const)
	//这会导致一个常量的New_bangumi_data不能调用一个普通成员函数(const不能赋给非常量)
	//使用const后 便可另常量类调用,同时在函数内也不能修改类的数据 提高了灵活性
public:
	//构造函数
	New_bangumi_data() = default;//合成默认的构造函数
	//test隐式类类型转换
	New_bangumi_data(EPS ep):eps(ep){}
	New_bangumi_data(std::string na):name(na){}
	New_bangumi_data(std::string na, unsigned i, double sc, EPS ep):name(na),ip_id(i),score(sc),eps(ep) {}
	std::string Name() const { return name; } //定义在类内
	unsigned Id() const { return ip_id; }
	New_bangumi_data &Combine(const New_bangumi_data&);
	double AvgScore()const;
	//获得一个eps的副本
	EPS Eps()const { return eps; }
	//取引用
	//一个const成员函数如果以引用的形式返回*this,那么它的返回类型将是常量引用
	//通过区分成员函数是否是const 我们可以进行重载,与之前的类似 如下(注意const是this的)
	//const EPS & RefEps(int x)const{}
	EPS& RefEps() { return eps; }
private:
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


//类类型
//每个类定义了唯一的类型,即使成员完全一样也是不同的类型,不能直接赋值
//New_bangumi_data item1;
//class New_bangumi_data item1; //两者等价 //继承自c语言
//这对struct也有效
//也可以仅仅声明一个类而不定义
class ThisNoDefineClass;
//这种声明被称为前向声明,在程序中引入名字,并指明是一种类类型,
//这时在声明之后,定义之前是一不完全类型,因此不清楚它有什么成员
//功能有限:可以定义指向这种类型的指针或引用,也可声明以不完全类型作为参数或返回类型的指针
//只有当类全部完成以后才算被定义,因此一个类的成员类型不能是该类自己,一旦一个类的名字出现过了 但尚未定义
//它就被认为是声明过了,因此类允许包含指向自身类型的引用或指针

//对于类中定义的类型(using typedef定义的别名),使用作用域运算符
//A::B c;
//一旦遇到了类名,[定义]的剩余部分就在类的作用域之内了,这里的剩余部分是包括参数列表和函数体(没有返回类型)

//名字查找(寻找与所用名字最匹配的声明的过程)
//首先在名字所在的块中寻找其声明语句,只考虑在名字的使用之前出现的声明
//如果没找到 继续查找外层作用域
//否则报错

//如果定义在类内的成员函数来说
//首先 编译成员的声明
//直到类全部可见后才编译函数体
//如果某个成员的声明使用了类中尚未出现的名字,则编译器将会在定义该类的作用域(类外)中继续查找
//在类中如果已经使用了外层作用域的某个名字,则此名字代表了一种类型,则类不能在之后重新定义该名字
//因此,类型名的定义通常出现在类的开始处,这样能确保所有使用该类型的成员都出现在类名定义之后

//成员函数中使用的名字按照如下方式解析
//首先在成员函数内查找(之前的) [如果隐藏了类内成员使用this-> 或 ClassName:: 访问]
//在类内查找,类的所有成员都可以被考虑 [使用 :: 访问类外的]
//在成员函数定义之前的作用域内继续查找

//构造函数中数据成员的初始化和赋值是有区别的,与下类似
//string foo = "zxc"; //定义并初始化
//string bar;	//默认初始化成空string 对象
//bar  = "zxc";  //为bar赋一个新值
//有时可以忽略初始化和赋值之间的差异,但成员如果是引用或是const,必须初始化
//类似地某些没有默认构造函数的类也需要
class Test_ConstRef {
public:
	Test_ConstRef()//成员的初始化顺序与声明的顺序一致而与列表的顺序无关,因此J(i),i(4)正确 j=i=4
					//不过尽量避免j(i)使用变量初始化变量的操作
		:j(i),i(4),ci(5),ri(i) //这样才正确 并且使用初始化效率更高
	{
		//ci = 1; //错误 不能给const赋值
		//ri = ci; //错误 ri没被初始化
	}
private:
	int i;
	const int ci;
	int &ri;
	int j;
};
//如果在头文件中定义一个变量,并且这个头文件可能被多次include则使用static 等,防止出现链接时重定义错误
//static Test_ConstRef test_class_x;
//如果没有为它们提供构造函数初始值的话 错误 尝试引用已删除的函数
//拥有一个默认实参的构造函数相当于有一个默认构造函数

//C++ 11 委托构造函数 (delegating constructor)使用它所属类的其他构造函数执行它自己的初始化过程
//也就是把自己的一些或全部职责委托给了其他构造函数
//在委托构造函数中成员初始值列表只有一个唯一的入口,就是类名本身
class Test_Delegate_Con {
public:
	//非委托构造函数
	Test_Delegate_Con(int a, int b, int c)
		:x(a),y(b),z(c)
	{}
	//委托构造函数,受委托的函数体结束之后控制权才会交回委托构造函数
	Test_Delegate_Con(int b, int c) :Test_Delegate_Con(b) { y = c; }
	Test_Delegate_Con(int b ) :Test_Delegate_Con(b, 2, 3) {}
	//explicit Test_Delegate_Con(int b ) :Test_Delegate_Con(b, 2, 3) {}
	Test_Delegate_Con() :Test_Delegate_Con(1, 2, 3) {}
private:
	int x;
	int y;
	int z;
};

//隐式的类类型转换
//只限于只有一个参数的构造函数
//string null_book = "99- 999";
//item.combine(null_book);
//实际是调用了string的构造函数并生成了一个临时的对象成为combine的参数(因为combine的参数是一个常量引用),所以正确
//但是编译器只允许一步类类型转换 因此不能 item.combine("99- 999");
//但可以显式转换成string 或者 Sales_data对象
//item.combine(string("99- 999"))
//item.combine(Sales_data("99- 999"))
//类类型转换不是总有效

static Test_Delegate_Con test_xx = 1; //正确

//与之相反的操作 抑制构造函数定义的隐式转换 explicit
//关键字 explicit只对一个实参的构造函数有效,需要多个实参的构造函数不能用于隐式转换
//只能在类内声明构造函数时使用explicit关键字,在类外部定义时不应重复
//使用explicit关键字的构造函数中只能以直接初始化的形式使用
//Sales_data item1(null_book);

//虽然不能隐式转换,但可以显式使用
//Sales_data item1(Sales_data(null_book));
//Sales_data item1(sataic_cast<Sales_data>(cin));
//但实际上总是创建了一个临时的对象

//标准库中的类含有单参数的构造函数
//比如接受一个单参数的const char*的string 不是explicit
//接受一个容量参数的vector构造函数 是 explicit的

//聚合类 使得用户可以直接访问其成员,并且具有特殊的初始化语法,当一个类满足如下条件是聚合的
//所有成员都是public
//没有定义任何构造函数
//没有类内初始值
//没有基类,也没有virtual函数

//例如
struct TestAggregateClass {
	TestAggregateClass() =default; //如果显示地定义合成默认构造函数不会影响聚合类的本质
	//TestAggregateClass(){}  //不再是聚合类
	//TestAggregateClass(int) {} //不再是聚合类
	int ival;
	std::string s;
};
//可以提供一个花括号括起来的成员初始值列表,并用它初始化聚合类的数据成员
static TestAggregateClass test_a = { 0,"Ana" };
//初始值的顺序必须和声明的顺序一致
//同时与初始化数组元素的规则一样,如果初始值列表中的元素个数少于类的成员数量,则靠后的成员被值初始化
//

//字面值常量类
//constexpr函数的参数和返回值必须是字面值类型,除了算术类型/引用和指针外,某些类也是字面值类型
//其可能含有constexpr函数成员,这样的成员必须符合constexpr函数的所有要求,它们是隐式const的
//数据成员都是字面值类型的聚合类是字面值常量类
//如果符合下面要求也是一个字面值常量类
//1.数据成员都必须是字面值
//2.类必须至少含有一个constexpr构造函数
//3.如果一个数据成员含有类内初始值,则初始值必须是一条常量表达式...
//4.类必须使用析构函数默认定义,该成员负责销毁类的对象

//尽管构造函数不能是const但字面值常量类的构造函数可以是constexpr函数
//constexpr构造函数必须既符合构造函数要求:不能包含返回语句,又符合constexpr函数要求:唯一可执行语句就是返回语句
//综上一般函数体为空,但可以通过初始化列表
//constexpr构造函数必须初始化所有数据成员
//c++ 14有部分更改 提示 constexpr将不表示常量考虑显式指定常量
class TestDebug {
public:
	//constexpr TestDebug(int code, bool bo) :error_code(code), error_bool(bo) {};
	//constexpr TestDebug(bool bo) :error_bool(bo),error_code(404) {};
	//constexpr int Code() { return error_code; }
	//constexpr bool BError() { return error_bool; }
	const TestDebug(int code, bool bo) :error_code(code), error_bool(bo) {};
	const TestDebug(bool bo) :error_bool(bo),error_code(404) {};
	const int Code() { return error_code; }
	const bool BError() { return error_bool; }
private:
	int error_code;
	bool error_bool;
	//const bool a = true;
};
//注意不应当在头文件中定一个作用域,除非静态
//否则会链接重定义

//类的静态成员
//通过在成员的声明之前加上关键字static使得其与类关联在一起
//静态成员可以是public private 类型可以是常量,引用 指针 类类型
//类的静态成员存在于任何对象之外,对象中不包括任何与静态数据成员有关的数据
//静态成员函数也不与任何对象绑定在一直,它们不包含this指针,因此不能声明成const 而且不能使用在内this

//使用类名的作用域直接访问静态成员:当然具体的对象也能像之前那样访问
//定义静态成员:既可在类的内部,也可在类的外部定义静态成员函数,当在类的外部定义静态成员时
//不能重复static关键字,该关键字只出现在类的内部声明语句
//静态成员不是构造函数初始化的,而且一般不能在类内初始化静态成员,相反,必须在类的外部定义和初始化每个
//静态成员,一个静态成员只能定义一次
//类似于全局变量,静态数据成员定义在任何函数之外,因此一旦被定义就将一直存在于程序的整个生命周期
//定义静态数据成员的方式和在类的外部定义成员函数差不多,需要指定类型名,然后是类名,使用域运算符以及成员自己的名字
class TestStatic {
public:
	static int id;
	static std::string name;
	static bool Ready() { return bReady; }
	static std::string Msg();
	static const int &Period() { return period; }
private:
	static bool bReady;
	static std::string msg;
	//注意必须+const 否则不能类内初始值
	static const int period = 30; 
	//如果仅仅用在定义数组大小,则可不定义,但是如果其他地方又使用了它的引用则必须定义,因为已有类内初始值,定义语句不加初始值
	//然而尝试后没有出错...
	double dail_tbl[period];
};
//定义并初始化一个静态成员包括函数
//最好不要在头文件中定义静态的成员或者静态的函数,但可以定义非静态的函数 否则可能会报重定义
//必须初始化,不会进行默认的初始化,否则未识别
//int TestStatic::id = 1;
//std::string TestStatic::name = "ddd";
//要想确保对象只定义一次,最好的办法是把静态数据成员的定义与其他非内联函数的定义放在同一个文件中

//静态成员也可类内初始化
//要求静态成员必须是字面常量类型的constexpr 初始值必须是常量表达式

//静态成员能用于某些场景(即静态数据成员可以是不完全类型,而非静态成员就只能声明成它所属类的指针或引用)
//另外一个区别:可以使用静态成员作为默认实参 (自增的ID对象有用)
#endif
