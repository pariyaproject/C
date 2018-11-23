#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <memory>
//包含来自标准库的头文件时使用<>否则""
//class
#include "bangumi_subject.h"
#include "Test_class.h"
#include "Detail_Class.h"
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
	Bangumi_subject my_subject3(0, 0, 1000);

	std::cin >> my_subject;
	std::cout << "current subject:\n" << my_subject << std::endl;
	std::cout << "++subject\n" << ++my_subject << std::endl;
	std::cout << "subject++\n" << my_subject++ << std::endl;
	std::cout << "subject+subject:\n" << my_subject1 + my_subject2 << std::endl;
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
void test_type() {
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
	B_S subject_1(0, 0, 2);
	auto subject_item = subject_1 + subject_1;//auto也可以是一个类B_S
	std::cout << sizeof(item) << "  " << item << std::endl;
	std::cout << sizeof(subject_item) << "  " << subject_item << std::endl;
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
}
//结构体
struct Bangumi_data {
	//Bangumi_data() {}
	//Bangumi_data(unsigned i,std::string n):id(i),name(n){}
	//unsigned id = 0;
	unsigned id;
	std::string name;
	friend std::ostream& operator<< (std::ostream &os, const Bangumi_data& bd) {
		std::cout << "name: " << bd.name << "\nid: " << bd.id << std::endl;
		return os;
	}
}test_struct_0;//此外必须有; 因为类体后可以紧跟变量名
void test_struct() {
	using B_D = Bangumi_data; //或者直接加在声明前 但就不能紧跟变量名
	B_D test_struct_1;
	Bangumi_data test_struct_2;
	//c++ 11
	//可以为类内数据成员提供一个类内初始值
	//注意类内初始值 放在花括号里或等号右 不能使用圆括号
	Bangumi_data test_struct_3{ 1,"" }; //注意此时这里报错，只有当定义时没有默认时才正确 （unsigned id;）
	Bangumi_data test_struct_4 = { 1,"" };//注意此时这里报错，只有当定义时没有默认时才正确 （unsigned id;）
}
//确保多次包含头文件也能安全工作的技术是预处理器
//预处理功能 #include 用指定的头文件代替
//预处理变量有两个状态 已定义和未定义 #define 
//string和vector是两个重要的标准库类型
//前者支持可变长的字符串，后者支持可变长的集合
//内置数组是一种更基础的类型，string和vector都是对它的某种抽象
//命名空间using声明
void test_using() {
	//cout << "ddd";//报错: 应当位于using之后
	using std::cout;
	cout << "yes";
	using std::cin; using std::endl;
	//using也是在其声明的作用域中有效,并且在声明语句之后
}
//头文件不应包含using声明,否则包含了这个头文件的文件都会有这个声明
//标准库string

