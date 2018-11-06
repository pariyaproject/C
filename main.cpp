#include <iostream>
//包含来自标准库的头文件时使用<>否则""
//class
#include "bangumi_subject.h"
//extern const int x ;
//输入输出
void cin_cout_cerr_clog() {
	//cerr clog 和 cout 都会输出在同一个窗口
	std::cerr << "err" << std::endl;
	std::clog << "log" << std::endl;
	std::cout << "cout" << std::endl;
	//std::endl作用一是结束当前行，作用二将缓冲区内容刷到设备上
	//而不是仍在内存中等待，若程序崩溃，关键的输出仍在内存中从而很难推断错误地方
}
//注释问题
void note_err() {
	std::cout << "/*";
	std::cout << "*/";
	//错误
	//std::cout << /*"*/"*/;
	std::cout << /*"*/" /* "/*"*/;
}
//不定的for循环
void undefine_num_for() {
	int num = 0;
	//当使用一个istream对象作为条件时，实际是检测流是否是有效的
	//因为istream对象返回左侧的运算对象
	//流有效，即是未碰到错误，当碰到文件结束符(EOF)or无效输入（类型不符，这里为非整数）则为无效输入
	while (std::cin >> num) {
		std::cout << "you have cin : " << num << std::endl;
	}
	//EOF win:ctrl+z unix:ctrl+d
}
//类的创建使用
void use_bangumi_class() {
	//.运算符左侧只能是类类型的对象不能是指针
	//指针使用->
	Bangumi_subject my_subject;
	Bangumi_subject my_subject1(123, 9, 5);
	Bangumi_subject my_subject2(123, 8, 3);
	Bangumi_subject my_subject3(0,0,1000);

	std::cin >> my_subject;
	std::cout <<"current subject:\n"<< my_subject << std::endl;
	std::cout <<"++subject\n"<< ++my_subject << std::endl;
	std::cout <<"subject++\n"<< my_subject++ << std::endl;
	std::cout <<"subject+subject:\n"<< my_subject1 + my_subject2 << std::endl;
	my_subject += my_subject3;
	std::cout << "subject+=:\n" << my_subject << std::endl;
		
}
//c++是一种静态数据类型语言 区别与php等运行时检查数据变量的类型
//->静态类型语言：在编译阶段检查类型(类型检查)
//32位系统中一个字(word)有32bit即4个字节(bytes)
//->32位有2^32(字节)bytes寻址空间4*2^10*2^10*2^10=4G
//char != signed char (0~255)由编译器决定 [unsigned char(-128~127)]
//->因为以上原因不要使用char做运算 而代替为有(un)signed修饰的
//long 一般和 int 有一样的尺寸 longlong更好
//不可能是负 则用unsigned修饰(大于等于0) 只有unsigned则默认unsigned int
//给一个无符号的数赋值超范围的数结果取模后所得余数 如 unsigned char x=-1 (实际255)
//给一个有符号的数赋值超范围的数结果是未定义
//字符串("")比字符('')多一个空字符('\0')，两个字体串仅间隔空格，缩进，换行的话
//则实际它们是一个整体“x” “y”=="xy"
//指定字面值类型
//->L'a' 宽字符字面值 类型是wchar_t [字符的是前缀]
//->u8"hi!" utf-8字符串字面值  [数字的是后缀]
//->nullptr是指针字面值
//C++11新特性: int units_sold{0} 使用花括号初始化变量(列表初始化)
//->[内置类型的变量可能的信息丢失时编译报错]
//默认初始化，内置类型其值由定义的位置决定，定义在任何函数体外的的变量初始化为0
//->定义在函数体内的变量不被初始化(未定义)
//声明和定义
//->声明时可能也定义(申请空间，赋初始)了这个变量名，可以添加extern关键字不显示地初始化变量
//->例如：extern int i;  声明而非定义
//->int j;  声明并定义
//->extern double pi = 3.1416;  定义
//->在函数体内部(当然也算main)若初始化一个extern标记的变量则错
//声明=使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。而定义负责创建与名字关联的实体。 
//变量声明规定了变量的类型和名字，在这一点上定义与之相同。但是除此之外，定义还申请存储空间，也可能会为变量赋一个初始值。
//其中可能赋了初始值(显示或隐式)是指自定义类型调用构造函数，内置基本类型看定义所在的域
void test_extern() {
	//extern double pi = 3.1416;
}
//变量只能被定义一次，可以多次声明
//->如果要在多个文件中使用同一个，就必须将声明和定义分离，变量的定义必须出现在且只能出现在一个文件中
//->而其他用到该变量的文件必须对其进行声明，绝不能重复定义
//以下是良好风格(编译可以通过)
//->用户自定义的标识符中不能连续出现两个下划线，也不能下划线紧连大写字母开头
//->定义在函数体外的标识符不能以下划线开
//int _abc;
//void test_identifier() {
//	int __c;
//	int _X;
//  int _;
//}
//scope(作用域)c++中大多作用域以花括号分隔，不同作用域可以有相同的名字但不同的实体
//->名字的有效区域始于名字的声明语句，以声明语句所在的作用域末端为结束
void test_scope() {
	int sum = 0;
	for (int val = 0; val < 11; ++val) {
		sum += val;
	}
}
//test_scope定义于所有花括号之外(全局作用域)
//->sum定义于test_scope函数限定的作用域之内，出了函数体就无法访问(块作用域)
//->val定义于for语句内，只能在for中访问
//局部同名变量会覆盖全局变量
//->显示访问全局作用域时使用::sum
//复合类型
//c++11新增"右值引用"一般“引用”是指"左值引用"
//声明语句 = 基本类型 声明符;
//引用为对象起了另外一个名字
//->声明符 &d 来定义引用类型
void test_refers() {
	int val = 12;
	int &refval = val;
	std::cout << refval << val++ << std::endl;
	std::cout << refval;

	//int &refval1; //报错: 引用必须被初始化
	//一般在初始化变量时，初始值会被拷贝到新建的对象中
	//而定义引用时，程序会把引用和它的初始值绑定在(bind)一起
	//注意：绑定以后无法重新绑定另外一个对象，因此必须初始化，不能绑定一个字面值或不同类型的变量
	//引用并非一个对象(没有一个实际的物理地址)，只是一个别名，所以无法定义引用的引用
}
//指针本身是一个对象，允许赋值拷贝，定义时无需赋初值，存放对象的地址
//->与其他内置变量一样，在块作用域内定义的指针如果没有初始化，将拥有一个不确定的值
//声明符 *d
void test_pointer() {
	//int *ip1, *ip2; //不确定的值
	//获取对象的地址
	int val = 42;
	int *p = &val;
	//当然不能将不同类型的对象赋值
	//通过指针访问一个对象，使用解引用符*
	*p = 123;
	std::cout << *p;
	//使用一个指针前，最好检查指针的有效性(空)
	//生成空指针的方法
	int *p1 = nullptr; //等价*p1 = 0; 推荐使用
	int *p2 = 0;//直接初始化为字面常量0
	int *p3 = NULL;//等价*p3 = 0;
	//不能给指针赋值一个变量
	//int x = 0;
	//int *p4 = x;
	//任何非0指针的条件值都是true
	//void* 指针可以存放任意对象的地址
	double obj = .14, *pd = &obj;
	void *pv = pd;
	pv = &obj;
	//由于不知void*指针的类型，不知类型的话能做的事有限
	std::cout << *(double*)pv;
	//std::cout << *pv; //报错
	//多级指针
	//指向指针的引用
	int *x = 0;
	//int &*r = x; //不允许使用指向引用的指针
	//从右向左读
	//距离变量名最近的最(先)有影响 &*r=&(*r) r是一个指针 引用不是变量 *r可看成一个整体，r指向这个整体，但这个整体是一个引用
	int *&r = x; //*&r=*(&r) r是一个引用 r的引用是一个指针
}
//const限定符 必须初始化
void test_const() {
	//const int i = sizeof(int); 
	//运行初始化(函数返回值) 注意这里sizeof是一个关键字
	const int j = 45; //编译时初始化
	//const int k; //错误 必须初始化
	int c = 123;
	const int a = c;
	int d = a;
	//当以编译时初始化的方式定义一个const 对象时，编译器会在编译过程中直接将变量替换成字面值
	//默认状态下 const对象仅在文件内有效，多文件可以重名const变量
	//有必要在文件间共享时(像非常量一样工作)应当对const变量不管声明还是定义都添加extern关键字
	//对const的引用
	const int ci = 1024;
	const int &rl = ci; //注意类型 const int

	//引用类型必须和对象的类型一致的例外
	//初始化常量引用允许用任意表达式作为初始值，只要表达式的结果能转换成引用的类型
	//原因是常量引用是不会更改值的，因此通过临时量进行初始化
	//而非常量可能会更改原内存值，通过一个拷贝转换的临时量是无法改变的，因此非法
	int i = 42;
	const int &r1 = i;  //int 可转换成const int
	const int &r2 = 45;  //字面值 可转换成const int
	const int &r3 = r1 * 2;  //可转换成const int
	//int &r4 = r1 * 2; //错误 r4是一个普通的非常量引用
	//r1 = 5;//错误 r1是一个常量引用(对const的引用)
	//指针和const类似于引用
	const double xpi = 3.14;
	//double *ptr = &xpi; //错误
	const double *ptrc = &xpi;
	//*ptrc = 42.0; //错误
	//例外
	double val = 3.14;
	ptrc = &val; //通过 但不能通过ptrc改变val的值

	//const指针 必须初始化 不变的是指针本身的值而非指向的那个值
	int errNumb = 0;
	int *const curErr = &errNumb;
	const double pi = 3.1415;
	const double *const piptr = &pi;
	//顶层const 本身是const
	//底层const 所指的对象是const

}
//常量等
void const_test_others() {
	//常量表达式 constexpr变量
	//声明为constexpr的变量一定是一个常量，而且用常量表达式(编译过程就能得到结果)初始化
	constexpr int size = sizeof(int);
	//常量表达式
	std::cout << size;
	//constexpr是有限制的(字面值类型) 自定义类 IO库 string类型不属于字面值类型
	//定义在所有函数体之外的对象其地址固定不变，能用来初始化constexpr指针
	const int *cpp = nullptr; //指向常量的指针
	constexpr int *cpp2 = nullptr; //指向int的常量指针
	constexpr const int *cpp3 = nullptr; //指向常量的常量指针
}
//类型别名
//定义类型别名 传统方法
typedef double wages;
typedef wages base, *f; //f是 double*的同义词
const f double_f = 0;//double_f是指向double的常量指针
//此时的关联关系和以前的不同 f类型已经是指针了 const f 已经是基本数据类型了 double_f 才是声明符
//c++ 11新的方法 别名声明 注意声明后才能使用
using B_S = Bangumi_subject; //B_S是类的同义词
using ptr_int = int *;

