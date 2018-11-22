#ifndef DETAIL_CLASS_H
#define DETAIL_CLASS_H
#include <iostream>

#include <memory>
//类
//一个类通过定义五种特殊的成员函数来控制操作
//拷贝构造函数
//拷贝赋值运算符  
//移动构造函数
//移动赋值运算符
//析构函数
//
//拷贝和移动构造函数定义了当用同类型的另一个对象初始化本对象时做什么
//拷贝和移动赋值运算符定义了将一个对象赋予同类型的另一个对象时做什么
//析构就是此类型对象销毁时做什么
//以上操作称为拷贝控制操作,没有显式定义,编译器会补上

//如果一个构造函数的第一个参数是自身类型的引用,[且任何额外参数都有默认值]
//则此构造函数是拷贝构造函数
//Foo();  //默认构造函数
//Foo(const Foo&);  //拷贝构造函数(一般是const)
//拷贝构造函数在几种情况下会被隐式地使用,因此不应该量explicit的
//合成拷贝构造函数,由编译器定义,与合成默认构造函数不同,即使有定义了其他的构造函数,编译器也会合成一个拷贝构造函数 
//某情况下合成拷贝构造函数用来阻止拷贝该类类型的对象,
//而一般情况下,合成的拷贝构造函数会将其参数的成员逐个拷贝到正在创建的对象中
//编译器从给定对象中依次将每个非static成员拷贝到正在创建的对象中
//每个成员的类型决定了它如何拷贝:类=>拷贝构造函数 内置类型=>直接拷贝
//虽然不能直接拷贝一个数组,但合成拷贝构造函数会逐元素地拷贝一个数组类型的成员(成员类型同上)

//string dots(10,' ');				//直接初始化
//string s(dots);					//直接初始化
//string d2 = dots;					//拷贝初始化
//string null_book = "9-999-99";	//拷贝初始化
//string nines = string(100,'9');	//拷贝初始化
//当使用直接初始化时,实际上是要求编译器使用普通的函数匹配选择参数最匹配的构造函数
//当使用拷贝初始化时,要求编译器将右侧运算对象拷贝到正在创建的对象中,需要的话还要进行类型转换

//如果有一个类有一个移动构造函数,则拷贝初始化有时会使用移动构造函数而非拷贝构造函数来完成
//拷贝构造函数不仅在用=定义变量时会发生:以下也会发生
//1.将一个对象作为实参传递给一个非引用类型的形参
//2.从一个返回类型为非引用类型的函数返回一个对象
//3.用花括号列表初始化一个数组中的元素或一个聚合类中的成员
//某些类类型会对它所分配的对象使用拷贝初始化:初始化标准库容器或调用其insert或push成员会进行拷贝初始化
//与之相对用emplace成员创建的元素都会进行直接初始化
//如果拷贝构造函数形参不是一个引用类型,那么将无限循环调用自身
//调用自身使用的实参(也调用自身)

//拷贝构造函数的限制:可以声明为explicit(只有一个参数),这样可以防止隐式地转换,必须类型一致
//vector<int> v1(10);	//正确
//vector<int> v2 = 10; //错误:接受大小参数的构造函数是explicit的

//编译器可以绕过(不是必须)拷贝构造函数,直接创建对象
//string null_book = "9-999-999";  //拷贝初始化
//改写为(算是一种优化)
//string null_book("9-999-999");	//编译器略过了拷贝构造函数
//即使略过了拷贝/移动构造函数,在这个程序点上,拷贝/构造函数必须是存在并且可以访问的(不能private)

//拷贝赋值运算符
//Bangumi_Data a, b;
//a = b;
//与拷贝构造函数一样,如果类未定义自己的拷贝赋值运算符,编译器会合成一个
//重载赋值运算符(本质也是一个函数)
//如果一个运算符是一个成员函数,其左侧运算对象就绑定到隐式的this参数,对于一个二元运算符,其右侧运算对象作为显式参数传递
//Foo& operator=(const Foo&); //赋值运算符
//标准库通常要求保存在容器中的类型具有赋值运算符,且返回值是左侧运算对象的引用

//合成拷贝赋值运算符
//对于某些类,合成拷贝赋值运算符用来禁止该类型对象的赋值,如果不是出于此目的,会将右侧的运算对象的每个非static成员
//赋予左侧运算对象的对应成员这一工作是通过成员类型的拷贝赋值运算符来完成的,对于数组类型的成员
//逐个赋值数组元素,合成拷贝赋值运算符返回一个指向其左侧运算对象的引用

//析构函数
//构造函数初始化对象的非static数据成员,还可能做一些其他工作;
//析构函数释放对象使用的资源,并销毁对象的非static数据成员;
//~Foo(); //析构函数
//由于析构函数不接受参数,因此不能被重载,对一个给定类,只会有唯一一个析构函数