void test_string() {
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
	//string的初始化方法
	string s1; //空字符
	string s2 = s1; //(拷贝初始化)s1的副本 等价于 (直接初始化)string s2(s1);
	string s3 = "hiya"; //字面值 该字面值除了最后的空字符'\0'其它所有的字符被拷贝
	//也就是说string这个类中没有字符串字面值的最后的'\0'
	//->等价 s3("hiya")
	string s4(10, 'c'); //s4的内容是 cccccccccc
	//s4对应的拷贝初始化 string s4=string(10, 'c');
	//初始化的方式
	//如果使用等号 = 初始化则是拷贝初始化
	//如果不使用等号 = 则是 直接初始化
	//>>输入流以空白字符分隔 
	//注意使用getline一定要包含<string> 仅仅使用string可不用
	//getline和cin一样会返回流参数 例如 while(getline(std::cin,s1));
	getline(std::cin, s1);//从输入流读取一行赋值给s1 相比cin>>s1只忽略空白字符,但换行依旧不存储(但有读入标志结束)
	//如果一开始就是换行符那么将会是一个空字符
	//s1 = { '\0' };
	if (!s1.empty())//注意 空格 \0不是一个空字符()
		cout << "getline=" + s1 + "=end" << endl;
	//但是cin>>s1就不会以换行符结束,也就是说cin>>不可能出现一个空字符,必须录入一个非空白字符才会算完成这个操作
	cin >> s1;
	cout << s1 << endl;
	cout << s1.empty() << endl;
	//"xxx"这是一个C风格的字符串 是以\0为末尾识别的
	//string 是一个对象 也有长度记录 完全可以不用\0来确定长度(什么时候结束)
	string test1("123\0");//"123\0"就已经确定了是 '1''2''3'三个字符的赋值
	string test2("123");
	string test3(4, '\0');//string对象不会将\0忽略因为\0本身就是空字符的含义
	string test4{ '1','2','3','\0' };
	//size()返回的是string::size_type类型(无符号类型的值)因此不应混用int(至少用unsigned)
	//auto len = s1.size();
	//string::size_type x;
	cout << s1.size() << endl;
	cout << test1 << " " << test1.size() << endl;//size返回string中字符的个数
	cout << test2 << " " << test2.size() << endl;
	cout << test3 << " " << test3.size() << endl;
	cout << test4 << " " << test4.size() << endl;
	//但是使用 c_str() data()将string对象转换为const char *时最后一个字符是'\0'
	string blan;
	cout << "空白=" << blan[blan.size()] << "=ddd" << endl;
	cout << "空白=" << test1[test1.size()] << "=ddd" << endl;//0-size()-1是存储有效字符
	//当试图访问size()位时会固定返回'\0'
	//reference:https://segmentfault.com/q/1010000005141633
	//==如果s1 s2所含的字符完全一样才相等(大小写敏感)
	//>= <= 根据在字典中的顺序对比 
	string a("a");
	string b("b");
	cout << (a >= b) << endl;// a<b 依此类推 
	//string("a")<string("aa")
	//如果两个string长度不同,并且较短的string中每个字符都与较长的对应位置相同,则较短的<较长的
	//如果比较的字符在某些位置不同,结果是第一对不同的字符的字典顺序
	//string 对象可以使用+ 返回是一个新的string对象(所有字符拼接)
	//但是必须至少有一个对象是string(并且必须先进行string和字面值的运算)不能是字符串字面值: "123"+"dd"
	string("123") + "123" + "222";
	//"123" + "   " + string("ddd");//非法存在字面值直接相加的过程
	//位于 <cctype>
	isalnum('s');//当字母或数字时为真
	//isalpha > 字母
	//iscntrl > 控制字符
	//isdigit > 数字
	//islower > 小写字母
	//isprint > 可打印
	//ispunct > 标点符号
	//tolower > 输出小写 注意返回的是int类型
	//toupper > 输出大写 注意返回的是int类型

	//基于范围的for  range for
	//for (declaration : expression) 遍历给定序列的每个元素
	//每次迭代declaration会被初始化为expression部分的下一个元素值
	//因为string表示一个字符的序列
	string test_range_for("aabbcc dd");
	for (auto &each : test_range_for) {//如果需要改变值 则使用引用
		//cout << static_cast<char>(toupper(each)) << endl;
		each = static_cast<char>(toupper(each));
	}
	cout << test_range_for << endl;
	//下标运算符[] 接受的参数是string::size_type 返回值是此位置字符的引用
	//&& 逻辑与运算符 c++中只有左侧的运算为真才会检查右侧的运算对象
}
//vector 容器
void test_vector() {
	using std::string;
	using std::endl;
	using std::cout;
	//vector表示对象的集合,其中所有对象的类型都相同 
	//使用vector必须包含 <vector>
	//vector也位于std命名空间 vector是一种类模板 需要提供额外的信息(类型)
	//编译器根据模板创建类或函数的过程称为实例化
	using std::vector;
	vector<int> ivec; //<int>是提供的额外信息 //空vector 执行默认初始化
	vector<Bangumi_data> bdvec;
	vector<vector<string>> strvv;//vector可以嵌套 类似二维的数组
	//vector<int&>d; 错误
	//请注意 引用不是一个对象 不能放在vector中
	//c++旧版本嵌套vector外层vector对象的右尖括号和元素类型之间要有一个空格 vector<vector<int> >
	//c++ 11 无需空格
	//初始化vector
	vector<int> ivec2(ivec); //直接初始化 ivec的副本
	vector<int> ivec3 = ivec; //赋值初始化 等价上一个(ivec)
	vector<int> ivec4(10, 1); //包含了10个值为1的int
	//vector<int> ivec44 = (10, 1); //错误 
	vector<int> ivec5(11); //包含了11个执行了默认初始化的int
	vector<int> ivec6{ 1,2 }; //两个元素 分别是1 2
	//c++11 提供了列表初始化 vector
	vector<int> ivec7 = { 1,2 };//可以看作 vector<int> ivec6={int(1),int(2)}
	vector<string> strvec = { "dd","ddd" };
	//vector<Bangumi_data> bdvec2 = { {1,""},{2,"ddd"} }; //可以初始化列表中使用初始化列表
	vector<Bangumi_data> bdvec2 = { { 1,"" },{2,"ddd"} };//不同于类 即使没有相关的构造函数依旧可以直接使用{}初始化
	Bangumi_subject test_bs1 = { 1,2,3 }; //类也可使用初始化列表的形式,但实际上是调用了相关的构造方法
	//->正如之前所提到的使用{}列表初始化编译会检查类型,不对便会报错 
	cout << "BangumiSubject" << test_bs1 << endl;
	vector<Bangumi_subject> bsvec = { {1,2,3},{2,3,4} };//不能使用{(1,2,3)} 只能用列表初始化
	//综上 vector中的初始化列表[严格要求类型一致]
	//->隐藏了对应的对象类型名 如 Bangumi_subject{1,2,3} => {1,2,3} int{1}=>1
	for (auto bd : bdvec2) {
		cout << bd << endl;
	}
	for (auto bs : bsvec) {
		cout << bs << endl;
	}
	//圆括号用来构造 花括号用来列表初始化
	ivec.push_back(2); //向vector尾添加元素
	//vector是可以高效地增长的,只有一种例外初始化相同的元素
	//否则使用运行时push新元素到一个空vector更高效
	//为了高效很多检查保护省略,应确保无误
	//如果循环体包含有向vector添加元素语句 时 不能使用range for
	//除了push_back()
	//empty() //是否存在一个元素
	//size() //元素个数
	//[n] //返回引用
	//== //当且仅当元素个数相同并且对应位置值相同
	//< > //以字典顺序比较
	//size_type要对应
	vector<int>::size_type testx = 0;
	//如两个vector比较如string一样 看个数和内容
	//内容的比较看具体的类型的比较
	//->前提是只有vector内的元素值可比时 对应的vector才可比
	//两个整数相除结果还是整数,余数被忽略
	//iterator迭代器
	//除了vector还有其他容器
	//所有标准库容器都能使用迭代器 string也可以 
	//迭代器有 有效和无效之分
	//迭代器的end指向的是容器的一个本不存在的尾后,仅仅标识最后
	//如果容器为空 则 begin 和 end 返回的是同一个迭代器 都是尾后迭代器
	//迭代器运算符
	//*iter 返回元素引用
	//iter->name
	//++iter
	//--iter
	//iter1 == iter2
	string strtest("aabbccdd");
	for (auto it = strtest.begin(); it != strtest.end(); ++it) {
		*it = toupper(*it);
	}
	cout << strtest << endl;
	//
	string::iterator it2; //能读写字符
	//如果vector 或 string是常量 只能 用const_iterator
	string::const_iterator it3; //只能读取字符 不能写字符
	//begin和end返回的具体的类型由对象是否是常量决定
	//为了便于得到const_iterator类型
	//c++引入了 cbegin和 cend
	string::const_iterator testc = strtest.cbegin();
	//某些对vector对象的操作会使迭代器失效
	//比如在使用了迭代器的for中用使用push_back
	//因此push_back应当在一般循环中使用
	//迭代器运算
	//iter + n //向前移动n个元素
	//iter - n //向后移动
	//iter += n
	//iter1 - iter2 //两个迭代器之间的距离 中间的元素差个数 
	//< > //
	//begin()是指0下标
	auto mid = strtest.cbegin() + strtest.size() / 2;
	string::difference_type difference = mid - strtest.cbegin(); //带符号的整形
	//二分

}
//数组大小确定不变
//char cha1[] = "c++";
//char cha2[] = { 'c','+','+','\0' }; //结尾应当有一个空字符 可以将char[]看作c风格的string 即字符串字面值
//char cha3[] = { 'c','+','+' }; //由于没有结尾的空字符 c++后输出很多 烫烫
void test_array() {
	using std::cout;
	using std::endl;
	//数组a[b]的维度(b)必须是常量表达式
	unsigned cnt = 45; //不是常量表达式
	//int arr[cnt]; //错误
	constexpr unsigned cnt1 = 45;
	int arr[cnt1] = {}; //可以
	int arr2[sizeof(int)] = {}; //可以
	//和内置类型一样 在函数体内定义了某种类型的数组,默认初始化会含有未定义的值
	//定义数组必须指定数组的类型 不能用auto
	//auto xxx[] = { 1,1,1 };//报错
	//数组的元素为对象 不存在引用 
	//显示初始化数组元素(列表初始化)
	int a3[5] = { 0,1,2 }; //等价 a3[]={0,1,2,0,0} 函数体外否则未定义
	//cout << a3[4] << "  " << a3[5] << endl; //未定义值
	//字符数组有一种额外的初始化方式,使用字符串字面值
	char cha1[] = "c++";
	char cha2[] = { 'c','+','+','\0' }; //结尾应当有一个空字符 可以将char[]看作c风格的string 即字符串字面值
	char cha3[] = { 'c','+','+' }; //由于没有结尾的空字符 c++后输出很多 烫烫(函数体内是这样,外部尝试后正常输出c++)
	cout << cha1 << endl;
	cout << cha2 << endl;
	//cout << cha3 << endl;
	//const char a4[6] = "123456"; //错误  没有空间存放\0
	//数组不允许拷贝和赋值(可能有些编译器支持赋值,但不是标准)
	int *ptrs[10]; //10个int型指针的数组
	//int &refs[10]; //错误  :不存在引用的数组
	int arr3[10] = {};
	int(*parray)[10] = &arr3; //指向一个含有10个整形的数组
	int(&arrref)[10] = arr3; //引用一个含有10个int的array
	//从里向外绑定 parray是一个指针 指向 int [10]
	int *(&arrya)[10] = ptrs; // arrya是数组的引用 数组含有10个指针
	//除了固定大小 其他和vector基本一致
	unsigned scores[11] = {}; //array没有现有的迭代器类型(数组并不是一个类) 全部默认初始化为 0
	//->注意 使用了{}初始化列表就是显示地默认初始化(等同于在函数体外定义并初始化)
	//->但不加{}只是定义 unsigned scores[11]; 则为未定义值
	for (auto i : scores) {
		cout << i << endl;
	}
	//这与vector有点区别
	std::vector<unsigned> scores2(11, 0);
	//使用数组时,编译器一般会把其转换成指针
	using std::string;
	string nums[] = { "one","two","three" };
	string *p = &nums[0];
	string *p1 = nums; //两者等价
	//**** 编译器自动替换nums为指向数组第一个元素的指针 ****
	decltype(nums) x = {};//类型是 string[3];
	auto x2(nums);//类型是 string*  ==x2(&nums[0])
	//数组的迭代
	cout << *(++p1) << endl; //从nums[0] 到 Nums[1]
	//++根据指向的类型向后移动 sizeof(指向类型)个字节
	//指针类型重载了++ 和 + 等等运算符
	//判断结尾用尾后元素地址 这里是 nums[3]->指向不在的一个元素[尾元素是最后一个有效值]
	//为了更加安全 c++ 11标准引用 begin end 函数
	string *beg = std::begin(nums);
	string *end = std::end(nums); //尾后指针不能直接使用 *
	for (auto i = beg; i != end; ++i) {
		cout << *i << endl;
	}
	//当然也有类似const_iterator的cbegin
	const string *beg1 = std::cbegin(nums);
	int ary[] = { 1,1,2,3,6,4 };
	auto n = std::cend(ary) - std::cbegin(ary); //ary中元素的个数 类型是 ptrdiff_t标准库类型
	//而迭代器中的类型是 vector::difference_type
	cout << n << endl;
	int nn = sizeof(ary) / sizeof(*ary);
	cout << nn << endl; //也可得知元素个数
	//ptrdif_t(带符号)和size_t一样定义在cstddef
	//数组使用的是内置的下标运算(可以处理负值)
	//vector的下标运算只支持无符号
}
//c风格字符串不是一种类型而是一种写法
void test_c_cpp_string() {
	//c-style string最后一个字符后跟上一个空字符'\0'(也占一个字符位)
	//实际上c风格的字符串就是一个char的数组
	using std::string;
	using std::cout;
	using std::endl;
	string str = "abc";
	const char co_str[] = "def";
	char c_str[7] = "abc";
	cout << sizeof(str) << endl; //40字节
	cout << sizeof("abc") << endl; //4字节
	//c style的操作函数
	//返回长度 空字符不计
	cout << strlen(co_str) << "  " << strlen("abc") << endl;
	//strcmp(p1,p2)  相等为0 p1大于p2为正数
	cout << c_str << "  " << sizeof(c_str) << " " << strlen(c_str) << endl;
	//输出 abc 7 3
	cout << c_str[5]; // \0空字符
	strcat(c_str, co_str);
	cout << c_str << endl;//参数一不能是const 将2附加到1并返回1
	//->这个操作会引发中断,原因是c_str没有足够的空间 因此声明c_str[7]
	strcpy(c_str, co_str); // 将2拷贝给1 返回1
	cout << c_str << endl; //确保1的内存空间足够
	//对于一个string对象比较直接使用 < > (重载了操作符) 
	//而对于c风格的使用 < > 比较的是指针,而非字符串本身 当然 + -也不能使用(实际是两个不相关的指针的运算) 必须使用strcmp

	//任何出现字符串字面值的地方都可用空字符结束的字符数组来替代
	//标准库string提供一个s_str()来初始化 const char* (不能是const char[]函数只能返回指针) (c风格)[]
	const char *xx = str.c_str();
	//char xxx[] =
	cout << xx << endl; //注意 char类型的指针使用<<流时会一直输出到\0为止
	//因为是一个指针,无法保证c_str()返回的值一直有效
	str = "ddd";
	cout << xx << endl; //输出ddd
	//使用数组初始化vector对象
	int int_arr[] = { 0,1,2,3,4,5,6 };
	//注意 所有的end都是指尾后元素(不存在定义内容)
	std::vector<int> ivec(std::begin(int_arr) + 1, std::end(int_arr) - 1);
	for (auto i = ivec.begin(); i != ivec.end(); ++i) {
		cout << *i << endl;
	}
	//尽量使用标准库而非数组
	//多维数组 数组的数组
	int ia[3][4] = {}; //大小为3 每个元素是含有4个整数的数组
	//按照从里向外解读 (数组这样来解读)
	//对于二维数组 常把第一个维度称作行 第二个维度称作列
	int ib[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	//也可以没两层花括号
	int ic[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int id[3][4] = { {0}, {1}, {2} };//也可部分给定初始化 其他默认初始化
	int(&row)[4] = ib[1]; //把row绑定到时ib的第二个4元素数组上;
	//二维数组的for
	//传统方法 两个for嵌套
	//c++11 range for
	for (auto &i : ia) {
		for (auto &j : i) {
			j = 1;
		}
	}
	//使用引用的原因 以上不仅是因为需要改变值
	for (const auto &row : ia) {//此处(外层)需要用 & 引用来避免数组自动转成指针
		for (int col : row) {
			cout << col << endl;
		}
	}
	//实际使用range for 是寻找begin函数先找到指针 然后由range for 自动解指针
	//for (const auto row : ia) {
	//	for (auto col : row) { //row的类型是int *const row 无法找到合适的begin
	////**** 编译器自动替换一个数组的名为指向数组第一个元素的指针 ****
	////多维数组会被转换为1级指针
	//		cout << col << endl;
	//	}
	//}
	//int ox = std::begin(ia); 
	//begin返回的就是一个指针 但返回的是 int(*) [4]
	//这和直接使用数组名有本质区别:直接使用名会使用其退化为一级指针 int*
	for (auto p = std::begin(ia); p != std::end(ia); ++p) {
		for (auto q = std::begin(*p); q != std::end(*p); ++q) {
			cout << *q << endl;

		}
	}
	//使用类型别名简化工作 c++ 11
	using int_array = int[4];
	typedef int int_array[4];//等价
}
//小结
//string(可变长的字符序列) 和 vector(一组同类型对象的容器)是两个 重要的标准库类型
//两者都有迭代器
//数组和指向数组元素的指针在一个较低的层次上实现了与标准库类型string和vector类似的功能
//buffer overflow 主要原因试图通过一个越界的索引访问容器的内容 
//编译器扩展 不易移植
//拷贝初始化 使用= 初始化形式 新创建的对象是初始值的一个副本
//左值和右值 c++的表达式不是左值 就是 右值: c语言中左值可以位于赋值语句的左侧,右值不能
//c++中 两者区别: 一个左值表达式的求值结果是一个对象或一个函数,然而以常量对象为代表的某些左值不能作为赋值语句的左侧运算对象
//此外虽然某些表达式的求值结果是对象 但它们是右值
//总结 当一个对象被用作右值时,用的是对象的值(内存);当对象被用作左值时.用的是对象的身份(对象的位置)
//c++ pri p121有详细的例子

void test_basic() {
	//对于那些没有指定顺序的运算符来说,如果表达式指向并修改同一个对象,将会引发错误并产生未定义行为
	//例如<<没有明确规定何时以及如何对运算对象求值
	//因此以下输出表达式是未定义的
	using std::cout;
	using std::endl;
	int i = 0;
	cout << i << "" << ++i << endl; //错误 //一种输出是 11
	//有4种运算符明确规定了运算对象的求值顺序1>&& 2>|| 3>?: 4>,
	//求值顺序与优先级和结合律无关,在f()+g()*h()+j()中
	//优先级规定,g()的返回值和h()的返回值相乘
	//结合律规定,f()的返回值先与g()和h()的乘积相加,结果再与j()的返回值相加
	//对于这些函数的调用顺序没有明确规定
	//如果它们都是无关函数(同一对象的改变,IO任务),则调用顺序不受限制,反之则未定义行为
	//因此一个表达中最好不要有对同一对象的更改操作*++iter没有问题 ++总先运算
	//取模运算对象必须是整数
	//c++11规定商一律向0取整(直接切除小数部分)
	//m n为整数且n!=0 m==(m/n)*n+m%n
	//m%(-n) == m%n  (-m)/n == m/(-n) == -(m/n)
	//<= >= < >优先级大于== !=
	//&&当且仅当两个运算对象都为真时结果为真||只要一个为真即为真
	//两者都是先求左侧运算对象的值当且仅当左侧无法确定表达式的值时才会计算右侧的运算值
	//->这种策略叫 短路求值
	//赋值运算符的左侧对象必须是一个可修改的左值
	int ii = 0, j = 0;//初始化而非赋值
	const int ci = ii;//初始化而非赋值
	//i+ j =k; //错误 算数表达式是右值
	//k = {3.14}; //错误 窄化转换 {}类型要求一致
	//如果初始化列表{}为空 则值初始化创建一临时是并将其赋缎带左侧运算对象
	//赋值运算满足右结合律 不同其他二元运算符 其优先级较低
	//复合运算符求值次数只有一次 而普通的需要两次 +=
	//递增 递减运算符
	//前置版本将对象本身作为左值返回(推荐) 后置版本则将对象原始值的副本(消耗)作为右值返回
	//后置的使用例子 *pbeg++
	//后置递增运算符优先级高于解引用运算符
	//std::string s;
	//std::string::iterator beg = s.begin();
	//while (beg != s.end() && !std::isspace(*beg)) {
	//	*beg = std::toupper(*beg++); //未定义,右侧改变了beg 左侧又使用了beg
	//	//可能先求 = 号 右侧的值  也可能先求 左侧的值
	//}
	//解引用运算符的优先级低于点运算符 (*p).size()
	//条件运算符 ?: 满足右结合律 优先级非常低
	//在输出表达式中使用?:
	int grade = 70;
	cout << ((grade < 60) ? "fail" : "pass") << endl; //pass or fail
	cout << (grade < 60) ? "fail" : "pass";//输出1 或 0
	//cout << grade < 60 ? "fail" : "pass" ; //错误 试图比较cout 和 60
	//后两者后再加<<endl 直接也错误
	//位运算符作用于整数类型,并把运算对象看成是二进制位的集合,位运算提供检查和设置二进制位的功能
	//名为  bitset 的标准库类型也可以表示任意大小的二进制位的集合,因此也能用位运算符
	//符号位没有明确的规定 强烈建议用于无符号类型
	//~ 位求反 0=>1 1=>0
	//<< >> 左移 右移 IO那里进行了重载,这里首先令左侧运算对象的内容按照右侧要求移动指定位数,移动后的(可能进行提升)左侧运算对象的拷贝作为求值的结果,右侧对象一定不能为负,并且必严格小于结果的位数,否则会产生未定义行为,二进制移出边界之外的被舍弃
	//& 位与
	//^ 位异或
	//| 位或
	//0开关的整数代表 八进制 0x 代表十六进制
	cout << "char size: " << sizeof(char) << endl; //1字节
	cout << "int size: " << sizeof(int) << endl; //4字节
	unsigned char bits = 0233; //10011011
	//bits << 8;//bits提升成int 然后左移8位
	//00000000 00000000 10011011 00000000
	//bits << 31;//超出边界 丢弃
	//10000000 00000000 00000000 00000000
	//bits >> 3; //向右移动3 注意右移插入与符号位相关的值
	//00000000 00000000 00000000 00010011
	unsigned char bits1 = 0227; //10010111
	//~bits1;//char类型首先要提升成int类型
	//11111111 11111111 11111111 01101000
	1UL << 27; //生成一个只有27位是1 的unsigned long ,int只能确保有16位
	unsigned long students = 0;
	students |= 1UL << 27;
	students &= ~(1UL << 27);
	bool status = (students & (1UL << 27)) == 1;
	//移位运算<< >>又叫IO运算符 满足左结合律  优先级介于 算术和关系运算符之间
	//sizeof运算符 满足右结合律返回值 size_t类型 优先级=*
	sizeof(int); //也可不加()
	int x = 0, *px = nullptr;
	sizeof x; //返回表达式的类型的大小 
	sizeof *px; //返回int的类型大小 即使px是一个无效指针也没事(只用类型)
	cout << "x " << sizeof x << " *px " << sizeof *px << endl;
	//c++ 11新标准允许使用作用域运算符来获取类成员的大小
	//sizeof运算不会把数组转换成指针来处理 因此返回数组的大小
	int array_int[10] = {};
	constexpr size_t sz = sizeof array_int / sizeof *array_int;
	int arr2[sz] = {};
	//逗号运算符 按从左到右的顺序依次求值
	//先对左侧的表达式求值 然后将结果丢弃掉,逗号运算的真正结果是右侧表达式的值
	using std::vector;
	vector<int> ivec;
	vector<int>::size_type cnt = ivec.size();
	//...
	//类型转换
	int ival = 3.541 + 3;//提示精度损失  (隐式转换) 3=>double +3.541  6.541 => int =6
	//何时发生类型转换 p141
	//算术转换 把算术类型转换成另一种算术类型如果一个运算对象的类型是long double 那么不论另一个运算对象的类型是什么都会转换成long double
	//整数提升 把小整数转换成较大的整数类型 只要所有可能的值能放在int就提升否则unsigned int
	short a1 = 1, a3 = 2;
	char a2 = 5;
	cout << "a1+a2: " << sizeof(a1 + /*+ a2 +*/a3) << endl; //已经整数提升了
	//其他的隐式类型转换
	//数组转换成指针 [注意:当用在& sizeof typeid 时不会转换成指针]
	int ia[10];
	int *ip = ia;
	//指针的转换 0 nullptr转换成任意类型的指针 指向任意非常量的指针能转换成void* 常量的是 const void*
	//转换成布尔
	//转换成常量
	//类类型定义的转换 字符串字面值转换成string cin=>布尔值
	//显示转换
	//强制类型转换(非常危险)
	//一个命名的强制类型转换有如下形式
	//cast-name<type>(expression);
	//type是目标类型 expression是需要转换的值 结果是左值
	//cast-name有 static_cast dynamic_cast(运行时类型识别)  const_cast 和 reinterpret_cast
	//static_cast任何具有明确定义的类型转换,只要不包含底层const 都可以使用
	int i1 = 1, j1 = 2;
	double slop = static_cast<double>(i1) / j1; //使表达式执行浮点数除法
	//利用 static_cast 可以找回存在于void*的指针
	//const_cast只能改变运算对象的底层const
	const char *pcc = "123";
	char *p = const_cast<char*>(pcc); //正确 但是通过p写值是未定义行为 
	//称为去掉const性质 如果对象本身不是一个常量对这样操作后的对象是可以进行写的,否则会未定义
	//只有const_cast能改变表达式的常量属性,但const_cast不能改变表达式的类型
	//reinterpret_cast通常为运算对象的位模式提供较低层次上的重新解释(非常危险)
	int *iip = 0;
	char *pc = reinterpret_cast<char*>(iip);
	//但需要牢记pc所指的真实对象是一个int而非char
	//string str(pc); //运行时可能错误
	//旧式强制类型转换
	//type(expr)
	//(type)expr
	//旧式分别具有与const_cast static_cast reinterpret_cast相似的行为
	//如果能替换成const_cast static_cast,则行为和对应的命名转换一致 否则与reinterpret_cast类似
	//p147运算符优先级表

}
//语句
void test_statement() {
	using std::cin;
	using std::cout;
	using std::endl;
	//c++语句都以分号结束 末尾别上;
	//空语句
	;
	//例如
	//int my_input;
	//while (cin >> my_input)
	//	; //空语句
	//复合语句 => 块 在block内引入的名字只能在块中访问(定义到块尾)
	//函数体内是可以随便定义一个块{} 外部需要提供名等 块不以分号结束
	//空块==空语句
	{}
	//语句作用域
	//if switch
	//悬垂else c++中规定else与离它最近的尚未匹配的if匹配
	int x = 0;
	//while (cin >> x) {
	switch (x)
	{
	case 100:
		cout << "ok" << endl;
		//std::string name; //错误 控制流绕过一个隐式初始化值
		//int cc = 1; //错误 控制流绕过一个显示初始化值
		{
			std::string name = "ddddd"; //定义在一个块中
		}
		int c; //正确 因为c没有被初始化
		break; //注意一但匹配 以下语句都执行 因此使用break;中断

	default:
		c = 10; //正确
		//cc = 1;//错误 控制流绕过一个显示初始化值
		//name = "d"; //错误 控制流绕过一个隐式初始化值
		cout << "no" << endl;
		break;
	}

	//}
	//break作用中断当前控制流上个例子中将控制权转移到了switch语句外面 
	//case关键字和它对应的值必须是整型常量表达式 两个case不能一样
	//case语句可以写在一行 case 'a':case 'e':
	//如果在case中有定义 : c++规定 不允许跨过变量的初始化语句直接跳转到该变量作用域的另一个位置
	//因此如果需要为某个case分支定义并初始化一个变量 应当定义在块内 从而确保后面的所有case标签都在变量的作用域之外
	//迭代语句
	//跳转语句
	//break 语句 负责终止离它最近的while do_while for switch语句
	//continue 语句 终止最近的循环中的当前迭代并立即开始下一次的迭代 只能出现在 for while do_while
	//goto 语句是无条件跳转到同一函数内的另一条语句
	//不要使用goto
	//语法: goto label; label是用于标识一条语句的标示符
	//end : return; //带标签语句,可以作为goto的目标
	//标签标示符独立于变量或其他标示符名字, 和switch类似 goto语句不能将程序的控制权从变量的作用域之外转移到作用域之内
	goto end;
	int ix = 10; //错误 goto绕过了一个带初始化的变量的定义 //实际没有报错
end:
	ix = 42;
	cout << ix << endl;
	//如果向前跳转(变量定义之前)意味着系统将销毁该变量 然后重新创建它
}
int test_exception() {
	//try语句块和异常处理
	//c++中异常处理包括
	//throw 表达式 引发异常
	//try 语句块 处理异常,以一个try关键字开始,并以一个或多个catch子句结束
	//一套异常类 用于在throw表达式和相关的catch子句之间传递异常信息
	//抛出一个异常将终止当前的函数,并把控制权转移给能处理该异常的代码
	//runtime_error定义在stdexcept头文件中
	using std::cin;
	using std::cout;
	using std::endl;
	const unsigned password = 123456;
	unsigned int input;
	while (cin >> input) {
		if (password != input) {
			throw std::runtime_error("An error password!");

		}
		cout << "Welcome~";
		return 0;
	}
	return -1;
	//try语句块中 当选定了一个catch子句处理异常之后,执行与之对应的块,
	//catch一旦完成,程序跳转到try语句最后一个catch子句之后的那条语句继续执行
	//try内声明的变量在块外部无法访问,特别是在catch子句内也无法访问

	//try中也可能调用了try
	//寻找处理代码的过程与函数调用链相反,
	//当异常被抛出时,首先搜索抛出该异常的函数.如果没有找到匹配的catch子句,终止该函数,并在
	//调用该函数的函数中继续寻找.如果还没有,依此类推直到找到为止.
	//最终没能找到任何匹配的catch子句,程序转到名为terminate的标准库函数,该函数的行为与系统有关
	//一般情况下导致程序非正常退出,没有try语句的也用这种方式处理
	//异常类
	//exception 头文件 最通用的,只报告异常的发生
	//stdexcept 头文件 定义了几种常用的异常类
	//new 头文件 定义了bad_alloc异常类
	//type_info 头文件 定义了bad_cast异常类

	//我们只能以默认初始的方式初始化exception,bad_alloc,bad_cast对象,不允许提供初始值
	//其他异常类型的行为则恰好相反,应该使用string对象或者c风格字符串初始化这些类型的对象
	//但是不允许使用默认初始化的方式(必须显示初始化)没有默认的构造函数
	//what返回的值取决于自身是否存储一个字符串 否则内容由编译器决定

}
//函数 : 是一个命名了的代码块
//典型的函数定义包括以下部分: 返回类型,函数名字,0+个形参以及函数体
//调用函数完成两项工作:1..实参初始化函数对应的形参 2..控制权转移给被调用函数 (主函数的执行被暂时中断)
//注意参数调用没有规定实参的初始化顺序
//提供的实参必须能转换成对应形参的类型(隐式 显式)
//隐式的空形参:() 显式的空形参(void)[兼容c]
//(int v1,v2) 错误  (int v1,int v2)正确
//形参不能重名 并且函数最外层作用域中的局部变量也不能使用与函数形参一样的名字
//函数的返回类型不能是数组类型或函数类型 但可以是指向数组或函数的指针

std::string::size_type find_char(const std::string &s)
{
	return 0;
}
int a;//可以重名 因为不属于函数的作用域 
void test_func(int a) {
	//int a;//不能重名 //因此形参的定义实际相当于在块的刚开始
	{
		int a = 0; //可以重名 不是最外层的作用域
	}
	//c++中名字有作用域 对象有生命周期
	//函数是一个语句块 块构成一个新的作用域,形参和函数体内部定义的变量统称为局部变量
	//仅在函数的作用域内可见,局部变量还会隐藏在外层作用域中同名的其他所有声明中
	//在所有函数体之外定义的所有变量在启动时被创建 直到程序结束都会销毁,局部变量的生命周期依赖于定义的方式

	//自动对象
	//对于普通局部变量对应的对象来说,当函数的控制路径经过变量定义语句时创建该对象
	//当到达定义所在的块末尾时销毁它:只存在于块执行期间的对象称为自动对象,结束后对象的值变成未定义
	//形参是一种自动对象,函数开始时申请存储空间,因为定义在函数体作用域之内,一旦结束形参销毁
	//对于局部变量对应的自动对象来说,则分为两种情况:变量定义本身含有初始值,应用这个初始值进行初始化,否则执行默认初始化
	//这意味着内置类型的未初始化局部变量将产生未定义值

	//静态局部变量
	//生命周期贯穿函数调用及之后的时间,定义为static类型
	//这样的静态变量在程序的执行路径第一次经过对象定义语句时初始化,并且直到程序终止才被销毁
	//在此期间即使对象所在的函数结束执行也不会对它有影响(声明=>只公布名字 定义=>申请空间 初始化=>赋值)
	//如果静态局部变量没有显式的初始值,它将 执行值初始化,内置类型的局部静态变量初始化为0

	//函数的名字必须声明在使用之前,类似于变量 函数只能定义一次,但可以多次声明
	//函数的声明和定义的区别 声明无函数体,用一个分号代替即可
	//因为声明不包括函数体,形参可以只写类型不写变量名
	//函数的声明也叫函数原型(返回类型 函数名 形参类型)
	//函数声明写在头文件 定义写在包含了这个头文件的源文件中 (推荐)
	//分离式编译允许把程序分割到时几个文件中去,每个文件独立编译
	//更改了一个源文件只需重新编译更改过的即可
	//分离编译:各个cpp分开编译生成各自的obj目标文件(.o .obj) [include将文件的代码直接拷到了.cpp中]
	//编译之后是连接 Link 将未定义的符号尝试找到外部定义并将调用地址替换为函数实际地址

	//形参的初始化和变量的初始化一样
	//形参可以是引用 否则是拷贝传值(两者是相互独立的对象)
	//指针形参,也是拷贝传值,两个指向相同对象的独立的指针
	//尽量使用引用避免拷贝: 大的类型对象低效 有些类型不支持拷贝操作
	//当函数无须改变引用形参的值 最好使用const
	//通过引用参数可以通过一个函数调用返回多个值,直接更改引用参数的值(隐式返回)

	//const 形参(顶层)比如 func(const int *p); 是可以在函数体内进行*p=0;的操作,但是不能 p=x;
	//和其他初始化一样,当用实参初始化形参时会忽略顶层const
	//例子: void func(int x);
	//     void fun(const int x); //错误重复定义 顶层const被忽略,
	const int b = 0;  //常量int
	const int * aa = {}; //指向const int的非常量指针
	const int * const c = b; //指向const int 的 const 指针

	//a = &b;
	//函数重载不能出现只是返回值不同的情况
	//尽量使用const 引用 形参这样也能接收更多的参数,因为不能将const赋值给非const的形参
	std::string x = "ddd";
	const std::string cc = "ccc";
	find_char(x);
	find_char(cc); //只有 const string& 才合法
	find_char("ddd"); //只有 const string& 才合法
	//实参赋值完全可以看成一个普通的初始化语句 string &s = x;const string &s = "ddd"


	//数组形参
	//不能拷贝数组 + 使用数组时(通常)会将其转换成指针
	//不能以值传递的方式使用数组参数 + 当传递一个数组时,实际上传递的是指向数组首元素的指针
	//尽管不能值传递数组,形参仍能写成数组的形式
	//以下等价
	//void x(const int*);
	//void x(const int[]);
	//void x(const int[10]); //这里只是期望的10个元素 ,实际不一定是10个
	//以上任意一个调用实际检查参数的类型是否是 const int*

	//因为传递的是指针,不能得知数组的长度
	//常用的三种常用的技术
	//1.使用标记指定数组长度:例子c风格的字符串 结尾有结束标记 \0 while(*p)//*不是空字符
	//2.使用标准库规范:传递指向数组的首元素和尾后元素 while(beg!=end){} 实参可用begin() end()获得
	//3.显示传递一个表示数组大小的形参

	//形参也可是数组的引用
	//void func(int (&array)[10] x){}
	//int &arr [10] //错误 将arr声明成了引用的数组 而且根本不存在一个引用的数组
	//使用数组的引用限制了函数的可用性 只能作用于大小为10的int数组
	//传递多维数组

	//main处理命令行选项
	//给main传递参数int main (int argc, char *argv[])
	//第二个参数是一个数组,它的元素是指向C风格字符串的指针,第一个形参表示数组中字符串的数量
	//当实参传给main之后 argv的第一个元素指向程序的名字或者一个空字符串.最后一个元素值保证为0
	//因此使用以上参数时一定记得可选的实参从argv[1]开始,argv[0]保存程序的名字,而非用户的输入

	//c++11
	//含有可变形参的函数 
	//initializer_list形参: initializer_list是一种标准库类型,定义在同名的头文件中
	//initializer_list<T> lst; 默认初始化 T类型的元素空列表
	//initializer_list<T> lst{a,b,c,d}; lst的元素数量和初始值一样多[lst中元素是对应初始值的副本,列表中的元素是const]
	//lst2(lst) lst2 = lst 拷贝或赋值一个initializer_list对象不会拷贝列表中的元素;拷贝后原始列表和副本共享元素
	//lst.size() 元素数量
	//lst.begin() 首元素的指针
	//lst.end() 尾后元素指针
	//和vector类似也是模板类型,两者区别initializer_list中的元素永远是常量
	//void error_msg(int time, std::initializer_list<std::string> il) {
	//	for (auto beg = il.begin(); beg != il.end(); ++beg) {
	//		std::cout<<*beg<<std::endl;
	//	}
	//}
	//使用时使用须把序列放入花括号中
	// std::string x ="";
	// error_msg(5,{"string1", "string2", x});
	//省略符形参是为了便于C++程序访问某些特殊的c代码而设置的,
	//这些代码使用了名为varargs的c标准库功能
	//省略符形参应该仅仅用于c和c++通用的类型,大多数类类型对象在传递给省略符形参时都无法正确拷贝
	//只能出现在形参列表的最后一个位置
	//void foo(parm_list,...);
	//void foo(...);
	//其实也有点复杂 麻烦,仍需要得知具体类型做好正确的类型识别

	//返回类型和return语句
	//有返回值的函数返回值须同返回类型一致或能隐式转换的
	//返回一个值的方式和初始化一个变量或形参的方式完全一样:返回的值用于初始化调用点的一个临时量
	//如果返回一个引用则不进行拷贝
	//不要返回局部对象的引用或指针
	//const string& example(){
	//std::string ret = "";
	//if (ret.empty()) {
	//	return ret; //错误 : ret是局部对象 不能返回局部对象的引用
	//}
	//else {
	//	return "XXXX"; //错误 : "XXXX"是一个局部临时量 不能返回(字体串字面值转换成一个局部临时string变量(隐式转换成返回类型))
	//}}

	//调用运算符也有优先级和结合律 优先级和点运算符,箭头运算符一样 符合左结合律
	//因此 auto sz = shorterString(s1, s2).size();
	//引用返回左值 

	//c++ 11 列表初始化返回值
	//函数可以返回花括号包围的值的列表,类似于其他返回结果,此处的列表也用来对表示函数返回的临时量进行初始化
	//std::vector<int> process() {
	//	int x = 1;
	//	if (x < 0) {
	//		return{}; //临时量执行值初始化 //返回一个空vector对象
	//	}
	//	else if (x == 0) {
	//		return{ 1,2 }; //返回列表初始化的vector对象
	//	}
	//	else {
	//		return{ 0, 1 };
	//	}
	//}
	//当然不仅限于vector; int x = {0};也可以用花括号的形式返回

	//main函数的返回值(隐式插入了一条return 0;)
	//main函数的返回值可以看作是状态指示
	//也可用cstdlib头文件中定义的两个预处理变量表示成功或失败
	//return EXIT_FAILURE; return EXIT_SUCCESS;
	//预处理变量不能加 std:: 也不能用using声明

	//递归
	//如果一个函数调用了它自身,不管直接间接都叫做递归函数
	//递归函数中一定有某条路径是不包含递归调用的 否则直到程序栈空间耗尽

	//返回数组指针(使用类型别名可以简化操作)


}
//尾置返回类型
typedef int int_T[10];
//等价
//int_T* test_return_array(int (&x)[10]) 
//尾置返回类型 c++11
//int (* test_return_array(int (&x)[10]))[10] 
auto test_return_array(int(&x)[10]) -> int(*)[10] //不知什么原因会提示无法找到函数定义(编译没问题),忽略之
{
	//int x[10] = {};
	//int(*y)[10] = &x;
	for (auto i = std::begin(x); i != std::end(x); ++i) {
		*i += 1;
	}
	return &x;
};
//也可使用decltype

//函数重载
//如果同一个作用域(不同作用域会隐藏外面的名字)内的几个函数名字相同但形参列表不同=>重载函数
//编译器会根据传递的实参类型推断想要的是哪个函数
//main函数不能重载
//假如有两个函数只有返回类型不同,则后定义的是错误的
//一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来
void adsfadsf(int) {};
//void adsfadsf(const int) {}; //错误 重复

void adsfadsf(int *) {};
//void adsfadsf(int * const) {}; //错误 重复

//当有两个如下一个const 一个非const的重载,当传递一个非常量参数会优先选择非常量的函数版本

void sdsdsdsds(int &) {};
void sdsdsdsds(const int &) {};
//void sdsdsdsds(int const &) {}; //和上面的语句一样
//[注意:引用不是一个对象,所以引用本身不存在const不const][int & const 这个写法也是错误的]

void sdsdsdsds(int*) {};
void sdsdsdsds(const int*) {};

//const_cast在重载函数的情景中最有用
const int & test_const_over(const int &x) {
	return x;
}
//重载一个非const版本
int & test_const_over(int &x) {
	auto &r = test_const_over(const_cast<const int&>(x));
	//注意不能返回一个局部变量(返回了一个别名,实际还是那块内存,相当于原变量,因此auto类型为int不是int&)
	return const_cast<int &>(r);
}
//调用重载函数
//函数匹配也叫重载确定,首先比较每个形参
//当调用重载函数有三种可能的结果:最佳匹配 无匹配 二义性调用 

//不好的习惯: 通常来说在局部作用域中声明函数不是一个好的选择
//[除此之外,外部定义一个read()函数,内作用域定义一个int read则会隐藏外部的]
//在局部新声明的与作用域外的同名函数会被隐藏(包括所有的重载,只有作用域内的可以被调用)

//在c++中名字查找发生在类型检查之前

//特殊用途语言特性
//默认实参,只能在形参表的最右,并且第一个默认起后面全部都是默认参数
void test_default_param(int y, std::string x = "aaaa~") {
	using std::cout;
	cout << x;
}
//默认实参声明,在给定的作用域中一个形参只能被赋予一次默认实参
//也就是说函数的后续声明只能为之前那些没有默认值的形参添加实参
//例如
void test_default_param_1(int x, int y, int c, int d = 1);
void test_default_param_1(int x, int y, int c = 2, int d);//不能写 int d=1 或者 d =0
//int c= 2是一个补充 也可不补充
//局部变量不能作为默认实参,只要表达式的类型换成形参所需的类型,表达式就能作为默认实参
int return_int(int x = 1) {
	return x;
}
int asdfs = 10;
//注意默认实参的求值是发生在函数调用时的,因此默认实参会随着变量和函数返回值的更改而更改
void test_default_param_1(int x = asdfs, int y = return_int(), int c, int d) {};//不能写 int d=1 或者 d =0


//内联函数和constexpr函数
//内联函数可以避免函数调用的开销
//关键字inline 不一定百分百是inline(只是请求,决定的仍是编译器)
//一般用于优化规模小 流程直接,调用频繁的函数

//constexpr是指能用于常量表达式的函数=>规定返回类型及所有形参的类型都是字面值类型
//而且函数体内只有一条return语句
constexpr int new_sa() { return 45; }
constexpr int dssdfdsfds = new_sa();//正确 foo是一个常量表达式
//允许constexpr函数的返回值并非一个常量
//constexpr为了能编译过程中随时展开,被隐式地指定为内联函数
//int arr[sacle(2)]; //正确 scale(2)是常量表达式
//int arr[sacle(i)]; //错误 不是constexpr
//注意:如果用在非常量上 sacle(i)返回非常量不出错,因此constexpr函数不一定返回常量表达式
//它只是额外具有能返回常量表达式的一面

//和其他函数不同,内联函数和constexpr函数可以在程序中多次定义,但多个定义必须完全一致
//因此内联函数和constexpr函数通常定义在头文件

//调试帮助
void test_debug() {
	//程序员会用到一种类似于头文件保护的技术,以便有选择地调试代码
	//程序发布要屏蔽高度代码,用到两项预处理功能:assert和NDEBUG
	//assert是一种预处理宏(相当于预处理变量)行为有点类似于内联函数,assert宏使用一个表达式作为它的条件
	//assert(expr); 首先对expr求值如果为假(0),输出信息并终止程序的执行,否则什么都不干
	//它定义在cassert头文件中,预处理名字由预处理器而非编译器管理
	//因此无需提供using or std::
	//和预处理变量一样宏名必须唯一,含有cassert头文件的程序不能再定义名为assert的变量,函数等
	//很多其他头文件也包含了它
	//assert宏学用于检查"不能发生"的条件 assert(word.size())>threshold);

	//assert的行为依赖于一个名为NDEBUG的预处理变量的状态,如果定义了NDEBUG,则assert什么也不做
	//默认状态下没有定义NDEBUG 定义后能避免检查各种条件所需的运行时开销

	//不能用assert代替逻辑 错误等检查
	//也可用这个预处理变量定义自己的调试代码
//#define NDEBUG
#ifndef NDEBUG
	//__func__是编译器定义的一个局部静态变量,用于存放函数的名字
	//__func__每个函数都有定义 const char的静态数组
	std::cerr << __func__ << ": error" << std::endl;
	//__FILE__ 存放文件名的字符串字面值
	//__LINE__ 存放当前行号的整形字面值
	//__TIME__ 存放文件编译时间的字符串字面值
	//__DATE__ 存放文件编译日期的字符串字面值
#endif

}
//函数匹配
//确定候选函数(集合中的函数)和可行函数
//候选函数有两个特性:与被调函数同名 声明在调用点可见
//可行函数也有两个特性: 形参数量与本次调用提供的实参数量相等 每个实参类型与对应的形参类型相同或是能转换成形参类型
//有默认值的可看成拥有多个形参数量
//最后寻找最佳匹配,逐一检查实参 寻找形参类型与实参类型最匹配的那个可行函数,类型越接近匹配越好
//f(int, int);
//f(double, double);
//f(3, 3.14);
//以上调用没有一个最佳匹配 两个一样的程度,都需要一次内置类型转换,因此会报错

//实参类型转换
//小整数一般会转换成int
//void ff(int);
//void ff(short);
//ff('a') //char提升到int 调用ff(int)

//所有的算术类型转换的级别都一样,int=>unsigned int转换并不比从int向double的转换级别高
//会引发二义性调用 

//参数匹配和const实参

//函数指针 指向函数而非对象
//函数的类型由它的返回类型和形参类型共同决定,与函数名无关
//bool lengthCompare(const string &, const string &);
//bool(*pf)(const string &, const string &); //函数指针
//*pf不能少括号
//pf = lengthCompare; 
//pf = &lengthCompare;  //等价的赋值语句: &可选
//调用时无需提前解引用指针
//b1 = pf("ddd","dddd");
//b2 = (*pf)("dddd","ddd"); //一个等价的调用
//b3 = lengthCompare("hello","godd"); //等价

//函数指针不存在类型转换(必须精确赋值(匹配)),可以赋0 nullptr
//重载函数的指针
//函数指针形参
//和数组类似,虽不能定义函数类型的形参,但可以是指向函数的指针
//虽然形参看起来是函数类型,实际上却是当成指针使用
//void use(bool pf(const string &,const string &); //会自动转换pf为指针
//void use(bool (*pf)(const string &,const string &); //等价 显示转换
//实参同上面的赋值一样可选&
//常用typedef 简化
//func func2是函数类型
//typedef bool func(const string &,const string &);
//typedef decltype(lengthCompare) func2; //等价的类型
//funcp funcp2是函数指针类型
//typedef bool (*funcp)(const string &,const string &);
//typedef decltype(lengthCompare) *funcp2; //等价的类型
//以上四种都可以是函数的形参
//[注意 decltype返回函数的类型 而不会自动转换成函数指针]

//返回指向函数的指针
//和数组类似,不能返回一个函数,但是能返回指向函数类型的指针.[但是一定要把返回类型写成指针形式]
//[编译器不会自动将函数返回类型当成对应的指针类型处理]
//using F = int(int*, int); //F是函数类型 不是指针
//using PF = int(*)(int*, int); //PF是指针类型
//PF fl(int); //正确: PF是指向函数的指针
//F fl(int); //错误: 不能返回一个函数
//F* fl(int); //正确
//也可直接声明
//int(*fl(int))(int*,int);
//auto fl(int) -> int (*)(int*, int); // c++11


//类
void test_class_1() {
	//eps1 7
	//eps2 8
	//eps3 9
	//eps4 10
	//eps5 6
	//eps6 8
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	using NBD = New_bangumi_data;
	//EPS eps1;
	//EPS eps2;
	EPS eps1{ {"eps1","eps2","eps3"} ,{7,8,9} };
	EPS eps2{ {"eps4","eps5","eps6"} ,{10,6,9} };
	cout << eps1 << endl;
	cout << eps2 << endl;
	//for (int i = 0; i < 3; ++i) {
	//	cin >> eps1;
	//}
	//cout << eps1 << endl;
	//for (int i = 0; i < 3; ++i) {
	//	cin >> eps2;
	//}
	//cout << eps2 << endl;

	//初始化列表{}仅仅可以对public成员有效(并且无须相应的构造函数定义)
	//NBD data1{ "Angel Beats",123456,9.1,eps1 };
	//NBD data2{ "Angel Beats",123456,9.1,eps1 };
	NBD data1("Angel Beats", 123456, 9.1, eps1);
	NBD data2("Angel Beats", 123456, 9.1, eps1);
	cout << data1.AvgScore() << endl;
	cout << data2.AvgScore() << endl;

	EPS eps3 = eps1 + eps2;
	cout << eps3 << endl;

	cout << eps1.Combine(eps2) << endl;
	cout << eps1.Score() << endl;
	//cout << eps1.avg_score << endl;

	data1.Combine(data2);
	cout << data1.Name() << "  " << data1.Id() << endl;
	cout << data1.RefEps() << endl;
	cout << data1.AvgScore() << endl;


	NBD data3 = add(data1, data2);
	print(cout, data3);
	NBD data4, data5;
	//因为返回类型是输入输出流 因此可以这样操作

	//使用IO类
	read(cin, data4) >> data5.RefEps();
	print(cout, data4) << data5.RefEps() << endl;

	//使用文件流
	string in_file_name("study.txt");
	string out_file_name("ostudy.txt");
	std::ifstream fin(in_file_name);
	std::ofstream fout(out_file_name);
	//在vs中当前路径是在代码所在的目录
	if (fin)
		read(fin, data4) >> data5.RefEps();
	//这里data1.eps是常量引用 因为 重载的函数中operator+ 没有用const修饰 因此不能隐式转换为非常量;
	if (fout)
		print(fout, data4) << data5.RefEps() << endl;

	//使用string流

	EPS new_eps;
	cout << new_eps.Score() << endl;//经测试,在类中定义的内置变量相当于在函数体内定义,默认初始化是未定义

	cout << "All_time: " << new_eps.Times() << endl;


	//测试隐式类类型转换
	string name = "Angel Beats";
	EPS test_eps;
	data1.Combine(test_eps);
	data1.Combine(string("Angel"));
	data1.Combine(name);
	data1.Combine(EPS());
	data1.Combine(EPS({}, {}));

	data1 = EPS(); //正确
	data1 = name;

	//(name).Eps(); //错误 只能作为右值
	//(EPS()).Eps();
	//read(cin, EPS()); //错误返回的不是左值
}
void test_TestDebug() {
	TestDebug a(404, true);
	TestDebug b(false);

}
void test_StaticClass() {
	const int &pe = TestStatic::Period();

	std::cout << TestStatic::id << "  "
		<< TestStatic::name << "  "
		<< TestStatic::Ready() << "  "
		<< TestStatic::Msg()
		<< TestStatic::Period() //输出30 类内定义的初始值30 类外定义初始值为40
		<< std::endl;

}
//c++标准库
//IO类
//c++不支持直接处理输入输出,而是通过一族定义在标准库中的类型来处理IO
//这些类型支持从设备读取,向设备写入数据的IO操作,设备可以是文件,控制台窗口等还有一些类型允许内存IO
//iostream定义了用于读写流的基本类型 宽字符 wistream wostream wiostream
//fstrem定义了读写命名文件的类型 wifstream wofstream wfstream
//sstream定义了读写内存string对象的类型 wistringstream(读取) wostringstream(写入) wstringstream
//宽字符版本的类型和函数的名字以一个w开始 wcin wcout
//两个版本定义在同一个头文件中 例如:头文件fstream定义了ifstream和wifstream类型
//类型ifstream和istringstream都继承自istream

//IO对象无拷贝或赋值,因此不能将形参或返回类型设置为流类型,通常以引用的方式传递和返回.读写一个对象会改变其状态,因此传递和返回的引用不能是const
//IO条件状态 strm::iostate[是一种机器无关的类型,提供了表达条件状态的完整功能] 其中strm是一种IO类型 例如 istream::iostate ifstream::iostate
//strm::badbit 用来指出流已崩溃 strm::failbit 指出IO操作失败 strm::eofbit 指出流到达了文件结束
//strm::goodbit 指出流未处于错误状态,此值保证为0
//s.eof() 若流s的eofbit置位,则返回true  s.fail() fail或者badbit置位返回true
//s.bad() 若流s的badbit置位,则返回true  s.good() s处于有效状态true
//s.clear() 将流中所有条件状态复位,状态设置为有效 返回void
//s.clear(flags)根据给定的flags标志位,将s中对应条件状态复位 flags类型为strm::iostate 返回void
//s.setstate(flags)将对应条件状态置位
//s.rdstate() 返回当前条件状态,类型为strm::iostate
//使用IO时 一定注意状态的复位等情况 确定一个流对象的简单方法是将它当作一个条件使用

//查询流状态
//strm::iostate作为一个位集来使用IO库定义了4个iostate类型的constexpr值表示特定的位模式
//badbit表示系统级错误,如不可恢复的读写错误,一旦badbit被置位,流就无法再使用了
//在发生可恢复错误后,failbit被置位,如期望读取类型不符,这种问题通常是可以修复的
//如果到达文件结束位置,eofbit和failbit都会被置位,goodbit的值为0表示未发生错误
//如果badbit,failbit,eofbit任一个被置位,则检测流状态的条件会失败
//使用good() fail()是确定流总体状态的正确方法,实际上将流作为条件使用的代码等价于 !fail()
//good()所有错误位均未置位返回true

//经尝试 badbit被置位,clear是可以还原的
//只复位failbit和badbit
//cin.clear(cin.rdstate()&~cin.failbit&~cin.badbit);

//每个输出流都管理一个缓冲区,用来保存程序读写的数据
//有了缓冲的机制,操作系统就可以将程序的多个输出操作组合成单一的系统级写操作,可以提升性能,写操作开销大
//导致缓冲区刷新(数据真正写到输出设备或文件)
//1.程序正常结束 main的 return
//2.缓冲区满了
//3.使用操纵符endl显式刷新
//4.在每个输出操作之后,可以用操纵符unitbuf设置流的内部状态,来清空缓冲区,默认情况下对cerr是设置unitbuf的,因此cerr的内容立即刷新
//5.一个输出流可能被关联到另一个流,在这种情况下,当读写被关联的流时,关联到流的缓冲区会被刷新,例如cin cerr关联到cout,因此读cin或写cerr会导致cout的缓冲区被刷新
//除了endl IO库中还有类似的操纵符 flush和ends flush刷新缓冲区,但不输出任何额外的字符,ends向缓冲区插入一个空字符,然后刷新缓冲区

void test_IO_buf() {
	using std::cout;
	using std::ends;
	using std::endl;
	using std::flush;

	cout << "xxx" << endl;
	cout << "xxx" << ends;
	cout << "xxx" << flush;

	cout << std::unitbuf; //之后输出操作后会立即刷新buf
	//注意 这是一个三次流输出,而非一次
	cout << "ddddssdsds" << "dddsdsd" << "vdvvfdvdvdv";
	cout << std::nounitbuf; //回到正常的缓冲方式

	//tie 验证失败,依旧会关联
	cout << "\n\nTest: tie()" << endl;
	std::cin.tie(nullptr);
	cout << "next: you input a num\n";
	int x;
	std::cin >> x;
	cout << "you have inputed\n";
	std::cin >> x;
	cout << "you have inputed again\n";
	cout << "cin.tie():" << (std::cin.tie() ? "yes" : "no") << endl;
	std::cin.tie(&std::cout);
}
//unitbuf操纵符如果想在每次输出操作后都刷新缓冲区,可以使用unitbuf操纵符,它告诉流在接下来的每次写操作之后都进行一次flush操作
//而nounitbuf操纵符则重置流,使其恢复使用正常的繁育管理的缓冲区刷新机制
//当程序异常终止,输出缓冲区是不会被刷新的,可能仪在输出缓冲区中等待打印

//关联输入和输出流标准库将cin cout关联在一起
//例如 cin>>x; 会导致cout的缓冲区被刷新
//交互式繁育通常应该关联输入流和输出流
//tie有两个重载版本:一个不带参数,返回指向流的指针.如果本对象当前关联到一个输出流,则返回的就是指向这个流的指针
//如果对象未关联到流,则返回空指针
//版本2接受一个指向ostream的指针,将自己关联到此ostream,即 x.tie(&o)将流x关联到输出流o
//每个流最多关联到一个流,但多个流可以同时关联到同一个ostream

//文件的输入输出
//头文件fstream定义了三个类型来支持文件IO:
//ifstream从一个给定的文件读取数据,ofstream向一个给定文件写入数据
//fstream读写给定文件
//这些类型提供的操作与之前使用过的对象cin cout的操作一样 >> << getline
//除了继承的行为,还增加了新的成员来管理与流关联的文件
//fstream fstrm; 创建一个未绑定的文件流, fstream是头文件中定义的一个类型
//fstream fstrm(s); s是string or 字符串字面值,这些构造函数都是explicit的,默认的模式依赖于fstream的类型
//fstream fstrm(s,mode); 指定mode打开文件
//fstrm.open(s); 打开名为s的文件,并将文件与fstrm绑定,s可以是一个string或一个指向c风格字符串的指针,默认的mode依赖于fstrm的类型
//fstrm.close(); 关闭与fstm绑定的文件,返回void
//fstrm.is_open(); 返回一个bool 指出与fstrm关联的文件是否成功打开并且尚未关闭

//当定义一个文件流对象时,如果指定有参数,会自动调用open(s)绑定一个文件名
//否则未与任何文件绑定

//用fstream代替iostream& 因为fstream是继承自iostream的因此可以用fstream的实参代替iostream&的形参
//这里运用到了多态的知识
//如果定义了一个空的文件流对象,随后可以用open来将它与文件关联
//如果调用open失败,failbit会被置位,因此需要检查open
//一旦一个文件流已经打开,它就保持与对应文件的关联
//对一个已经打开的文件流调用open会失败,并会导致failbit被置位
//随后试图使用文件流的操作都会失败
//为了将文件流关联到另外一个文件,必须首先关闭已经关联的文件,一旦文件成功关闭,才能打开新的文件
//如果open成功,则会设置流的状态,使得good()返回true;

//当一个fstream对象被销毁时,close函数会自动被调用
//注意一个循环体内创建的变量每次本次循环结束后便会被销毁
//因此可以在一个循环体内ifstream input (file_name); 而不使用close
//这样每次循环都会新创建一个ifstream

//文件模式 file mode用来指出如何使用文件
//in 以读的方式打开
//out 以写的方式打开
//app 每次写操作前均定位到文件末尾
//ate 打开文件后立即定位到文件末尾
//trunc 截断文件
//binary 以二进制的方式进行IO
//无论用哪种方式打开文件,我们都可以指定文件模式,调用open打开文件时可以
//用一个文件名初始化流来隐式打开文件时也可以,指定文件模式有如下限制
//只可对ofstream fstream 对象设定out 模式
//只可对ifstream fstream 对象设定in 模式
//只有当out也被设定时才可设定trunc模式
//只要trunc没被设定,就可以设定app模式,在app模式下即便没有显式指定out,文件也总是以输出方式打开
//默认情况下,即使没有指定trunc,以out模式打开的文件也会被截断,因此要不使用app模式,要不同时指定in模式
//ate和binary模式可用于任何类型的文件流对象 且可以与其他任何文件模式组合使用

//每个文件流类型都定义了一个默认的文件模式,未指定文件模式时,就会使用此默认模式
//ifstream => in   ofstream => out  fstream => in + out

//以out模式打开文件会丢弃已有数据
//阻止的方法是同时使用app模式 或同时使用in模式
//ofstream app("file", ofstream::out|ofstream::app);
//每次调用open都会确定文件模式

//string流
//sstream头文件定义了三个类型来支持内存IO,这些类型可以向string写入数据,从sstring读取数据
//就像string是一个IO流一样
//istringstream从string读取数据
//ostringstream向string写入数据
//stringstream 可读可写
//额外的函数
//sstream strm;  未绑定的stringstream对象 sstream是头文件中的定义的一个类型
//sstream strm(s);  strm是一个sstream对象,保存string s的一个拷贝,此构造函数是explicit的
//strm.str(); 返回strm所保存的string的拷贝
//strm.str(s); 将string s拷贝到strm中,返回void

//使用istringstream 一些工作是对整行文本进行处理,而其他一些工作是处理行内的单个单词时,通常使用istringstream
//
using EBD = struct Easy_Bangumi_Data {
	unsigned id;
	std::vector<std::string> msg;
};
void test_sstream() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	//只有\r不行 window中\r\n (\r是回车回到行首 \n是换一行)
	string input = "123 Angelbeats\r\n"
		"1111 Yoooo! Data:11-05\r\n"
		"5555 C Score:9\r\n"
		"1\r\n"
		"13021 D! Score:10";
	std::istringstream cinput(input);
	EBD temp_subject;
	string line, line_msg;
	std::vector<EBD> Bangumi;
	//也可在此定义,但是注意这个一个继承自iostream的string流
	//因此读取完一行后状态会改变(因为是公共的,所以一次循环后注意清状态)
	std::istringstream subject_ori;
	while (getline(cinput, line)) {
		//可以在此定义
		//std::istringstream subject_ori;
		subject_ori.str(line);
#ifndef NDEBUG
		cout << "###### "
			<< subject_ori.str()
			<< endl;
#endif
		subject_ori >> temp_subject.id;
		while (subject_ori >> line_msg) {
			temp_subject.msg.push_back(line_msg);
		}
		//push
		Bangumi.push_back(temp_subject);
		//清理vector
		temp_subject.msg.clear();
		//清理状态
		subject_ori.clear(subject_ori.goodbit);
	}

	//print
	for (auto s : Bangumi) {
		cout << s.id << endl;
		for (auto m : s.msg) {
			cout << m << " | ";
		}
		cout << endl;
	}

	//使用ostringstream 逐步构造最后一起打印
	//少于两项说明的不打印,输出特定字符,ID 和 说明分开打印
	cout << "\n========" << endl;
	std::string output_msg;
	std::ostringstream print(output_msg);
	for (auto s : Bangumi) {
		cout << "="
			<< s.id
			<< "="
			<< endl;
		if (s.msg.size() > 1) {
			print << "[" << s.id << "]\n";
			for (auto m : s.msg) {
				print << m << endl;
			}
		}
		else
			print << "[" << s.id << "]" << " 信息不足" << endl;
	}
	cout << "========\nInfo:\n=======\n";
	//最后输出信息

	cout << print.str() << endl;
}
//每个IO对象都维护一组条件状态,用来指出此对象上是否可以进行IO操作
//如果在输入流上遇到了文件末尾,则对象的状态变为失效
//getline也会改变流的状态,即一次就会让其变为失效

//顺序容器
//所有的容器类都共享公共的接口
//一个容器就是一些特定对象的集合
//所有的顺序容器都提供了快速访问元素的能力,但是在一些方面有不同的性能折中(添加删除容器的代价)(非顺序访问窗口中元素的代价)
//vector 可变大小的数组,支持快速随机访问,在尾部之外的位置插入或删除元素可能很慢
//deque 双端队列,支持快速随机访问,在头尾插入/删除速度很快
//list 双向链表,只支持双向顺序访问,在list中任意位置进行插入/删除操作速度很快
//forward_list 单向链表,只支持单向顺序访问,任意位置进行插入/删除操作速度很快
//array 固定大小数组,支持快速随机访问,不能添加或删除元素
//string 与vector相似的容器,但专门用于保存字符,随机访问快,在尾部插入/删除速度快

//string和vector将元素保存在连续的内存空间中,在中间添加或删除后,需要移动插入,删除位置之后的所有元素
//然而添加一个元素有时可能还需要分配额外的存储空间,这种情况下,每个元素都必须移动到新的存储空间中

//list forward_list为了访问一个元素,只能遍历整个容器,而且与vector deque array相比,这两个容器额外内在开销很大
//deque是一个复杂的数据结构,其在双端添加删除元素很快,与list或forward_list添加删除元素的速度相当

//forward_list和array是c++标准新增加的类型,与内置数组相比,array是一种更安全,更容易使用的数组类型
//forward_list的设计目的是达到与最好的手写的单向链表数据结构相当的性能
//因此forward_list没有size操作,因为保存计算大小会比手写链表多出额外的开销,对其他容器而言,size保证是一个快速的常量时间的操作

//通常使用vector是最好的选择
//vector如果需要在容器中间插入元素 可以先插后面再排序达到目的:标准库的sort函数
//也可考虑在输入阶段使用list,一旦输入完成,将list中的内容拷贝到一个vector中

//如果不确定应该使用哪种容器,可以在程序中只使用vector和list的公共的操作:使用迭代器,不使用下标
//这样更改方便

//接下来的操作对所有的容器(顺序,无序,关联,个别容器)都适用

//每个容器都定义在一个头文件中,文件名与类型名相同,deque定义在头文件deque中
//list定义在 list中, 容器均定义为模板类
//例如对vector,需要提供额外信息来生成特定的容器类型,对大多数,但不是所有容器,还需要提供元素类型的信息
//list<Bangumi_data> //保存类对象的list
//deque<double> //保存double的deque
//顺序容器几乎可以保存任意类型的元素,比如容器的容器
//vector<vector<int>> lines ;//注意较旧的编译器需要 <vector<int> > 加空格
//假定noDefault是一个没有默认构造函数的类型
//vector<noDefault> v1(10, init); //正确 提供了元素初始化器
//vector<noDefault> v1(10); //错误 必须提供一个元素初始化器
//容器的操作
//类型别名
//iterator const_iterator (迭代器类型)
//size_type(无符号整数类型) difference_type (有符号整数类型)
//value_type (元素的类型) reference (元素的左值类型与value_type&同义) 
//const_reference (const左值类型 const value_type&)

//构造函数 
//C c; 默认构造 空容器
//C c1(c2); 构造c2的拷贝c1
//C c(b,e); 构造c 将迭代器b和e指定的范围内的元素拷贝到c (array不支持)
//C c{a,b,c,...}; 列表初始化

//赋值与swap
//c1 = c2;  将c1中的元素替换为c2中的元素
//c1 = {a,b,c,...}; 将c1中的元素替换为列表中元素(不适用于array)
//a.swap(b); 交换a和b的元素
//swap(a,b); 与上面等价

//大小
//c.size(); 返回c中元素的数目(不支持forward_list)
//c.max_size(); c可保存的最大元素数目
//c.empty(); 若c中存储了元素,返回false,否则返回true;

//添加/删除元素(不适用于array)
//注:在不同的容器中这些操作的接口都不同
//c.insert(args); 将args中的元素拷贝进c
//c.emplace(inits); 使用inits构造c中的一个元素
//c.erase(args); 删除args指定的元素
//c.clear(); 删除c中的所有元素,返回void

//关系运算符
//所有容器支持== !=
//关系运算符(无序容器不支持) <,<=,>,>=

//获取迭代器
//c.begin(), c.end()
//c.cbegin(), c.cend() //返回const_iterator

//反向容器的额外成员(不支持forward_list)
//reverse_iterator  //按逆序寻址元素的迭代器
//const_reverse_iterator
//c.rbegin(), c.rend();	 //返回指向c的尾元素和首元素之前位置的迭代器
//c.crbegin(), c.crend();  //返回const_reverse_iterator

//注意,forward_list迭代器不支持递减去处符--
//迭代器范围是由一对迭代器表示的,两个迭代器分别指向同一个容器的元素或者尾后元素
//即begin 和 End 这种元素的范围是左闭合区间[begin,end)
//我们可以通过反复递增begin来到达end,即end不在begin之前
//使用左闭合区间的好处是可以通过 begin==end来判断是否还有元素
//容器类型成员
//对于一个反向的迭代器,使用++操作会得到上一个元素
//容器的类型别名在泛型编程中非常有用
//要使用这些类型,必须显式使用其类名
std::list<std::string>::iterator;
std::deque<int>::value_type;
//begin()实际上有两个版本 一个是对非常量,一个是const,这样就不用面对一个const容器特意使用cbegin(),而使用begin()让编译器判断
//以c开头的版本是c++新标准引入的,用以支持auto与begin和end函数结合使用

//每个容器类型都定义了一个默认构造函数
//除了array之外,其它容器的默认构造函数都会创建一个指定类型的空容器,且都可以接受指定容器大小和元素初始值的参数
//C c; 默认构造函数,如果C是一个array,则c中元素按默认方式初始化,否则c为空
//C c1(c2)
//C c1 = c2 c1初始化为c2的拷贝,必须相同的类型,对于array两个必须大小相同
//C c{...}
//C c={...}
//C c(b,e) 指定范围中的元素的拷贝,类型必须和C中元素类型一致
//只有顺序容器(不包括array)的构造函数才能接受大小参数
//C seq(n) seq包含n个元素,为此元素进行了值初始化;此构造函数是explicit的(string不适用)
//C seq(n,t) 初始值为t

//为一个新容器创建为另一个容器的拷贝的方法有两种:直接拷贝整个容器,
//拷贝由一个迭代器对指定的元素范围[不要求容器类型相同,也不要求必须元素类型相同,只要能够转换]
//list<const char*> authors = { "dddd","aaaaa","eeeee" };
//forward_list<string> words(authors.begin(), authors.end());  //正确
//与顺序容器大小相关的构造函数
//vector<int>iver(10); //如果没有提供元素初始值,则标准库会创建一个值初始化器
//[上面这条语句 每个元素都初始化为0,值初始化器可能是{}]
//如果元素类型是内置类型或者是具有默认构造函数的类类型,可以只为构造函数提供一个容器大小参数

//与内置数组一样,标准库array的大小也是类型的一部分
//当定义一个array时,除了指定元素类型,还要指定容器的大小
std::array<int, 2> test_new_array; //类型是保存42个int的数组 
int test_old_array[2];
std::array<int, 45>::size_type;//同样的在使用类型的类型时也要指定元素类型和大小

//与其他容器不同,一个array默认构造函数生成一个非空的:包含了与其大小一样多的元素,这些元素被
//默认初始化,就像一个内置数组中的元素那样.  如果对array进行列表初始化,初始值的数目必须等于或小于array的大小
//和内置类型的变量一样,如果在函数内部定义了某种内置类型的数组,那么默认初始化会令数组含有未定义值

void test_undefine() {
	using std::cout;
	using std::endl;
	std::array<int, 2> utest_new_array; // ? ? 
	std::array<int, 3>test = {}; // 0 0 0
	std::array<int, 3>test2 = { 1 };  // 1 0 0
	std::vector<int>iver(10); // 0 0 0 0 0 0 0 0 0...
	int utest_old_array[2]; // ? ?
	cout << test_new_array[0] << endl; //0
	cout << test_old_array[0] << endl; //0
	cout << utest_new_array[0] << endl; //未定义
	cout << utest_old_array[0] << endl; //未定义
	cout << iver[0] << endl; //0
	for (auto i : test) {
		cout << i << endl;
	}
	for (auto i : test2) {
		cout << i << endl;
	}
	//注意:只有数组类型(新旧)+内置类型在函数体内不初始化才会出现未定义的行为
	//而其他容器(使用name(num)构造)不会出现,在构造函数中给定了初始化器{}
}

//值得注意:虽然不能对内置数组类型进行拷贝或对象赋值操作,但array没有限制
//int a2[] = a; //错误
//a2 = a; //错误
//array<int, 10>copy = digits; //正确: 只要数组类型匹配即合法(大小 + 类型)

//赋值和swap
//赋值运算符将其左边容器中的全部元素替换为右边容器中元素的[拷贝]
//c1 = c2; //将c1内容替换为c2中元素的拷贝  如果两个容器原来大小不同,赋值运算后两者大小都与右边容器的原大小相同
//c1 = {a, b, c}; //赋值后c1大小为3  c1的size变为3
//由于右边运算对象的大小可能与左边运算对象的大小不同,因此array类型不支持assign,
//也不允许用花括号包围的值列表进行赋值 但实测没有问题
void test_array_assign() {
	std::array<int, 10> aa1 = { 0,1 };
	std::array<int, 10> aa2 = { 0 };
	aa1 = aa2; //array支持但类型严格要求
	//aa1;
	aa2 = { 0 }; //实测没问题 (原本array不支持)
	//c1 = c2  //将c1中的元素替换成c2中元素的拷贝, c1 c2必须有相同的类型
	//c = {a, b, c} //将c1中的元素替换为初始化列表中元素的拷贝
	//swap(c1, c2) //交换c1 c2中的元素,c1,c2必须有相同类型,swap通常比从c2向c1拷贝元素快
	//c1.swap(c2)
	// assign操作不适用关联容器和array
	//seq.assign(b,e) //迭代器b 和 e所表示的范围中的元素
	//seq.assign(i1) //将元素替换为初始化列表i1中的元素
	//seq.assign(n,t) //将seq中的元素替换为n个值为t的元素

	//赋值相关运算会导致指向左边容器内部的迭代器,引用和指针失效,而swap操作将容器内容交换不会导致指向容器的迭代器
	//引用和指针失效(容器类型为array和string的情况除外)

	//顺序容器定义了一个名为assign的成员,允许从不同但相容类型赋值,或子序列,但直接使用=不可
	//list<string> names;
	//vector<const char*> oldstyle;
	//names = oldstyle; //错误: 容器类型不匹配
	//names.assign(oldstyle.cbegin(),oldstyle.cend()); //正确
	//由于旧元素被替换,传递给assign的迭代器不能指向调用assign的容器

	//使用swap
	//vector<string> s1(10); //10个
	//vector<string> s2(20); //20个元素
	//swap(s1,s2); //s1=>20个元素 s2=>10个元素 swap只是交换了两个容器的内部的数据结构
	//除array外,swap不对任何元素进行拷贝,删除,插入,因此可以保证在常数时间内完成
	//swap不会使得迭代器失效,但原本的迭代器已经属于不同的容器了
	//但与其他容器不同,对一个string调用swap会导致迭代器,引用和指针失效

	//swap两个array会真正交换它们的元素因此时间和元素的数目成正比
	//新标准库提供成员函数版本的swap,也有非成员函数版本,但在泛型编程中使用非成员版本swap是一个好习惯

	//容器大小操作 
	//size 返回容器中
	//empty 当size为0时返回布尔值true否则返回false
	//max_size 返回一个大于或等于该类型容器所能容纳的最大元素数的值
	//注意 forward_list不支持size

	//关系运算符
	//只能比较同类型的,比较两个容器实际上是进行元素的逐对比较,与string类似
	//1.容器大小相同且所有元素都两两对应相等,则两个容器相等
	//2.容器大小不同,但较小容器中每个元素都等于较大容器中的对应元素,则较小容器<较大容器
	//3.如果两个容器都不是另一个容器的前缀子序列,则它们的比较结果取决于第一个不相等的元素的比较结果
	//注意只有当元素的类型也定义了相应的比较运算符时,我们才可以使用关系运算符来比较两个容器


}

//以上是所有的容器都有的操作
//顺序容器操作
void test_seq_container() {
	//向容器中添加元素
	//除了array外所有标准库容器都提供灵活的内存管理
	//
	//forward_list有自己专有版本的insert 和emplace;
	//forward_list不支持push_back和emplace_back
	//vector和string不支持push_front和emplace_front
	//
	//c.push_back(t)  在c的尾部创建一个值为t或由args创建的元素,返回void
	//c.emplace_back(args)
	//c.push_front(t) 在c的头部创建一个值为t或由args创建的元素,返回void
	//c.emplace_front(args)
	//c.insert(p, t) 在迭代器p指向的元素之前创建一个值为t或由args创建的元素,返回指向新添加的元素的迭代器
	//c.emplace(p, args) 
	//c.insert(p, n, t) 在迭代器p指向元素之前插入n个值为t的元素,返回指向新添加的第一个元素的迭代器,若n==0,返回p
	//c.insert(p, b, e) 将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前,
	//b和e不能指向c中的元素,返回指向新添加第一个元素的迭代器,空范围,返回p
	//c.insert(p,i1) i1是一个花括号包围的元素值列表,将这些给定值插入到迭代器p指向的元素之前
	//向一个vector , string 或 deque插入元素会使所有指向容器的迭代器,引用和指针失效


	//使用push_back
	//string也可使用push_back
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	using std::vector;
	using std::istringstream;
	string input1 = "d\r\n"
		"e\r\n"
		"f\r\n";
	istringstream ssinput1(input1);
	string test_string_push_back = "abc";
	cout << test_string_push_back.max_size() << endl;
	char test_input_word;
	while (ssinput1 >> test_input_word) {
		test_string_push_back.push_back(test_input_word);
		//等价于 +=test_input_word
		//调用后,在容器的尾部创建了一个新的元素,将container的size增大了1
		//元素的值是拷贝
	}
	cout << test_string_push_back.max_size() << endl;
	cout << test_string_push_back << endl;
	//当用一个对象来初始化容器时,或将一个对象插入到容器中时,实际上放入到容器中的是对象值的一个拷贝
	//而不对象本身

	//test for <<vector
	//vector<int> test_vector_output{ 1,2,3,5 };
	//cout << test_vector_output; //不能直接输出

	//push_front 很方便地生成一个逆序
	//deque是vector的升级版,支持push_front
	using std::list;
	list<string> test_list_push_front{ "Second",{'T','h','r','i','d'} };
	test_list_push_front.push_front("First");
	//下面相当于调用元素的构造函数进而添加元素
	test_list_push_front.emplace_front(10, '#'); //使用push_front就不行
	for (auto i : test_list_push_front) {
		cout << i << " ";
	}
	cout << endl;

	//在容器的特定位置添加元素 (在位置之前,相当于在位置上(顶替原来的))
	//vector,deque,list和string都支持insert成员,forward_list提供了特殊版本的insert
	//每个insert函数都接受一个迭代器作为其第一个参数,迭代器指出了在容器中什么位置放置
	//新元素,它可以指向容器中任何位置,包括容器尾后元素
	//vector不支持push_front因此可以使用insert代替(可能很耗时)
	vector<int> test_vector_insert{ 1,2,3 };
	vector<int> test_vector_insert1{ 9,7,6 };
	//test_vector_insert.insert(test_vector_insert.cbegin(), 0);
	//test_vector_insert.insert(test_vector_insert.cbegin(), 5,0);
	//test_vector_insert.insert(test_vector_insert.cbegin(), test_vector_insert1.rbegin(),test_vector_insert1.rend()-1);
	test_vector_insert.insert(test_vector_insert.cbegin(), { 7,7,7 });
	for (auto i : test_vector_insert) {
		cout << i << " ";
	}
	cout << endl;
	//通过使用insert的返回值,可以在容器中的一个特定位置反复插入元素


	//使用emplace操作
	//这些操作构造而还是拷贝元素,使用push,insert成员函数是将元素类型的对象传递给它们
	//这些对象被拷贝到容器中,而当调用一个emplace成员函数时,则是将参数传递给元素类型的
	//构造函数,emplace成员使用为此参数在容器管理的内存空间中直接构造元素
	//而调用push会创建一个局部临时对象,并将其压入容器中,emplace则会在容器内存空间直接创建对象

	//访问元素
	//如果容器没有元素,访问操作的结果是未定义的
	//包括array在内的每个顺序容器都有一个front成员函数,而除froward_list之外的所有
	//顺序容器都有一个back成员函数,这两个操作分别返回首元素和尾元素的引用 
	//在解引用或调用back front之前最好检查是否有元素 否则未定义行为
	//val1, val2是c中第一个元素值的拷贝
	//auto val1 = *c.begin(),val2 = c.front();
	//val1
	//auto last = c.end();
	//auto val3 = *(--last); //正确//但不能递减forward_list迭代器
	//auto val4 = c.back(); //正确//但forward_list不支持

	//在容器中访问元素的成员函数(front, back, 下标和at)返回的都是引用,
	//如果容器是一个const对象,则返回值是const的引用
	//下标访问的安全性
	//如果希望下标是合法的,可以使用at成员函数,at成员函数类似下标运算符
	//如果下标越界,at会抛出一个out_of_range异常

	//删除元素
	//非array容器也有多种删除元素的方式
	//forward_list有特殊版本的erase
	//forward_list不支持pop_back; vector和string不支持pop_front
	//
	//c.pop_back();  //删除c中的尾元素,若c为空,则函数行为未定义,函数返回void
	//c.pop_front();  //删除c中的首元素,若c为空,则函数行为未定义,函数返回void
	//c.erase(p);	//删除迭代器p所指定的元素,返回一个指向被删除元素之后元素的迭代器
	//				//若p指向尾元素,则返回尾后迭代器,若p是尾后迭代器,则函数行为未定义
	//c.erase(b, e);	//删除迭代器b和e范围内的元素,返回指向最后一个被删之后的元素的迭代器
	//					//若e是一个尾后元素,则函数也返回尾后元素
	//c.clear(); //删除c中的所有元素 返回void
	//
	//删除deque中除首尾位置之外的任何元素都会使所有迭代器,引用和指针失效
	//指向vector或string中删除点之后位置的迭代器,引用和指针都会失效
	//删除元素不检查参数,在删除元素之前,程序员必须确保它是存在的

	//pop_front,pop_back成员函数分别删除首元素和尾元素
	//注意这些操作返回void不返回元素的拷贝
	//从容器内部删除一个元素 earse()
	//elem1 = slist.erase(elem1, elem2);//调用后 elem1 == elem2

	//特殊的forward_list操作
	//当添加或删除一个元素,要获取元素的前驱,以便改变前驱的链接
	//但是是forward_list(单向链表)无法获取前驱,
	//因此在forward_list中添加或删除一个元素是通过给定元素之后的元素完成的
	//因此forward_list没有定义insert,emplace和erase 
	//而是定义了 insert_after, emplace_after ,和erase_after的操作
	//为了支持这些操作,forward_list定义了before_begin,它返回一个首前迭代器
	//类似于尾后迭代器

	//注意单向链表的insert不同于之前的,它是在指定位置之后插入(不是当前位置)
	//lst.before_begin()
	//lst.cbefore_begin() 返回首前元素迭代器,不能解引用
	//lst.insert_after(p, t) 在迭代器p之后的位置插入元素,t 是一个对象,n是一个
	//lst.insert_after(p, n, t) 数量,b,e是表示范围的一对迭代器(b,e不能指向自己)
	//lst.insert_after(p, b, e) il是一个花括号列表,返回一个指向最后一个插入元素的
	//lst.insert_after(p, il) 迭代器,如果范围为空,则返回p,若p为尾后迭代器则函数行为未定义
	//emplace_after(p, args) 使用args在p指定位置之后创建一个元素返回指向该元素的迭代器
	//
	//lst.erase_after(p); 删除p指向的位置之后的元素,或删除从b之后直到(但不包含)e
	//lst.erase_after(b, e); 之间的元素,返回指向被删除元素之后元素的迭代器,若不存在
	//返回尾后迭代器,如果p指向lst的尾元素或者是尾后迭代器,行为未定义
	//注意:相当begin和end的范围似乎没有变化

	//在使用forward_list添加或删除元素时必须关注两个迭代器
	//一个指向要处理的元素,另一个指向前驱
	std::forward_list<int> test_forward{ 1,2,3,4,5,6,7,8,9 };
	auto prev = test_forward.cbefore_begin();
	auto curr = test_forward.begin();
	//***auto over = test_forward.end(); //不要这样写
	//当删除元素时,尾后迭代器总是会失效
	//不推荐vector这样写 (迭代器失效)
	for (auto i = curr; i != test_forward.end(); ++prev, ++i) {
		if (*i % 2 == 0) {
			test_forward.emplace_after(prev);
		}
		else {
			cout << *i << " ";
		}

	}
	cout << endl;

	//改变容器的大小
	//可以使用resize来增大或缩小容器,与往常一样,array不支持resize
	//如果当前大小大于所要求的大小,容器后部的元素会被删除;
	//如果当前大小小于新大小,会将新元素添加到容器的后部
	list<int>ilist(10, 44);
	cout << ilist.size() << endl;
	ilist.resize(6);
	cout << ilist.size() << endl;
	ilist.resize(12); //新增的元素进行值初始化
	cout << ilist.size() << endl;
	for (auto i : ilist) {
		cout << i << " ";
	}
	cout << endl;
	//如果resize缩小容器,则指向被删除元素的迭代器,引用和指针都会失效
	//对vector,string deque进行resize可能导致迭代器的失效
	//容器操作可能使迭代器失效
	//向容器中添加元素后,
	//vector string 存储空间可能被重新分配 or 插入位置之后的元素可能失效
	//对于deque插入除首尾之外的的任何位置,失效,首尾的话会失效但指向存在的元素的引用和指针不会失效
	//list和forward_list不会失效
	//在容器中删除元素后,
	//list forward_list 不会失效
	//deque 同添加元素一样
	//vector string同添加元素一样
	//注意:当删除元素时,尾后迭代器总是会失效
	//
	//由于迭代器时刻可能失效,应当保证每次改变容器后重新定位迭代器
	//尤其是vector string deque
	//如果循环中调用的是insert或erase,更新迭代器很容易,这些操作返回迭代器

	//vector对象是如何增长的
	//为了支持快速随机访问 vector将元素连续存储,每个元素紧挨着前一个元素存储
	//
	//管理容量的成员函数
	//允许与vector和string类的实现中内存分配部分互动
	//shrink_to_fit只适用于vector string 和 deque
	//capacity和reserve只适用于vector和string
	//
	//c.shrink_to_fit() 将capacity()减少为与size()相同的大小
	//c.capacity() 不重新分配内存空间的话,c可以保存多少元素
	//c.reserve(n) 分配至少能容纳n个元素的内存空间
	//reserve并不改变容器中元素的数量,它仅影响vector预先分配多大的内存空间
	//可能分配比需要更多的内存空间=>大于等于传递的参数
	//并且只有大于当前的capacity时才会分配否则什么都不做
	//c++11中可以调用shrink_to_fit来要求deque, vector或string退回不需要的内存空间
	//但是调用shrink_to_fit并不保证一定退回内存空间
	//
	//capacity和size的区别
	//size是指已经保存的元素的个数,,而capacity则是在不分配新的内存空间的前提下它最多可以保存多少个元素
	vector<int> test_size_capacity;
	cout << "Test size and capacity: " << endl;
	cout << test_size_capacity.size() << "  " << test_size_capacity.capacity() << endl;
	//test_size_capacity.insert(test_size_capacity.cend(),30,999);

	auto last_changed_cap = test_size_capacity.capacity();
	for (int i = 0; i < 31; ++i) {

		if (test_size_capacity.capacity() != test_size_capacity.size() && last_changed_cap != test_size_capacity.capacity() && test_size_capacity.size() != last_changed_cap) {
			last_changed_cap = test_size_capacity.capacity();
			cout << "Capacity Change at " << i
				<< "  Current Capacity is " << last_changed_cap
				<< "  Current Size is " << test_size_capacity.size()
				<< endl;



		}
		test_size_capacity.push_back(999); //第三次push_back的时候增加了
	}
	//上面两个是有区别的,使用for循环多次调用了push_back使得变量的capacity增长
	//而一次性地插入不会
	//test_size_capacity.shrink_to_fit();
	cout << "Test size and capacity: " << endl;
	//test_size_capacity.pop_back(); //比size少1
	//test_size_capacity.reserve(130); //不使用reserve尝试后总是与size相同...
	cout << test_size_capacity.size() << "  " << test_size_capacity.capacity() << endl;
	//只要没有操作需求超出vector的capacity,vector就不重新分配内存

	//额外的string操作
	//构造string的其它方法
	//string s(cp, n) s是cp指向的数组中前n个字符的拷贝,此数组至少包含n个字符
	//string s(s2,pos2) s是string s2从下标pos2开始的字符的拷贝,若pos2>s2.size() ,构造函数未定义
	//string s(s2, pos2, len2) s是string s2从下标pos2 开始len2个字符的拷贝,不管len2的值是多少,构造函数至多拷贝s2.size()-pos2个字符
	//这些构造函数接受一个string或一个const char*参数(如果没有指定范围则未定义的操作)
	//
	const char *cp = "Hello World!!!";
	char noNull[] = { 'H','i' };
	string ss[8];
	ss[0] = string(cp);
	ss[1] = string(noNull, 2);
	//ss[2] = string(noNull); //未定义 noNUll不是以空字符结束的
	ss[2] = string(noNull, 1);
	ss[3] = string(cp + 6, 5);
	ss[4] = string(ss[0], 6, 5);
	ss[5] = string(ss[0], 6);
	ss[6] = string(*ss, 6, 20);
	//ss[7] = string(*ss,16); //抛出异常 out_of_range
	ss[7] = string(*ss, 8);
	//总的来说:string类型多一个第二个参数下标,这个参数不能越界
	for (auto i : ss) {
		cout << i << endl;
	}

	//substr操作
	//返回一个string,它是原始string的一部分或全部的拷贝
	//可以传递给substr一个可选的开始位置和计数值
	string test_sub(cp);
	string s2 = test_sub.substr(0, 5);
	string s3 = test_sub.substr(6);
	string s4 = test_sub.substr(6, 11);
	cout << s2 << "\n" << s3 << "\n" << s4 << endl;
	//string s5 = test_sub.substr(19); //抛出异常

	//string类型支持顺序容器的赋值运算符以及assign insert 和 erase操作
	//除此之外还有额外的insert和erase版本(第一个参数不是迭代器,而是下标参数)
	//s.insert(s.size(),5 ,'!') //s的末尾插入5个!
	//s.erase(s.size() - 5, 5) //从s删除最后5个字符
	//标准库还提供接受c风格字符数组的insert和assign版本
	//s.assign(cp, 7);  //第二个参数指定多少个字符<=size()
	//s.insert(s.size(),cp+7) //这样就相当于 s = cp; 注意 两个7意义不同

	//s.insert(0,s2) 在s中位置0之前插入s2的拷贝
	//s.insert(0,s2,0,s2.size()) 在s中位置0之前插入s2的从s2[0]开始的s2.size()个字符

	//append和replace
	//append操作是在string末尾进行插入操作的一种简写
	//s.insert(s.size(), " !!!!");  
	//s2.append(" !!!!"); 等价
	//s.erase(11, 3); 
	//s.insert(11, "xxx");
	//s2.replace(11,3,"xxx");  等价以上两个语句
	//插入文本可以不等删除文本

	//s.insert(pos,args)
	//s.erase(pos,len)
	//s.assign(args)
	//s.append(args)
	//s.replace(range,args) range或是一个下标一个长度,或者是一对指向s的迭代器
	//
	//args可以是下列形式之一: append和assign可以使用所有形式
	//str 字符串
	//str,pos,len str中从Pos开始最多len个字
	//cp,len 从cp指向的字符数组的最多len个字符
	//cp 以空字符结尾的字符数组
	//n,c  n个字符c
	//b,e 迭代器b和e指定的范围
	//初始化列表  花括号包围,以逗号分隔的字符列表
	//具体的p324
	//assign和append函数无须指定要替换string中哪个部分
	//

	//string搜索操作
	//返回一个string::size_type,失败返回一个名为string::nps的static成员
	//标准库将npos定义为一个const string::size_type类型并初始化为-1
	//由于npos是一个Unsigned类型,此初始值意味着npos等于任何string最大的可能大小
	//启发:想知道一个类型的最大值
	//使用 decltype(type) x = -1
	//
	decltype(string::npos) x = -1;
	cout << "string::npos max : " << x << endl;
	string test_npos;
	cout << "test_nops        : " << test_npos.npos << endl;

	//未找到返回npos 否则返回下标
	//s.find(args)  //查找s中args第一次出现的位置
	//s.rfind(args)  //查找s中args最后一次出现的位置
	//s.find_first_of(args)  //在s中查找args中任何一个字符第一次出现的位置
	//s.find_last_of(args)  //在s中查找args中任何一个字符最后一次出现的位置
	//s.find_first_not_of(args)  //在s中查找第一个不在args中的字符
	//s.find_last_not_of(args)  //在s中查找最后一个不在args中的字符
	//args
	//c, pos   //从s中位置pos开始查找字符c ,pos默认为0
	//s2, pos    //从s中位置pos开始查找字符串s2,pos默认为0
	//cp, pos    //从s中位置pos开始查找指针cp指向的以空字符结尾的C风格字符串,pos默认为0
	//cp, pos, n  //从s中位置pos开始查找指针cp指向的数组的前n个字符,pos和n无默认值

	string test_string_find{ "Angel Beats!" };
	//搜索以及其他string操作是大小写敏感的
	cout << test_string_find.find('r') << endl; //返回npos
	cout << test_string_find.rfind("ts") << endl; //9

	string numbers("0123456789"), name("r2d2"), tele("1321d65156");
	auto pos = name.find_first_of(numbers);  //2的下标是1
	cout << pos << endl;//1
	cout << tele.find_first_not_of(numbers) << endl; //返回d所在的下标

	//使用参数一般用于循环搜索子字符串出现的所有位置
	//while((pos = name.find_first_of(numbers,pos)) != string::npos){
	//++pos}

	//除了关系运算符,标准库string类型还提供了一组compare函数,这些函数与c标准的strcmp函数相似
	//返回值0 正数 负数
	//s.compare的几种参数形式
	//s2  比较s和s2
	//pos1, n1, s2 
	//pos1, n1, s2, pos2, n2
	//cp  比较s和cp指向的以空字符结尾的字符数组
	//pos1,n1,cp
	//pos1,n1,cp,n2

	//数值转换
	//新标准库引入了多个函数,可以实现数值数据与标准库string之间的转换
	int i = 45;
	string s = std::to_string(i);
	double d = std::stod(s);
	int ii = std::stoi(s);
	//要转换数值的string中的第一个非空白符必须是数值中可能出现的字符
	string sss1 = "pi = 3.14ddd";//即使后面有字符,也只处理数值
	//如果string不能转换为一个数值,抛出一个invalid_argument异常
	double ddd = stod(sss1.substr(sss1.find_first_of("+-.0123456789")));
	//没找到也会抛出异常 out of range
	cout << ddd << endl;
	//double ddd1 = stod(string("d3.1")); //抛出一个invalid_argument异常

	//to_string(val)  //一组重载函数,返回值val的string表示,val可以是任何算术类型,小整数会被提升
	//stoi(s,p,b)  //返回s的起始子串(表示整数内容)的数值,返回类型是int long unsigned long
	//stol			//等,b表示转换所用的基数,默认值为10,p是size_t指针
	//stoul			//用来保存s中第一个非数值字符的下标,p默认为0,(不保存下标)
	//stoll
	//stoull
	//stof(s,p)		//返回s的起始子串(表示浮点数内容)的数值,返回类型分
	//stod(s,p)		//别是float double longdouble 参数p的作用同上
	//stold(s,p)
	//
	size_t low;
	string sss2("2d");
	stoi(sss2, &low);//注意不能开关就是一个非数值的string
	cout << low << endl;

	cout << "\nInput a Number:" << endl;
	string user_input;
	cin >> user_input;
	using std::array;
	array<int, 3> base{ 8,10,16 };
	for (auto i : base) {
		//注意这个是将输入转换为10进制而不是返过来
		cout << i << " Based: " << stoi(user_input, 0, i) << endl;
	}


}
void test_adaptor() {
	//容器适配器
	//除了顺序容器外,标准库还定义了三个顺序容器适配器: stack queue 和 priority_queue
	//适配器(adaptor)是标准库中一个通用概念,容器 迭代器,和函数都有适配器
	//一个适配器是一种机制,能使某种事物的行为看起来像另外一种事物一样
	//一个容器适配器接受一种已有的容器类型,使其行为看起来像一种不同的类型
	//例如,stack适配器接受一个顺序容器(除array 和 forward_list外)
	//并使其操作起来像一个stack一样
	//size_type   一种类型,足以保存当前类型的最大对象的大小
	//value_type  元素类型
	//container_type  实现适配器的底层容器类型
	//A a   创建一个名为a的空适配器
	//A a(c)   创建一个名为a的适配器,带有容器c的一个拷贝
	//关系运算符   返回底层容器的比较结果
	//a.empty()  若a包含任何元素返回false,否则返回true
	//a.size()	返回a中的元素数目
	//swap(a,b)  a,b必须有相同类型,包括底层容器的类型
	//a.swap(b)

	//定义一个适配器
	//每个适配器都定义两个构造函数:默认构造创建一个空对象,接受一个容器的构造函数
	//拷贝该容器来初始化适配器
	//假定deq是一个deque<int>
	//初始化stack
	//stack<int> stk(deq);
	//默认情况下stack和queue是基于deque实现的
	//priority_queue是在vector之上实现的,
	//创建时重载一个适配器
	//stack<string, vector<string>> str_stk;
	//对于一个给定的适配器,容器使用有限制:具有添加删除元素的能力
	//因此不能使用array,forward_list(要求能访问尾元素)
	//stack只要求push_back,pop_back和 back操作,因此可以使用除array forward_list构造
	//queue适配器要求back push_back front push_front, 因此可以构造于list deque之上
	//priority_quue除了front(没有back) push_back pop_back操作之外还要求随机访问能力,因此可以构造于vector和deque,不能list

	//栈适配器
	//stack类型定义在stack头文件
	using std::cout;
	using std::cin;
	using std::endl;
	std::stack<int> intStack; //空栈
	//填满
	for (size_t ix = 0; ix != 10; ++ix)
		intStack.push(ix);
	while (!intStack.empty()) {
		cout << intStack.top() << endl;
		intStack.pop();
	}
	//Stack的操作(默认基于deque实现)
	//s.pop()  //删除栈顶元素但不返回该元素值
	//s.push(item)		//创建一个新元素压入栈顶,该元素通过拷贝或移动item而来
	//s.emplace(args)	//由args构造
	//s.top()  //返回栈顶元素,但不弹出栈

	//只可使用适配器定义的自己的特殊操作,不能使用底层容器类型的操作


	//队列适配器
	//queue和priority_queue适配器定义在queue头文件中
	//queue默认基于deque实现(可使用list,vector实现),priority_queue默认基于vector实现(可以使用deque)
	//q.pop() 返回queue的首元素或priority_queue的最高优先级元素,但不删除元素
	//q.front() 返回首元素或尾元素,但不删除此元素
	//q.back() 只适用于queue
	//q.top()  返回最高优先级元素,但不删除元素
	//q.push(item)  在queue末尾或priority_queue中恰当位置创建一个元素
	//q.emplace(args)  其值为item 或者由args构造

	//queue使用FIFO先进先出的存储和访问策略
	//priority_queue允许为队列中的元素建立优先级,新加入的元素会排在所有优先级比它低的已有元素之前
	//

}
//use for bind() test
bool check_size(const std::string &s, std::string::size_type sz) {
	return s.size() >= sz;
}
void test_algorithm() {
	//泛型算法
	//容器自身定义的方法少(添加删除元素 访问首尾元素 确定容器空否 首前尾后的迭代器)
	//泛型算法:查找特定元素 替换删除一个特定值 重排元素顺序
	//大多数算法都定义在头文件algorithm中
	//标准库还在头文件numeric中定义了一组数值泛型算法
	//一般情况下通过遍历由两个迭代器指定的一个元素范围进行操作

	//find
	using std::string;
	using std::vector;
	vector<string> vstring1{ "sfdsf","dsfasf","a value","dddd" };
	string sval1 = "a value";
	auto result1 = std::find(vstring1.cbegin(), vstring1.cend(), sval1);
	using std::cout;
	using std::endl;
	cout << (result1 == vstring1.cend() ? "No iteam" : string("At ").append(std::to_string(std::distance(vstring1.cbegin(), result1)))) << endl;
	//如果没有找到目标元素,则返回第二个参数end()[注意是尾后元素,不指向一个有效元素]
	//find也能用在内置的数组上
	//此时传递的参数是指针类型
	//可以使用标准库提供的std::begin()得到

	//算法永远不会执行容器的操作,它只会运行于迭代器之上,执行迭代器的操作
	//泛型算法永远不会改变底层容器的大小,算法可能改变容器中保存的元素的值,也可能在容器中移动元素,但不会直接添加删除元素

	//find的算法流程本质就是一个逐个循环对比==

	//标准库提供了超过100个算法
	//除了少数例外,标准库算法都对一个范围内的元素进行操作
	//接受输入范围的算法总是使用前两个参数来表示此范围(要处理的第一个元素和最后一个元素后一个的迭代器)

	//只读算法
	//不改变元素,find就是这样一种算法,count函数也是
	//另一个只读算法是accumulate,它定义在numeric中,接受三个参数,前两个范围,第三个是和的初值
	//假定vec是一个整数序列: 对vec中的元素求和 和的初值是0(决定了函数中使用哪个加法运算符以及返回值的类型)
	//int sum = accumulate( vec.cbegin(), vec.cend(), 0)
	//

	//算法和元素类型
	//accumulate将第三个参数作为求和起点,这蕴含着一个假定:将元素类型加到和的类型上的操作必须是可行的
	//即序列中元素的类型必须与第三个参数匹配,或能转换为第三个参数的类型
	//例子:  string定义了+运算符
	//string sum = accumulate(vec.cbegin(), vec.cend(), string(""));
	//
	//操作两个序列的算法
	//另一个只读算法是equal,用于确定两个序列是否保存相同的值
	//它将第一个序列中的每个元素与第二个序列中的对应元素进行比较,都相等true否则false
	//接受三个参数(两个范围,第三个是第二个序列的首元素迭代器)
	//equal(vec.cbegin(), vec.cend(), another.cbegin())
	//可以用来比较两个不同类型的容器中的元素,也可不同的元素 只要能相互==操作
	//但是equal基于非常重要的假设,第二个序列至少与第一个序列一样长

	//写容器元素的算法
	//一些算法将新值赋予序列中的元素.当使用这类算法时,必须注意序列原大小至少不小于
	//我们要求算法写入的元素数目
	//一些算法会向输入范围写入元素,这些算法本质上并不危险,它们最多写入与给定序列一样多的元素
	//例如fill接受一对迭代器表示一个范围,还授受一个值作为第三个参数
	//fill(vec.begin(), vec.end(), 0); //将每个元素重置为0
	//用一个单一的迭代器表示第二个序列的算法都假定第一个序列至少与第一个一样长
	//算法不检查写操作 [程序员确保]
	//函数 fill_n接受一个单迭代器,一个计数值,和一个值,它将给定值赋予迭代器指向的元素开始
	//的指定个元素,可以用fill_n将一个新值赋予vector中的元素
	//vector<int> vec;
	//fill_n(vec.begin(),vec.size(),0); //第二个元素确保不大于序列的大小
	//
	//back_inserter (插入迭代器 定义在<iterator>的一个函数)
	//一种保证算法有足够元素空间来容纳输出数据的方法是使用插入迭代器
	//当通过一个迭代器向容器元素赋值时,值被赋予迭代器指向的元素
	//当通过插入迭代器(insert_iterator)时,一个与赋值号右侧值相等的元素被添加到容器中

	//back_inserter接受一个指向容器的引用,返回一个与该容器绑定的插入迭代器
	//当通过此迭代器赋值时,赋值运算符会调用push_back将一个具有给定值的元素添加到容器中
	vector<int> vec1;
	auto it = back_inserter(vec1); //没有std
	*it = 42; //现在有一个元素42
	*it = 55;
	*(++it) = 60;
	++it;
	++it; //递增操作并不影响push_back的操作,因此可以fill_n中使用
	*(++it) = 70;
	for (auto i : vec1) {
		cout << i << " "; //42 55 60 70
	}
	cout << endl;
	//常使用back_inserter来创建一个迭代器作为算法的目的位置来使用
	//例如
	//vecotr<int> vec;//空向量
	//fill_n(back_inserter(vec), 10, 0);//添加10个元素到vec

	//拷贝算法
	//是另一个向目的位置迭代器指向的输出序列中的元素写入数据的算法
	//算法接受三个迭代器,前两个输入范围,第三个表示目的序列的起始位置
	//将输入范围中的元素拷贝到目的序列中,目的序列至少要包含与输入序列一样多的元素
	int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int a2[sizeof(a1) / sizeof(*a1)];
	//ret指向拷贝到a2的尾元素之后的位置,方便迭代所有有效的元素
	auto ret = std::copy(std::begin(a1), std::end(a1), a2);
	for (auto i : a2) {
		cout << i << " "; //
	}
	cout << endl;
	//
	//很多算法提供一个copy版本
	//例如replace算法读入一个序列,并将其中掺等于给定值的元素都改写成另一个值
	//此算法接受4个参数,前两个迭代器,后两个一个要搜索的值,一个是新值
	//replace(ilst.begin(), ilst.end(), 0, 42); //0全部替换成42
	//如果希望保留原序列不变,可以调用replace_copy,此算法接受额外第三个迭代器参数
	//replace_copy(ilst.cbegin(), ilst.cend(),back_inserter(iver), 0, 42);

	//重排容器元素的算法
	//sort算法接受两个迭代器,表示要排序的元素范围,
	//sort是利用元素类型的<运算符来实现的
	//unique算法"消除"重复项(只是将重复的放在末尾了,算法都不能增删元素的),并返回一个指向不重复范围末尾的迭代器
	//使用unique会返回一个最后一个不重复元素的下一个位置
	//利用返回值调用容器的earse做到真正删除元素

	//定制操作
	//很多算法会比较输入序列中的元素< == ,标准库还为这些算法定义了额外的版本
	//允许提供自己定义的操作来代替默认运算符
	//例如,sort算法默认使用元素类型的<运算符,但可能排序顺序与<不同,或是未定义<运算
	//这种情况下,需要重载sort的默认行为

	//向算法传递函数:,sort的第二个版本,重载过的,接受第三个参数,此参数是一个谓词
	//谓词是一个可调用的表达式,其返回结果是一个能用作条件的值
	//标准库算法使用的谓词有两类:
	//一元谓词(只接受单一参数) 二元谓词(两个参数),接受谓词参数的算法对输入序列
	//中的元素调用谓词,因此,元素类型必须能转换为谓词参数类型
	//接受一个二元谓词参数的sort版本用这个来代替<比较元素
	//bool isShorter(const string &s1, const string &s2){};
	//sort(words.begin(), words.end(), isShorter);
	//使用stable_sort可以保持sort之前的顺序,因此在调用之前一定要先字典排好
	//再使用这个进行二次排序

	//lambda表达式
	//根据算法接受一元谓词还是二元,传递给算法的谓词必须严格接受一个或两个参数
	//但是可能需要参考一些其他的参数

	//find_if算法来查找第一个具有特定大小的元素类似find
	//find_if算法接受一对迭代器,表示一个范围,但与find不同的是,find_if第三个参数是一个谓词(一元)
	//find_if对输入序列中的每个元素调用这个谓词,它返回第一个使谓词返回非0值的元素
	//如果不存在使谓词返回非0值的元素,则返回尾迭代器

	//lambda c++ 11
	//可以向一个算法传递的任何类别的可调用对象,对于一个对象或一个表达式
	//如果可以对其使用调用运算符,则称它可调用的,即e是一个可调用的表达式,则可以 e(args)
	//目前为止,使用过的仅有两种可调用对象是函数和函数指针
	//可以理解lambda表达式是一个未命名的内联函数
	//与任何函数类似,一个lambda具有一个返回类型,一个参数列表和一个函数体
	//但与函数不同,lambda可能定义在函数内部
	// [capture list](parameter list) -> return type {function body }
	//capture list是一个lambda所在函数中定义的局部变量的列表(通常为空)
	//其他三个与任何函数一样,但是不同的是lambda必须使用尾置返回来指定返回类型
	//可以忽略参数列表和返回类型(无参数,返回类型根据函数体,无有效return则为void),但必须包含捕获列表和函数体
	auto f = [] {return 45; };
	int(*ff)() = f; //
	//定义了一个可调用对象f,它不接受参数 返回45
	cout << ff() << endl;

	//向lambda传递参数
	//调用一个lambda时给定的实参被用来初始化lambda的形参,通常类型必须匹配,与普通函数不同
	//lambda不能有默认参数,因此数目相等
	//空捕获列表表明此lambda不使用它所在函数中的任何局部变量,
	//stable_sort(words.begin(), words.end(),
	//				[](const string &a,const string &b)
	//					{return a.size()<b.size();});

	//使用捕获列表
	//虽然一个lambda可以出现在一个函数中,使用其局部变量,但它只能使用那些明确指明的变量
	//一个lambda通过将局部变量包含在其捕获列表中来指出将会使用这些变量
	//一个lambda只有在其捕获列表中捕获一个它所在函数中的局部变量,才能在函数体中使用

	//调用find_if
	vector<string> words{ "12","123","1234","12345","12345678" };

	//可以封装成一个函数
	unsigned sz = 4;
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a)
	{
		return a.size() >= sz;
	});
	cout << distance(words.begin(), wc) << endl;
	//注意distance的两个参数 必须在是否常量上一致,cbegin cend 成对

	//for_each算法
	//此算法接受一个可调用对象,并对输入序列中每个元素调用此对象 
	for_each(wc, words.end(),
		[](const string &a) {
		cout << a << endl;
	});
	//捕获列表只用于局部非static变量,
	//lambda可以直接使用局部static变量和它所在函数之外声明的名字

	cout << "size: " << words.size() << endl;
	cout << "end - begin: " << words.cend() - words.cbegin() << endl;
	//注意begin就相当于words[0] 其实就是下标相减 end = words[5] 5个元素 实际不存在

	//当定义一个lambda时,编译器生成一个与lambda对应的新的(未命名的)类类型
	//可以理解当向一个函数传递一个lambda时,同时定义了一个新类型和该类型的一个对象:
	//传递的参数就是此编译器生成的类类型的未命名对象类似的,当使用auto定义一个用lambda初始化
	//的变量时,定义了一个从lambda生成的类型的对象
	//默认情况下,从lambda生成的类都包含一个对应该lambda所捕获的变量的数据成员
	//类似任何普通类的数据成员,lambda的数据成员也在lambda对象创建时被初始化

	//值捕获
	//类似参数传递,变量的捕获方式也可是值或引用采用值捕获的前提是变量可以拷贝
	//与参数不同,被捕获的变量的值是在lambda创建时拷贝,而不是调用时拷贝,因此创建完成之后改变
	//变量的值不影响lambda
	//与之相对的可以使用引用的捕获[&sz] 例如Iostream
	//引用要请注意变量的生命周期

	//隐式捕获
	//为了能够隐式(让编译器操作),在捕获列表中写一个&或=
	//&告诉编译器采用捕获引用的方式, =则表示采用值捕获的方式
	//隐式和显式可以混合使用 [&,sz] [=,&os] 注意第一个必须是=/&表明默认的操作
	//并且不能前引用后也引用这样一样的

	//可变lambda
	//默认情况下,对于一个值被拷贝的变量,lambda不会改变其值,如果需要改变的话
	//必须在参数列表后加上关键字mutable,因此可变lambda能省略参数列表
	auto fff = [sz]()mutable -> int {return ++sz; };
	//如果没有mutable的声明,return语句就会报错
	//位置不能放错
	cout << fff() << endl;
	//对于一个使用引用捕获的变量只依赖引用是否是const

	//指定lambda返回类型
	//[注意:如果一个lambda体包含return之外的任何语句,则编译器假定返回void]
	//不过这个在不同的编译器表现可能不同,建议写上返回类型
	auto ffff = [] {}; //也可
	//算法transform接受三个迭代器和一个可调用对象,前两个输入范围,第三个是目的位置迭代器
	//当参数1==参数3,transform交输入序列中每个元素替换为可调用对象操作该元素得到的结果
	//这个没有保护,输入范围一定少于等于后者
	transform(words.begin(), words.end(), words.begin(),
		[](string& s) //参数也可是 string /const ...没有要求
	{
		if (s.size() < 5) {
			s += "d";
			return "[" + s + "]";
		}
		else {
			return "[" + s + "]";
		}

	});
	for (auto i : words) {
		cout << i << " "; //
	}
	cout << endl;

	//参数绑定
	//对于 那种只在一两个地方使用的简单操作,lambda表达式最有用
	//很多地方使用的话,通常应该定义一个函数,类似的复杂也用函数
	//如果捕获列表为空,通常可以用函数代替,但是有的话不容易替换(参数个数问题)



	//标准库 bind 函数 c++11
	//可以解决向check_size传递一个长度参数的问题
	//它定义在头文件functional中
	//可以将bind看成一个通用的函数适配器,它接受一个可调用对象,生成一个新的可调用对象
	//来"适应"原对象的参数列表
	// auto newCallable = bin(callable, arg_list);
	//其中,newCallable本身是一个可调用对象,arg_list是一个逗号分隔的参数列表
	//对应给定的callable的参数.即 当调用 newCallable时,newCallable会调用callable
	//并传递给arg_list中的参数 arg_list中的参数可能包含形如_n的名字,其中n是
	//一个整数,这些参数是点位符,表示newCallable的参数,它们占据了传递给newCallable的
	//参数的"位置",数值n表示生成的可调用对象中参数的位置:
	//_1为newCallable的第一个参数, _2为第二个参数
	//[注意使用标准库的std::placeholders::_n]

	//绑定check_size的sz参数
	auto check6 = bind(check_size, std::placeholders::_1, 6);
	//_1出现在args_list的第一个表明调用的check_size的第一个参数用check6的1号参数

	//这样可以代替之前的lambda表达式
	words = { "12","123","1234","12345","12345678" };
	auto wc2 = find_if(words.begin(), words.end(),
		bind(check_size, std::placeholders::_1, sz)
	);
	cout << distance(words.begin(), wc2) << endl;

	//使用placeholders名字
	//_n名字都定义在一个名为placeholders的命名空间中,而这个命名
	//空间本身定义在std命名空间
	//

	//一般用bind修正函数的参数(安排参数的顺序)
	//f是一个可调用对象,有5个参数
	using namespace std::placeholders;
	//auto g = bind(f, a, b, _2, c, _1);
	//g(_1, _2) = > f(a, b, _2, c, _1);
	//用bind重排参数顺序,因此可以使用bind来从小于判定改成大于判定
	//
	//绑定引用参数
	//默认情况下,bind的那些不是占位符的参数被拷贝到bind返回的可调用对象中
	//但是,与lambda类似,有时对有些绑定的参数希望以引用方式传递,或是要绑定参数类型无法拷贝
	//例如一个函数
	//ostream &print(ostream &os, const string &s, char c)
	//不能直接使用bind来代替对os的捕获
	//bind(print,os, _1 ,' ');
	//如果要传递给bind一个对象而又不拷贝它,必须使用标准库ref函数
	//bind(print, ref(os), _1, ' ');

	//函数ref返回一个对象,包含给定的引用,此对象是可以拷贝的
	//还有一个函数cref,生成一个保存const 引用的类,两个函数也定义在头文件functional

}
//用于打印的宏函数
#define PRINT_C(c)\
	for (auto i : c) {\
		std::cout << i << " ";\
	}\
	std::cout << std::endl;