//auto类型说明符 c++ 11
//auto让编译器通过初始值来推算变量的类型，auto定义的变量必须有初始值
double val1 = 1.5;
int val2 = 5;
auto item = val1 + val2; //double类型 
B_S subject_1(0,0,2);
auto subject_item = subject_1 + subject_1;//auto也可以是一个类B_S
//虽然有auto的支持 但仍不能改变c++是强类型语言的事实
//auto可以一次多个声明，但多个名字必须是同一个类型
//auto sz = 0, pi = 3.14; //error
//auto会忽略顶层const 否则显示声明 const auto
//decltype类型指示符 c++ 11
//作用是希望得知类型 但不不需要用其值初始化
//返回操作数的数据类型
//decltype(f()) sum = x; //sum的类型是函数f的返回类型
//如果使用的是变量，则decltype返回该变量的类型(包括顶层const和引用在内) 直接相当于替换
//如果是表达式 其中返回是引用 应当能作为左值
//int iii = 45, *ppp = &iii, &rrr = iii;
//decltype(rrr + 0) bbdsfsa; //r+0 =>int
//decltype(*ppp) dfadadf; //错误 c 是Int& 类型 必须初始化 
//int i;
//decltype ((i)) d; //d是int & 错误 没初始化 ()当作是表达式处理 可以直接处理因此是引用
//双层括号永远是引用 单层只有当变量本身是引用才是引用
//decltype (i) d; //d是int 
//结构体
struct Bangumi_date {
	//Bangumi_date() {}
	//Bangumi_date(unsigned i,std::string n):id(i),name(n){}
	unsigned id = 0;
	std::string name;
	
}test_struct_0;//此外必须有; 因为类体后可以紧跟变量名
using B_D = Bangumi_date; //或者直接加在声明前 但就不能紧跟变量名
B_D test_struct_1;
Bangumi_date test_struct_2;
//c++ 11
//可以为类内数据成员提供一个类内初始值
//注意类内初始值 放在花括号里或等号右 不能使用圆括号
//Bangumi_date test_struct_3{1,""}; //注意此时这里报错，只有当定义时没有默认时才正确 （unsigned id;）
//Bangumi_date test_struct_4={1,""};//注意此时这里报错，只有当定义时没有默认时才正确 （unsigned id;）
//确保多次包含头文件也能安全工作的技术是预处理器
//预处理功能 #include 用指定的头文件代替
//预处理变量有两个状态 已定义和未定义 #define 
//
int main() {
	//输入输出
	//cin_cout_cerr_clog();
	///*/*xx*/xxxx*/会报错
	//以上原因是/**/不能嵌套
	//注释问题
	//note_err();
	//不定的for循环
	//undefine_num_for();
	//类的创建使用
	//use_bangumi_class();
	//extern double p;
	//p = 3.1416;
	//指针
	//test_pointer();
	std::cout << sizeof(item)<<"  "<<item<<std::endl;
	std::cout << sizeof(subject_item)<<"  "<<subject_item<<std::endl;
	//extern const关键字
	//std::cout << x;
	system("pause");
	return 0;
}