//如同构造函数有一个初始化部分和一个函数体,析构函数也有一个函数体和一个析构部分
//在构造函数中,成员的初始化是在函数体执行之前完成的,且按照它们在类中出现的顺序进行初始化
//在析构函数中,首先执行函数体,然后销毁成员,成员按初始化顺序的逆序销毁

//在对象最后一次使用之后,析构函数的会执行收尾工作,一般是资源的释放

//在一个析构函数中,不存在类似构造函数中初始化列表的东西控制成员如何销毁,析构部分是隐式的
//成员销毁时发生的什么完全依赖于成员的类型,销毁类类型的成员需要执行自己的析构函数,内置类型没有析构
//函数,因此销毁内置类型成员什么也不需要做[隐式销毁一个内置指针类型不会delete它指向的对象]
//与普通指针不同,智能指针是类类型,所以具有析构函数,因此与普通指针不同,智能指针成员在析构阶段会被销毁

//无论何时一个对象被销毁,就会自动调用其析构函数:
//1.变量在离开其作用域时被销毁
//2.当一个对象被销毁时,其成员被销毁
//3.容器(无论是标准库容器还是数组)被销毁时,其元素被销毁
//4.对于动态分配的对象,当对指向它的指针应用delete运算符时被销毁
//5.对于临时对象,当创建它的完整表达式结束时被销毁
//由于析构函数自动运行,程序可以按需要分配资源,而通常不用担心何时释放这些资源

//当指向对象的引用或指针离开作用域时,析构函数不会执行

//当一个类未定义自己的析构函数,编译器会自动合成一个析构函数
//对于某些类,合成析构函数用来阻止该类型的对象被销毁
//如果不是这种情况,合成析构函数的函数体就为空
//~Bangumi_Data() {}  //等价于合成析构函数[因为析构部分是隐式的]
//在(空)析构函数体执行完毕后,成员会被自动销毁,特别的,string的析构函数会被调用,释放成员所用的内存

//注意:析构函数体自身并不直接销毁成员,成员是在析构函数体之后隐含的析构阶段中被销毁的
//在整个对象销毁过程中,析构函数体是作为成员销毁步骤之外的另一部分进行的

//三/五法则
//在新标准下,一个类还可以定义一个移动构造函数和一个移动赋值运算符
//c++并不要求定义所有这些操作
//当决定一个类是否要定义自己版本的拷贝控制成员时,一个基本原则是首先确定这个类是否需要一个析构函数
//通常对析构函数的需求要比对拷贝构造函数或赋值运算符的需求更为明显,如果这个类需要一个析构函数,
//可以肯定它也需要一个拷贝构造函数和一个拷贝赋值运算符
//例如一个类的构造函数中new一个内存(普通指针),而在析构函数中delete ptr
//如果使用合成的拷贝赋值运算符和拷贝构造函数,那么这个指针只是简单地被赋值过去,一旦原对象被delete
//那么新的对象也会丢失指针的内容,然后销毁时被delete一个未知内存(未定义)

//需要拷贝操作的类也需要赋值操作,反之亦然
//例如一个类的每个对象都必须有唯一的ID,需要特殊的拷贝操作

//使用 = default
//可以通过它显式要求编译器生成合成的版本,在类内使用 = default默认是inline
//如果不希望是inline,在类外部使用 = default

//阻止拷贝
//例如iostream类阻止了拷贝,以避免多个对象写入或读取相同的IO缓冲
//定义删除的函数
//在新的标准下,可以通过将拷贝构造函数和拷贝赋值运算符定义为删除的函数来阻止拷贝,
//删除的函数是这样一种函数:虽然声明了它,但不能以任何方式使用它们.
//在函数的参数列表后加上 = delete来指出希望将它定义为删除的
struct NoCopy
{
	NoCopy() = default;  //合成构造函数
	NoCopy& operator = (const NoCopy &) = delete; //删除拷贝赋值运算符
	NoCopy(const NoCopy&) = delete;  //删除拷贝构造函数
	~NoCopy() = default; //合成析构函数
};
//与default不同,delete必须出现在函数第一次声明的时候,即不能类外定义时
//与default不同的是,delete可以对任何函数使用(defalut只能用在存在编译器合成版本的函数)
//析构函数最好不要是删除的成员,不能删除析构函数,如果析构函数被删除,就无法销毁此类型的对象了
//对于一个删除了析构函数的类型,编译器将不允许定义该类型的变量或创建该类的临时对象
//而且,如果一个类有某个成员的类型删除了析构函数,也不能定义该类的变量或临时对象
//虽然不能定义这种类型的变量或成员,但可以动态分配这种类型的对象,但是不能释放这些对象
struct NoDtor {
	NoDtor() = default;
	~NoDtor() = delete;
};
void test_Nodtor() {
	//NoDtor nd; //错误 析构函数已经删除
	//NoDtor *p = new NoDtor(); //正确:但不能delete p 
	//delete p;  //错误, NoDtor的析构函数是删除的
}
//对某些类:
//编译器将这些合成的成员定义为删除的函数
//1.如果类的某个成员的析构函数是删除的或不可访问的(private),则类的合成析构函数被定义为删除的
//2.如果类的某个成员的拷贝函数是删除的或不可访问的,则类的合成拷贝构造函数被定义为删除的,如果类的某个成员的析构函数是删除的(或不可访问),则类合成的拷贝构造函数也定义为删除的
//3.如果类的某个成员的拷贝赋值运算符是删除的或不可访问的,或是类有一个const的或引用成员,则类的合成拷贝赋值运算符被定义为删除的
//4.如果类的某个成员的析构函数是删除的或不可访问的,或是类有一个引用成员,它没有类内初始化器
//或是类有一个const成员,它没有类内初始化器且类型未显式定义默认构造函数,则该类的默认构造函数被定义为删除的