void test_iterator() {
	//除了为每个容器定义的迭代器之外,标准库在头文件iterator中还定义了额外几个迭代器
	//插入迭代器  绑定在一个容器上,可用来向容器插入元素
	//流迭代器  绑定在输入输出流上,可用来遍历所关联的IO流
	//反向迭代器  迭代器向后而不是向前移动,除了forward_list之外的标准库容器都有反向迭代器
	//移动迭代器  不是拷贝其中的元素,而是移动它们

	//插入器是一种迭代器适配器,接受一个容器生成一个迭代器,能实现向给定容器添加元素
	//当通过一个插入迭代器赋值时,该迭代器调用容器操作来向给定容器的指定位置插入一个元素
	//操作有
	//it = t ;  在it指定的当前位置插入值t,依赖于绑定的容器,分别调用c.push_back(t)
	// c.push_front(t) 或 c.insert(t,p) p为传递给inserter的迭代器位置
	//*it , ++it, it++  这些操作虽然存在,但不会对it做的任何事,每个操作都返回it
	//
	//插入器有三种类型,差异在于元素插入的位置
	//back_inserter()  创建一个使用push_back的迭代器
	//front_inserter   创建一个使用push_front的迭代器
	//inserter 创建一个使用insert的迭代器,接受第二个参数,必须指向给定容器的迭代器,插入给定的元素之前
	//只有绑定容器支持相关的操作才能调用相关的插入器函数

	//inserter:  
	//*it = val;  //等价
	//it = c.insert(it,val);
	//++it;  //等价

	using std::list;
	using std::cout;
	using std::cin;
	list<int> lst{ 1,2,3,4 };
	list<int> lst2, lst3;

	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	PRINT_C(lst2); // 4 3 2 1
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
	PRINT_C(lst3); // 1 2 3 4

	//iostream迭代器
	//虽然iostream类型不是容器,但标准库定义了可以用于这些IO类型对象的迭代器
	//istream_iterator读取输入流
	//ostream_iterator向输出流写数据
	//这些迭代器将它们对应的流当作一个特定类型的元素序列来处理,通过使用流迭代器,可以用
	//泛型算法从流对象读取数据以及向其写入数据

	//当创建一个流迭代器时,必须指定迭代器将要读写的对象类型,一个istream_iterator使用
	//>>来读取流,因此,istream_iterator要读取的类型必须定义了运算符
	//可以默认初始化值,创建一个可以当作尾后值使用的迭代器
	//istream_iterator<int> int_it(cin);  //从cin读取int
	//istream_iterator<int> int_eof;  //尾后迭代器
	//ifstream in("afile");
	//istream_iterator<string> str_it(in); //从"afile"读取字符串
	//
	using std::cin;
	using std::cout;
	using std::endl;
	//允许使用懒惰求值(编译器不保证迭代器立即从流读取数据),
	//保证在第一次解引用迭代器之前从流中读取数据的操作已经完成
	//[注意:只要声明了一个istream_iterator,就会执行cin从流中读取数据,不一定]
	//std::istream_iterator<int> in_iter(cin); //从cin读取int
	std::istream_iterator<int> eof;  //istream尾后迭代器
	std::vector<int> vec;  //用来存储的vector
	//while (in_iter != eof) { 
	//	//注意一旦关联的流遇到了文件尾或遇到了IO错误
	//	//[这点很有用,当输入类型与期望不符,IO便出错直接终止错误值赋值]
	//	//迭代器的值就会与尾后迭代器相等
	//	vec.push_back(*in_iter++);
	//}
	//PRINT_C(vec);

	//循环赋值可能有些难用, 可以使用构造
	//但也会丢失首元素指针
	//cout << "#### " << *in_iter++ << endl; // 7
	//std::vector<int> vec2(in_iter, eof); // 7 8 9
	//PRINT_C(vec2);
	//cin.clear();
	//std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
	//cout << "#### " << *in_iter++ << endl; // 7  仍然从开始读取
	//cout << "#### " << *in_iter++ << endl; // 7
	//cout << "#### " << *in_iter++ << endl; // 7
	//std::vector<int> vec3(in_iter, eof); // 7
	//PRINT_C(vec3);
	//[注意:出现以上情况的原因是每次使用++时,流迭代器会检查流对象是否有效,无效则无法getVal]
	//[GetVal的实现就是每次操作输入流>>,因此这终归是一个迭代器,不存储的任何数据,现取现用]
	//[也就是说如果在某个函数中对这个流进行了++操作就会消耗一次输入,并且不可找回旧的]
	//[之所以*in_iter能返回值,是因为内置一个temp变量存储上个成功取到的值,返回它]

	//istream_iterator<T> in(is); //in从输入流is读取类型为T的值
	//istream_iterator<T> end;  //类型T的迭代器,表示尾后位置
	//in1 == in2  //两个必须读取相同类型,如果它们都是尾后迭代器,或绑定相同的输入,则两者相等
	//in1 != in2  
	// *in 返回从流中读取的值
	//in->mem  与(*in).mem的含义相同
	//++in, in++  使用元素类型所定义的>>运算符从输入流中读取下一个值
	//
	//使用算法操作流迭代器
	std::istream_iterator<int> inin(cin);
	cout << std::accumulate(inin, eof, 100/*要加上的初始值*/) << endl;

	//类似的使用ostream_iterator<T>
	//要求元素类型可以使用<<运算符,可以提供可选的第二个参数(必须C风格字符串),
	//在输出每个元素后都会打印此字符串.必须将ostream_iterator绑定到一个指定的流
	//不允许空的或表示尾后位置的ostream_iterator
	//ostream_iterator<T> out(os);
	//ostream_iterator<T> out(os,d); 值写到输出流os中,每个值后面都输出一个d,d指向一个空字符结尾的字符数组
	//out = val;  用<<运算符将val写入到out所绑定的ostream中,val类型与out可写的类型兼容
	//*out, ++out, out++;  存在但不做任何事 返回out

	//可以用ostream_iterator来输出值的序列
	std::ostream_iterator<int> out_iter(std::cout, " ");
	std::vector<int> vec4{ 8,7,6,3,2,1 };
	for (auto e : vec4)
		out_iter = e;//*out_iter++ = e;
	cout << endl;

	//可以通过调用copy来打印vec中的元素
	copy(vec4.begin(), vec4.end(), out_iter);
	cout << endl;

	//反向迭代器
	//是在容器中从尾元素向首元素反向移动的迭代器,对于反向迭代器,递增操作含义会反
	//除了forward_list之外,其他容器都支持反向迭代器,
	//可以通过调用rbegin,rend,crbegin,crend成员函数获得反向迭代器
	//这些成员函数返回指向容器尾元素和首前元素
	//反向迭代直接使用
	//string(line.crbegin(),rcomma)会反序打印单词
	//应当通过调用reverse_iterator的base成员函数来完成, 返回其对应的普通迭代器
	//string(rcomma.base(), line.cend()); //请注意base前后两个指向的元素不同,差了一个位置
	//p364
}
void test_algorithm_struct() {
	//算法要求的迭代器操作可以分为5个迭代器类别
	//输入迭代器
	//输出迭代器
	//前向迭代器
	//双向迭代器
	//随机访问迭代器

	//5类迭代器
	//迭代器也定义了一组公共的操作
	//算法sort要求随机访问迭代器,array,deque,string,vector的迭代器都是随机访问迭代器
	//用于访问内置数组元素的指针也是

	//算法的形参模式
	//alg(beg, end, other args);
	//alg(beg, end, dest, other args);
	//alg(beg, end, beg2, other args);
	//alg(beg, end, beg2, end2, other args);

	//dest参数是一个表示算法可以写入的目的位置的迭代器,算法假定按需要写入数据,不管
	//写入多少个元素都是安全的,向输出迭代器定稿数据的算法都假定目标空间足够容纳
	//(一般是插入迭代器或是ostream_iterator)
	//使用beg2的假定至少与beg和end 表示的范围一样大

	//算法命名规范
	//一些算法使用重载形式传递一个谓词
	//unique(beg, end);  //使用 == 运算符比较元素
	//unique(beg, end, comp);  //使用comp比较元素
	//将相邻的重复元素删除(只是放到最后)返回一个unique的尾后元素
	//if版本的算法
	//find(beg, end, val); //查找输入范围中val第一次出现的位置
	//find_if(beg, end, pred);  //查找第一个令pred为真的元素
	//区分拷贝元素的版本和不拷贝元素的版本
	//默认情况下重排元素的算法将重排后的元素写回给定的输入序列中,这些算法还提供另外一个版本
	//将元素写到一个指定的输出目的位置,它们名字后加_copy
	//reverse(beg, end);  //反转输入范围中元素的顺序
	//reverse_copy(beg, end ,dest);  //将元素逆序拷贝到dest
	//一些算法同时提供 _copy和 _if版本
	//remover_if(v1.begin(), v1.end(),
	//				[](int i){return i%2;}); //从v1中"删除"奇数元素
	//remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
	//				[](int i) {return i%2;}); //将偶数元素从v1拷贝到v2,v1不变


	//特定容器算法
	//与其他容器不同链表类型list和forward_list定义了几个成员函数形式的算法
	//特别的 它们定义了独有的sort, merge, remove, reverse和 unique
	//通用版本的sort要求随机访问迭代器,链表类型定义的其他算法的通用版本可以用于链表但代价
	//太高(需要真正的交换元素的位置)
	//因此对于list,forward_list 应该优先使用成员函数版本的算法而不是通用算法
	//lst.merge(lst2) 将来自lst2的元素合并入lst,lst和lst2必须是有序的
	//lst.merge(lst2, comp) 元素将从lst2中删除,合并之后 lst2为空,第一个版本使用<,第二个用谓词
	//lst.remove(val)  //调用erase删除掉与给定值相等(==)或令一元谓词为真的第一个元素
	//lst.remove_if(pred)
	//lst.reverse()  //反转lst中元素的顺序
	//lst.sort()  //使用<或给定比较操作排序元素
	//lst.sort(comp)  
	//lst.unique()  //调用erase删除同一个值的连续拷贝
	//lst.unique(pred)  

	//splice成员(list和forward_list的成员函数的参数)
	//链表类型还定义了splice算法,独有
	//lst.splice(args) 或 first.splice_after(args)
	//(p,lst2) p是一个指向lst中元素的迭代器,或是一个指向flst首前元素,函数将lst2所有元素移动到p之前or flst之后
	//(p, lst2, p2) p2是一个指向lst2中位置的有效的迭代器,将p2指向的元素移动到lst中,或将p2之后的元素移动到flst中,lst2可以与lst相同list
	//(p, lst2, b, e) b和e必须表示lst2中的合法范围,将给定范围中的元素从lst2移动到lst工flst, last2与lst可以是相同的链表,但p不能指向给定范围内的元素

	//注意:链表中独有的操作会改变容器
	//而泛型算法不会改变底层的容器
	//
	//算法不直接改变它们所操作的序列的大小,它们会将元素从一个位置拷贝到另一个位置,但不会直接添加工删除元素
	//但可以通过插入迭代器做到

}

