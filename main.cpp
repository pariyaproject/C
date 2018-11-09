#include <iostream>
#include <string>
#include <cctype>
#include <vector>
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
int test_exception(){
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
	try {
		test_exception();//执行测试代码
		//若失败则抛出异常
	}
	catch (std::runtime_error re) {
		std::cout << re.what(); //输出异常(runtime_error)的信息
		//what()返回c风格的字符串(const char*)
	}
	system("pause");
	return 0;
}
