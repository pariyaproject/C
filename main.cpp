#include <iostream>

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

int main() {
	//输入输出
	//cin_cout_cerr_clog();
	///*/*xx*/xxxx*/会报错
	//以上原因是/**/不能嵌套
	//注释问题
	note_err();


	system("pause");
}