//关联容器
void test_associative() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	using std::istringstream;
	string inputstring("");
	istringstream sinput(inputstring);
	//关联容器支持高效的关键字查找和访问,两个主要的关联容器类型是map和set
	//map中的元素是一些关键字-值对
	//关键字起到索引的作用,值则表示与索引相关联的数据
	//set中每个元素只包含一个关键字
	//set支持高效的关键字查询操作:检查一个给定关键字是否在set中
	//例如,在某些文本处理过程中,可以用一个set来保存想要忽略的单词,字典则是一个很好的使用
	//map的例子

	//标准库提供8个关容器,不同
	//1.每个容器或是一个set,或是一个map
	//2.或者要求不重复的关键字,或允许重复的关键字
	//3.按顺序保存元素,或无序保存
	//允许重复关键字的容器的名字中都包含单词multi
	//不保持关键字按顺序存储的容器的名字都以单词unordered开头
	//因此一个unordered_multi_set是一个允许重复关键字元素无序保存的集合
	//而一个set则是一个要求不重复关键字,有序存储的集合
	//无序容器使用哈希函数来组织元素

	//类型map和multimap定义在头文件map中,set和multiset定义在头文件set中
	//无序容器则定义在头文件unordered_map和unoreder_set中
	//
	//按关键字有序保存元素
	//map 关联数组,保存key-value
	//set 关键字即值,即只保存关键字的容器
	//multimap 关键字可重复出现的map
	//multiset 关键字可重复出现的set 
	//无序集合
	//unordered_map 哈希函数组织的map
	//unordered_set 哈希函数组织的set
	//unordered_multimap 哈希组织的map,关键字可重复
	//unordered_multiset 

	//使用关联容器
	//一个经典的使用map的例子是单词计数器

	//使用map
	//map<string, size_t> word_count;
	//string word;
	//while(cin>>word)
	//   ++word_count[word];
	//for( const auto &w : word_count) 
	//   cout<<w.first<<" occurs "<<w.second
	//       <<((w.second>1) ? "times" : " time"<<endl;
	//类似顺序容器,关联容器也是模板
	//如果一个word还未在map,下标运算[]会创建一个新元素,其关键字为word,值为0
	//当从map中提取一个元素时,会得到一个pair类型的对象
	//pair是一个模板类型,保存两个名为first和second的(public)数据成员
	//

	//使用set
	//set<string> exclude = {"the", "a", "or"};
	//if(exclude.find(word)==exclude.end())
	//

	//关联容器概述
	//关联容器不支持顺序容器的位置相关的操作,例如push_front或push_back
	//关联容器的迭代器都是双向的

	//定义关联容器
	//每个关联容器都定义了默认的构造函数,创建一个指定类型的空容器,也可初始化为另一个同类型
	//容器的拷贝,或是从一个值范围来初始化关联容器,只要值能转化
	//在新标准下,也可以对关联容器进行值初始化 c++ 11
	//当初始化一个map时,必须提供关键字类型和值类型,将每个关键字-值对包围在花括号中
	//{key,value}

	//初始化multimap或multiset
	//一个map和set中的关键字必须是唯一的,multi版本没有限制
	using std::vector;
	using std::set;
	using std::multiset;
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	//
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	PRINT_C(iset);
	cout << miset.size() << endl;
	PRINT_C(miset);

	//关键字类型的要求
	//关联容器对其关键字类型有一些限制
	//对于有序容器:map multimap set multiset
	//关键字类型必须定义比较的方法,默认情况下使用关键字类型的<运算符来比较两个关键字
	//在集合类型中,关键字就是元素类型,在映射类型中,关键字类型是元素的第一部分的类型
	//
	//有序容器的关键字类型
	//可以向一个算法提供我们自己定义的比较操作,与之类似,也可提供自己的操作来代替关键字上的<
	//运算符,所提供的操作必须在关键字类型上定义一个严格弱序,可以将其看作"小于等于"
	//虽然实际定义的操作可能是一个复杂的函数,无论我们怎样定义比较函数,它必须具备如下基本性质
	//1.两个关键字不能同时"小于等于"对方
	//2.k1"<="k2 k2"<="k3 则 k1"<="k3
	//3.如果存在两个关键字,任何一个都不"<="另一个,那么说这两个关键字是等价的,同样应当有传递性

	//使用关键字类型的比较函数
	//为了使用自定义的操作,在定义multiset时必须提供两个类型,关键字类型
	//和比较操作类型--应该是一种函数指针类型
	//multiset<Bangumi_Data,decltype(compareBD)*>
	//		bangumi_set(compareBD);
	//同时使用函数名来初始化对象,也可用&compareBD实参代替,因为默认会将函数名转换为指针类型

	//pair类型
	//它定义在头文件utility中
	//一个pair保存两个数据成员,类似容器
	std::pair<string, string> anon;
	std::pair<int, string > sfdfsfad{ 1,"xxx" };
	//pair的默认构造函数对数据成员进行初始化
	//与其他的标准库类型不同,pair的数据成员是public的,两个成员分别命名为first和second
	//用普通成员访问符号访问它们
	//
	//pair的操作
	//pair<T1, T2> p;
	//pair<T1, T2> p(v1, v2);
	//pair<T1, T2> p = {v1,v2};
	//make_pair(v1,v2);  返回一个用v1 v2初始化的pair,类型从v1,v2的类型中推断
	//p.first  返回p的名为first的公有数据成员
	//p.second 返回p的名为second的公有数据成员
	//p1 relop p2  关系运算符按字典序的定义:例如,当p1.first<p2.first 或 !(p2.first < p1.first)&&p1.second<p2.second
	//成立时,p1 <p2为true
	//p1 == p2
	//p1 != p2

	//创建一个函数需要返回一个pair,在新的标准下,可以对返回值 进行列表初始化
	//return {v.back(), v.back().size()}; //较早的c++不支持只用一个花括号,必须下面的
	//return pair<string, int>();
	//也可使用make_pair()函数return一个pair对象

	//关联容器操作
	//key_type 此容器类型的关键字类型
	//mapped_type 每个关键字关联的类型:只适用于map
	//value_type 对于set,与key_type相同 / 对于map为 Pair<const key_type, mapped_type>
	//注意pair的第一个类型是const

	//关联容器迭代器
	//当解引用一个关联迭代器时,得到一个类型为容器的value_type的值的引用.注意不能更改Pair的第一个数据(关键字)(const)
	//map => pair类型  set => key_type类型
	//set的迭代器是const的,虽然set类型定义了iterator和const_iterator类型,但两种类型都只允许访问set中的元素
	//与不能改变一个map元素的关键字一样,set中的关键字也是const

	//遍历关联容器,两个容器支持begin和end操作

	//关联容器和算法
	//通常不对关联容器使用泛型算法,比如find算法,有自带的效率远高于泛型算法(顺序搜索)
	//一般使用用作一个目标位置,源序列 例如拷贝一个关联容器
	//类似地可以用inserter将一个插入器绑定到一个关联容器

	//添加元素
	//关联容器的insert成员,向容器中添加一个元素或一个元素范围 
	//由于map和set不包含重复的关键字,因此插入一个已存在的元素对容器没有影响
	vector<int> ivec10 = { 2,4,6,8,2,4,6,8 };
	set<int> seti10;
	seti10.insert(ivec10.cbegin(), ivec10.cend()); //有4个元素 2 4 6 8
	seti10.insert({ 1,3,5,7,1,3,5,7 }); //有8个元素 1 2 3 4 5 6 7 8
	using std::ostream_iterator;
	ostream_iterator<int> oiter(cout, " ");
	for (auto i = seti10.cbegin(); i != seti10.cend(); ++i) {
		oiter = *i;
	}
	cout << endl; //注意:关联容器也是支持迭代器的,也可通过迭代器遍历
	//cout << "Test Print_c:\n";
	//PRINT_C(seti10);
	//向map添加
	//对一个map进行insert,记住一个map的元素是pair类型
	//向map插入元素的四种方法
	//m.insert({word,1});
	//m.insert(make_pair(word,1));
	//m.insert(pair<string,size_t>(word,1));
	//m.insert(map<string,size_t>::value_type(word,1));

	//关联容器的insert操作
	//m.insert(v)  v是value_type类型的对象:args用来构造一个元素
	//m.emplace(args)  只有当元素的关键字不在m中都会插入(构造)元素,返回一个pair包含一个迭代器
	//					指向具有指定关键字的元素,以及一个指示插入是否成功的bool值
	//					对于multimap和multiset总会插入(构造)给定元素,并返回一个指向新元素的迭代器
	//m.insert(b, e)   be是迭代器,表示一个m::value_type类型值 的范围
	//m.insert(i1)   il是这种值的花括号列表,返回void
	//m.insert(p, v)  与单一参数类似,只是指定了p迭代器位置的插入,返回一个迭代器,指向具有给定关键字
	//m.emplace(p, args)   的元素

	//向multimap,multiset添加元素
	//接受单个元素的insert操作返回一个指向新元素的迭代器,无须返回一个bool值

	//删除元素
	//关联容器定义了三个版本的erase
	//与顺序容器相似,可以通过给erase一个迭代器或一个迭代器对来删除一个元素或一个元素范围,返回void
	//关联容器提供一个额外的erase操作
	//它接受一个key_type参数,此版本删除所有匹配给定关键字的元素(如果存在的话)
	//返回实际删除的元素的数量

	//c.erase(k)  从c中删除每个关键字为k的元素,返回一个size_type值,指出删除的元素的数量
	//c.erase(p)  删除迭代器p指定的元素,返回指向p之后的元素,尾元素删除返回尾后元素c.cend()
	//c.erase(b, e)  删除迭代器对b和e所表示的范围中的元素,返回e

	//map的下标操作
	//map和unordered_map提供了下标运算符和一个对应的at函数
	//set类型不支持下标,不能对multimap等进行下标,因为可以一对多
	//但是注意如果下标接受的关键字不在map中,会为它创建一个元素并插入到map中
	//关联值将进行值初始化
	//由于关联容器可能插入一个新的元素,我们只可以对非const的map使用下标操作
	//word_count["Anna"] = 1;
	//1.在word_count中搜索关键字为Anna的元素
	//2.将新的关键字-值插入到word_count中,关键字是一个const string,保存Anna
	//值进行值初始化
	//3.提取出新插入的元素,将值赋予它

	//c[k]  返回关键字为k的元素(不是迭代器)如果k不在,添加一个关键字为k的元素,对其进行值初始化
	//c.at(k)   访问关键字为k的元素,带参数检查;k不在c中,抛出一个out_of_range的异常

	//与vector和string 不同 ,map的下标运算符返回的类型与解引用map迭代器得到的类型不同
	//
	//访问元素
	//关联容器提供多种查找一个指定元素的方法,
	//如果只关心一个特定元素是否已在容器中,可能find是最佳选择,对于不允许重复关键字的容器,使用
	//find和count没什么区别,但对于允许重复关键字的容器,count不会做更多的工作,如果元素在容器中
	//不会统计有多少个元素有相同的关键字,否则最好使用find
	set<int> iset11 = { 0,1,2,3,4 };
	iset11.find(1);	//返回一个迭代器,指向key==1的元素
	iset11.find(11);	//返回一个迭代器,其值等于iset.end()
	iset11.count(1);	//返回1
	iset11.count(11);	//返回0
	//lower_bound和upper_bound不适用于无序容器
	//下标和at操作只适用于非const的map和unordered_map
	//c.find(k) 返回一个迭代器 ,指向关键字为k的元素,若k不在容器中,返回尾后元素
	//c.count(k) 返回关键字等于k的元素的数量 
	//c.lower_bound(k)  返回一个迭代器,指向第一个关键字不小于k的元素 否则返回一个不影响排序关键字插入位置
	//c.upper_bound(k)  返回一个迭代器,指向第一个关键字大于k的元素 否则返回一个不影响排序关键字插入位置
	//c.equal_range(k)  返回一个迭代器pair,表示关键字等于k的元素的范围,若k不存在,pair的两个成员均等于c.end()

	//在map中通过使用find和count可以遍历相同关键字的所有元素
	//auto times = c.cout("x");
	//auto iter = c.find("x");
	//while(times){ ;++iter;--times}

	//以上还可以使用lower_bound和uupper_bound来实现
	//for( auto beg = c.lower_bound(1),
	//		end = c.upper_bound(1);
	//		beg != end; ++beg)
	//   ;
	//如果不存在1,lower_bound可能返回第一个大于1的元素,也可能是尾后迭代器

	//equal_range函数
	//最直接的解决方法
	//for(auto pos = c.equal_range(1);pos.first!=pos.second;++pos.first)
	//;
	//

	//单词转换的map p392
	//

}