//本质上如果一个类有数据成员不能默认构造,拷贝,复制或销毁,则对应的成员函数将被定义为删除的

//private拷贝控制
//在新标准发布之前,类是对过将其拷贝构造函数和拷贝赋值运算符声明为private来阻止拷贝

//声明但不定义一个成员函数是合法的,对此只有一个例外,试图访问一个未定义的成员将导致一个链接时错误
//通过声明(但不定义)private的拷贝构造函数,可以预先阻止任何拷贝该类型对象的企图
//试图拷贝对象的用户代码在编译阶段标记为错误,成员函数or友元函数拷贝会导致链接时错误
//不过这些是旧的,现在使用delete

//拷贝控制和资源管理
//行为像值的类 => 每个对象都应该有一份自己的拷贝
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& p) :
		ps(new std::string(*p.ps)), i(p.i) {}
	HasPtr& operator = (const HasPtr&);
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};
//赋值运算符退学组合了析构函数和构造函数的操作,
//赋值操作会销毁左侧运算对象的资源,会从右侧运算对象拷贝数据
//这些操作以正确的顺序执行,即使将自己赋予自己也保证正确
HasPtr& HasPtr::operator =(const HasPtr& p) {
	auto newp = new std::string(*p.ps);//拷贝底层的string
	delete ps;	//释放旧内存
	ps = newp;	//从右侧运算对象拷贝数据
	i = p.i;
	return *this;
}
//一个好的顺序是先拷贝右侧对象的数据到一个临时对象,再销毁左侧对象,最后将临时对象赋值
//前两个顺序因为如果是自赋值会错误

//定义行为像指针的类
//使用引用计数
//工作方式如下
//1.除了初始化对象外,每个构造函数(拷贝构造函数除外)还要创建一个引用计数[用来记录有多少对象与正在创建的对象共享状态]
//2.拷贝构造函数不分配新的计数器,而是拷贝给定对象的数据成员,包括计数器.拷贝构造函数递增共享的计数器,指出新增一个共享用户
//3.析构函数递减计数器,指出共享状态的用户少了一个,如果计数器变为0,则析构函数释放状态
//4.拷贝赋值运算符递增右侧运算对象的计数器,递减左侧运算对象的计数器,如果左侧运算对象的计数器变为0,意味着没有用户,销毁状态
//难题在于哪里存放引用计数,计数器不能直接作为HasPtr对象的成员
//解决一种方法是将计数器保存在动态内存中,当创建一个对象时,也分配一个新的计数器,当拷贝或赋值对象时
//拷贝指向计数器的指针