//无序容器
void test_unordered_container() {
	//c++11 定义了4个无序关联容器
	//这些容器不是使用比较运算来组织元素的
	//而是使用一个哈希函数和关键字类型的==运算符
	//在关键字类型的元素没有明显的序关系的情况下,无序容器是非常有用的
	//在某些应用中维护元素的序代价非常高昂,此时无序容器有用

	//除了哈希管理之外,无序容器还提供了与有序容器相同的操作(find,insert等)
	//因此通常可以用一个无序容器替换对应的有序容器,反之亦然,但是由于元素未按顺序存储,
	//一个使用无序容器的程序的输出(通常)会与使用有序容器的版本不同(FIFO)

	//管理桶
	//无序容器在存储上组织为一组桶,每个桶保存0个或多个元素,无序容器使用一个哈希函数将元素映射到
	//桶,为了访问一个元素,容器首先计算元素的哈希值,它指出应该搜索哪个桶,容器将具有一个特定哈希值
	//的元素都保存在相同的桶中,如果容器允许重复关键字,所有具有相同关键字的元素也都会在同一个桶中
	//因此,无序容器的性能依赖于哈希函数的质量和大小
	//对于相同的参数,哈希函数必须总是产生相同的结果,当一个桶保存多个元素时,需要顺序搜索这些元素
	//来查找想要的那个,通常哈希和在桶中搜索很快,但保存多个元素会...

	//无序容器提供了一组管理桶的函数
	//桶接口
	//c.bucket_count()  //正在使用的桶的数目
	//c.max_bucket_count()  //容器能容纳的最多的桶的数量
	//c.bucket_size(n)   //第n个桶中有多少元素
	//c.bucket(k)    //关键字为k的元素在哪个桶中
	//桶迭代
	//local_iterator  //可以用来访问桶中元素的迭代器类型
	//const_local_iterator  //桶迭代器的const版本
	//c.begin(n), c.end(n)  //桶n的首元素迭代器和尾后迭代器
	//c.cbegin(n), c.cend(n)  //返回const_local_iterator
	//哈希策略
	//c.local_factor()  //每个桶的平均元素数量,返回float值
	//c.max_load_factor()  //c试图维护的平均桶大小,返回float值,c会在需要时添加新的桶,使得load_factor<=max_load_factor
	//c.rehash(n)  //重组存储,使得bucket_count>=n且bucket_count>size/max_load_facotor
	//c.reserve(n) //重组存储,使得c可以保存n个元素且不必rehash

	//无序容器对关键字类型的要求
	//默认情况下,无序容器使用关键字类型的==运算符来比较元素,还使用一个
	//hash<key_type>类型的对象来生成每个元素的哈希值
	//标准库为内置类型(包括指针)提供了hash模板,还为一些标准库类型,包括string
	//和智能指针类型定义了hash,因此可以直接定义关键字是内置类型(包括指针类型)string还是智能指针的
	//无序容器

	//不能直接定义关键字类型为自定义类类型的无序容器,与容器不同,不能直接使用哈希模板
	//而必须提供自己的hash模板版本
	//定义一个重载函数
	//using hasher = 
#define hasher(bs)	[](const Bangumi_subject&bs) {return std::hash<int>()(bs.Id());}
	typedef size_t(*hash_type)(const Bangumi_subject&);
#define eqOp(lhs,rhs)  [](const Bangumi_subject&lhs,const Bangumi_subject &rhs)\
{return lhs.Id() == rhs.Id();}
	typedef bool(*eqOp_type)(const Bangumi_subject&lhs, const Bangumi_subject &rhs);

	using BS_multiset = std::unordered_multiset<Bangumi_subject, hash_type, eqOp_type>;

	//参数是桶的大小,哈希函数指针和相等性判断运算符指针
	BS_multiset bangumi(42, [](const Bangumi_subject&bs) {return std::hash<int>()(bs.Id()); },
		[](const Bangumi_subject&lhs, const Bangumi_subject &rhs)
	{return lhs.Id() == rhs.Id(); });

	//如果类已经定义了==运算符,则可以只重载哈希函数

	//关联容器支持通过关键字高效查找和提取元素,对关键字的使用将关联容器和顺序容器区分开来
	//顺序容器中是通过位置访问元素的
	//标准库定义了8个关联容器
	//有序容器使用比较函数来比较关键字,默认情况下,比较操作是使用<运算符
	//无序容器使用关键字类型的==运算符和一个hash<key_type)类型的对象来组织元素

}
//动态内存
void test_dyn_mem() {
	//除了自动和static对象外,c++还支持动态分配对象
	//动态分配的对象的生存期与它们在哪里创建是无关的
	//只有当显式地被释放时,这些对象才会销毁
	//为了更安全地使用动态对象,标准库定义了两个智能类型来管理动态分配的对象
	//当一个对象应该被释放时,指向它的智能指针可以确保自动地释放它

	//静态内存用来保存局部static对象,类static数据成员以及定义在任何函数之外的变量
	//栈内存用来保存定义在函数内 的非static对象,分配在静态或栈内存中的对象 由编译器自动创建和销毁
	//static对象在使用之前分配,在程序结束时销毁

	//除了静态内存和栈内存,每个程序还拥有一个内存池,这部分内存被称作自由空间(free store)或堆(heap)
	//程序用堆来动态分配的对象,即那些在程序运行时分配的对象,动态对象的生存期由程序来控制
	//也就是说当动态对象不再使用时,代码必须显式地销毁

	//动态内存与智能指针
	//在c++中 动态内存的管理是通过一对运算符来完成的:
	//new:在动态内存中为对象分配空间并返回一个指向该对象的指针,可以选择对对象进行初始化
	//delete:接受一个动态对象的指针,销毁该对象,并释放与之关联的内存
	//

	//c++11
	//新标准库提供两种智能指针类型来管理动态对象
	//智能指针的行为类似常规指针,重要的区别是它负责自动释放所指向的对象
	//两种智能指针的区别在于管理底层指针的方式;
	//shared_ptr允许多个指针指向同一个对象
	//unique_ptr则独占所指向的对象
	//标准库还定义了一个名为weak_ptr的伴随类,它是一种弱引用,指向shared_ptr所管理的
	//对象,这三种类型都定义在memory头文件中

	//shared_ptr类
	//类似vector,智能指针也是模板(提供额外的信息)
	//
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
	std::shared_ptr<string> p1;
	//默认初始化的智能指针中保存一个空指针
	//如果一个条件判断中使用智能指针,效果就是检测它是否为空
	//检查p1是否为空,如果不为空,检查昰否指向一个空string
	if (p1 && p1->empty()) {
		;
	}

	//shared_ptr和unique_ptr公共支持的操作
	//shared_ptr<T> sp  //空智能指针,可以指向类型为T的对象
	//unique_ptr<T> up  //
	//p  //将p用做一个条件判断,若p指向一个对象,则为true
	//*p  //解引用p,获得它指向的对象
	//p->mem  //等价于(*p).mem
	//p.get()  //返回p中保存的指针,要小心使用,若智能指针释放了其对象,返回的指针所指的对象也就消失
	//swap(q,p)  //交换p和q中的指针
	//p.swap(q)  


	//shared_ptr独有的操作
	//make_shared<T>(args) //返回一个shared_ptr,指向一个动态分配的类型为T的对象,使用args初始化此对象
	//shared_ptr<T>p(q) //p是shared_ptr的拷贝:此操作会递增q中的计数器.q中的指针必须能转换为T*
	//p = q  //p和q都是shared_ptr,所保存的指针必须能相互转换,此操作会递减p的引用次数,递增q的引用计数
	//			//若p的引用计数变为0,则将其管理的原内存释放
	//p.unique()  //若p.use_count()为1,返回true;否则返回false
	//p.use_count()  //返回与p共享对象的智能指针数量(可能慢:用于调试)

	//make_shared函数 
	//最安全的分配和使用动态内存的方法是调用make_shared
	//此函数在动态内存中分配一个对象并初始化它,返回指向此对象的shared_ptr(定义在memory)
	//使用时需要指定要创建的对象的类型,定义方式与模板类相同
	//make_shared()类似顺序容器的emplace成员,它用参数来构造给定类型的对象,args与元素的某个构造函数匹配
	//如果不传递任何参数,对象就会进行值初始化

	//注意即使在函数内make_shared  int也不会未定义,这里初始化0
	std::shared_ptr<int> test_int_sp = std::make_shared<int>();
	cout << *test_int_sp << endl;

	//shared_ptr的拷贝和赋值
	//当进行拷贝或赋值操作时,每个shared_ptr都会记录有多少个其他shared_ptr指向相同的对象
	//auto p = make_shared<int>(42); //p指向的对象只有p一个引用者
	//auto q(p);  //p和q指向相同对象,此对象有两个引用者
	//可以认为每个shared_ptr都有一个关联的计数器,通常称其为引用计数count,无论何时
	//拷贝一个shared_ptr,计数器都会递增,例如,当用一个shared_ptr初始化另一个shared_ptr
	//或将它作为参数传递给一个函数以及作为函数的返回值时,它所关联的计数器就会递增,当给shared_ptr
	//赋予一个新值或是shared_ptr被销毁(例如一个局部的shared_ptr离开其作用域),计数器会递减
	//一旦一个shared_ptr的计数器变为0,就会自动释放自己所管理的对象
	auto sfs = std::make_shared<int>(3);//r是3的唯一引用者
	sfs = test_int_sp;
	//给sfs赋值
	//递增q指向的对象的引用计数
	//递减r原来指向对象的引用计数
	//r原来指向的对象已经没有引用者,会自动被释放

	//shared_ptr自动销毁所管理的对象
	//当指向一个对象的最后一个shared_ptr被销毁时,shared_ptr类会自动销毁此对象,
	//它是通过另外特殊的成员函数--析构函数完成销毁工作的,类似于构造函数,每个类都有一个析构函数
	//就像构造函数控制初始化一样,析构函数控制此类型的对象销毁时做什么操作
	//析构函数一般用来释放对象所分配的资源,
	//shared_ptr的析构函数会递减它所指向的对象的引用计数,如果引用计数变为0,shared_ptr的析构函数会销毁对象
	//并释放它占用的内存

	//shared_ptr还会自动释放相关联的内存,当动态对象不再被使用时,shared_ptr会自动释放动态对象
	//这个特性使得动态内存的使用变得非常容易,例如可能有一个函数,它返回一个shared_ptr,
	//指向一个Foo类型的动态分配对象,对象是通过一个类型为T的参数进行初始化的
	//另外一个函数中调用该函数拷贝生成了一个局部变量shared_ptr,并且函数没有返回这个,函数结束后则这个对象本身也释放
	//其原理与上面一样(本质还是引用计数的好)

	//总之没有任何引用的指针存在,内存就会被释放

	//share_ptr在无用之后仍然保留的一种可能情况是:将shared_ptr放在一个容器中,
	//随后重排了容器,从而不再需要某些元素,这种情况下,应该确保用erase删除那些不再需要的shared_ptr元素

	//使用了动态生存期的资源的类
	//1.程序不知要使用多少对象
	//2.程序不知所需对象的准确类型
	//3.程序需要在多个对象间共享数据

	//容器类原因是1使用的动态内存
	//目前为止,使用过的类中,分配的资源都与对应对象的生存期一致
	//每个vector拥有自己的元素,当拷贝一个vector时,原vector和副本vector中的元素相互分离
	//但某些类分配的资源具有与原对象相独立的生存期,拥有共享的元素
	//一个对象如果有想要共享的内容,应当使用内存池创建内容防止对象被析构时内容被回收,信息丢失
	//p406

	//直接管理内存
	//c++定义了两个运算符来分配和释放动态内存,运算符new分配内存,delete释放new分配的内存
	//相对于智能指针,容易出错
	//在自由空间分配的内存是无名的,因此new无法为其分配的对象命名,而是返回一个指向对象的指针
	//int *p = new int;
	//默认下,动态分配的对象是默认初始化的,这意味内置类型或组合类型的对象的值将是未定义的
	//而类类型对象将使用默认构造函数进行初始化
	//可以使用直接初始化方式 int *p = new int(1024);
	//可以使用传统的构造方式 string *ps = new string(10, '9');
	//可以使用列表初始化(花括号) vector<int> *pv = new vector<int>{0,1,2,3};

	//也可对动态分配的对象进行值初始化,只需在类型名之后跟一对空括号
	//stirng *ps1 = new string; //默认初始化空string
	//string *ps = new string();  //值初始化为空
	//int *pi1 = new int;  //默认初始化:*pi1的值未定义
	//int *pi2 = new int(); //值初始化为0; *pi2为0
	//对于定义了自己的构造函数的类类型(例如string)来说,要求值初始化是没有意义的
	//不管采用什么形式,对象都会通过默认构造函数来初始化
	//但对于内置类型,两种形式不同;值初始化的内置类型对象有良好定义的值
	//而默认初始化的对象的值是未定义的,在类中没有值初始化的内置类型也会未定义

	//c++ 11
	//如果使用了{}初始化器(类型必须一样),就可以使用auto
	//但是由于编译器要用初始化器的类型来推断要分配的类型,只有当括号中仅有单一初始化器才可以使用auto
	//auto p1 = new auto(obj); p指向一个与obj类型相同的对象,对象调用obj初始化
	//auto p2 = new auto{a,b,c}; //错误:括号中只能有单个初始化器


	//动态分配的const对象
	//用new分配const对象是合法的
	//const int *pci = new const int (1024);
	//const string *pcs = new const string;
	//因为是const对象,必须进行初始化,除非有默认构造函数可以隐式初始化,new返回的指针是指向const的指针

	//内存耗尽
	//一个程序如果用光了可用的内存,就会new失败,会抛出异常bad_alloc
	//可以改变new的使用方式阻止抛出异常
	//int *p = new int; //失败的话抛出异常bad_alloc
	//int *p = new (nothrow) int ;  //如果失败返回一个空指针
	//这种形式的new称为定位new,允许向new传递额外的参数,bad_alloc和nothrow都定义在new头文件

	//释放动态内存
	//不用要归还内存,通过delete表达式,接受一个指针,指向需要释放的对象
	//delete p; //p必须指向一个动态分配的对象或一个空指针 
	//与new类似,delete有两个操作:1.销毁指向的对象 2.释放对应的内存

	//指针值和delete
	//delete的必须指向动态分配的内存或一个空指针,如果释放一个非new分配的内存,或将一个相同的
	//指针多次释放会产生未定义行为. 虽然const对象的值不能被改变,但可以被释放

	//动态对象的生命周期直到被释放为止,由内置指针(非智能指针)管理的动态内存在被显式释放前一直会存在
	//出错点:
	//1.忘记delete内存,会导致内存泄漏
	//2.使用已经释放掉的对象,通过在释放后将指针量置空可以解决
	//3.同一块内存释放两次,比如两个指针指向相同的动态分配对象时,可能发生

	//delete之后,指针本身仍存在,内容不在=>空悬指针

	//shared_ptr和new结合使用
	//shared_ptr<double>p1; //shared_ptr可以指向一个double
	//shared_ptr<int> p2(new int (45));
	//接受指针参数的智能指针是explicit的(只能用于直接初始化,并且不能隐式转换单一参数),因此不能将一个内置指针隐式转换为一个智能指针
	//必须使用直接初始化形式来初始化一个智能指针 
	//shared_ptr<int>p1 = new int (1024) //错误: 必须使用直接初始化形式(不能拷贝一个普通指针(因为阻止了隐式转换))
	//shared_ptr<int>p (new int(1024));  //正确:使用了直接初始化形式(构造函数接受一个普通指针参数)
	//因此不能return new int(p); 到share_ptr<int>
	//没有一个内置指针到智能指针的隐式转换

	//默认一个用来初始化智能指针的指针指向一个动态分配的内存空间,因为智能指针默认使用delete释放
	//如果要绑定一个指向其他类型的资源的指针上.应当提供自己的delete操作

	//定义和改变shared_ptr的其他方法
	//shared_ptr<T> p(q)  //p管理内置指针q所指向的对象,q必须指向new分配的内存,且能转换为T*
	//shared_ptr<T> p(u)  //p从unique_ptr u 接管对象的所有权,将u置为空
	//shared_ptr<T> p(q,d)	//p接管了内置指针q的对象的所有权,p将使用可调用对象d代替delete
	//shared_ptr<T> p(p2, d)  //p2是shared_ptr类型, p是p2的拷贝,唯一区别是使用d代替delete
	//p.reset()	 //若p是唯一指向其对象的shared_ptr,reset会释放此对象,若传递了可选的参数内置
	//p.reset(q)	//指针q,会令p指向q否则会将p置为空,d是使用d而不是delete释放q
	//p.reset(q,d)  //reset减少一次引用计数

	//不应当混合使用普通new指针和shared_ptr
	//不应使用get初始化另一个智能指针或为智能指针赋值
	//get()返回一个内置指针,指向智能指针管理的对象,是为了需要向不能使用智能指针的代码传递一个内置
	//指针,使用get返回的指针的代码不能delete此指针(会只减少计数导致释放)
	//p414

	//reset可以将一个新的指针赋予一个shared_ptr
	//与赋值类似,reset会更新引用计数,如果需要,会释放p指向的对象,reset经常和unique一起使用
	//控制多个shared_ptr共享的对象,在改变底层对象之前,检查是否当前对象仅有的用户,否则在改变前
	//制作一份新的拷贝

}
void test_smart_pointer() {
	//智能指针和异常
	//使用智能指针,即使程序块过早结束,智能指针也能确保在内存不再需要时将其释放
	//正常处理或发生异常,局部的变量都会被销毁,因此不能通过delete(异常之后)释放
	//
	//所有标准库在内的很多c++类都定义了析构函数

	//使用自己的释放操作
	//默认情况下,shared_ptr假定它们指向的是动态内存,因此,当一个shared_ptr被销毁时
	//默认进行delete操作
	//假定有以下
	//connection connect(destination*)
	//void disconnect(connection);
	//void f(destination &d){
	//	connection c = coneect(&d);
	//	//如果没有在f退出前调用 disconnect,就无法关闭c
	//}

	//void end_conneciont(connection *p){disconnect(*p);}
	//void f(destination &d){
	//	connection c = connect(&d);
	//	shared_ptr<connection> p(&c, end_connection);
	//  //当f退出(或异常)connection会被正确关闭
	//}

	//智能指针的陷阱
	//需要坚持的一些基本规范
	//1.不使用相同的内置指针值初始化(reset)多个智能指针
	//2.不delete get()返回的指针
	//3.不使用get()初始化或reset另一个智能指针
	//4.如果使用get()返回的指针,当最后一个对应的智能指针销毁后,指针变为无效
	//5.如果使用智能指针管理的资源不是new分配的内存,记住传递给它一个删除器

	//unique_ptr
	//一个Unique"拥有"它所指向的对象,与shared_ptr不同,某个时刻只能有一个Unique_ptr
	//指向一个给定的对象,当unique_ptr被销毁时,它所指向的对象也被销毁
	//与shared_ptr不同,unique_ptr没有一个类似make_shared的标准库函数
	//当定义一个unique_ptr时,需要绑定new返回的指针,初始化方式也必须是直接初始化
	std::unique_ptr<double> p1; //可以指向一个double的uniunique_ptr
	//由于一个Unique拥有一个对象,因此不能普通拷贝和赋值操作
	//unique_ptr<string> p2(p1);   //错误:不支持拷贝
	//p3 = p2;  //错误: 不支持赋值
	//
	//unique_ptr的操作
	//unique_ptr<T> u1  空
	//unique_ptr<T,D> u2  //u2会调用D的可调用对象来释放指针
	//unique_ptr<T,D> u(d)  //空unique_ptr,指向类型为T的对象,用类型为D的对象d代替delete
	//u = nullptr ;  //释放u指向的对象,将u置为空
	//u.release();  //放弃对指针的控制权,返回指针,并将U置为空
	//u.reset();  //释放u指向的对象
	//u.reset(q);  //如果提供了内置指针q,令u指向这个对象,否则将u置为空
	//u.reset(nullptr);
	//虽然不能拷贝或赋值unique_ptr,但可以通过调用release或reset将指针的所有权转移(一个u到另一个U)
	using std::string;
	std::unique_ptr<double> p2(p1.release());
	std::unique_ptr<double> p3(new double(1.0));
	//reset会释放自身指向的对象
	p2.reset(p3.release());

	//p2.release();//错误: p2不会释放内存,而且会丢失指针
	//auto fsfsdd = p2.release(); //正确,必须记得delete(p)

	//不能拷贝unique_ptr的规则有一个例外,可以拷贝或赋值一个将要被销毁的Unique_ptr
	//常见的例子是从函数返回一个unique_ptr
	//{return unique_ptr<int>(new int(p));}也可返回局部的变量
	//这种情况下编译器使用一种特殊的"拷贝"

	//向后兼容 auto_ptr
	//标准库较早时包含了一个名为auto_ptr的类,具有unique_ptr的部分特性,应当弃用


	//向Unique_ptr传递删除器
	//与shared_ptr不同,应当在声明时提供额外的信息(删除器的类型参数)
	//在创建或reset一个这种unique_ptr类型的对象时,必须提供一个指定类型的可调用对象(删除器)
	//unique_ptr<objT, delT> p (new objT, fcn);

	//重写连接的例子
	//void f(destination &d){
	//   connection c = connect(&d);
	//	 unique_tr<connection, decltype(end_connerction)*>
	//        p(&c,end_connection);
	//}

	//weak_ptr
	//weak_ptr是一种不控制所指向对象生存期的智能指针,它指向由一个shared_ptr管理的对象
	//.将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数,一旦最后一个
	//指向对象的shared_ptr被销毁,对象就会被释放,即使有weak_ptr指向对象,对象也还会被释放
	//因此,weak_ptr的名字抓住了这种智能指针"弱"共享对象的特点

	//weak_ptr
	//weak_ptr<T> w //空weak_ptr可以指向类型为T的对象
	//weak_ptr<T> w(sp)  //与shared_ptr sp指向相同对象的weak_ptr,T必须能转换为sp指向的类型
	//w = p    //p可以是一个shared_ptr or weak_ptr,赋值后w与p共享对象
	//w.reset()  //将w置为空
	//w.use_count()  //与w共享的对象的shared_ptr的数量
	//w.expired()   //若use_count()为0,返回true,否则返回false
	//w.lock()  //如果expired为true,返回一个空shared_ptr;否则返回一个指向w的对象的shared_pt

	//当创建一个weak_ptr时,要用一个shared_ptr来初始化
	auto dfsf = std::make_shared<int>(42);
	std::weak_ptr<int> sfdfsf = dfsf;  //dfsf的引用计数并没有改变

	//由于对象可能不存在,不能使用weak_ptr直接访问对象,而必须调用lock,此函数检查
	//weak_ptr指向的对象是否仍存在,如果存在lock返回一个指向共享对象的shared_ptr
	//只要此shared_ptr存在,它所指向的底层对象也就会一直存在
	if (std::shared_ptr<int> np = sfdfsf.lock());
	//这句只有当lock调用返回true

	//检查指针类
	//指针操作
	//weak_ptr可以解决循环引用

}

void test_dyn_array() {
	//动态数组
	//c++提供了两种一次分配一个对象数组的方法
	//定义了另一种new表达式语法:可以分配并初始化一个对象数组
	//标准库中包含一个名为allocator的类: 允许将分配和初始化分离
	//使用allocator通常会提供更好的性能和更灵活的内存管理能力
	//使用容器更为简单

	//new和数组
	//为了让new分配一个对象数组,要在类型的后面跟上一对方括号,在其中指明要分配的对象的数目
	//int *pia = new int[get_size()]; //调用函数确定大小
	//数目可以不是常量,但要是整数

	//也可用typedef int arrT[42]; int *p = new arrT;

	//分配一个数组会得到一个元素类型的指针
	//实际上分配的并不是一个数组类型,因此不能对其调用begin或end

	//初始化动态分配对象的数组 
	//默认初始化 Int = > 0
	//新标准中,还可以提供一个元素初始化器的花括号列表
	//int *pia = new int[4]{0,12,2,5};
	//不足的使用默认初始化
	//如果大于元素数目,则new表达式失败,不会分配的任何内存,抛出bad_array_new_length,定义在new头文件中
	//动态分配一个空数组是合法的,调用 new int[0]是合法的
	//char arr[0]; //错误
	//char *cp = new char[0]; //正确,不能解引用

	//释放动态数组 
	//使用delete 在指针前加上一个空方括号
	//delete p;  //释放一个对象
	//delete []pa;	//释放一个数组  其中元素按逆序销毁
	//注意:使用typedef的时候new时不需要加[],但delete时一定加上[]

	//智能指针和动态数组
	//[注意:要明确数组可以转换为指针,因此完全可以将智能指针看作是数组的别名]
	//标准库提供了一个可以管理new分配的数组的unique_ptr版本
	//为了用一个unique_ptr管理动态数组,必须在对象类型后面跟一对方括号
	std::unique_ptr<int[]> up(new int[10]);

	//这个版本的unique_ptr操作有不同
	//当一个unique_ptr指向一个数组时,不能使用点和箭头成员运算
	//可以这样访问元素
	for (size_t i = 0; i != 10; ++i) {
		up[i] = i;
	}
	up.release(); //自动用delete[]销毁其指针
	//由于up指向一个数组,当up销毁它管理的指针时会自动使用delete[] ...

	//shared_ptr不直接支持管理动态数组,如果希望应该提供自己定义的删除器
	//注意是<int>不是<int*> [shared_ptr已经说明了指针 *]
	std::shared_ptr<int> test_s_n(new int[5], [](int *p) {delete[]p; });
	//不过使用shared_ptr遍历就会相对麻烦
	for (size_t i = 0; i != 5; ++i)
	{
		*(test_s_n.get() + i) = i;
	}
	test_s_n.reset();


	//allocator类
	//new有一些灵活上的局限,其中一方面表现在它将内存分配和对象构造组合在一起
	//类似,delete将对象析构和内存释放组合在一块
	//当分配一大块内存时,通常计划在这块内存上按需构造对象,但只在真正需要时才真正
	//执行对象创建操作
//一般情况下,将内在分配和对象构造组合在一起可能会导致不必要的浪费
//
//allocator类
//标准库allocator类定义在头文件memory中
//它提供一种类型感知的内存分配方法,它分配的内存是原始的,未构造的
//
//allocator<T> a  //定义了一个名为a的allocator对象,可以为类型为T的对象分配内存
//a.allocate(n)  //分配一段原始的,未构造的内存,保存n个T对象
//a.deallocate(p,n)  //释放从T*指针p中地址开始的内存,这块内存保存了n个类型为T的对象
//						//p必须是一个先前由allocate返回的指针,且n必须是p创建时要求的大小
//					//在调用deallocate之前,用户必须对每个在这块内存中创建的对象调用destroy
//a.construct(p, args) //p必须是一个类型为T*的指针,指向一块原始内存:arg被传递给类型为
//					//T的构造函数,用来在p指向的内存中构造一个对象
//a.destroy(p)  //P是T*类型的指针,此算法对p指向的对象执行析构函数

//allocator分配未构造的内存
//分配的内存是未构造的,需要在此内存中构造对象,在新标准中,construct成员函数接受一个指针和0or多个额外的参数
//在给定的位置构造一个元素
int n = 10;
using std::string;
using std::cout;
using std::endl;
std::allocator<string> alloc;
auto const p = alloc.allocate(n);
auto q = p;
alloc.construct(q++);
alloc.construct(q++, 10, 'c');
alloc.construct(q++, "dddd");
//为了使用allocate返回的内存,必须使用construct构造对象,使用未构造内存,行为未定义
//当用完指针,必须对对象调用destroy来销毁
while (q != p)
alloc.destroy(--q);
//一旦元素被销毁,可以重新使用这部分内存也可归还给系统,释放内存通过调用deallocate完成
alloc.deallocate(p, n);
//deallocate的指针不能为空,必须指向由allocate分配的内存,而且传递给deallocate的大小参数
//必须与调用allocated分配内存时提供的大小参数一样
//因此,以上每个步骤都是紧密相关的,n,p,q

//拷贝和填充未初始化内存的算法
//标准库为allocator类定义了两个伴随算法,可以在未初始化内存中创建对象
//定义在头文件memory中
//uninitialized_copy(b, e, b2)  从迭代器b和e指出的输入范围中拷贝元素到迭代器b2指定的
//						未构造的原始内存中,b2指向的内存必须足够大,能容纳输入序列中元素的拷贝
//uninitialized_copy_n(b,n,b2)  从迭代器b指向的元素开始,拷贝n个元素到b2开始的内存中
//uninitialized_fill(b,e,t);  在迭代器b和e指定的原始内存范围中创建对象,对象的值均为t的拷贝
//uninitialized_fill_n(b,n,t); 从迭代器b指向的内存地址开始创建n个对象,b必须指向足够大的未
//			构造的原始内存
int test_un_size = 16;
std::vector<int> to_mem(10, 1);
std::allocator<int> test_uninit;
auto tu_p = test_uninit.allocate(test_un_size);
//使用uninitialized_copy系列指针都不够安全 unsafe编译器阻止
//auto qqq = std::uninitialized_copy_n(to_mem.cbegin(), to_mem.size(), tu_p);
//但是使用fill就不会unsafe
std::uninitialized_fill_n(tu_p, to_mem.size(), 6);
for (auto q = 0; q != to_mem.size(); ++q) {
	cout << *(tu_p + q) << " "; // 10个6
}
cout << endl;
}