//定义一个作用引用计数的类
class HasPtr2 {
public:
	HasPtr2(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr2(const HasPtr2& p) :
		ps(new std::string(*p.ps)), i(p.i), use(p.use) {
		++*use;
	}
	HasPtr2& operator = (const HasPtr2&);
	~HasPtr2();
private:
	std::string *ps;
	int i;
	std::size_t *use; //用来记录有多少个对象共享*ps的成员 
};
HasPtr2::~HasPtr2() {
	if (--*use == 0) { //如果引用计数变为0
		delete ps;		//释放
		delete use;
	}
}
HasPtr2& HasPtr2::operator =(const HasPtr2& p) {
	++*p.use;
	auto newps = p.ps;
	auto newuse = p.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = newps;
	use = newuse;
	i = p.i;
	return *this;

}

//交换操作
//定义swap是非常重要的,这类算法在需要交换两个元素时会调用
//如果一个类定义了自己的swap,那么算法将使用类自定义的,否则,将使用标准库的swap
//编写自己的swap函数
class HasPtr3 {
	inline friend void swap(HasPtr3&, HasPtr3&);
private:
	std::string *ps;
	int i;
};
inline void swap(HasPtr3& a, HasPtr3&b) {
	using std::swap; //注意这个问题,虽然声明了using 但如果存在特定版本的swap会优先使用那个版本
	swap(a.ps, b.ps);//因此不能使用std::swap(a,b)这样的,这样就限定了只能用标准库的swap
	swap(a.i, b.i);
}
//宝了swap的类通常用swap定义赋值运算符
//HasPtr& HasPtr::operator =(const HasPtr p) {
//	swap(*this, p);
//	return *this;
//}
//这个版本的重载使用的形参不是引用,而是一个副本,函数体调用swap完成
//即使使用引用传值也会需要创建临时变量
//这种方法自动处理了自赋值情况且异常安全的也不会出现new(可能出现异常)


//动态内存管理类
//某些类需要在运行时分配可变大小的内存空间,这种类通常可以使用标准库来保存数据
//例如使用一个vector来管理元素的底层内在
//但是并不通用

//StrVec类的设计
//每个strVec有三个指针成员指向其元素所使用的内存
//首元素 最后一个实际元素之后 内存末尾之后的位置

//除了这些指针之外,strVec还有一个名为alloc的静态成员,类型是allocator<string>
//alloc会分配strVec使用的内存

class StrVec {
	using string = std::string;
public:

	StrVec() :
		element(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&para); //拷贝构造函数
	StrVec& operator=(const StrVec&para);//拷贝赋值运算符
	~StrVec() { free(); }
	void push_back(const string&para);
	inline string* begin()const { return element; }
	inline string* end() const { return first_free; }
	inline size_t size() const { return first_free - element; }
	inline size_t capacity() const { return cap - element; }
private:
	static std::allocator<string> alloc; //分配元素
	void chk_n_alloc();
	void free();
	void reallocate();
	std::pair<string*, string*> alloc_n_copy(const string*, const string*);
	string *element;
	string *first_free;
	string *cap;
};
void StrVec::push_back(const string & para)
{
	chk_n_alloc();//当使用alloc时必须记住内存是未构造的
	alloc.construct(first_free++, para);
}
void StrVec::chk_n_alloc()
{
	if (size() + 1 < capacity()) {
		alloc.allocate(2 * size() + 1);
	}
}
inline std::pair<StrVec::string*, StrVec::string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return{ data,std::uninitialized_copy(b,e,data) };
	//两个指针分别指向新空间的开始位置和拷贝尾后的位置
	//return std::pair<string*, string*>();
}
inline void StrVec::free()
{
	if (element)
	{
		for (auto p = first_free; p != element; --first_free) {
			alloc.destroy(--p);
		
		}
		alloc.deallocate(element, cap - element);
	}
}
inline StrVec::StrVec(const StrVec & para)
{
	auto newdata = alloc_n_copy(para.begin(), para.end());
	element = newdata.first;
	first_free = cap = newdata.second;

}
inline StrVec & StrVec::operator=(const StrVec & para)
{
	auto newdata = alloc_n_copy(para.begin(), para.end());
	free();
	element = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
//通过新标准库引入的两种机制,可以避免string的拷贝,有一些标准库类,包括string,都定义了所谓的
//移动构造函数,移动构造函数通常是将资源从给定对象"移动"而还是拷贝到正在创建的对象,
//并且标准库保证"移后源"string仍然保持一个有效,可析构的状态
//move标准库函数,定义在utility头文件中,
//当reallocate在内存中构造string时,必须调用move来表示希望使用string移动构造函数...
inline void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = element;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++)); //请注意是std::move
	//由于使用了移动构造函数,这些string管理的内存将不会被拷贝,相反构造的每个string都会从
	//elem指向的string那里接管内存的所有权
	free();
	element = newdata;
	first_free = dest;
	cap = element + newcapacity;
}
//****注意:有Static成员一定要定义,在类中声明可能extern只是声明没有 定义,否则链接错误
std::allocator<StrVec::string> StrVec::alloc;

//对象移动
//新标准的一个最主要的特性是可以移动而非拷贝对象的能力,
//大幅提升性能 //
//源于IO类或unique_ptr这样的类,它们包含不能被共享的资源(指针或IO缓冲)
//因此这些类型的对象不能被拷贝但可以被移动

//标准库容器,string 和 shared_ptr类既支持移动也支持拷贝
//右值引用
//为了支持移动操作,新标准引入了一种新的引用类型---右值引用
//即必须绑定到右值的引用,通过使用&&而不是&来获得右值引用
//右值引用有一个重要特性,只能绑定到一个将要销毁的对象
#endif