//类


//重载运算与类型转换
//几元运算符就有几个参数
//如果一个运算符是成员函数,则它的第一个运算对象绑定到隐式的this指针上
//this绑定到左侧运算对象上
//对于一个运算符函数来说,它或者是类的成员,或者至少含有一个类类型的参数
//int operator+(int, int)不能为int重定义内置的运算符
//只能重载而不能发明一个操作符
//不能被重载的运算符 :: .* . ?:
//data1 + data2;
//operator+(data1, data2); 两者等价
//某些运算符不应被重载,一些操作符影响求值顺序 && || ,
//也不要重载 &

//赋值(=) 下标([]) 调用(())和成员访问箭头(->)运算符必须是成员
//复合赋值一般也是成员
//改变对象状态的运算符 递增 递减 解引用 通常是成员
//具有对称的运算通常是普通的非成员函数

//输入输出运算符必须是非成员函数,否则它的左侧运算对象是类的一个对象 而不是cout之类的
//输入结束后应当if(cin)检查是否有错误输入,否则重置当前类为默认状态,并且输入的状态需要重置
//如果类同时定义了算术运算符和相关的复合赋值运算符,则通常情况下应该使用复合赋值来实现算术运算符
//同理对于== 和 != 其中一个调用另一个来实现
//一般关系运算符定义<
//<要满足:1.如果类同时含有==运算符,则定义一种关系令其与==保持一致:特别是如果两个对象
//是!=的则一个对象应该<另一个对象

//赋值运算
//标准库除了拷贝,移动赋值运算外还提供了第三种赋值运算符:花括号

//StrVec &operator=(std::initializer_list<std::string>);

//不论形参类型是什么,赋值运算符必须定义为成员函数

//下标运算符
//std::string& operator[](std::size_t n)
//{return elements[n];}
//const std::string& operator[](std::size_t n) const
//{return elements[n];}

//前置的递增运算符
//StrBlobPtr & operator++();
//后置的递增运算符
//StrBlobPtr operator++(int); //不被使用的int参数区别两者

//注意两者返回的类型不同,后置返回一个拷贝,前置返回一个引用
//同时尽量在后置中使用前置实现

//重载的箭头运算符必须返回类的指针或自定义了箭头运算符的某个类的对象[复杂]

//函数调用运算符
//int operator()(int val) const{return 1;}
//如果类定义了调用运算符,则该类的对象称作函数对象,因为这些对象的行为像函数一样

//含有状态的函数对象类

//lambda是函数对象

//标准库定义的函数对象
//p510
//例如greater<Type> 可以作为sort的自定义算法   ,greater<string>());
//

//标准库function类型
//function定义在functional头文件中
//function<T> f; 用来存储可调用对象的空function,这些可调用对象的调用形式应该与函数类型T相同(retType(args))
//function<T> f(nullptr); 显式构造一个空function
//function<T> f(obj); 在f中存储可调用对象obj的副本
//f 将f作为条件:当f含有一个可调用对象时为真
//f(args) 调用f中的对象,参数是args
//定义为function<T>的成员的类型
//resutl_type 该function类型的可调用对象返回的类型
//argument_type  当T有一个或两个实参时定义的类型,如果T只有一个实参,则argument_type量该类型的同义词
//first_argument_type  如果T有两个实参,则first_argument_type和second_argument_type分别代表两个实参的类型
//second_argument_type

//function是一个模板
//function<int(int, int)> f1 = add;  //函数指针
//function<int(int, int)> f2 = divide();  //函数对象类的对象
//function<int(int, int)> f3 = [](int i, int j) {return i*j};  //lambda

//cout << f1(4, 2)<<endl;
//使用这个function类型可以重新定义map:
//map<string, function<int(int,int)>> binops;   
//binops = { {"+",add},
//			{"/", divide()}}
//binops["+"](10,5);

//重载函数与function
//不能(直接)将重载函数的名字存入function类型的对象中
//只能使用对应的函数指针赋值,或使用lambda表达式

//重载,类型转换和运算符
//转换构造函数和类型转换运算符共同定义了类类型转换,这样的转换有时也称作用户定义的类型转换
//类型转换运算符,是类的一种特殊成员函数,负责将一个类类型的值转换成其他类型
//类型转换函数的一般形式如下:
//operator type() const;
//其中type表示某种类型,类型转换运算符可以面向任意类型(除了void之外)进行定义,只要该类型
//能作为函数的返回类型,因此,不允许转换成数组或者函数类型,但允许转换成指针类型/引用类型
//类型转换运算符没有显式的返回类型,也没有形参,而且必须定义成类的成员函数
//一般定义为const
//因为类型转换运算符是隐式执行的,所以无法给这些函数传递实参,而且也没有一个返回类型
//编译器一次只能执行一个用户定义的类型转换

//{//某类中
//    operator int() const {return 5;}
//}

//尽量少用类型转换运算符  有用的是operator bool() const{}
//
//int i = 42;
//std::cin << i; //如果cin可以隐式转换为bool则编译通过(istream=>bool=>int=>位运算)

//显式地类型转换 c++ 11




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
	//extern const关键字
	//std::cout << x;
	//test_using();
	//cout << "end"; //using在块位域中声明只在其中有效
	//test_string();
	//test_vector();
	//test_array();
	//test_c_cpp_string();
	//test_basic();
	//test_statement();
	//try {
	//	test_exception();//执行测试代码
	//	//若失败则抛出异常
	//}
	//catch (std::runtime_error re) {
	//	std::cout << re.what(); //输出异常(runtime_error)的信息
	//	//what()返回c风格的字符串(const char*)
	//}
	//测试返回数组
	//int x[10] = { 0,1,2,3 };
	//for (auto i : x) {
	//	std::cout << i << " ";
	//}
	//std::cout << std::endl;
	//int (*y)[10] = test_return_array(x);
	//for (auto i : *y) {
	//	std::cout << i << " ";
	//}
	//std::cout << std::endl;
	//test_debug();
	//test_class_1();
	//test_TestDebug();
	//test_StaticClass();
	//test_IO_buf();
	//test_sstream();
	//测试初始化
	//int a; //若直接使用报错使用未初始化的值
	//int b = {};
	//std::cout /*<< a*/ << " " << b << std::endl;
	//test_undefine();
	//test_array_assign();
	//test_seq_container();
	//test_adaptor();
	//test_algorithm();
	//test_iterator();
	//test_algorithm_struct();
	//test_associative();
	//test_unordered_container();
	//test_dyn_mem();
	//test_smart_pointer();
	test_dyn_array();
	system("pause");
	return 0;
}
